#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//��ʼ���б�  - 
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
//	Date d1(2022, 1, 12);//������  / ����ʵ����
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
//	Date d1(2022, 1, 12,i);//������  / ����ʵ����
//	return 0;
//}



//class A
//{
//public:
//	A(int a)     //  ����
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
//	//��ʼ���б�  -  ��Ա��������ĵط�
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
//	int _year;   //����
//	int _month;
//	int _day;
//
//	//������Щ�����ڳ�ʼ���б��ж���
//	const int _N;  //const    ���������ڶ����ʱ���ʼ��
//	int& _ref;     //����
//	A _aa;         //û��Ĭ�Ϲ��캯�����޲Ρ�ȫȱʡ��Ĭ�����ɵģ����Զ������ͳ�Ա����
//};
//
//int main()
//{
//	int i = 0;
//	Date d(2022, 1, 12,i);//������  / ����ʵ����
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




//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ�Σ���ʼ��ֻ�ܳ�ʼ��һ�Σ�
//2. ���а������³�Ա �� ������ڳ�ʼ�б�λ�ý��г�ʼ��
//    ���ó�Ա����
//    const��Ա����
//    �Զ������ͳ�Ա������û��Ĭ�Ϲ��캯�����޲Σ�ȫȱʡ��������Ĭ�����ɣ���




//��Ա������ʼ���б��г�ʼ����˳���ǰ��ճ�Ա����������˳�������ڳ�ʼ���б��е�˳���޹�

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)   //  �ȳ�ʼ�� ����_a2Ϊ���ֵ
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;     
//	int _a1;
//
//	// _a2������   --> �ڳ�ʼ���б����ȳ�ʼ��
//
//};
//
//int main()
//{
//	A a(10);
//	a.Print();
//	return 0;
//}




//explicit   -- �ؼ���


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
//	//C++�����
//	Date d2 = 2022;  //��ʽ����ת��
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
//	//C++�����
//	Date d2 = 2022;  //��ʽ����ת��
//	//������2022����һ����ʱ����Date(2022),����������󿽱�����d2
//	//����C++��������������һ�������У��������ᱻ�Ż����϶�Ϊһ
//	//�������ﱻ�Ż�Ϊһ������
//
//
//
//	////��ʽ����ת��    -- �������   --��ʾ�������Ƶ�����
//	//double d = 1.1;
//	//int i = d;
//	////d����ֱ��ת��i��    -- �м������ʱ����
//
//	////�м�������г���  const  ��i����dʱ��ʵ�������м���� ��Ϊ��i���м����������ͬ�ĳ��ԣ����Լ�const����i
//	//const int& i = d;
//
//	//
//	////ǿ������ת��  - �޹�����
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
//	//explicit  ��ֹ����д��  Date d2=2022 ����
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
//	//��Ȼ������������ֱ�ӹ��죬���ǹ����ǲ�һ����
//	Date d1(2021);
//
//
//	//C++�����
//	Date d2 = 2022;  //��ʽ����ת��
//
//	return 0;
//}




//static  -- �ؼ���

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
//	// ��̬��Ա�������������࣬���Զ��������������������������ڼ�
//	static int _sCount;//����
//};
//
//int A::_sCount = 0;//�����ʼ��
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	return 0;
//}



//��η���count

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
//	// ��̬��Ա�������������࣬���Զ��������������������������ڼ�
//	static int _sCount;//����
//};
//
//int A::_sCount = 0;//�����ʼ��
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	//���������    ---> public
//	//ȥ����������ȥ��
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
//	// û��thisָ�룬ֻ�ܷ��ʾ�̬��Ա�����;�̬��Ա����
//	static int GetCount()
//	{
//		return _sCount;
//	}
//private:
//	int _a;
//
//	// ��̬��Ա�������������࣬���Զ��������������������������ڼ�
//	static int _sCount;//����
//};
//
//int A::_sCount = 0;//�����ʼ��
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




//   static ���÷�
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
//
//���ݷ�Χ�� 0 <  n��200
//	���ף� �ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)

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
























