#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class Stack
{
public:
	int* _a;
	int _Top;
	int _capacity;
public:
	void Init();
	void StackPush(int x);
};


//int main()
//{
//	//为什么类里存了成员变量，却没有存成员函数呢
//	Stack s1;
//	
//	cout << sizeof(Stack) << endl;
//	cout << sizeof(s1) << endl;
//
//
//	//为什么类里存了成员变量，却没有存成员函数呢
//	Stack s2;
//
//	//不同对象的成员变量都是独立的
//	s1._Top = 0;
//	s2._Top = -1;
//
//
//	//不同对象调用的是同一个成员函数（为了减少空间消耗 会将这些成员函数地址放在一个公共区域，不放在类里面）
//	s1.Init();
//	s2.Init();
//
//	return 0;
//}


//结构体大小计算  ---结构体内存对齐

//第一个成员在与结构体变量偏移量为0的地址处
//其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处

//对齐数  : 编译器默认的对齐数（vs默认是8）与该成员大小的较小值


//struct S1
//{
//	char c1;  //c1的大小是一个字节   并且是第一个成员放在结构体变量偏移量为0的地址处
//	int a;    //a的大小是4个字节 对齐数是4     放在对齐数（4）的整数倍
//	char c2;  //c2的大小是1个字节  对齐数是1   放在对齐数（1）的整数倍
//};
//
//
////结构体的总大小为最大对齐数的整数倍(4)     目前我们算的大小是9个字节   不是4的倍数   再浪费3个字节总大小12个字节
//
//
//
////内存
//    ----------
//    |        |
//    ----------  0    存放c1
//    |        |
//	  ----------  1
//	  |        |
//	  ----------  2
//	  |        |
//	  ----------  3
//	  |        |
//	  ----------  4    存放a
//	  |        |
//	  ----------  5
//    |        |
//	  ----------  6
//    |        |
//	  ----------  7
//	  |        |
//	  ----------  8  存放c2
//	  |        |
//	  ----------  9
//	  |        |
//	  ----------  10
//	  |        |
//	  ----------  11
//	  |        |
//	  ----------  12

//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//int main()
//{
//	//struct S1 s1 = { 0 };
//	//cout << sizeof(s1) << endl;
//
//	struct S2 s2 = { 0 };
//	cout << sizeof(s2) << endl;
//
//	return 0;
//}


//嵌套了结构体的情况

//嵌套结构体的情况，嵌套的结构体的对齐到自己的最大对齐数的整数倍处，结构体的整齐大小就是所有最大对齐数的整数倍

//struct S1
//{
//	char c1;   
//	char c2;
//	int a;
//};
//
////S1的大小是8个字节
//
//struct S2
//{
//	char c1;   
//	struct S1 s1;   //最大对齐数是4个字节   大小是8
//	int c2;
//};
//
//
//int main()
//{
//	struct S2 s2;
//	cout << sizeof(s2) << endl;
//
//	return 0;
//}




//我们先定义一个结构体

//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	struct S1 s1;
//	int a;
//};
//
//int main()
//{
//	struct S2 s2;
//	cout << sizeof(s2) << endl;
//	return 0;
//}



//日期类


//this 指针的用法

//class Data
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << " - " << _month << " - " << _day << endl;
//	}
//};
//
//int main()
//{
//	Data D1;
//	D1.Init(2023, 4, 2);
//	D1.Print();
//
//	Data D2;
//	D2.Init(2023, 5, 2);
//	D2.Print();
//
//	
//	//函数成员不存在对象里，而是存在类外的公共区域上
//	//D1和D2同时调用Print，编译器怎么知道是要打印 D1对象还是D2对象呢
//
//	//隐藏指针  this 
//	//void Print（Data* this）
//	
//	//D1.Print(&D1)
//	
//	//cout <<     _year     <<       _month      <<     _day
//	//        this->_year        this ->_month       this -> _day
//
//	//1.调用成员函数时，不能显示传实参给this
//	//2.定义成员函数时，也不能显示声明形参this
//	//3.在成员函数内部，我们可以显示使用this
//
//	return 0;
//}



//this 指针的经典问题


//为什么不会编译报错，并且运行正常
//class A
//{
//public:
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A*p = nullptr;
//	p->Show();
//	return 0;
//}
//
////为什么不会编译报错，但是却运行崩溃
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//		//此时this是空指针
//		//this->_a
//		//程序崩溃
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}


//分析  : 1.p虽然是空指针，但是p调用成员函数不会编译报错，因为空指针是不是语法错误，编译器检查不出来

//2.p虽然是空指针，但是p在调用成员函数时不会出现空指针访问，因为成员函数没有存在对象里面
//3.这里p会作为实参传递给this指针（所有为什么程序崩溃的原因）



















