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

}
void C_traps_and_defects::kinds_technique(){
	
	void (*p)(char*);//����ָ�붨����ʽ

	int *g();//��Ϊ�����Ľ�����ȼ�����*���ȼ���*��g������
	//��Ϊһ������ֵΪ int * ��g��������
	//�Ա����������ĺ���ָ����������������


	//*****************����ָ���÷����漰
	void fun(char *);

	p = fun;
	p("function");
	(*p)("function");

	p = &fun;
	char *ch = "fff";
	p(ch);

	(*p)(ch);//����Ŀ��ͬ

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
