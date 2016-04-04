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

//传函数指针进行函数调用就是一个回调的过程

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
	//typedef string size;
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

inline void class_primer::func_friend(class_test1 test1){
	//可以在外面定义内联函数
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
		//一层的转换可以隐式进行：可以将一个string（必须是显示的string类型的）隐式转换为此class_type_change
		//详见class_test()函数中
	}
};

//class class_constexpr{
//private:
//	int aa = 111;
//	int bb;
//
//public:
//
//	static int static_expr;// = 23333;//wahahah
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
//int class_constexpr::static_expr = 23333;//很想知道这样算是什么.....
////待考量，重新学习

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

	//erase删除，一般返回指向被删除的最后一个元素后面的迭代器
	//一般vector，string，deque删除非两端的元素，会影响其迭代器，指针，引用等
	//(vector非尾删，deque非首位删，string非尾删(vector和string删出元素会导致其后面的。。。))
	//forwar_list单链表的性质，比较特殊
	//一般情况下能用vector解决（中间要插入操作之类的的不算）的数据结构就不要想着使用别的容器
	//添加元素能用emplace就用emplace，会更高效一些


	//----------vector---------
	vector<int> arr(10,10);
	arr.size();
	//arr.push_back(10);
	//arr.clear();
	//上执行后，会清空vector arr

	vector<int >arr_vector(12, 1);
	vector<int>::iterator arr_vec_begin = arr_vector.begin();
	arr_vector = arr;//此操作过后，arr_vector长度与arr同
	//上一行若不进行对迭代器的再赋值，则debug failed,其指向的数据已经被删除
	//cout << "arr_vector[11]:"<<arr_vector[11] << endl;//会终止，因为长度只有10了

	arr_vec_begin = arr_vector.begin();
	cout << "vector被赋值后，其iterator指针指向的值：" << *arr_vec_begin << endl;
		

	vector<int>::iterator arr_begin = arr.begin();//此时指向的是值为10
	vector<int> arr1_vector(16, 16);
	swap(arr, arr1_vector);//符合赋值规则，交换后长度也会交换，交换此方法最高效
	//此时arr长度为16，arr1_vector和arr_vector长度为10

	cout << "swap后的指针指向的值为：" << *arr_begin << endl;
	//swap后，其以前取的指针还是指向原来的数据（即原数据并没有移动），！！！但是指向的数据结构是交换后的结构
	//但是，对于array结构，swap会真正交换它们的元素，指针（或引用）指向原来的数据结构，但是元素值变了

	vector<int>::iterator begin = arr1_vector.begin();
	auto end = arr1_vector.end();
	arr.assign(begin,end);
	cout <<"arr此时的长度："<<arr.size()<< endl;//结果是10,上assign会清楚以前所有，然后按照这个长度来
	//assign相当于初始化的过程，可以用初始化的所有方式如：arr.assign(10,2);arr.assign(arr1_vector);

	arr.insert(arr.begin(),1,2);
	//arr.insert(arr.begin(),begin,end);
	//arr.insert(arr.begin(),2333);
	
	//会插在前面
	cout << "现在arr[0]：" << arr[0] << endl;

	arr.emplace(arr.begin(),21);//感觉功能不太给力
	cout << "emplace后arr[0]:" << arr[0] << "\n emplace后arr[1]:" << arr[1] << endl;

	cout << "arr emplace后的长度：" << arr.size() << endl;
	//综上，insert和emplace暂时没看到有什么区别，效果上没有区别
	//应该说是，insert多了一些功能，如可以添加多个数据

	arr.insert(arr.begin(),233);
	cout << "再insert后arr[0]:" << arr[0] << endl;
	//arr.emplace(arr.begin(), arr1_vector.begin(),arr1_vector.end());
	//cout << "再emplace后arr[0]:" << arr[0] << endl;

	arr.emplace_back(13);
	//使用此方法会直接在容器管理的内存空间中创建对象，而不是创建一个局部临时对象压入容器中
	//听起来，使用此方法要高效一些

	//-----arr_vector包含10个10,论中间insert对迭代器的影响
	auto arr_vector_end = arr_vector.end();
	auto arr_vector_begin = arr_vector.begin();
	auto arr_vector_mid = --arr_vector_end;
	//此时查看指针信息：begin比end大40，符合，并且说明其顺序是按照地址增大的方向分配内存
	//地址为0x0060b38和0x0060b60
	cout << "*arr_vector_begin:" << *arr_vector_begin << endl;
	arr_vector.insert(arr_vector_begin,3);
	//执行完后地址变为：0x0060b38和0x0060b60，也就是说其地址并没有变，但是其值变化了
	//按照地址来看，begin指向的还是以前的首元素，
	//但是，end不能解引用，尽管真实的按地址看是vector的第11个元素(原因未知，并非由于在插入点后面的未知引起)
	cout << "*arr_vector_begin:" << *arr_vector_begin << endl;
	if (arr_vector_end != arr_vector.end())
		cout << "*arr_vector_mid:" << *arr_vector_mid << endl;//能输出，所以end不能解引用是否是由于定义的时候时end所以不能吗？


	//----------array---------//固定长度数组
	//固定数组array的使用要求：
	//include<array>
	//using std::array
	array<int, 8> arr_array = {42};//会将第0个赋值为42，其余0
	//array<int, 8>::size_type size;
	//取size_type时必须使用完整的对象，如上array<int,42>才是完整的
	//array会默认初始化,不知道是不是真的默认了，但是其值绝对不是0，全是一个很大的负数
	for (int i = 0; i < 8;i++)
		cout << "arr_array[i]:"<<arr_array[i] << endl;//

	array<int, 8> arr1_array = arr_array;
	//可以这样复制，但是必须对象一致（即类型和长度一致）

	//arr_array = { 12, 11, 1 };//array不支持此种赋值方式，只有初始化时可以

	//array<int, 9> arr2_array;
	//swap(arr_array, arr2_array);//此种方法只能使用两个长度一样的array交换
	swap(arr_array,arr1_array);
	arr_array.swap(arr1_array);//此方法没有上一行高效，上快得多，vector同

	//----------list---------//双向链表
	//#include<list>
	//using std::list;
	list<int> ilist;
	ilist.push_front(11);
	ilist.push_front(12);
	ilist.insert(ilist.begin(),13);
	for (auto it : ilist)
		cout << "it:"<<it << endl;

	//----------deque---------//双端队列
	//#include<deque>
	//using std::deque;
	deque<int> ideque;
	ideque.push_back(1);
	ideque.push_front(2);
	ideque.insert(ideque.begin(),3);

	//----------string---------
	string str;
	str.push_back('a');
	str.insert(str.begin(),'b');
	cout <<"str:"<< str << endl;

	//----------forward_list---------//单链表
	//#include<forward_list>
	//using std::forward_list

	//使用一个primer上删除链表中奇数的元素的例子
	forward_list<int> flist = {1,2,3,4,5,6,7,8,9};
	auto prev = flist.before_begin();
	auto curr = flist.begin();
	//while (curr != flist.end())
	//{
	//	if (*curr % 2)
	//		flist.erase_after(prev);
	//	curr++;//会在这里出错，因为上面将curr指向的节点删除了，然后为什么不能递加，是不是因为++操作是使用->next操作的原理
	//	//反汇编：迭代器并非单纯的指针，++操作为重载的操作符，此外，其中也涉及到了别的函数调用
	//	prev++;
	//}
	//std::_Flist_iterator <std::_Flist_val<std::_Flist_simple_types<int> > >::~_Flist_iterator<std::_Flist_val<std::_Flist_simple_types<int> > >(0254537h)

	while (curr != flist.end())
		if (*curr % 2)//删除奇数
			curr = flist.erase_after(prev);
			//此处会给curr赋被删除后的一个元素的迭代器
		else{
			prev = curr;
			curr++;
		}
	
	for (auto temp_flist : flist)
		cout <<"flist_value:" <<temp_flist << endl;

	curr = flist.begin();
	flist.resize(2);
	cout << "after resize curr:" << *curr << endl;
	//resize缩小应该只是和删除类似，会影响删除后的迭代器之类的


	//----------适配器---------//强行是个栈，强行是个队列，强行是个优先级队列233333
	//类似接口的转换
	//#include<stack>
	//using std::stack;
	deque<int> deq(10, 2);
	stack<int> std(deq);//强行让这个看起来是个栈（先进后出）
	cout << "std.top():" << std.top() << endl;

	stack<string, vector<string>> str_stack;//并不能懂这个到底是什么意思	
	str_stack.push(string ("wahaha"));//存
	//vector<string> vec_str(3, "aaa");
	//str_stack.push(vec_str);
	//str_stack.pop();//丢
	cout <<"str_stack.top():"<<str_stack.top() << endl;//唯一取栈顶值的方法
	
	//#include<queue>
	//using std::queue
	queue<int> que(deque<int> (1,2));
	que.push(12);
	cout <<"que.front():"<<que.front() << endl;//取前头的数据 相当于top()
	cout<<"que.back():"<<que.back() << endl;//取尾数据
	que.emplace(23333);//也是添加到尾上（先进先出）

	
	//优先级队列 priority_queue只不过是在queue上添加优先级，优先级高的先pop出来
	//.pop()返回queue的首元素或者优先级最高的元素（但是不删除）与top同
	//
	//
	//using std::priority_queue	
	priority_queue<int> que_ority;
	que_ority.push(123);
	que_ority.pop();//Primer P330左下角说好的不删除是骗人的，基本上和队列差不多，只是有个优先级而已



}

