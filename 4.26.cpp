#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNUM;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNUM << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//
//	return 0;
//}


//class Person
//{
//public:
//	static int _count;
//	Person() { ++_count; }
//protected:
//	string _name;
//};
//
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNUM;
//};
//
//class Graduate : public Student
//{
//public:
//	string _Course;
//};
//
//
//int main()
//{
//	Person p;
//	Student s;
//
//	cout << &(s._count) << endl;
//	cout << &(p._count) << endl;
//
//	++Person::_count;
//	cout << Student::_count << endl;
//
//	return 0;
//}


//class A final
//{
//private:
//	A()
//	{}
//
//protected:
//	int _a;
//};
//
//class B : public A
//{
//protected:
//	int _b;
//};
//
//int main()
//{
//
//	return 0;
//}



//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive :public Base1, public Base2 { public: int _d; };
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//
//	cout << p1 << endl;
//	cout << p2 << endl;
//
//	return 0;
//}



//class Person
//{
//public:
//	string _name;   //姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id;   //职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; //主修课程
//};
//
//int main()
//{
//	Assistant at;
//	at._name = "张三";
//	at.Student::_name = "张三";
//	at.Teacher::_name = "李四";
//	
//	return 0;
//}



class A
{
public:
	int _a;
};
//class B : public A
class B : virtual public A
{
public:
	int _b;
};
//class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public C, public B
{
public:
	int _d;
};


int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}










