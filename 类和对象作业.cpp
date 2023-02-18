#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//设置已经有 A B C D 四个类的定义  ，程序中A B C D 析构函数调用顺序为 ?

//class C
//{
//public:
//	C()
//	{
//		cout << "C()" << endl;
//	}
//
//	~C()
//	{
//		cout <<"~C()" << endl;
//	}
//};
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//class D
//{
//public:
//	D()
//	{
//		cout << "D()" << endl;
//	}
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};
//
//C c;
//
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return 0;
//}


//构造顺序 :   c是全局变量，在mian函数之前就一定会先构造
//局部变量，局部静态变量 :  谁先定义谁先构造
//  C A B D


//先定义后析构
//析构顺序   :  出了main作用域，先把这个函数里面的局部变量清理掉
//静态局部变量会在main函数整个完了之后才会销毁
// B A D C 




//以下代码共调用多少次拷贝构造函数

//class Widget
//{
//public:
//	Widget()
//	{
//		//cout << "Widget()" << endl;
//	}
//	Widget(const Widget&)
//	{
//		cout << "Widget(const Widget&)" << endl;
//	}
//};
//
//
//Widget f(Widget u)
//{
//	return u;
//}
//
//int main()
//{
//	Widget x;
//	Widget y = f(x);
//	return 0;
//}

//上面程序 一共调用了3次拷贝构造函数
//  在x在u传参时调用了一次拷贝构造函数  ，   在返回值  u 传给y时  这里调用了2次
      //             ----------
      // u   -----> | 中间变量 | ------  > y
	//		一次	-----------   一次

//不过编译器在这里进行了优化     u传给y时 ，省区了中间变量  ，合二为一（将u直接传给y）

//一次调用里面，连续的拷贝构造函数，会被编译器优化，合二为一

//也就是说上面的程序总共调用了2次拷贝构造函数



//这样子就 优化不了了

class Widget
{
public:
	Widget()
	{
		//cout << "Widget()" << endl;
	}
	Widget(const Widget&)
	{
		cout << "Widget(const Widget&)" << endl;
	}
	Widget& operator=(const Widget&)
	{
		cout << "Widget& operator=(const Widget&)" << endl;
		return *this;
	}

};


Widget f(Widget u)
{
	return u;
}

int main()
{
	Widget x;
	Widget y;
	y = f(x);
	return 0;
}

















































