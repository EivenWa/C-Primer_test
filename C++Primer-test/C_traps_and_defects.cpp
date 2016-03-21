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

	//*************进制默认
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


	//*****************unsigned 和signed类型char使用：
	char cc = 0x80;
	printf("%x,%d\n", cc,sizeof(cc)); //输出为0xFFFFFF80，1（存的还是一个字节）
	//作为一个char类型，会默认为signed类型的
	//然后对于signed，会自动扩展的
	//对于下面的赋值，赋的是0xFFFFFF80（signed char最高位不为1，则不改变）
	//若是signed最高位为1，前面全补上1 
	int aa_int = cc;
	printf("%x,%x\n", cc,aa_int);

	cc = cc >> 1;
	aa_int = cc<<1;
	printf("%x,%x", cc, aa_int); //VS signed char右移，符号位不变

}


void C_traps_and_defects::kinds_technique(){
	
	void (*p)(char*);//函数指针定义形式

	int *g();//因为（）的结合优先级高于*，等价于*（g（））
	//即为一个返回值为 int * 的g（）函数
	//对比这个看上面的函数指针申明，就容易了


	//*****************函数指针用法与涉及
	void fun(char *);

	p = fun;
	p("function");//
	(*p)("function");//

	p = &fun;
	char *ch = "fff";
	p(ch);//

	(*p)(ch);//四种方式同等效果

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

//need cstdio
void C_traps_and_defects::IO_problem(){
	
	char buf[BUFSIZ];
	setbuf(stdout, buf);
	//函数功能：使用buf暂时存储要输出的字符，等到后面fflush或者结束前输出
	//日狗，VS默认禁用此函数,使用#pragma warning( disable : 4996)强行允许
	printf("wahahahahahaha");

	char * chp = new char[100];
	setbuf(stdout, chp);

	printf("wahahahhhhhhhhhhhhhhhhhhh");
	std::cout << "wahahahahahahah  wahahahahahaha" ;
	//尽管setbuf是针对C语言的输出，但是也兼容C++的输出
	std::cout << std::endl;//此行代码与fflush功能类似
	printf("wahahahhhhhhhhhhhhhhhhhhh");

	delete[] chp;//若在此处delete，则输出的是一堆不知道什么的东东
	chp = 0;
	fflush(stdout);
	//保证在此函数之前的数据要完好，so最好还是加上这个函数比较安全
	//delete[] chp;//没事
	//chp = 0;
	
}

#define MAX(a,b)\
	auto temp1 = a,temp2 = b;\
	b = temp1>temp2?temp1:temp2;


void C_traps_and_defects::paramaters_define(){

	//不要随便用++i，i++之类的作为宏的参数传递
	//i++传参时传递的是i的值，调用后i才加1

	//在有宏参与的if语句要严格格式，不能偷工减料（大括号之类的东东）

	//类型定义还是要用typedef，不要用define
	float a = 10.2, b = 5.5;
	MAX(++a, b);
	std::cout << b;//11.2
}

void C_traps_and_defects::type_cast(){

	//func_type_函数

	//*****************还可以这样的~~
	"0123456789"[2]; // 就问你6不6


	//****************取余数时结果：
	int re = (-16) % 7;	//输出为-2
	int res = (-16) % (-7);	//输出为-2
	int ress = 16 % -7;	//输出为2
	std::cout << re << res << ress << std::endl;
	//总结：在计算余数时，前面的数的正负决定余数的正负
	//此处 会不会与编译器有关暂待考量


	//****************执行顺序
	//int aa = 10;
	//int cc = ++aa--; //竟然 不能这样写
	//std::cout << cc << std::endl;

	//将判断的值放到右边可以在少写一个=时编译器报错（false == flag）

}
void func_type_(void (*p) ()){
	//(*p)('a');
	//若是 此指针函数没有显示说明带什么类型的参数，则不能随便添加参数

}






