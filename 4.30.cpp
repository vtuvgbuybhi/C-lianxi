#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//以下程序输出的结果是什么
//class A
//{
//public:
//	virtual void func(int val = 1) { cout << "A->" << val << endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { cout << "B->" << val << endl; }
//};
//int main()
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}


//class A
//{
//public:
//	void print()
//	{
//		printf("hello A");
//	}
//};
//
//class B :public A
//{
//public:
//	void print(int )
//	{
//		printf("hello B");
//	}
//};
//
//int main()
//{
//	B bb;
//	bb.A::print(1);
//	return 0;
//}


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch = 'A';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bb;
//	return 0;
//}


//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}



//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//protected:
//	int _age = 1;
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func1(Person& p)
//{
//	p.BuyTicket();
//}
//
//void Func2(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func1(ps);
//	Func1(st);
//
//	Func2(ps);
//	Func2(st);
//	return 0;
//}



//class Person
//{
//public:
//	void BuyTicket() { cout << "买票-全价" << endl; }
//protected:
//	int _age = 1;
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func1(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func1(ps);
//	Func1(st);
//	return 0;
//}



class Person
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
protected:
	int _age = 1;
};
class Student : public Person
{
public:
	//virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func1(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func1(ps);
	Func1(st);
	return 0;
}








