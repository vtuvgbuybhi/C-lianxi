#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//��ֵ��������

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
//	//һ���Ѿ����ڵĶ��󿽱���ʼ��һ�����ϴ���ʵ�����Ķ���
//	Data d3(d1);
//
//	//�����Ѿ����ڵĶ���֮��ĸ�ֵ����
//
//	//���ں��������   -- �������������ֻ�������������� ������ֻ��������������أ�
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
//	//�����ӻ���һ������  ���������ķ��ض��ǿ������أ���Ч����һ����Ӱ�죩  --����ͨ���۲���ÿ������캯�������۲�
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
//	//��������
//	Data d3(d1);
//
//	//��ֵ�������캯��
//
//	//d1=d2  �з���ֵ����d1
//
//	d1 = d3 = d2;//�Ƚ�d2��ֵ��d3������d3   ���ڽ�d3��ֵ��d1 ������d1
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

	//����ֵ�����ý���
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

	//��������
	Data d3(d1);

	//��ֵ�������캯��

	//d1=d2  �з���ֵ����d1

	d1 = d3 = d2;//�Ƚ�d2��ֵ��d3������d3   ���ڽ�d3��ֵ��d1 ������d1

	return 0;
}














































