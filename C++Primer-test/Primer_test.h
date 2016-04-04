#pragma once

#include<iostream>
#include<initializer_list>
#include<vector>
#include<string>
#include <array> 
#include<list>
#include<deque>
#include<forward_list>
#include<stack>
#include<queue>
//#include<priority_queue>
#include<algorithm>
#include<numeric>
#include<iomanip>

#include<functional>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::initializer_list;
using std::vector;
using std::string;
using std::array;
using std::iterator;
using std::list;
using std::deque;
using std::forward_list;
using std::stack;
using std::queue;
using std::priority_queue;
using std::setprecision;
using std::bind;

class Primer_test
{
public:
	Primer_test();
	~Primer_test();

	//数据成员
	void parameter();
	//函数
	void function();
	//类
	void class_test();
	//容器
	void container();
	//泛型算法
	void generic_algorithm();//#include<algorithm>


};


