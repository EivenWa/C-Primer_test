#include "Primer_test.h"

Primer_test::Primer_test()
{
	
}

Primer_test::~Primer_test()
{
}

/*-----------------parameter patrion------------------*/
void Primer_test::parameter(){

	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto temp : arr)
		cout <<"arr de auto:"<< temp << endl;
	//temp 是二维数组arr的三个子数组的首地址值（即地址值arr[0],arr[1],arr[2]）
	//传递借函数func_parameter(int arr[])

	for (auto temp : arr[0])
		cout << "arr[0] de auto:"<<temp << endl;
	//阐述多维数组即数组的数组，区分上temp和arr[0]等之间的区别
	//arr[0]是一个长度为3的以为数组，temp只是一个指针

	//for (auto temp : arr)
	//	for (auto temp1 : temp)
	//		cout << temp1 << endl;

	int arry[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	void func_parameter(int[10], int(&)[10]);
	
	func_parameter(arry, arry);
	//注意：此处对于arry数组的引用具有严格的要求
	//要求数组的定义显式的控制数组长度
	//在形参的定义中也必须显式定义数组长度，并且要严格相同

	//多维数组的传参：
	int (*p)[10] = &arry;
	vector<string> func_duoweishuzu_parameter(int arr[10][10]);
	func_duoweishuzu_parameter(p);
	
	int arr1[10][10] = { 5 };//此处会将第一个参数赋值，其余的赋0
	func_duoweishuzu_parameter(arr1);
	//多维数组的形参最多第高维度长度不固定，其余必须相同，对于传递的参数，最多可以最高唯独长度不相等

	cout << "sizeof(arr):" << sizeof(arr) << endl;
	cout << "sizeof(arry):" << sizeof(arry) << endl;
	//数组的长度为总数组所占内存大小,多维数组也是一样的
	cout << "sizeof(p):" << sizeof(p) << endl;
	cout << "sizeof(*p):" << sizeof(*p) << endl;

	void print_parameter(const int ia[10]);
	print_parameter(arry);


	//返回数组指针的函数使用实例：
	int(*function_parameter(int))[10];
	int(*pp)[10] = function_parameter(10);
	cout <<"(*pp)[1]:"<< (*pp)[1] << endl;
	for (auto temp:*pp)
		cout << "(*pp)[*]:" << temp << endl;

}

void func_parameter(int arr[10], int(&arry)[10]){
	//begin(arr);//此方法不能适应于指针，数组数据的传参时传递其首地址，即传递的是指针而不是数组本身
	//数组不同于指针，指针不会带着数组的长度信息
	//数组可以看成是一个比指针更高层的东西，它的首地址传数据，它还可以有一些别的东西，比如在11标准添加的begin和end，这使得更好的区分与数组与指针
	//指针应该是一个很底层的东西，p[offset]这种可以看成只是一种针对地址对象取值的方式
	//所以将指针如此取值不应该看成是将指针转换成数组，而是指针自己的方法

	for (auto temp : arry)   //只能对数组的引用（引进来的是一个数组，具有所有数组功能）
		cout << "dui shuzu de yinyong chuancan :"<<temp << endl;
	
	//int arry[10];
	auto aut = begin(arry);

}

vector<string> func_duoweishuzu_parameter(int arr[10][10]){
	
	cout << "duowei shuzu:"<<arr[0][0] << endl;
	//也就是说，传递二维或多维的数组，一定得加一个最高维长度参数才能防止越界之类的问题
	for (auto temp : *arr)
		cout <<"duoweizhuzu:" <<temp << endl;

	//使用return初始化vector<string>
	return{ "abcc", "cbaa", "aabb" };
}

