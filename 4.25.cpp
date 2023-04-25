#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Person
//{
//protected:
//	string _name;   //姓名
//	string _sex;   //性别
//	int _age;     //年龄
//};
//
//class Student :public Person
//{
//public:
//	int _NO;
//};
//
//int main()
//{
//	Student sobj;
//
//	//子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//
//	Person* pp = &sobj;
//
//	Person& rp = sobj;
//
//	int i = 0;
//	const double& d = i;
//
//	return 0;
//}


class Person
{
public:
	Person(const char* name)
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person &p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person opeartor=(const Person&p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};


class Student : public Person
{
public:
	Student(const char* name, int num)
		:Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Stident&s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		cout << "Student& operator=(const Student& s)" << endl;
		return *this;
	}

	~Student()
	{
		//Person::~Person();
		//……  处理子类自己的
		cout << "~Student()" << endl;
	}

protected:
	int _num;
};

int main()
{
	Student s1("张三",1);
	Student s2(s1);

	Student s3("李四", 2);
	s1 = s3;

	return 0;
}


















































