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
	//此例中，/* 在一起则直接视为注释，从左到右递归辨认，以最长最匹配为优先
	b = b/ *c;

	*c = b++ + a;
	int d = b+ ++a;
	std::cout << a<<b<<*c<<d<< std::endl;// 4 2 4 6
	int e = a++ + ++b;//仅此种被认可

	a = 1;
	b = 1;
	
	d = a+++b;//等同于 a++ +b
	std::cout << a << b << d << std::endl;//2 1 2
}

void C_traps_and_defects::default_data(){

	int a = 010; //以0开头的数据都是会认为是8进制的
	std::cout << a << std::endl;//输出为8

	std::cout << sizeof(a) << std::endl; //输出为4(此计算机为X64)

	
	//******************关于优先级的注意点
	// ！=  优先于&，| bit操作符
	bool aa = true, b = false;
	if (aa&b != 0){} //结果会是( a & (b != 0))

	//****************关于连等于的值确定
	int c = 1, d = 2, f = 3;
	f = d = c;

	std::cout << c << d << f << std::endl;
	//输出为1 1 1，VS编译器是用最后的一个值

}
void C_traps_and_defects::kinds_technique(){
	
	void (*p)(char*);//函数指针定义形式

	int *g();//因为（）的结合优先级高于*，等价于*（g（））
	//即为一个返回值为 int * 的g（）函数
	//对比这个看上面的函数指针申明，就容易了


	//*****************函数指针用法与涉及
	void fun(char *);

	p = fun;
	p("function");
	(*p)("function");

	p = &fun;
	char *ch = "fff";
	p(ch);

	(*p)(ch);//三种目的同

	//typedef void(*(funcptr))();
	//(*(funcptr)0)(); //感觉并没有申明卵用，说到底就是一个强转而已，执行时崩

	(*(void(*)())0);

	//(*(void(*)())0)();//执行时崩
	//前一个括号内是将0强转为一个返回值为void类型的函数指针的值（*p）,但是意义一样
	
	
	// **********返回值为函数指针的函数申明
	void (*pp) (char*);
	void ( *signal(int, void(*)(int*)) ) (char*);	
	//此为函数声明，函数名为signal，函数返回值为 void(*)(char*) 的函数指针
	//signal函数参数有两个，一个int型，一个void(*)(int *)的函数指针

	


}
void fun(char* ch){
	std::cout << ch << std::endl;
}
