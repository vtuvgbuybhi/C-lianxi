#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//class A
//{
//public:
//	int _a;
//};
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public C, public B
//{
//public:
//	int _d;
//};
//
//
//void func(B* ptr)
//{
//	cout << ptr->_a << endl;
//}
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B b = d;
//	B* pb = &d;
//
//	C c = d;
//	C* pc = &d;
//
//	B bb;
//	cout << sizeof(bb) << endl;
//	bb._a = 1;
//	bb._b = 2;
//
//	func(&d);
//	func(&bb);
//
//
//	return 0;
//}


//class C
//{
//	//...
//};
//
//class D
//{
//protected:
//	C _c;
//	//...
//};
//
//
//int main()
//{
//	
//	return 0;
//}


//virtual void BuyTicket()
//{
//	cout << "ÂòÆ±-°ë¼Û" << endl;
//}

//class Person
//{
//public:
//	virtual void BuyTicket(){cout << "ÂòÆ±-È«¼Û" << endl;}
//};
//
//class Student : public Person
//{
//public:
//	//Ðéº¯ÊýµÄÖØÐ´£¨¸²¸Ç£©
//	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
//};
//
//class solder : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "ÓÅÏÈÂòÆ±" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	solder sd;
//	Func(ps);
//	Func(st);
//	Func(sd);
//	return 0;
//}


//class Person
//{
//public:
//	virtual Person* BuyTicket() 
//	{ 
//		cout << "ÂòÆ±-È«¼Û" << endl; 
//		return this;
//	}
//};
//
//class Student : public Person
//{
//public:
//	//Ðéº¯ÊýµÄÖØÐ´£¨¸²¸Ç£©
//	virtual Student* BuyTicket() 
//	{ 
//		cout << "ÂòÆ±-°ë¼Û" << endl; 
//		return this;
//	}
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}



class A
{};
class B : public A
{};
class Person
{
public:
	virtual A* BuyTicket()
	{
		cout << "ÂòÆ±-È«¼Û" << endl;
		return nullptr;
	}
};
class Student : public Person
{
public:
	//Ðéº¯ÊýµÄÖØÐ´£¨¸²¸Ç£©
	virtual B* BuyTicket()
	{
		cout << "ÂòÆ±-°ë¼Û" << endl;
		return nullptr;
	}
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}






























