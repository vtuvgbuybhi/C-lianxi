#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Data
//{
//public:
//	Data(int year=0, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//D1.operator>(D2);
//	bool operator>(const Data& d1, const Data& d2)
//	{
//		if (d1._year > d2._year)
//		{
//			return true;
//		}
//		else if (d1._year == d2._year && d1._month > d2._month)
//		{
//			return true;
//		}
//		else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
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
//	Data D1(2022, 1, 16);
//	Data D2(2022, 1, 18);
//
//	D1.operator>(D2);
//
//	return 0;
//}





//运算符重载

//运算符重载是具有特殊函数名的函数
//函数名字为  : 关键字operator后面接需要重载的运算符符号
//函数原型 : 返回值类型operator操作符（参数列表）

//class Data
//{
//public:
//	Data(int year=0, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};

//函数名  operator操作符
//返回类型 看操作符运算后返回值是什么
//参数 ，操作符有几个操作数，他就有几个参数
//bool operator>(const Data& d1, const Data& d2)
//{
//	if (d1._year > d2._year)
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month > d2._month)
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//int main()
//{
//	Data D1(2022, 1, 16);
//	Data D2(2022, 1, 18);
//
//	//默认情况C++是不支持自定义类型对象使用运算符
//
//	//比较日期的大小
//
//	//这是编译器的约定，这么调用函数
//	cout << (D1 > D2) << endl;//<<流插入运算符 的优先级大于 > 要加括号
//
//	//  D1>D2的原理是  编译器对D1>D2处理了  转换成operate>(D1,D2)
//
//	cout << operator>(D1, D2) << endl;
//
//
//	//两日期相减
//	//int day1 = D1 - D2;
//
//	return 0;
//}


//注意:
//不能通过连接其它符号来创建新的操作符: 比如   operate@
//重载运算符必须有一个类类型参数
//对于内置类型运算符，其含义不能改变
// ( .* ) 、 ( :: ) 、( ?: )、 （ . ） 、 ( sizeof ) 这五个运算符不能重载






//class Data
//{
//public:
//	Data(int year=0, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//访问限定符   --- 不能在类外面使用对象直接访问私有成员变量
//	//在类外面不能访问私有
//	//在类里面不受访问限定符的性质
//
//	bool operator>(const Data& d1, const Data& d2)
//	{
//		if (d1._year > d2._year)
//		{
//			return true;
//		}
//		else if (d1._year == d2._year && d1._month > d2._month)
//		{
//			return true;
//		}
//		else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
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
//	bool operator>(const Data& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
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
//	d1 > d2;
//	d1.operator>(d2);
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
//	//访问限定符   --- 不能在类外面使用对象直接访问私有成员变量
//	//在类外面不能访问私有
//	//在类里面不受访问限定符的限制
//
//
//	//d1.operator(d2)             bool operator(const Data* this  ,  const Data& d1)
//	bool operator>(const Data& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
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
//	d1 > d2;
//
//	d1.operator>(d2);
//
//	return 0;
//}



//class stu
//{
//public:
//	stu(int year = 0, int month = 1, int day = 1)
//	{
//		_yea = year;
//		_mont = month;
//		_da = day;
//	}
//private:
//	int _yea;
//	int _mont;
//	int _da;
//};
//
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
//	//访问限定符   --- 不能在类外面使用对象直接访问私有成员变量
//	//在类外面不能访问私有
//	//在类里面不受访问限定符的限制
//
//
//	//d1.operator(d2)             bool operator(const Data* this  ,  const Data& d1)
//	bool operator>(const stu& d)
//	{
//		if (_year > d._yea)
//		{
//			return true;
//		}
//		else if (_year == d._yea && _month > d._mont)
//		{
//			return true;
//		}
//		else if (_year == d._yea && _month == d._mont && _day > d._da)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
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
//	stu d2(2015, 2, 4);
//
//	d1 > d2;
//
//	d1.operator>(d2);
//
//	return 0;
//}


































