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
	//temp �Ƕ�ά����arr��������������׵�ֵַ������ֵַarr[0],arr[1],arr[2]��
	//���ݽ躯��func_parameter(int arr[])

	for (auto temp : arr[0])
		cout << "arr[0] de auto:"<<temp << endl;
	//������ά���鼴��������飬������temp��arr[0]��֮�������
	//arr[0]��һ������Ϊ3����Ϊ���飬tempֻ��һ��ָ��

	//for (auto temp : arr)
	//	for (auto temp1 : temp)
	//		cout << temp1 << endl;

	int arry[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	void func_parameter(int[10], int(&)[10]);
	
	func_parameter(arry, arry);
	//ע�⣺�˴�����arry��������þ����ϸ��Ҫ��
	//Ҫ������Ķ�����ʽ�Ŀ������鳤��
	//���βεĶ�����Ҳ������ʽ�������鳤�ȣ�����Ҫ�ϸ���ͬ

	//��ά����Ĵ��Σ�
	int (*p)[10] = &arry;
	vector<string> func_duoweishuzu_parameter(int arr[10][10]);
	func_duoweishuzu_parameter(p);
	
	int arr1[10][10] = { 5 };//�˴��Ὣ��һ��������ֵ������ĸ�0
	func_duoweishuzu_parameter(arr1);
	//��ά������β����ڸ�ά�ȳ��Ȳ��̶������������ͬ�����ڴ��ݵĲ��������������Ψ�����Ȳ����

	cout << "sizeof(arr):" << sizeof(arr) << endl;
	cout << "sizeof(arry):" << sizeof(arry) << endl;
	//����ĳ���Ϊ��������ռ�ڴ��С,��ά����Ҳ��һ����
	cout << "sizeof(p):" << sizeof(p) << endl;
	cout << "sizeof(*p):" << sizeof(*p) << endl;

	void print_parameter(const int ia[10]);
	print_parameter(arry);


	//��������ָ��ĺ���ʹ��ʵ����
	int(*function_parameter(int))[10];
	int(*pp)[10] = function_parameter(10);
	cout <<"(*pp)[1]:"<< (*pp)[1] << endl;
	for (auto temp:*pp)
		cout << "(*pp)[*]:" << temp << endl;

}

void func_parameter(int arr[10], int(&arry)[10]){
	//begin(arr);//�˷���������Ӧ��ָ�룬�������ݵĴ���ʱ�������׵�ַ�������ݵ���ָ����������鱾��
	//���鲻ͬ��ָ�룬ָ�벻���������ĳ�����Ϣ
	//������Կ�����һ����ָ����߲�Ķ����������׵�ַ�����ݣ�����������һЩ��Ķ�����������11��׼��ӵ�begin��end����ʹ�ø��õ�������������ָ��
	//ָ��Ӧ����һ���ܵײ�Ķ�����p[offset]���ֿ��Կ���ֻ��һ����Ե�ַ����ȡֵ�ķ�ʽ
	//���Խ�ָ�����ȡֵ��Ӧ�ÿ����ǽ�ָ��ת�������飬����ָ���Լ��ķ���

	for (auto temp : arry)   //ֻ�ܶ���������ã�����������һ�����飬�����������鹦�ܣ�
		cout << "dui shuzu de yinyong chuancan :"<<temp << endl;
	
	//int arry[10];
	auto aut = begin(arry);

}

vector<string> func_duoweishuzu_parameter(int arr[10][10]){
	
	cout << "duowei shuzu:"<<arr[0][0] << endl;
	//Ҳ����˵�����ݶ�ά���ά�����飬һ���ü�һ�����ά���Ȳ������ܷ�ֹԽ��֮�������
	for (auto temp : *arr)
		cout <<"duoweizhuzu:" <<temp << endl;

	//ʹ��return��ʼ��vector<string>
	return{ "abcc", "cbaa", "aabb" };
}

