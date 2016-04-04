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

//������ָ����к������þ���һ���ص��Ĺ���

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
	//typedef string size;
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

inline void class_primer::func_friend(class_test1 test1){
	//���������涨����������
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
		//һ���ת��������ʽ���У����Խ�һ��string����������ʾ��string���͵ģ���ʽת��Ϊ��class_type_change
		//���class_test()������
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
//int class_constexpr::static_expr = 23333;//����֪����������ʲô.....
////������������ѧϰ

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

	//eraseɾ����һ�㷵��ָ��ɾ�������һ��Ԫ�غ���ĵ�����
	//һ��vector��string��dequeɾ�������˵�Ԫ�أ���Ӱ�����������ָ�룬���õ�
	//(vector��βɾ��deque����λɾ��string��βɾ(vector��stringɾ��Ԫ�ػᵼ�������ġ�����))
	//forwar_list����������ʣ��Ƚ�����
	//һ�����������vector������м�Ҫ�������֮��ĵĲ��㣩�����ݽṹ�Ͳ�Ҫ����ʹ�ñ������
	//���Ԫ������emplace����emplace�������ЧһЩ


	//----------vector---------
	vector<int> arr(10,10);
	arr.size();
	//arr.push_back(10);
	//arr.clear();
	//��ִ�к󣬻����vector arr

	vector<int >arr_vector(12, 1);
	vector<int>::iterator arr_vec_begin = arr_vector.begin();
	arr_vector = arr;//�˲�������arr_vector������arrͬ
	//��һ���������жԵ��������ٸ�ֵ����debug failed,��ָ��������Ѿ���ɾ��
	//cout << "arr_vector[11]:"<<arr_vector[11] << endl;//����ֹ����Ϊ����ֻ��10��

	arr_vec_begin = arr_vector.begin();
	cout << "vector����ֵ����iteratorָ��ָ���ֵ��" << *arr_vec_begin << endl;
		

	vector<int>::iterator arr_begin = arr.begin();//��ʱָ�����ֵΪ10
	vector<int> arr1_vector(16, 16);
	swap(arr, arr1_vector);//���ϸ�ֵ���򣬽����󳤶�Ҳ�ύ���������˷������Ч
	//��ʱarr����Ϊ16��arr1_vector��arr_vector����Ϊ10

	cout << "swap���ָ��ָ���ֵΪ��" << *arr_begin << endl;
	//swap������ǰȡ��ָ�뻹��ָ��ԭ�������ݣ���ԭ���ݲ�û���ƶ���������������ָ������ݽṹ�ǽ�����Ľṹ
	//���ǣ�����array�ṹ��swap�������������ǵ�Ԫ�أ�ָ�루�����ã�ָ��ԭ�������ݽṹ������Ԫ��ֵ����

	vector<int>::iterator begin = arr1_vector.begin();
	auto end = arr1_vector.end();
	arr.assign(begin,end);
	cout <<"arr��ʱ�ĳ��ȣ�"<<arr.size()<< endl;//�����10,��assign�������ǰ���У�Ȼ�������������
	//assign�൱�ڳ�ʼ���Ĺ��̣������ó�ʼ�������з�ʽ�磺arr.assign(10,2);arr.assign(arr1_vector);

	arr.insert(arr.begin(),1,2);
	//arr.insert(arr.begin(),begin,end);
	//arr.insert(arr.begin(),2333);
	
	//�����ǰ��
	cout << "����arr[0]��" << arr[0] << endl;

	arr.emplace(arr.begin(),21);//�о����ܲ�̫����
	cout << "emplace��arr[0]:" << arr[0] << "\n emplace��arr[1]:" << arr[1] << endl;

	cout << "arr emplace��ĳ��ȣ�" << arr.size() << endl;
	//���ϣ�insert��emplace��ʱû������ʲô����Ч����û������
	//Ӧ��˵�ǣ�insert����һЩ���ܣ��������Ӷ������

	arr.insert(arr.begin(),233);
	cout << "��insert��arr[0]:" << arr[0] << endl;
	//arr.emplace(arr.begin(), arr1_vector.begin(),arr1_vector.end());
	//cout << "��emplace��arr[0]:" << arr[0] << endl;

	arr.emplace_back(13);
	//ʹ�ô˷�����ֱ��������������ڴ�ռ��д������󣬶����Ǵ���һ���ֲ���ʱ����ѹ��������
	//��������ʹ�ô˷���Ҫ��ЧһЩ

	//-----arr_vector����10��10,���м�insert�Ե�������Ӱ��
	auto arr_vector_end = arr_vector.end();
	auto arr_vector_begin = arr_vector.begin();
	auto arr_vector_mid = --arr_vector_end;
	//��ʱ�鿴ָ����Ϣ��begin��end��40�����ϣ�����˵����˳���ǰ��յ�ַ����ķ�������ڴ�
	//��ַΪ0x0060b38��0x0060b60
	cout << "*arr_vector_begin:" << *arr_vector_begin << endl;
	arr_vector.insert(arr_vector_begin,3);
	//ִ������ַ��Ϊ��0x0060b38��0x0060b60��Ҳ����˵���ַ��û�б䣬������ֵ�仯��
	//���յ�ַ������beginָ��Ļ�����ǰ����Ԫ�أ�
	//���ǣ�end���ܽ����ã�������ʵ�İ���ַ����vector�ĵ�11��Ԫ��(ԭ��δ֪�����������ڲ��������δ֪����)
	cout << "*arr_vector_begin:" << *arr_vector_begin << endl;
	if (arr_vector_end != arr_vector.end())
		cout << "*arr_vector_mid:" << *arr_vector_mid << endl;//�����������end���ܽ������Ƿ������ڶ����ʱ��ʱend���Բ�����


	//----------array---------//�̶���������
	//�̶�����array��ʹ��Ҫ��
	//include<array>
	//using std::array
	array<int, 8> arr_array = {42};//�Ὣ��0����ֵΪ42������0
	//array<int, 8>::size_type size;
	//ȡsize_typeʱ����ʹ�������Ķ�������array<int,42>����������
	//array��Ĭ�ϳ�ʼ��,��֪���ǲ������Ĭ���ˣ�������ֵ���Բ���0��ȫ��һ���ܴ�ĸ���
	for (int i = 0; i < 8;i++)
		cout << "arr_array[i]:"<<arr_array[i] << endl;//

	array<int, 8> arr1_array = arr_array;
	//�����������ƣ����Ǳ������һ�£������ͺͳ���һ�£�

	//arr_array = { 12, 11, 1 };//array��֧�ִ��ָ�ֵ��ʽ��ֻ�г�ʼ��ʱ����

	//array<int, 9> arr2_array;
	//swap(arr_array, arr2_array);//���ַ���ֻ��ʹ����������һ����array����
	swap(arr_array,arr1_array);
	arr_array.swap(arr1_array);//�˷���û����һ�и�Ч���Ͽ�ö࣬vectorͬ

	//----------list---------//˫������
	//#include<list>
	//using std::list;
	list<int> ilist;
	ilist.push_front(11);
	ilist.push_front(12);
	ilist.insert(ilist.begin(),13);
	for (auto it : ilist)
		cout << "it:"<<it << endl;

	//----------deque---------//˫�˶���
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

	//----------forward_list---------//������
	//#include<forward_list>
	//using std::forward_list

	//ʹ��һ��primer��ɾ��������������Ԫ�ص�����
	forward_list<int> flist = {1,2,3,4,5,6,7,8,9};
	auto prev = flist.before_begin();
	auto curr = flist.begin();
	//while (curr != flist.end())
	//{
	//	if (*curr % 2)
	//		flist.erase_after(prev);
	//	curr++;//�������������Ϊ���潫currָ��Ľڵ�ɾ���ˣ�Ȼ��Ϊʲô���ܵݼӣ��ǲ�����Ϊ++������ʹ��->next������ԭ��
	//	//����ࣺ���������ǵ�����ָ�룬++����Ϊ���صĲ����������⣬����Ҳ�漰���˱�ĺ�������
	//	prev++;
	//}
	//std::_Flist_iterator <std::_Flist_val<std::_Flist_simple_types<int> > >::~_Flist_iterator<std::_Flist_val<std::_Flist_simple_types<int> > >(0254537h)

	while (curr != flist.end())
		if (*curr % 2)//ɾ������
			curr = flist.erase_after(prev);
			//�˴����curr����ɾ�����һ��Ԫ�صĵ�����
		else{
			prev = curr;
			curr++;
		}
	
	for (auto temp_flist : flist)
		cout <<"flist_value:" <<temp_flist << endl;

	curr = flist.begin();
	flist.resize(2);
	cout << "after resize curr:" << *curr << endl;
	//resize��СӦ��ֻ�Ǻ�ɾ�����ƣ���Ӱ��ɾ����ĵ�����֮���


	//----------������---------//ǿ���Ǹ�ջ��ǿ���Ǹ����У�ǿ���Ǹ����ȼ�����233333
	//���ƽӿڵ�ת��
	//#include<stack>
	//using std::stack;
	deque<int> deq(10, 2);
	stack<int> std(deq);//ǿ��������������Ǹ�ջ���Ƚ������
	cout << "std.top():" << std.top() << endl;

	stack<string, vector<string>> str_stack;//�����ܶ����������ʲô��˼	
	str_stack.push(string ("wahaha"));//��
	//vector<string> vec_str(3, "aaa");
	//str_stack.push(vec_str);
	//str_stack.pop();//��
	cout <<"str_stack.top():"<<str_stack.top() << endl;//Ψһȡջ��ֵ�ķ���
	
	//#include<queue>
	//using std::queue
	queue<int> que(deque<int> (1,2));
	que.push(12);
	cout <<"que.front():"<<que.front() << endl;//ȡǰͷ������ �൱��top()
	cout<<"que.back():"<<que.back() << endl;//ȡβ����
	que.emplace(23333);//Ҳ����ӵ�β�ϣ��Ƚ��ȳ���

	
	//���ȼ����� priority_queueֻ��������queue��������ȼ������ȼ��ߵ���pop����
	//.pop()����queue����Ԫ�ػ������ȼ���ߵ�Ԫ�أ����ǲ�ɾ������topͬ
	//
	//
	//using std::priority_queue	
	priority_queue<int> que_ority;
	que_ority.push(123);
	que_ority.pop();//Primer P330���½�˵�õĲ�ɾ����ƭ�˵ģ������ϺͶ��в�ֻ࣬���и����ȼ�����



}

