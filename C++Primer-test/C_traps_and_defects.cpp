#include "C_traps_and_defects.h"
int global ;
//global = 0;
C_traps_and_defects::C_traps_and_defects()
{


}

C_traps_and_defects::~C_traps_and_defects()
{
}

void C_traps_and_defects::blank_space(){

	int a = 2;
	int *c = &a;
	int b =*c/* a; //*/; 
	//�����У�/* ��һ����ֱ����Ϊע�ͣ������ҵݹ���ϣ������ƥ��Ϊ����
	b = b/ *c;

	*c = b++ + a;
	int d = b+ ++a;
	std::cout << a<<b<<*c<<d<< std::endl;// 4 2 4 6
	int e = a++ + ++b;//�����ֱ��Ͽ�

	a = 1;
	b = 1;
	
	d = a+++b;//��ͬ�� a++ +b
	std::cout << a << b << d << std::endl;//2 1 2
}


void C_traps_and_defects::default_data(){

	//*************����Ĭ��
	int a = 010; //��0��ͷ�����ݶ��ǻ���Ϊ��8���Ƶ�
	std::cout << a << std::endl;//���Ϊ8

	std::cout << sizeof(a) << std::endl; //���Ϊ4(�˼����ΪX64)



	//******************�������ȼ���ע���
	// ��=  ������&��| bit������
	bool aa = true, b = false;
	if (aa&b != 0){} //�������( a & (b != 0))


	//****************���������ڵ�ֵȷ��
	int c = 1, d = 2, f = 3;
	f = d = c;

	std::cout << c << d << f << std::endl;
	//���Ϊ1 1 1��VS��������������һ��ֵ


	//*****************unsigned ��signed����charʹ�ã�
	char cc = 0x80;
	printf("%x,%d\n", cc,sizeof(cc)); //���Ϊ0xFFFFFF80��1����Ļ���һ���ֽڣ�
	//��Ϊһ��char���ͣ���Ĭ��Ϊsigned���͵�
	//Ȼ�����signed�����Զ���չ��
	//��������ĸ�ֵ��������0xFFFFFF80��signed char���λ��Ϊ1���򲻸ı䣩
	//����signed���λΪ1��ǰ��ȫ����1 
	int aa_int = cc;
	printf("%x,%x\n", cc,aa_int);

	cc = cc >> 1;
	aa_int = cc<<1;
	printf("%x,%x", cc, aa_int); //VS signed char���ƣ�����λ����

}


void C_traps_and_defects::kinds_technique(){
	
	void (*p)(char*);//����ָ�붨����ʽ

	int *g();//��Ϊ�����Ľ�����ȼ�����*���ȼ���*��g������
	//��Ϊһ������ֵΪ int * ��g��������
	//�Ա����������ĺ���ָ����������������


	//*****************����ָ���÷����漰
	void fun(char *);

	p = fun;
	p("function");//
	(*p)("function");//

	p = &fun;
	char *ch = "fff";
	p(ch);//

	(*p)(ch);//���ַ�ʽͬ��Ч��

	//typedef void(*(funcptr))();
	//(*(funcptr)0)(); //�о���û���������ã�˵���׾���һ��ǿת���ѣ�ִ��ʱ��

	(*(void(*)())0);

	//(*(void(*)())0)();//ִ��ʱ��
	//ǰһ���������ǽ�0ǿתΪһ������ֵΪvoid���͵ĺ���ָ���ֵ��*p��,��������һ��
	
	
	// **********����ֵΪ����ָ��ĺ�������
	void (*pp) (char*);
	void ( *signal(int, void(*)(int*)) ) (char*);	
	//��Ϊ����������������Ϊsignal����������ֵΪ void(*)(char*) �ĺ���ָ��
	//signal����������������һ��int�ͣ�һ��void(*)(int *)�ĺ���ָ��

	
}
void fun(char* ch){
	std::cout << ch << std::endl;
}

//need cstdio
void C_traps_and_defects::IO_problem(){
	
	char buf[BUFSIZ];
	setbuf(stdout, buf);
	//�������ܣ�ʹ��buf��ʱ�洢Ҫ������ַ����ȵ�����fflush���߽���ǰ���
	//�չ���VSĬ�Ͻ��ô˺���,ʹ��#pragma warning( disable : 4996)ǿ������
	printf("wahahahahahaha");

	char * chp = new char[100];
	setbuf(stdout, chp);

	printf("wahahahhhhhhhhhhhhhhhhhhh");
	std::cout << "wahahahahahahah  wahahahahahaha" ;
	//����setbuf�����C���Ե����������Ҳ����C++�����
	std::cout << std::endl;//���д�����fflush��������
	printf("wahahahhhhhhhhhhhhhhhhhhh");

	delete[] chp;//���ڴ˴�delete�����������һ�Ѳ�֪��ʲô�Ķ���
	chp = 0;
	fflush(stdout);
	//��֤�ڴ˺���֮ǰ������Ҫ��ã�so��û��Ǽ�����������Ƚϰ�ȫ
	//delete[] chp;//û��
	//chp = 0;
	
}

#define MAX(a,b)\
	auto temp1 = a,temp2 = b;\
	b = temp1>temp2?temp1:temp2;


void C_traps_and_defects::paramaters_define(){

	//��Ҫ�����++i��i++֮�����Ϊ��Ĳ�������
	//i++����ʱ���ݵ���i��ֵ�����ú�i�ż�1

	//���к�����if���Ҫ�ϸ��ʽ������͵�����ϣ�������֮��Ķ�����

	//���Ͷ��廹��Ҫ��typedef����Ҫ��define
	float a = 10.2, b = 5.5;
	MAX(++a, b);
	std::cout << b;//11.2
}

void C_traps_and_defects::type_cast(){

	//func_type_����

	//*****************������������~~
	"0123456789"[2]; // ������6��6


	//****************ȡ����ʱ�����
	int re = (-16) % 7;	//���Ϊ-2
	int res = (-16) % (-7);	//���Ϊ-2
	int ress = 16 % -7;	//���Ϊ2
	std::cout << re << res << ress << std::endl;
	//�ܽ᣺�ڼ�������ʱ��ǰ�������������������������
	//�˴� �᲻����������й��ݴ�����


	//****************ִ��˳��
	//int aa = 10;
	//int cc = ++aa--; //��Ȼ ��������д
	//std::cout << cc << std::endl;

	//���жϵ�ֵ�ŵ��ұ߿�������дһ��=ʱ����������false == flag��

}
void func_type_(void (*p) ()){
	//(*p)('a');
	//���� ��ָ�뺯��û����ʾ˵����ʲô���͵Ĳ��������������Ӳ���

}






