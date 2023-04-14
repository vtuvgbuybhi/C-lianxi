#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<array>
using namespace std;



//#define N 100


//这是类型模板参数   
//template<class T>
//class array
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	array<int> a1;
//	array<double> a2;
//
//	//可是  a1  a2  都是只能存100个数据
//	//但这时候我想  a1存10个数据     a2存1000个数据了呢
//
//	return 0;
//}




//非类型模板参数     --  常量

//template<class T,size_t N=100>
//class array
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	array<int> a0;
//	array<int,10> a1;
//	array<double,1000> a2;
//
//	return 0;
//}




//int main()
//{
//	array<int, 10> a1; //c++11
//	int a2[10];      //C
//
//	//越界都能检查出来    --  函数调用
//	a1[10] = 5;
//	a1[15];  
//
//	//指针解引用   --  检查是否越界，只针对越界写，越界读不检查
//	a2[10];
//	a2[10] = 1;
//	a2[15] = 2;
//
//	return 0;
//}




//模板特化   --  模板的特殊化


//函数模板特化

	//struct Date
	//{
	//	Date(int year, int month, int day)
	//		:_year(year)
	//		, _month(month)
	//		, _day(day)
	//	{}

	//	int _year;
	//	int _month;
	//	int _day;
	//};

	//template<class T>
	//bool Greater(T left, T right)
	//{
	//	return left > right;
	//}


	//特殊化处理    --  针对某些类型   --  特化
	//template<>
	//bool Greater<Date*>(Date* left, Date* right)
	//{
	//	return *left > *right;
	//}


//int main()
//{
//	cout << Greater(1, 2) << endl;   //可以比较正确结果  ---》 传整形，用整形进行实例化，用整形的实例化进行比较
//
//	Date d1(2022, 7, 8);
//	Date d2(2022, 7, 9);
//	cout << Greater(d1, d2) << endl;  //可以比较正确结果    --》 实例化成日期类，调用日期类里的比较
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Greater(p1, p2) << endl;    //可以比较，结果错误
//
//
//	return 0;
//}




//类模板特化

//	struct Date
//	{
//		Date(int year, int month, int day)
//			:_year(year)
//			, _month(month)
//			, _day(day)
//		{}
//
//		int _year;
//		int _month;
//		int _day;
//	};
//
//
//
//namespace cdc
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& x1, const T& x2)const
//		{
//			return x1 < x2;
//		}
//	};
//
//	//类模板特化
//	template<>
//	struct less<Date*>
//	{
//		bool operator()(Date*& x1,Date*& x2)const
//		{
//			return *x1 < *x2;
//		}
//	};
//
//}
//
//int main()
//{
//	Date d1(2022, 7, 8);
//	Date d2(2022, 7, 9);
//
//	cdc::less<Date> lessFunc1;
//	cout << lessFunc1(d1, d2) << endl;
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cdc::less<Date*> lessFunc2;
//	cout << lessFunc2(p1, p2) << endl;
//
//	return 0;
//}




//template<class T1,class T2>
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//private:
//	T1 d1;
//	T2 d2;
//};
//
////全特化
//template<>
//class Date<int , char>
//{
//public:
//	Date()
//	{
//		cout << "Date<int , char>" << endl;
//	}
//private:
//	int _d1;
//	int _d2;
//};
//
//
//
////偏特化
//template<class T1>
//class Date<T1, int>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1,int>" << endl;
//	}
//private:
//
//};
//
//
////这个也是特化     -----   这个是指定范围，无论什么指针类型都匹配这个版本（要求是两个都要是指针）
//template<class T1,class T2>
//class Date<T1*, T2*>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1*,T2*>" < endl;
//	}
//private:
//
//};
//
//
//template<class T1, class T2>
//class Date<T1&, T2&>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1&,T2&>" < endl;
//	}
//private:
//
//};









