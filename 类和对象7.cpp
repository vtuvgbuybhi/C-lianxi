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
////隐藏的this指针   Date* const this
////   const 修饰this指向不变
//
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//d.Print()   //  Date* d            ----> 权限不变
//d1.Print()   // const Date* d1      ----> 权限变小  （d1内容不变  ，传给this指针使得this指向的内容可变）
//
//
//
//
//void Print() const
////const Date* const this
////第一个const修饰this指向的内容不变
////第二个const修饰this指向不变
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//
//d.Print()   //Date* d      --->权限缩小
//d1.Print()  // const Date*d  --->权限不变


//总结: 成员函数加const是好的，建议能加const都加上，这样普通对象和const对象都可以调用
//但是如果要修改成员变量的成员函数是不能加的   比如日期类中  ++  +=  等等实现


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




//有元函数


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
//	//流插入的重载
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
//	//流插入的重载
//	//cout << d1;           //这个用法不行
//	d1.operator<<(cout);  //这个用法可以
//
//
//
//	//运算符的重载里面，如果双操作数的操作符重载
//	//第一个参数（隐藏的this指针）是左操作数  ， 第二个参数是右操作数
//
//	d1 << cout;  //这样子可以跑起来，不过不符合我们用的习惯（太别扭了）
//
//	return 0;
//}


//上面说明了  流插入重载成成员函数不合适


//那我们搞全局的，不在类外面，就没有什么this指针什么的影响了

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
////这样子就面临类外面不能访问私有的成员变量了
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






//引入有元函数


//class Date
//{
//	//有元函数
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
//	cout << d1;//这样子就可以了
// 	cout << d1 << d2;   //可想要连续的输出就不可以了
//
//	return 0;
//}




//class Date
//{
//	//有元函数
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
//	//cou<<d1  调用完返回out
//	//out<<d2  这样子就可以连续输出了
//
//	return 0;
//}





//流提取的重载


//class Date
//{
//	//有元函数
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













