#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<array>
using namespace std;



//#define N 100


//��������ģ�����   
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
//	//����  a1  a2  ����ֻ�ܴ�100������
//	//����ʱ������  a1��10������     a2��1000����������
//
//	return 0;
//}




//������ģ�����     --  ����

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
//	//Խ�綼�ܼ�����    --  ��������
//	a1[10] = 5;
//	a1[15];  
//
//	//ָ�������   --  ����Ƿ�Խ�磬ֻ���Խ��д��Խ��������
//	a2[10];
//	a2[10] = 1;
//	a2[15] = 2;
//
//	return 0;
//}




//ģ���ػ�   --  ģ������⻯


//����ģ���ػ�

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


	//���⻯����    --  ���ĳЩ����   --  �ػ�
	//template<>
	//bool Greater<Date*>(Date* left, Date* right)
	//{
	//	return *left > *right;
	//}


//int main()
//{
//	cout << Greater(1, 2) << endl;   //���ԱȽ���ȷ���  ---�� �����Σ������ν���ʵ�����������ε�ʵ�������бȽ�
//
//	Date d1(2022, 7, 8);
//	Date d2(2022, 7, 9);
//	cout << Greater(d1, d2) << endl;  //���ԱȽ���ȷ���    --�� ʵ�����������࣬������������ıȽ�
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Greater(p1, p2) << endl;    //���ԱȽϣ��������
//
//
//	return 0;
//}




//��ģ���ػ�

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
//	//��ģ���ػ�
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
////ȫ�ػ�
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
////ƫ�ػ�
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
////���Ҳ���ػ�     -----   �����ָ����Χ������ʲôָ�����Ͷ�ƥ������汾��Ҫ����������Ҫ��ָ�룩
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









