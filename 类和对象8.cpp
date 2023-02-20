#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//初始化列表  - 
//Date(int year, int month, int day)
//	:_year(year)
//	, _month(month)
//	, _day(day)
//{}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_N(10)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;
//};
//
//int main()
//{
//	Date d1(2022, 1, 12);//对象定义  / 对象实例化
//	return 0;
//}


//class A
//{
//public:
//	A(int aa)
//	{
//		cout << "A()" << endl;
//	}
//private:
//	int _aa;
//};


//class Date
//{
//public:
//	//Date(int year, int month, int day, int& i)
//	//	:_N(10)
//	//	, _ref(i)
//	//	,_aa(10)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date(int year, int month, int day, int& i)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _N(10)
//		, _ref(i)
//		, _aa(-1)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _N;
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	int i = 0;
//	Date d1(2022, 1, 12,i);//对象定义  / 对象实例化
//	return 0;
//}



//class A
//{
//public:
//	A(int a)     //  带参
//	{
//		_aa = a;
//	}
//private:
//	int _aa;
//};
//
//
//
//class Date
//{
//public:
//	//Date(int year,int month,int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//初始化列表  -  成员变量定义的地方
	//Date(int year, int month, int day,int& i)
	//	:_year(year)
	//	, _month(month)
	//	, _day(day)
	//	,_N(10)
	//	,_ref(i)
	//	,_aa(-1)
	//{}
//
//private:
//	int _year;   //声明
//	int _month;
//	int _day;
//
//	//以下这些必须在初始化列表中定义
//	const int _N;  //const    常量必须在定义的时候初始化
//	int& _ref;     //引用
//	A _aa;         //没有默认构造函数（无参、全缺省、默认生成的）的自定义类型成员变量
//};
//
//int main()
//{
//	int i = 0;
//	Date d(2022, 1, 12,i);//对象定义  / 对象实例化
//
//	return 0;
//}



//class A
//{
//public:
//	A(int aa=0)
//	{
//		_aa = aa;
//		cout << "A()" << endl;
//	}
//	void operator=(const A& aa)
//	{
//		cout << "operator=()" << endl;
//	}
//private:
//	int _aa;
//};
//class Date
//{
//public:
//	Date(int year, int month, int day, const A& a)
//		:_aa(a)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa;
//};
//
//int main()
//{
//	A aa;
//	Date d1(2021,1,5,aa);
//	return 0;
//}




//1. 每个成员变量在初始化列表中只能出现一次（初始化只能初始化一次）
//2. 类中包含以下成员 ， 必须放在初始列表位置进行初始化
//    引用成员变量
//    const成员变量
//    自定义类型成员（该类没有默认构造函数（无参，全缺省、编译器默认生成））




//成员变量初始化列表中初始化的顺序是按照成员变量声明的顺序，与其在初始化列表中的顺序无关

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)   //  先初始化 ，故_a2为随机值
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;     
//	int _a1;
//
//	// _a2先声明   --> 在初始化列表中先初始化
//
//};
//
//int main()
//{
//	A a(10);
//	a.Print();
//	return 0;
//}




//explicit   -- 关键字


//class Date
//{
//public:
//	Date(int year)
//	{
//		cout << "Date(int year)" << endl;
//		_year = year;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(2021);
//
//	//C++允许的
//	Date d2 = 2022;  //隐式类型转化
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year)
//	{
//		cout << "Date(int year)" << endl;
//		_year = year;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(2021);
//
//	//C++允许的
//	Date d2 = 2022;  //隐式类型转化
//	//本来用2022构造一个临时对象Date(2022),再用这个对象拷贝构造d2
//	//但是C++编译器在连续的一个过程中，多个构造会被优化，合二为一
//	//所以这里被优化为一个构造
//
//
//
//	////隐式类型转化    -- 相近类型   --表示意义相似的类型
//	//double d = 1.1;
//	//int i = d;
//	////d不是直接转给i的    -- 中间产生临时变量
//
//	////中间变量具有常性  const  用i引用d时其实是引用中间变量 ，为了i与中间变量具有相同的常性，所以加const修饰i
//	//const int& i = d;
//
//	//
//	////强制类型转化  - 无关类型
//	//int* p = &i;
//	//int j =(int) p;
//
//
//	return 0;
//}



//class Date
//{
//public:
//
//	//explicit  禁止这种写法  Date d2=2022 发生
//	explicit Date(int year)
//	{
//		cout << "Date(int year)" << endl;
//		_year = year;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	//虽然他们两个都是直接构造，但是过程是不一样的
//	Date d1(2021);
//
//
//	//C++允许的
//	Date d2 = 2022;  //隐式类型转化
//
//	return 0;
//}




//static  -- 关键字

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_sCount;
//		cout << "A()" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++_sCount;
//		cout << "A(const A& aa)" << endl;
//	}
//private:
//	int _a;
//
//	// 静态成员变量属于整个类，所以对象，生命周期在整个程序运行期间
//	static int _sCount;//声明
//};
//
//int A::_sCount = 0;//定义初始化
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	return 0;
//}



//如何访问count

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_sCount;
//		cout << "A()" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++_sCount;
//		cout << "A(const A& aa)" << endl;
//	}
//private:
//	int _a;
//
//public:
//	// 静态成员变量属于整个类，所以对象，生命周期在整个程序运行期间
//	static int _sCount;//声明
//};
//
//int A::_sCount = 0;//定义初始化
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	//类外面访问    ---> public
//	//去整个类里面去找
//	cout << A::_sCount << endl;   
//	cout << a1._sCount << endl;
//	cout << a2._sCount << endl;
//
//	return 0;
//}



//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_sCount;
//		cout << "A()" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++_sCount;
//		cout << "A(const A& aa)" << endl;
//	}
//
//	// 没有this指针，只能访问静态成员变量和静态成员函数
//	static int GetCount()
//	{
//		return _sCount;
//	}
//private:
//	int _a;
//
//	// 静态成员变量属于整个类，所以对象，生命周期在整个程序运行期间
//	static int _sCount;//声明
//};
//
//int A::_sCount = 0;//定义初始化
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	cout << a1.GetCount() << endl;
//	cout << A::GetCount() << endl;
//
//	return 0;
//}




//   static 的用法
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//
//数据范围： 0 <  n≤200
//	进阶： 空间复杂度 O(1)，时间复杂度 O(n)

class Sum
{
	Sum()
	{
		_ret += i;
		i++;
	}
	int Getret()
	{
		return _ret;
	}

private:
	static int i;
	static int _ret;
};

int Sum::i = 1;
int Sum::_ret = 0;

class Solution 
{
public: 
	int Sum_Solution(int n)
	{
		Sum a[n];

		return 
	}
};
























