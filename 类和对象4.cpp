#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//�������캯��     ---  ����ĳ�Ա����
//����  : 
//1.�������캯���ǹ��캯����������ʽ
//2.�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ�ʹ�ô�ֵ�ķ�ʽ����������ĵݹ����



//class Data
//{
//public:
//	//���캯��
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//�������캯��
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
//	//���캯��
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//�������캯��
//  ���ÿ������죬��Ҫ�ȴ����� ����ֵ��������һ���������죨��˼����˵D1����d����D1�����ݴ���d����������˿������죬D1���������d��
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
//	//���캯��
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//�������캯��
//
//	//���þͲ����ڽ�D1���������d�����  --  d��D1�ı���
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


//�Զ������ͣ�class �� struct����ͬһ�����ͳ�ʼ���ң���D1��ʼ��d�������ǿ������죨��C++�У�


//class Data
//{
//public:
//	//���캯��
//	Data(int year = 2021, int month = 5, int day = 5)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//�������캯��
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
//		//d._year = _year;//������ͻᱻ������  --��const
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


//��δ��ʾ���壬ϵͳ������Ĭ�Ͽ������캯��

//Ĭ�����ɿ������캯��  : �������ͳ�Ա , ����ɰ��ֽ���Ŀ���(ǳ����)
// �Զ������ͳ�Ա��������Ŀ�������


//class Data
//{
//public:
//	//���캯��
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
//	//��������  -- Ĭ�����ɵĿ������캯��
//	Data D2(D1);
//	return 0;
//}



//class Data
//{
//public:
//	//���캯��
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
//	//��������  -- Ĭ�����ɵ�
//	Data D2(D1);
//
//	//D1��������D2  ����Ĭ�ϵĿ������캯��������������Զ���Ŀ�������  
//	//�ѵ����ɵ�Ĭ�Ͽ������캯�����㹻����
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
//	//��������
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
//	//�Զ����ù��캯��
//
//	Stack s1(5);
//
//	//�������췢�ֳ��������   -- ǳ����  (s1��s2�������Զ����Ա���� _a ָ����ͬһ���ڴ�  ��������������ڴ��ͷ������Σ�һ���ڴ�ռ�ֻ���ͷ�һ��)
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

	//��������
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
};

int main()
{
	//�Զ����ù��캯��
	Stack s1(5);
	Stack s2(s1);

	return 0;
}















//�ܽ�  : �����������ǲ�д���ɵ�Ĭ�Ͽ������캯�������������ͺ��Զ������Ͷ��´���������Ǵ����
//ϸ���ǲ�һ���ģ����������������ǲ�һ����









