void Primer_test::generic_algorithm(){
	//#include<algorithm>
	//#include<iomanip> //用于指定小数点后输出多少位
	cout << setprecision(10);//指定默认小数点为10位

	float float_test = (float)8.999999;//float只有6位的精度

	vector<float> vec_float = { 1, 2, 3, 4, 5, 6, 7, 8, (float)8.9999991 };//不强转的话，会将整个数组默认看为double而不能赋值给左边（g++4.8 允许）
	auto result = find(vec_float.begin(), vec_float.end(), (float)8.999999);//不强转的话，会默认转换为double，然后会找不到9.1
	if (result!= vec_float.end())
		cout << "result:" << *result << endl;//找到了，但是输出的是8.999999046（在精度范围内想等就算是相等，怀疑这个+也是重写过的）


	//#include<numeric>
	vector<double> vec_double = { 1, 2, 3, 4, 5, 6, 7, 8, (double)8.9999991 };
	
	//-----------accumulate函数
	double sum = accumulate(vec_double.cbegin(), vec_double.cend(), 0);//VS编译器会警告：因为将double强转为int型了，换为0.0则不会
	cout << "sum:"<<sum << endl;//结果是44，8.9999991被强转为int值为8，结果由第三个参数0确定是一个int型

	double sum_double = accumulate(vec_double.cbegin(), vec_double.cend(), 0.0);
	cout << "sum_double:" << sum_double << endl;//44.9999991

	vector<double>::const_iterator vec_double_it = vec_double.cend();
	//const时必须使用const_iterator
	//const是针对具体值的，不能改变迭代器指向的值，但是可以改变迭代器
	cout << "*--vec_double_it:" << *--vec_double_it << endl;

	//---------------equal函数
	bool if_vec_equal = equal(vec_float.cbegin(), vec_float.cend(),vec_double.cbegin());
	if (!if_vec_equal)
		cout << "类型不匹配的元素比较,然后结果不相等\n（在最后会将两个值转换为double型的，但是float在传值过程中丢失了一些精度）" << endl;


	vector<string> vec_str = {"111","222","333"};
	vector<string> vec_str1 = {"aaa","bbb","ccc"};
	//sum_double = accumulate(vec_str.cbegin(),vec_str.cend(),0.0);//编译通不过

	bool if_equal = equal(vec_str.cbegin(), vec_str.cend(),vec_str1.cbegin());//默认第二个序列长度至少与第一个序列长度相等
	if (!if_equal)
	{
		cout << "两个字符串不相等~~" << endl;
	}

	//----------------fill函数（要注意：算法中不会对容器本身进行操作（如改变容器的容量））
	//fill(vec_str.begin(),vec_str.end(),"aaa");此系列只能用一个值去赋值（例此中"aaa"）
	fill_n(vec_str.begin(),vec_str.size(),"aaa");//此中不能使用cbegin(),从头填size个"aaa"
	string str = accumulate(vec_str.cbegin(), vec_str.cend(), string(""));
	cout << "str:" << str << endl;
	
	//最好是配套插入迭代器来使用，能保证容器有足够的空间来保存数据，但是改变了容器本身，这样会不会与泛型的理念有冲突？
	fill_n(back_inserter(vec_str), 10, "vvv");

	//---------------back_inserter函数
	auto ret = copy(vec_str.cbegin(),vec_str.cend(),back_inserter(vec_str1));//三个迭代器，最后是目的，前两个表示范围
	*ret = "abc";//ret的类型与输入的第三个参数有关，还是back_inserter(vec_str1),
				//即添加后的最后一个空元素地方，但是可以直接赋值(由插入迭代器)
				//在这里ret不能读取，只能赋值
	//*ret = "bbb";//【后添加】此方法可以直接往后添加元素，每次赋值ret都会自增

	string str1 = accumulate(vec_str1.cbegin(), vec_str1.cend(), string(""));
	cout << "tstr1:" << str1<< endl;//结果最后面有abc串

	//--------------replace函数
	replace(vec_str.begin(),vec_str.end(),"vvv","ddd");//将所有中为vvv的元素改为ddd

	//--------------replace_copy函数
	replace_copy(vec_str.cbegin(), vec_str.cend(),vec_str1.begin(),"ddd","str");
	//将vec_str中的元素复制一份，并将其中所有的ddd替换为str保存到vec_str1中，vec_str不变

	//--------------sort函数 排序,之前vec_str有aaa和10个ddd,仅仅只是排序而已,使用元素的 < 进行排序
	sort(vec_str.begin(), vec_str.end());

	fill_n(back_inserter(vec_str), 2, "111");
	fill_n(back_inserter(vec_str), 2, "333");


	//---------------unique函数 重排输入范围，使得每个单词只出现一次，返回最后一个不重复单词的后一个的位置（有可能是end（））
	vector<string>::iterator vec_str_era = unique(vec_str.begin(),vec_str.end());
	//if (vec_str_era != vec_str.cend())//primer上说，就算指向end()，删除空的元素也是没问题的！！！
		vec_str.erase(vec_str_era,vec_str.end());//需要先排序，然后才能这样消除重复的，需要手动删除

	str = accumulate(vec_str.cbegin(), vec_str.cend(), string(""));
	cout << "排序删重后的str：" << str << endl;

	//---------------find_if
	bool if_find_if(int a);//貌似只能这样子，不能还别的类型的参数 见下：find_if 会调用_Find_if函数
	/*template<class _InIt,
	class _Pr> inline
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	for (; _First != _Last; ++_First)
	if (_Pred(*_First))
	break;
	return (_First);
	}*/
	vector<int> vec_int = { 1, 2, 3, 4, 5, 6, 7 ,8,9,10};
	auto temp_find_if = find_if(vec_int.cbegin(), vec_int.cend(), if_find_if);
	cout <<"*temp_find_if:"<< *temp_find_if << endl;//指向谓词返回true的第一个元素的未知的迭代器

	//---------------lambda表达式//中括号（捕获列表），函数体必不能少，别的可以省略
	auto f = [](int a, int b) ->int{return a + b; };
	cout << "f(1,2):" << f(1, 2) << endl;

	//上find_if
	int in = 6;
	temp_find_if = find_if(vec_int.cbegin(), vec_int.cend(), [in](int a){return a > in; });
	cout <<"*temp_find_if:"<< *temp_find_if << endl;//输出7

	for_each(temp_find_if, vec_int.cend(), [](int a){cout << a << endl; });
	/*
		void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	// perform function for each element
		for (; _First != _Last; ++_First)
			_Func(*_First);//在这里传过去的
	}
	*///for_each

	//---------------stable_sort
	vector<string> vec_words = {"abc","abb","abd","a","b"};
	//按照字符串长度排序，从短到长
	stable_sort(vec_words.begin(), vec_words.end(), [](const string &a, const string &b){return a.size() > b.size(); });

	//-----------------再谈lambda
	//默认情况下，Lambda函数总是一个const函数，mutable可以取消其常量性

	size_t v1 = 42;
	auto f_v1 = [v1](){return v1; };
	//在此传的值的拷贝，这过程在此处完成

	//若想跟随值变化，则用引用（但是要求在调用lambda的时候，引用的变量是存在的）：
	auto f_v = [&v1](){return v1; };
	v1 = 0;
	cout << "f_v1():" << f_v1() << endl;//输出为42！！
	cout << "f_v():" << f_v() << endl;//输出为0
	
	//auto f_v2 = [v1](){v1 = 3; };//出错，const函数不能改变外面的值
	//上lambda是const的，不能改变外部的值
	auto f_v3 = [v1]()mutable{ v1 = 3; };//改变的也是函数内部的一个对v1的值拷贝，无意义
	f_v3();
	cout << "f_v3();v1:" << v1 << endl;//0

	auto f_v4 = [&v1](){v1 = 5; };//5,尽管是const的，但是确确实改变了全局的变量值了
	f_v4();
	cout << "f_v4();v1:" << v1 << endl;
	
	
	//------------------bind函数，为了使用函数作为谓词设计（因为谓词有参数个数的限制）
	//------------------也可以重拍参数顺序
	//#include<functional>
	//using std::bind;

	auto re_if_find_if = bind(if_find_if,6);
	//功能：绑定6作为if_find_if的输入

	if (re_if_find_if())//调用if_find_if(6)
		cout << "调用成功了,是调用6" << endl;

	int test_bind(int a, int b,int c);
	auto re_test_bind = bind(test_bind, std::placeholders::_2, 6, std::placeholders::_1);
	//这些_1是指对应的re_test_bind函数的顺序，有_2则必须有_1
	//test_bind函数有n个参数，bind函数中则有n+1(+1为函数名)个参数，并且顺序一一对应
	//另：可以using namespace std::placeholders;直接使用_1什么的

	cout << "re_test_bind():" << re_test_bind(12,13) << endl;
	//上与test_bind(13,6,12)同，test_bind的第一个参数对应re_test_bind函数的第二个参数




}
bool if_find_if(int a){
	return a > 5;
}

int test_bind(int a,int b,int c){
	cout << "a:" << a << "\tb:" << b<<"\tc:"<<c << endl;
	return a + b;
}


