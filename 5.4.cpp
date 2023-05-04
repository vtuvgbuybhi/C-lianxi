#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
//	virtual void Func1() { cout << "Person Func1()" << endl; }
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
//	virtual void Func2() { cout << "Student Func2()" << endl; }
//};
//
//typedef void(*VFPTR)();
////void PrintVFTable(VFPTR* table,int n)
//void PrintVFTable(VFPTR table[],int n)
//{
//	for (size_t i = 0;i<n; ++i)
//	{
//		printf("vft[%d]:%p->", i, table[i]);
//		VFPTR pf = table[i];
//		pf();
//	}
//}
//int main()
//{
//	Student s1;
//	Student s2;
//	Person p1;
//	Person p2;
//	PrintVFTable((VFPTR*)*(int*)(&s1),3);
//
//	PrintVFTable((VFPTR*)*(int*)(&p1),2);
//	return 0;
//}





//class Base1
//{
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int _b1 = 1;
//};
//class Base2 :public Base1
//{
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int _b2 = 2;
//};
//
//
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	cout << sizeof(b2) << endl;
//	cout << sizeof(b1) << endl;
//	return 0;
//}





typedef void(*VFPTR)();
//void PrintVFTable(VFPTR* table,int n)
void PrintVFTable(VFPTR* table)
{
	for (size_t i = 0;table[i]!=nullptr; ++i)
	{
		printf("vft[%d]:%p->", i, table[i]);
		VFPTR pf = table[i];
		pf();
	}
}
class Base1
{
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int _b1 = 1;
};
class Base2
{
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int _b2 = 2;
};
class Derive : public Base1, public Base2
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};


int main()
{
	Derive d;
	//cout << sizeof(d) << endl;
	PrintVFTable((VFPTR*)*(int*)&d);
	PrintVFTable((VFPTR*)*(int*)((char*) & d + sizeof(Base1)));

	return 0;
}
















































