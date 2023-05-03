#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Person
//{
//public:
//	virtual ~Person(){cout << "~Person()" << endl;}
//};
//class Student : public Person
//{
//public:
//	~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* ptr1 = new Student;
//	delete ptr1;
//	Person* ptr2 = new Person;
//	delete ptr2;
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-ÊæÊÊ" << endl; }
//};
//int main()
//{
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive()  {}
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive() override { cout << "Benz-ÊæÊÊ" << endl; }
//};
//int main()
//{
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Bmw : public Car
//{
//public:
//	virtual void Drive() { cout << "²Ù×Ý-ºÃ¿ª" << endl; }
//};
//
//int main()
//{
//	//Car* ptr1 = new Car;
//	Car* ptr2 = new Bmw;
//	ptr2->Drive();
//	return 0;
//}


//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
//	virtual void Func1()
//	{}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
//	virtual void Func2()
//	{}
//};
//
//int main()
//{
//	Person p1;
//	Person p2;
//
//	Student s1;
//	Student s2;
//	return 0;
//}



class Person
{
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
	virtual void Func1() { cout << "Person Func1()" << endl; }
};
class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
	virtual void Func2() { cout << "Student Func2()" << endl; }
};

typedef void(*VFPTR)();
void PrintVFTable(VFPTR table[],int n)
{
	for (size_t i = 0;i<n; ++i)
	{
		printf("vft[%d]:%p->", i, table[i]);
		VFPTR pf = table[i];
		pf();
	}
}
int main()
{
	Student s1;
	Person p1;
	PrintVFTable((VFPTR*)*(int*)(&s1),3);

	PrintVFTable((VFPTR*)*(int*)(&p1),2);
	return 0;
}

