void print_parameter(const int ia[10]){
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;

	//没想明白 initializer_list存在的具体意义
	initializer_list<char> lst{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	auto lst2 = lst;
	for (auto temp : lst)
		cout << temp << endl;

}

int(*function_parameter(int))[10]{
		
	//返回数组指针的函数
	int *p = new int[10];
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int (*pp)[10]= &arr;
	//return &p; //错误，类型不匹配
	return pp;//也就是说只能返回局部变量的数组指针，不知道这种设计的实际意义
}


/*-----------------function partion-------------------*/
auto funccc(int) -> int(*)[10];//函数声明（返回值为数组指针）
auto func_ppp(int) -> int(*)(int);//函数指针申明（返回值为函数指针）
//对于在形参中的const与非cosnt不匹配问题，只有在使用引用的时候才会出现问题

const string &shorterString(const string &s1, const string &s2){
	return s1.size() <= s2.size() ? s1 : s2;
}
string & shorterString(string &s1, string &s2){
	auto &r = shorterString(const_cast<const string &>(s1),
		const_cast<const string &>(s2));
	return const_cast<string &>(r);
}
//也就是说，参数加const不可以重构函数


void func_chonggou(int c){
	cout << "Use this, num0" << endl;
}
void func_chonggou(int a, int b = 10){
	cout << "Use this, num1" << endl;
}
void func_chonggou(double a, double b = 3.14){
	cout << "Use this, num2" << endl;
}

void(*fun_p)(int c) = func_chonggou;
using pp = void(*)(int c);// = func_chonggou;
void Primer_test::function(){
	//string& shorterString(const string&,const string&);
	//上声明语句会覆盖上面两个函数的重构，在局部环境内，shorterString函数只有上形式能用
	//即：局部声明会覆盖所有相关的全局声明
	string str = "abcdefg";
	string str1 = "abcdefghijklmn";
	string &s1 = str;
	string &s2 = str1;
	string &s3 = shorterString(s1,s2);
	cout << s3 << endl;

	//在这种情况下，函数定义是正确的，但是使用的时候要自己指定到底使用的是哪个函数
	//func_chonggou(1);
	func_chonggou(3.14);

	typedef decltype (funccc) Func1;
	typedef int(*((*Func2)(int)))[10];

	//解析上式： （）内必须为整体，*Func2表示指针，函数指针，int为其参数，
	//由数组指针形式： type （*Name）[]
	//函数指针形式： return_type (*Name)(形参)
	//组合就是将函数指针形式放进Name位置

	typedef int(*F1(int, int))(int, int);
	decltype(funccc) * function_shenming();
	//上俩返回值为函数指针的函数指针

	Func2 ff;
	ff = function_parameter;
	//其中函数名不能有重构现象

	vector<int(*)[]> vector_arr;
	vector<int(*)(int, int)>vector_funcpoit;

}



/*-------------------class partion--------------------*/

//使用func_friend成员函数作为友元顺序：
//---1 先声明class_test1
//---2 定义class_primer,中声明func_friend函数
//---3 定义class_test1
//---4 定义函数func_friend
class class_test1;
class class_primer{
	string str;
	string(*str_p)[10];
public:
	class_primer(string a);
	//也就是说，在类外定义构造器，还是需要再类里面声明的

	//最好保证：对象被创建时里面的所有对象成员被初始化
	//无论是构造器，还是声明对象时初始化

	//类的私有成员是对自己成员的私有

	void func_friend(class_test1 test1);/* {
		cout << test1.num << ":" << test1.str << endl;
	}*/
	void inline_yinshi(){}//隐式内联函数
	inline void inline_xianshi(){}//显示内联函数
};
typedef string size;

int temp_test_redef = 123;
class class_test1{
	//friend class class_primer;
	int num;
	string str;
public:
	friend void class_primer::func_friend(class_test1);
	friend void func_friend(class_test1);
	//友元函数是允许该函数使用本对象的私有成员

	class_test1(int a, string str1) :num(a), str(str1){}

	
	//此方法的作用域为定义的地方直到类的结束；
	//其public和private只在继承时有区别
	
	size func_use_friend(){
		
		class_test1 test1(3, "abd");
		func_friend(test1);
		//class_primer::func_friend(test1);

		size ik = 12;//使用的内部类型名string::size_type
		return sss;
	}

	size sss = "abd";
	typedef string::size_type size;
	//由类先定义所有数据成员，类型名的声明也是在这个过程中顺序执行的，再对函数成员
	//故而，开始的数据定义时，使用的是外部的size类型，
	//而在函数里面，是先在类内部找寻，再找外部，所以使用的是里面的string类型
	//而这种在里面使用了外部定义的类型再在里面定义这种类型：这种做法在C++ primer是不被允许的
	//最好的办法是将类型名的定义放在最前方，就能防止数据成员使用与内部有重定义的外部类型名（）即将typedef这行放最前方
	
	//类里面的寻找数据成员顺序是就近原则
	int temp_test_redef = 456;
	void func_test_redf(int temp_test_redef){
		cout <<"::到底是什么意思："<< ::temp_test_redef << endl;
	}
	//结果输出的是123，即全局的temp_test_redef，就是说没用具体的类名，就是使用了全局的域

};

class_primer::class_primer(string a) :str(a){
	cout << "str:" << str << endl;
}

//可以在外面定义内联函数
inline void class_primer::func_friend(class_test1 test1){
	cout << "This is the class_primer function func_friend()~~" << endl;
	cout << test1.num << ":" << test1.str << endl;
}

void func_friend(class_test1 test1){
	cout << "This is the global function func_friend()~~" << endl;
	cout << test1.num << ":" << test1.str << endl;
}

class class_init{
	int a{ 10 };
	int b = 10;//同上一样的意思，使用大括号或者=初始化类内成员
	mutable int mut;

	const int const_int;
	int & int_yinyong;

public:
	void changeValue(int temp) const {
		mut = temp;//合理性表现在mutabele成员可以在任何对象中改变其值
	}

	class_init(int ii) :b(ii), const_int(ii), int_yinyong(b){
		cout << "使用了委托构造器" << endl;
	}
	//这种叫做使用构造函数初始值，C++primer更推荐这种做法，效率登上都有提高
	//这样就算是const等必须初始化的变量，这样也是初始化了
	//虽然没有明说，但是C++primer推荐当使用构造函数初始值时，顺序最好与数据成员声明顺序一致
	//可能他在构造函数初始化的顺序与数据成员声明的顺序是一致的，并且，最好避免在构造函数初始值中使用数据成员初始化数据成员

	class_init() :class_init(0){};
};

class class_recons{
	char chh = 'c';
	char ch = 'd';
public:
	const char getchar()const{
		cout << "I have been there, the function with const limit" << endl;
		return chh;
	}
	char getchar(){
		return ch;
	}
	void func_recons() {
		class_recons recons;
		char temp_char = recons.getchar();
		cout << "temp_char:" << temp_char << endl;
		const char const_temp_char = recons.getchar();
		cout << "const_temp_char:" << const_temp_char << endl;

	}
};
//void func_recons()const{
//	class_recons recons;
//	char ch = recons.getchar();
//}//这种函数（后面定义为const的函数）只能是成员函数

class class_type_change{
	
public:
	string str;
	class_type_change() = default;
	class_type_change(string st):str(st){}
};
class  class_type_change1{

public:
	void change(class_type_change change){
		cout << "转换竟然成功了："<<change.str<<endl;
	}
};

//class class_constexpr{
//private:
//	int aa = 111;
//	int bb;
//
//public:
//
//	static constexpr int static_expr = 23333;//wahahah
//	constexpr class_constexpr(int b) :bb(b){
//
//	}
//
//	constexpr int getaa(){
//		return aa;
//	}
//	//void funn(){
//	//	bb = 123;
//	//}
//	//constexpr int* func(){	
//	//	constexpr int *p = (int*)malloc(sizeof(int));
//	//	return p;
//	//}
//
//};
//constexpr int class_constexpr::static_expr = 23333;//很想知道这样算是什么.....

//static 静态数据成员可以是不完全类型的
//不完全类型是只声明了，但是未定义的类型


void Primer_test::class_test(){
	string aaa = "abd";
	class_primer cla(aaa);
	cout << "If it is succeed" << endl;


	//void funn(int a, string str);
	class_test1 test1(1,"abc");

	cla.func_friend(test1);
	//友元函数的使用示例（使用友元的私有成员）

	cout << "woshi fengexian --------------------" << endl;//与下作参照
	test1.func_use_friend();
	//试一试使用声明过的友元函数，不出意外的话就是全局的友元函数
	//使用类的友元函数还是必须要用类对象来调用

	//test1.size ss;
	class_recons recons;
	char ch = recons.getchar();
	const char chh = recons.getchar();
	//调用的全是没有const的函数，是只有在const对象中才会调用const的函数吗？
	cout << "No const ch:" << ch << "\nconst chh:" << chh << endl;

	recons.func_recons();
	//竟然这样都还是调用的没有const的函数，搞不懂
	//然后问题来了，const函数不是只能使用const函数么，为啥~~

	//懂了,只有用const对象才能调用const函数
	const class_recons recon;
	char ch_ = recon.getchar();
	//recon.func_recons();
	cout << "const_class:" << ch_ << endl;

	//另：const对象只能调用const函数，wtf！！！
	test1.func_test_redf(789);

	//类成员的初始化等问题
	class_init init;//里面只有一个构造器是否会调用委托构造器里面的执行语句问题验证

	class_type_change1 change1;
	string str = "opopop";
	change1.change(class_type_change("opoopp"));

	change1.change(str);//不可以是一个字符串，必须为string类型的对象
	//const char *可以隐式转化为string类型，但是不能转两次。。。
	class_type_change change = "opoopp";
	//当构造器参数只有一个时，可以隐式的将参数转换为此对象！！！
	//参数多个不可以，可以用explicit禁止这种功能,则上两种不能使用了
	//暂时只看到explicit用于构造器的

	const char* char_const = "aabbcc";
	char char_arr[] = "abc";
	char_const = char_arr;
	//只是确定开始const char*的写法是否正确

	//这样写char_arr数组长度为4，保存'\0'
	cout << "sizeof(char_arr:)" << sizeof(char_arr) << endl;
	
	//保留对聚合类使用的疑问
	//【思考】聚合类的限制要求，感觉和一个纯粹的数据结构一样，然后其实作用就只有这样吗？





}
	

/*-------------------Container partion--------------------*/

void Primer_test::container(){
	
	vector<int> arr(10,0);
	arr.size();
	arr.push_back(10);
	arr.clear();
	
	

}
