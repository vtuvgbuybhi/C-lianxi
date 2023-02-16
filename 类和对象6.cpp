#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//赋值拷贝函数

//class Data
//{
//public:
//	Data(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//d1=d3
//	//void operator=(const Data& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	Data operator=(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//
//	Data d1(2022, 2, 16);
//	Data d2(2015, 2, 4);
//
//	//一个已经存在的对象拷贝初始化一个马上创建实例化的对象
//	Data d3(d1);
//
//	//两个已经存在的对象，之间的赋值拷贝
//
//	//等于号是运算符   -- 但是内置运算符只能用在内置类型 （这里只能用运算符的重载）
//	d1 = d3;
//	//d1=d3   d1.operator=(d3)
//
//	return 0;
//}




//class Data
//{
//public:
//	Data(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Data(Data& p)
//	{
//		cout << " Data()" << endl;
//	}
//
//	//这样子会有一个问题  函数参数的返回都是拷贝返回（对效率有一定的影响）  --可以通过观察调用拷贝构造函数的来观察
//	Data operator=(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//
//	Data d1(2022, 2, 16);
//	Data d2(2015, 2, 4);
//
//	//拷贝构造
//	Data d3(d1);
//
//	//赋值拷贝构造函数
//
//	//d1=d2  有返回值的是d1
//
//	d1 = d3 = d2;//先将d2赋值给d3，返回d3   ，在将d3赋值给d1 ，返回d1
//
//	return 0;
//}


class Data
{
public:
	Data(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Data(Data& p)
	{
		cout << " Data()" << endl;
	}

	//返回值用引用接受
	Data& operator=(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{

	Data d1(2022, 2, 16);
	Data d2(2015, 2, 4);

	//拷贝构造
	Data d3(d1);

	//赋值拷贝构造函数

	//d1=d2  有返回值的是d1

	d1 = d3 = d2;//先将d2赋值给d3，返回d3   ，在将d3赋值给d1 ，返回d1

	return 0;
}














































