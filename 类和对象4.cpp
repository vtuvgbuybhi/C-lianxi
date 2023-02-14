#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//拷贝构造函数     ---  特殊的成员函数
//特征  : 
//1.拷贝构造函数是构造函数的重载形式
//2.拷贝构造函数的参数只有一个且必须使用引用传参，使用传值的方式会引发无穷的递归调用



//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//	Data(const Data& d)
//	{
//		d._year=_year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data D1;
//	Data D2(D1);
//	return 0;
//}





//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//  调用拷贝构造，需要先传参数 ，传值传参又是一个拷贝构造（意思就是说D1传给d，将D1的内容传给d，这里调用了拷贝构造，D1拷贝构造给d）
//	Data(Data d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data D1;
//
//	Data D2(D1);
//
//	return 0;
//}


//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//
//	//引用就不存在将D1拷贝构造给d的情况  --  d是D1的别名
//	Data(Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data D1;
//
//	Data D2(D1);
//
//	return 0;
//}


//自定义类型（class 、 struct）用同一个类型初始化我（用D1初始化d），就是拷贝构造（在C++中）


//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//	//Data(Data& d)
//	//{
//	//	//year=d._year;
//	//	d._year = _year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//
//	Data(const Data& d)
//	{
//		//year=d._year;
//		//d._year = _year;//误操作就会被检查出来  --加const
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data D1;
//
//	Data D2(D1);
//	return 0;
//}


//若未显示定义，系统会生成默认拷贝构造函数

//默认生成拷贝构造函数  : 内置类型成员 , 会完成按字节序的拷贝(浅拷贝)
// 自定义类型成员会调用它的拷贝构造


//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data D1;
//
//	//拷贝复制  -- 默认生成的拷贝构造函数
//	Data D2(D1);
//	return 0;
//}



//class Data
//{
//public:
//	//构造函数
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data D1;
//
//	//拷贝复制  -- 默认生成的
//	Data D2(D1);
//
//	//D1拷贝给了D2  生成默认的拷贝构造函数就完成了我们自定义的拷贝函数  
//	//难道生成的默认拷贝构造函数就足够了嘛
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
//};
//
//int main()
//{
//	//自动调用构造函数
//
//	Stack s1(5);
//
//	//拷贝构造发现程序崩溃了   -- 浅拷贝  (s1和s2对象内自定义成员变量 _a 指向了同一块内存  析构函数对这块内存释放了两次，一块内存空间只能释放一次)
//	Stack s2(s1);
//
//	return 0;
//}




class Stack
{
private:
	int* _a;
	size_t _top;
	size_t _capacity;
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail" << endl;
			exit(-1);
		}
		_capacity = capacity;
		_top = 0;
	}

	//析构函数
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
};

int main()
{
	//自动调用构造函数
	Stack s1(5);
	Stack s2(s1);

	return 0;
}















//总结  : 拷贝构造我们不写生成的默认拷贝构造函数对于内置类型和自定义类型都会拷贝处理，但是处理的
//细节是不一样的，这个跟构造和析构是不一样的









































