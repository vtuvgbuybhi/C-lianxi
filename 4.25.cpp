#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//class Person
//{
//protected:
//	string _name;   //����
//	string _sex;   //�Ա�
//	int _age;     //����
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
//	//���������Ը�ֵ���������/ָ��/����
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
		//����  ���������Լ���
		cout << "~Student()" << endl;
	}

protected:
	int _num;
};

int main()
{
	Student s1("����",1);
	Student s2(s1);

	Student s3("����", 2);
	s1 = s3;

	return 0;
}


















































