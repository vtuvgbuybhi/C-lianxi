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





//���������

//����������Ǿ������⺯�����ĺ���
//��������Ϊ  : �ؼ���operator�������Ҫ���ص����������
//����ԭ�� : ����ֵ����operator�������������б�

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

//������  operator������
//�������� ������������󷵻�ֵ��ʲô
//���� ���������м����������������м�������
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
//	//Ĭ�����C++�ǲ�֧���Զ������Ͷ���ʹ�������
//
//	//�Ƚ����ڵĴ�С
//
//	//���Ǳ�������Լ������ô���ú���
//	cout << (D1 > D2) << endl;//<<����������� �����ȼ����� > Ҫ������
//
//	//  D1>D2��ԭ����  ��������D1>D2������  ת����operate>(D1,D2)
//
//	cout << operator>(D1, D2) << endl;
//
//
//	//���������
//	//int day1 = D1 - D2;
//
//	return 0;
//}


//ע��:
//����ͨ���������������������µĲ�����: ����   operate@
//���������������һ�������Ͳ���
//��������������������京�岻�ܸı�
// ( .* ) �� ( :: ) ��( ?: )�� �� . �� �� ( sizeof ) ������������������






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
//	//�����޶���   --- ������������ʹ�ö���ֱ�ӷ���˽�г�Ա����
//	//�������治�ܷ���˽��
//	//�������治�ܷ����޶���������
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
//	//�����޶���   --- ������������ʹ�ö���ֱ�ӷ���˽�г�Ա����
//	//�������治�ܷ���˽��
//	//�������治�ܷ����޶���������
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
//	//�����޶���   --- ������������ʹ�ö���ֱ�ӷ���˽�г�Ա����
//	//�������治�ܷ���˽��
//	//�������治�ܷ����޶���������
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


