void Primer_test::generic_algorithm(){
	//#include<algorithm>
	//#include<iomanip> //����ָ��С������������λ
	cout << setprecision(10);//ָ��Ĭ��С����Ϊ10λ

	float float_test = (float)8.999999;//floatֻ��6λ�ľ���

	vector<float> vec_float = { 1, 2, 3, 4, 5, 6, 7, 8, (float)8.9999991 };//��ǿת�Ļ����Ὣ��������Ĭ�Ͽ�Ϊdouble�����ܸ�ֵ����ߣ�g++4.8 ����
	auto result = find(vec_float.begin(), vec_float.end(), (float)8.999999);//��ǿת�Ļ�����Ĭ��ת��Ϊdouble��Ȼ����Ҳ���9.1
	if (result!= vec_float.end())
		cout << "result:" << *result << endl;//�ҵ��ˣ������������8.999999046���ھ��ȷ�Χ����Ⱦ�������ȣ��������+Ҳ����д���ģ�


	//#include<numeric>
	vector<double> vec_double = { 1, 2, 3, 4, 5, 6, 7, 8, (double)8.9999991 };
	
	//-----------accumulate����
	double sum = accumulate(vec_double.cbegin(), vec_double.cend(), 0);//VS�������ᾯ�棺��Ϊ��doubleǿתΪint���ˣ���Ϊ0.0�򲻻�
	cout << "sum:"<<sum << endl;//�����44��8.9999991��ǿתΪintֵΪ8������ɵ���������0ȷ����һ��int��

	double sum_double = accumulate(vec_double.cbegin(), vec_double.cend(), 0.0);
	cout << "sum_double:" << sum_double << endl;//44.9999991

	vector<double>::const_iterator vec_double_it = vec_double.cend();
	//constʱ����ʹ��const_iterator
	//const����Ծ���ֵ�ģ����ܸı������ָ���ֵ�����ǿ��Ըı������
	cout << "*--vec_double_it:" << *--vec_double_it << endl;

	//---------------equal����
	bool if_vec_equal = equal(vec_float.cbegin(), vec_float.cend(),vec_double.cbegin());
	if (!if_vec_equal)
		cout << "���Ͳ�ƥ���Ԫ�رȽ�,Ȼ���������\n�������Ὣ����ֵת��Ϊdouble�͵ģ�����float�ڴ�ֵ�����ж�ʧ��һЩ���ȣ�" << endl;


	vector<string> vec_str = {"111","222","333"};
	vector<string> vec_str1 = {"aaa","bbb","ccc"};
	//sum_double = accumulate(vec_str.cbegin(),vec_str.cend(),0.0);//����ͨ����

	bool if_equal = equal(vec_str.cbegin(), vec_str.cend(),vec_str1.cbegin());//Ĭ�ϵڶ������г����������һ�����г������
	if (!if_equal)
	{
		cout << "�����ַ��������~~" << endl;
	}

	//----------------fill������Ҫע�⣺�㷨�в��������������в�������ı���������������
	//fill(vec_str.begin(),vec_str.end(),"aaa");��ϵ��ֻ����һ��ֵȥ��ֵ��������"aaa"��
	fill_n(vec_str.begin(),vec_str.size(),"aaa");//���в���ʹ��cbegin(),��ͷ��size��"aaa"
	string str = accumulate(vec_str.cbegin(), vec_str.cend(), string(""));
	cout << "str:" << str << endl;
	
	//��������ײ����������ʹ�ã��ܱ�֤�������㹻�Ŀռ����������ݣ����Ǹı����������������᲻���뷺�͵������г�ͻ��
	fill_n(back_inserter(vec_str), 10, "vvv");

	//---------------back_inserter����
	auto ret = copy(vec_str.cbegin(),vec_str.cend(),back_inserter(vec_str1));//�����������������Ŀ�ģ�ǰ������ʾ��Χ
	*ret = "abc";//ret������������ĵ����������йأ�����back_inserter(vec_str1),
				//����Ӻ�����һ����Ԫ�صط������ǿ���ֱ�Ӹ�ֵ(�ɲ��������)
				//������ret���ܶ�ȡ��ֻ�ܸ�ֵ
	//*ret = "bbb";//������ӡ��˷�������ֱ���������Ԫ�أ�ÿ�θ�ֵret��������

	string str1 = accumulate(vec_str1.cbegin(), vec_str1.cend(), string(""));
	cout << "tstr1:" << str1<< endl;//����������abc��

	//--------------replace����
	replace(vec_str.begin(),vec_str.end(),"vvv","ddd");//��������Ϊvvv��Ԫ�ظ�Ϊddd

	//--------------replace_copy����
	replace_copy(vec_str.cbegin(), vec_str.cend(),vec_str1.begin(),"ddd","str");
	//��vec_str�е�Ԫ�ظ���һ�ݣ������������е�ddd�滻Ϊstr���浽vec_str1�У�vec_str����

	//--------------sort���� ����,֮ǰvec_str��aaa��10��ddd,����ֻ���������,ʹ��Ԫ�ص� < ��������
	sort(vec_str.begin(), vec_str.end());

	fill_n(back_inserter(vec_str), 2, "111");
	fill_n(back_inserter(vec_str), 2, "333");


	//---------------unique���� �������뷶Χ��ʹ��ÿ������ֻ����һ�Σ��������һ�����ظ����ʵĺ�һ����λ�ã��п�����end������
	vector<string>::iterator vec_str_era = unique(vec_str.begin(),vec_str.end());
	//if (vec_str_era != vec_str.cend())//primer��˵������ָ��end()��ɾ���յ�Ԫ��Ҳ��û����ģ�����
		vec_str.erase(vec_str_era,vec_str.end());//��Ҫ������Ȼ��������������ظ��ģ���Ҫ�ֶ�ɾ��

	str = accumulate(vec_str.cbegin(), vec_str.cend(), string(""));
	cout << "����ɾ�غ��str��" << str << endl;

	//---------------find_if
	bool if_find_if(int a);//ò��ֻ�������ӣ����ܻ�������͵Ĳ��� ���£�find_if �����_Find_if����
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
	cout <<"*temp_find_if:"<< *temp_find_if << endl;//ָ��ν�ʷ���true�ĵ�һ��Ԫ�ص�δ֪�ĵ�����

	//---------------lambda���ʽ//�����ţ������б���������ز����٣���Ŀ���ʡ��
	auto f = [](int a, int b) ->int{return a + b; };
	cout << "f(1,2):" << f(1, 2) << endl;

	//��find_if
	int in = 6;
	temp_find_if = find_if(vec_int.cbegin(), vec_int.cend(), [in](int a){return a > in; });
	cout <<"*temp_find_if:"<< *temp_find_if << endl;//���7

	for_each(temp_find_if, vec_int.cend(), [](int a){cout << a << endl; });
	/*
		void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	// perform function for each element
		for (; _First != _Last; ++_First)
			_Func(*_First);//�����ﴫ��ȥ��
	}
	*///for_each

	//---------------stable_sort
	vector<string> vec_words = {"abc","abb","abd","a","b"};
	//�����ַ����������򣬴Ӷ̵���
	stable_sort(vec_words.begin(), vec_words.end(), [](const string &a, const string &b){return a.size() > b.size(); });

	//-----------------��̸lambda
	//Ĭ������£�Lambda��������һ��const������mutable����ȡ���䳣����

	size_t v1 = 42;
	auto f_v1 = [v1](){return v1; };
	//�ڴ˴���ֵ�Ŀ�����������ڴ˴����

	//�������ֵ�仯���������ã�����Ҫ���ڵ���lambda��ʱ�����õı����Ǵ��ڵģ���
	auto f_v = [&v1](){return v1; };
	v1 = 0;
	cout << "f_v1():" << f_v1() << endl;//���Ϊ42����
	cout << "f_v():" << f_v() << endl;//���Ϊ0
	
	//auto f_v2 = [v1](){v1 = 3; };//����const�������ܸı������ֵ
	//��lambda��const�ģ����ܸı��ⲿ��ֵ
	auto f_v3 = [v1]()mutable{ v1 = 3; };//�ı��Ҳ�Ǻ����ڲ���һ����v1��ֵ������������
	f_v3();
	cout << "f_v3();v1:" << v1 << endl;//0

	auto f_v4 = [&v1](){v1 = 5; };//5,������const�ģ�����ȷȷʵ�ı���ȫ�ֵı���ֵ��
	f_v4();
	cout << "f_v4();v1:" << v1 << endl;
	
	
	//------------------bind������Ϊ��ʹ�ú�����Ϊν����ƣ���Ϊν���в������������ƣ�
	//------------------Ҳ�������Ĳ���˳��
	//#include<functional>
	//using std::bind;

	auto re_if_find_if = bind(if_find_if,6);
	//���ܣ���6��Ϊif_find_if������

	if (re_if_find_if())//����if_find_if(6)
		cout << "���óɹ���,�ǵ���6" << endl;

	int test_bind(int a, int b,int c);
	auto re_test_bind = bind(test_bind, std::placeholders::_2, 6, std::placeholders::_1);
	//��Щ_1��ָ��Ӧ��re_test_bind������˳����_2�������_1
	//test_bind������n��������bind����������n+1(+1Ϊ������)������������˳��һһ��Ӧ
	//������using namespace std::placeholders;ֱ��ʹ��_1ʲô��

	cout << "re_test_bind():" << re_test_bind(12,13) << endl;
	//����test_bind(13,6,12)ͬ��test_bind�ĵ�һ��������Ӧre_test_bind�����ĵڶ�������




}
bool if_find_if(int a){
	return a > 5;
}

int test_bind(int a,int b,int c){
	cout << "a:" << a << "\tb:" << b<<"\tc:"<<c << endl;
	return a + b;
}