void print_parameter(const int ia[10]){
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;

	//û������ initializer_list���ڵľ�������
	initializer_list<char> lst{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	auto lst2 = lst;
	for (auto temp : lst)
		cout << temp << endl;

}

int(*function_parameter(int))[10]{
		
	//��������ָ��ĺ���
	int *p = new int[10];
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int (*pp)[10]= &arr;
	//return &p; //�������Ͳ�ƥ��
	return pp;//Ҳ����˵ֻ�ܷ��ؾֲ�����������ָ�룬��֪��������Ƶ�ʵ������
}


/*-----------------function partion-------------------*/
auto funccc(int) -> int(*)[10];//��������������ֵΪ����ָ�룩
auto func_ppp(int) -> int(*)(int);//����ָ������������ֵΪ����ָ�룩
//�������β��е�const���cosnt��ƥ�����⣬ֻ����ʹ�����õ�ʱ��Ż��������

const string &shorterString(const string &s1, const string &s2){
	return s1.size() <= s2.size() ? s1 : s2;
}
string & shorterString(string &s1, string &s2){
	auto &r = shorterString(const_cast<const string &>(s1),
		const_cast<const string &>(s2));
	return const_cast<string &>(r);
}
//Ҳ����˵��������const�������ع�����


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
	//���������Ḳ�����������������ع����ھֲ������ڣ�shorterString����ֻ������ʽ����
	//�����ֲ������Ḳ��������ص�ȫ������
	string str = "abcdefg";
	string str1 = "abcdefghijklmn";
	string &s1 = str;
	string &s2 = str1;
	string &s3 = shorterString(s1,s2);
	cout << s3 << endl;

	//����������£�������������ȷ�ģ�����ʹ�õ�ʱ��Ҫ�Լ�ָ������ʹ�õ����ĸ�����
	//func_chonggou(1);
	func_chonggou(3.14);

	typedef decltype (funccc) Func1;
	typedef int(*((*Func2)(int)))[10];

	//������ʽ�� �����ڱ���Ϊ���壬*Func2��ʾָ�룬����ָ�룬intΪ�������
	//������ָ����ʽ�� type ��*Name��[]
	//����ָ����ʽ�� return_type (*Name)(�β�)
	//��Ͼ��ǽ�����ָ����ʽ�Ž�Nameλ��

	typedef int(*F1(int, int))(int, int);
	decltype(funccc) * function_shenming();
	//��������ֵΪ����ָ��ĺ���ָ��

	Func2 ff;
	ff = function_parameter;
	//���к������������ع�����

	vector<int(*)[]> vector_arr;
	vector<int(*)(int, int)>vector_funcpoit;

}



/*-------------------class partion--------------------*/

//ʹ��func_friend��Ա������Ϊ��Ԫ˳��
//---1 ������class_test1
//---2 ����class_primer,������func_friend����
//---3 ����class_test1
//---4 ���庯��func_friend
class class_test1;
class class_primer{
	string str;
	string(*str_p)[10];
public:
	class_primer(string a);
	//Ҳ����˵�������ⶨ�幹������������Ҫ��������������

	//��ñ�֤�����󱻴���ʱ��������ж����Ա����ʼ��
	//�����ǹ�������������������ʱ��ʼ��

	//���˽�г�Ա�Ƕ��Լ���Ա��˽��

	void func_friend(class_test1 test1);/* {
		cout << test1.num << ":" << test1.str << endl;
	}*/
	void inline_yinshi(){}//��ʽ��������
	inline void inline_xianshi(){}//��ʾ��������
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
	//��Ԫ����������ú���ʹ�ñ������˽�г�Ա

	class_test1(int a, string str1) :num(a), str(str1){}

	
	//�˷�����������Ϊ����ĵط�ֱ����Ľ�����
	//��public��privateֻ�ڼ̳�ʱ������
	
	size func_use_friend(){
		
		class_test1 test1(3, "abd");
		func_friend(test1);
		//class_primer::func_friend(test1);

		size ik = 12;//ʹ�õ��ڲ�������string::size_type
		return sss;
	}

	size sss = "abd";
	typedef string::size_type size;
	//�����ȶ����������ݳ�Ա��������������Ҳ�������������˳��ִ�еģ��ٶԺ�����Ա
	//�ʶ�����ʼ�����ݶ���ʱ��ʹ�õ����ⲿ��size���ͣ�
	//���ں������棬���������ڲ���Ѱ�������ⲿ������ʹ�õ��������string����
	//������������ʹ�����ⲿ����������������涨���������ͣ�����������C++ primer�ǲ��������
	//��õİ취�ǽ��������Ķ��������ǰ�������ܷ�ֹ���ݳ�Աʹ�����ڲ����ض�����ⲿ��������������typedef���з���ǰ��
	
	//�������Ѱ�����ݳ�Ա˳���Ǿͽ�ԭ��
	int temp_test_redef = 456;
	void func_test_redf(int temp_test_redef){
		cout <<"::������ʲô��˼��"<< ::temp_test_redef << endl;
	}
	//����������123����ȫ�ֵ�temp_test_redef������˵û�þ��������������ʹ����ȫ�ֵ���

};

class_primer::class_primer(string a) :str(a){
	cout << "str:" << str << endl;
}

