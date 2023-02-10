#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//
//	return 0;
//}

//以上频繁调用函数 需要频繁建立函数栈帧（有消耗）

//C语言中  用宏来解决  （两个数相加的宏）  宏是一种替换
//#define ADD(x,y) ((x)+(y))
//
//int main()
//{
//	cout << ADD(1, 2) << endl;
//
//	return 0;
//}


//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//int main()
//{
//	Add(1, 2);//直接将Add函数展开在这里（不建立函数栈帧）
//
//	return 0;
//}

//内联函数: 适合短的函数(10行以内) ，不适合递归函数(减少控制C语言宏的使用)



//基础语法复习

//输入 输出

//int main()
//{
//	//IO流
//	int i = 0;
//	double d = 1.11;
//
//	//   >>  流体取运算符
//	//   <<  流插入运算符
//
//	//自动识别数据类型
//	cin >> i;
//	cin >> d;
//
//	cout << i <<" "<< d << endl;
//
//	return 0;
//}



//using namespace std  //C++的库函数都是存在一个名问std的命名空间中 
//using  将std的命名空间函数全部展开  方便我们使用


//展开部分常用的  --> 全部展开（易产生命名污染的问题）
//using std::cin  //是意思是只将std中的cin函数展开，剩下的函数不展开
//using std::cout  



//缺省参数 (默认参数)

//全缺省

//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func();//直接用默认的
//	Func(1, 2, 3);//用我们传的
//	return 0;
//}

//半缺省

//半缺省参数必须依次从右往左依次给，不能间隔给
//缺省参数不能在函数声明和定义中同时出现
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func(2);//直接用默认的
//	Func(1, 2, 3);//用我们传的
//	return 0;
//}



//函数重载  (函数名相同 ，参数不同 （可以是参数类型、参数个数、或者顺序不同）)


//引用

//int main()
//{
//	int a = 10;
//	
//	int& b = a;//引用
//	int* p = &b;//取地址
//
//	return 0;
//}

//引用的底层原理

//int main()
//{
//	int a = 10;
//
//	int& b = a;
//
//	cout << sizeof(b) << endl;
//
//	int* p = &a;
//
//	cout << sizeof(p) << endl;
//
//	//反汇编来看
//	//int& b = a;
//	//00007FF77A131994  lea         rax, [a]    lea（取地址）  取a的地址放在rax的寄存器上
//	//	00007FF77A131998  mov         qword ptr[b], rax    move移动     将rax上的值（a的地址）移动到b变量名空间中
//	//	int* p = &a;
//	//00007FF77A13199C  lea         rax, [a]
//	//	00007FF77A1319A0  mov         qword ptr[p], rax
//
//	//语法层  : 指针和引用是完全不同的概念
//	//指针是开空间，存储变量的地址
//	//引用不开空间，仅仅是对变量取别名
//
//	//底层汇编实现时: 引用是用指针实现的
//
//	return 0;
//}



//auto 关键字

int main()
{
	int a = 1;
	
	//auto 自动推导变量的类型

	auto c = a;
	auto d = 'A';
	auto e = 10.11;

	//typeid 打印变量的类型
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;

	return 0;
}
























