#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Date
//{
//public:
//	Date(int year=0,int month=1,int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	const Date d1;
//
//	d.Print();  
//
//	d1.Print();
//
//	return 0;
//}



//void Print()   
////���ص�thisָ��   Date* const this
////   const ����thisָ�򲻱�
//
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//d.Print()   //  Date* d            ----> Ȩ�޲���
//d1.Print()   // const Date* d1      ----> Ȩ�ޱ�С  ��d1���ݲ���  ������thisָ��ʹ��thisָ������ݿɱ䣩
//
//
//
//
//void Print() const
////const Date* const this
////��һ��const����thisָ������ݲ���
////�ڶ���const����thisָ�򲻱�
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//
//d.Print()   //Date* d      --->Ȩ����С
//d1.Print()  // const Date*d  --->Ȩ�޲���


//�ܽ�: ��Ա������const�Ǻõģ������ܼ�const�����ϣ�������ͨ�����const���󶼿��Ե���
//�������Ҫ�޸ĳ�Ա�����ĳ�Ա�����ǲ��ܼӵ�   ������������  ++  +=  �ȵ�ʵ��


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	const Date d1;
//
//	d.Print();  
//	d1.Print();
//
//
//	return 0;
//}




//��Ԫ����


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void operator<<(ostream& out)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
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
//	Date d1;
//
//	//�����������
//	cout << d1;
//
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void operator<<(ostream& out)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
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
//	Date d1;
//
//	//�����������
//	//cout << d1;           //����÷�����
//	d1.operator<<(cout);  //����÷�����
//
//
//
//	//��������������棬���˫�������Ĳ���������
//	//��һ�����������ص�thisָ�룩���������  �� �ڶ����������Ҳ�����
//
//	d1 << cout;  //�����ӿ��������������������������õ�ϰ�ߣ�̫��Ť�ˣ�
//
//	return 0;
//}


//����˵����  ���������سɳ�Ա����������


//�����Ǹ�ȫ�ֵģ����������棬��û��ʲôthisָ��ʲô��Ӱ����

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////�����Ӿ����������治�ܷ���˽�еĳ�Ա������
//void operator<<(ostream& out, const Date& d)
//{
//	out <<d._year << "-" << d._month << "-" << d._day << endl;
//}
//
//int main()
//{
//	Date d1;
//	operator<<(cout, d1);
//	return 0;
//}






//������Ԫ����


//class Date
//{
//	//��Ԫ����
//	friend void operator<<(ostream& out, const Date& d)
//	{
//		out << d._year << "-" << d._month << "-" << d._day << endl;
//	}
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1;
//
//	cout << d1;//�����ӾͿ�����
// 	cout << d1 << d2;   //����Ҫ����������Ͳ�������
//
//	return 0;
//}




//class Date
//{
//	//��Ԫ����
//	friend ostream& operator<<(ostream& out, const Date& d)
//	{
//		out << d._year << "-" << d._month << "-" << d._day << endl;
//		return out;
//	}
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	cout << d1 << d2;  
//
//	//cou<<d1  �����귵��out
//	//out<<d2  �����ӾͿ������������
//
//	return 0;
//}





//����ȡ������


//class Date
//{
//	//��Ԫ����
//	friend istream& operator>>(istream& in, Date& d)
//	{
//		in >> d._year >> d._month >> d._day;
//		return in;
//	}
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	//d1.Print();
//	//cin >> d1;
//	//d1.Print();
//
//	//d1.Print();
//	//d2.Print();
//	//cin >> d1>>d2;
//	//d1.Print();
//	//d2.Print();
//	
//	return 0;
//}