//���������涨����������
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
	int b = 10;//ͬ��һ������˼��ʹ�ô����Ż���=��ʼ�����ڳ�Ա
	mutable int mut;

	const int const_int;
	int & int_yinyong;

public:
	void changeValue(int temp) const {
		mut = temp;//�����Ա�����mutabele��Ա�������κζ����иı���ֵ
	}

	class_init(int ii) :b(ii), const_int(ii), int_yinyong(b){
		cout << "ʹ����ί�й�����" << endl;
	}
	//���ֽ���ʹ�ù��캯����ʼֵ��C++primer���Ƽ�����������Ч�ʵ��϶������
	//����������const�ȱ����ʼ���ı���������Ҳ�ǳ�ʼ����
	//��Ȼû����˵������C++primer�Ƽ���ʹ�ù��캯����ʼֵʱ��˳����������ݳ�Ա����˳��һ��
	//�������ڹ��캯����ʼ����˳�������ݳ�Ա������˳����һ�µģ����ң���ñ����ڹ��캯����ʼֵ��ʹ�����ݳ�Ա��ʼ�����ݳ�Ա

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
//}//���ֺ��������涨��Ϊconst�ĺ�����ֻ���ǳ�Ա����

class class_type_change{
	
public:
	string str;
	class_type_change() = default;
	class_type_change(string st):str(st){}
};
class  class_type_change1{

public:
	void change(class_type_change change){
		cout << "ת����Ȼ�ɹ��ˣ�"<<change.str<<endl;
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
//constexpr int class_constexpr::static_expr = 23333;//����֪����������ʲô.....

//static ��̬���ݳ�Ա�����ǲ���ȫ���͵�
//����ȫ������ֻ�����ˣ�����δ���������


void Primer_test::class_test(){
	string aaa = "abd";
	class_primer cla(aaa);
	cout << "If it is succeed" << endl;


	//void funn(int a, string str);
	class_test1 test1(1,"abc");

	cla.func_friend(test1);
	//��Ԫ������ʹ��ʾ����ʹ����Ԫ��˽�г�Ա��

	cout << "woshi fengexian --------------------" << endl;//����������
	test1.func_use_friend();
	//��һ��ʹ������������Ԫ��������������Ļ�����ȫ�ֵ���Ԫ����
	//ʹ�������Ԫ�������Ǳ���Ҫ�������������

	//test1.size ss;
	class_recons recons;
	char ch = recons.getchar();
	const char chh = recons.getchar();
	//���õ�ȫ��û��const�ĺ�������ֻ����const�����вŻ����const�ĺ�����
	cout << "No const ch:" << ch << "\nconst chh:" << chh << endl;

	recons.func_recons();
	//��Ȼ���������ǵ��õ�û��const�ĺ������㲻��
	//Ȼ���������ˣ�const��������ֻ��ʹ��const����ô��Ϊɶ~~

	//����,ֻ����const������ܵ���const����
	const class_recons recon;
	char ch_ = recon.getchar();
	//recon.func_recons();
	cout << "const_class:" << ch_ << endl;

	//��const����ֻ�ܵ���const������wtf������
	test1.func_test_redf(789);

	//���Ա�ĳ�ʼ��������
	class_init init;//����ֻ��һ���������Ƿ�����ί�й����������ִ�����������֤

	class_type_change1 change1;
	string str = "opopop";
	change1.change(class_type_change("opoopp"));

	change1.change(str);//��������һ���ַ���������Ϊstring���͵Ķ���
	//const char *������ʽת��Ϊstring���ͣ����ǲ���ת���Ρ�����
	class_type_change change = "opoopp";
	//������������ֻ��һ��ʱ��������ʽ�Ľ�����ת��Ϊ�˶��󣡣���
	//������������ԣ�������explicit��ֹ���ֹ���,�������ֲ���ʹ����
	//��ʱֻ����explicit���ڹ�������

	const char* char_const = "aabbcc";
	char char_arr[] = "abc";
	char_const = char_arr;
	//ֻ��ȷ����ʼconst char*��д���Ƿ���ȷ

	//����дchar_arr���鳤��Ϊ4������'\0'
	cout << "sizeof(char_arr:)" << sizeof(char_arr) << endl;
	
	//�����Ծۺ���ʹ�õ�����
	//��˼�����ۺ��������Ҫ�󣬸о���һ����������ݽṹһ����Ȼ����ʵ���þ�ֻ��������





}
	

/*-------------------Container partion--------------------*/

void Primer_test::container(){
	
	vector<int> arr(10,0);
	arr.size();
	arr.push_back(10);
	arr.clear();
	
	

}
