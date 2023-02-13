#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class stu
{

};

int main()
{
	cout << sizeof(stu) << endl;

	return 0;
}





//类的6个默认成员函数

//空类（没有任何的成员变量）但并不是什么都没有--> 任何一个类在我们不写的情况下都会自动生成6个默认的成员函数
//这个默认的成员函数是特殊的成员函数（特殊的点非常非常多，我们不实现，编译器自动生成一份）

//初始化和清理   ---  > 相当于 Init函数  和 Destroy 函数

//构造函数  - 初始化
//构造函数是特殊的成员函数，并不是开空间创建对象，而是初始化对象

//构造函数特征
//1.函数名与类名相同
//2.无返回值
//3.对象实例化时编译器自动调用对应的构造函数
//4.构造函数可以重载

//class Data
//{
//public:
//	//Data()
//	//{
//	//	_year = 0;
//	//	_month = 12;
//	//	_day = 5;
//	//}
//	//Data(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//全缺省
//	Data(int year=2022, int month = 2, int day = 5)
//	{
//		_year = year;
//	    _month = month;
//	    _day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//创建类对象时就是实例化  --> 自动调用对应的构造函数
//	Data D3;
//
//	Data D2(2023, 1, 9);
//
//	return 0;
//}


//当我们没有自定义构造函数时 ， C++编译器会默认生成构造函数
//我们来验证---C++默认生成的构造函数

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_aa = 0;
//	}
//private:
//	int _aa;
//};
//
//
//class Data  //没有自定义构造函数
//{
//public:
//private:
//
//	//C++里面把类型分成两类  : 内置类型（基本类型） 、 自定义类型
//	// 内置类型  : int /char/double/指针/内置类型数组  等等
//	// 自定义数据类型  struct / class 定义的类型
//
//	//我们不写构造函数 ，编译器默认生成构造函数，但对内置类型不做处理
//	//对于自定义类型成员变量会去调用他的默认构造函数初始化，如果没有默认构造函数就会报错
//
//	//任何一个类的默认构造函数就是 - 不用参数就可以调用的（全缺省  、 无参 、我们不写编译器默认生成）
//
//
//	//以下三个都是内置类型 ，生成的默认构造函数不做处理
//	int _year;
//	int _month;
//	int _day;
//
//	A aa;  //自定义类型，默认构造函数需要将他做另外的处理  - 让它去调用他自己默认的构造函数
// };
//
//
//int main()
//{
//	Data D1;
//
//	return 0;
//}









//析构函数  : 与构造函数功能相反，析构函数不是完成对象的销毁 ， 局部对象的销毁工作是由编译器完成的，
//而对象在销毁时会自动调用析构函数，完成对象的一些资源清理工作


//析构函数是特殊的成员函数

//特性 :
//1.析构函数名是在类名前加上字符   ~
//2.无参数无返回值
//3.一个类只有析构函数，若显示未定义，相同会自动生成默认的析构函数
//4.对象声明周期结束是，C++编译系统自动调用析构函数
//
//class Data
//{
//public:
//
//	Data(int year=2022, int month = 2, int day = 5)
//	{
//		_year = year;
//	    _month = month;
//	    _day = day;
//	}
//	~Data()
//	{
//		//Data类没有资源需要清理  -- 所有Data不实现析构函数都是可以的
//		cout << "~Data()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data D1(2023, 1, 9);
//
//	return 0;
//}




//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//};
//
//int main()
//{
//	//自动调用构造函数
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}




//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//如果我们不写析构函数，编译器会自动默认生成析构函数  和  构造函数类似
//	//对于内置成员类型不做处理
//	//对于自定义类型会去调用它的析构函数
//
//
//	//析构函数
//	//~Stack()
//	//{
//	//	free(_a);
//	//	_a = nullptr;
//	//	_top = _capacity = 0;
//	//}
//
//};
//
//int main()
//{
//	//自动调用构造函数
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}




//那么编译器默认生成的析构函数就没有用了嘛   -->   其实是有很大作用的  （如在用两个栈实现队列）

//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//};
//
//class MyQueue {
//public:
//	MyQueue() {
//
//	}
//
//	void push(int x) {
//
//	}
//
//	int pop() {
//
//	}
//
//	int peek() {
//
//	}
//
//	bool empty() {
//
//	}
//
//private:
//	Stack Push1;
//	Stack Pop;
//};
//
//
//
//int main()
//{
//	//自动调用构造函数
//	Stack s1;
//	Stack s2(20);
//
//	//我们没有在MyQueue定义构造函数和析构函数
//	//我们可以直接使用默认的析构函数和默认的构造函数对Push1和Pop进行清理和初始化
//
//	MyQueue q1;
//
//	return 0;
//}















