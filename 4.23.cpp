#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name = "Peter";
//	int _age = 18;
//};
//
//class student : public Person
//{
//protected:
//	int _stuid;//ѧ��
//};
//
//
//
//int main()
//{
//	student s;
//	s._name = "����";
//	s._age = 18;
//	s.Print();
//
//
//	return 0;
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "Peter";
//	int _age = 18;
//};
//
//class student : public Person
//{
//	void Set(const char* name, int age)
//	{
//		_name = name;
//		_age = age;
//	}
//
//protected:
//	int _stuid;//ѧ��
//};
//
////protected / private �����治�ܷ��ʣ���������Է���
////���ɼ�   �����ˣ������������涼�޷�����
//int main()
//{
//	student s;
//	//s._name = "hello";
//	//s.age = 18;
//	return 0;
//}




//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "Peter";
//	int _age = 18;
//};
//
//class student :public  Person
//{
//protected:
//	int _stuid;//ѧ��
//};
//
//
//int main()
//{
//	student s;
//	s._name = "bk";
//	s.Print();
//
//	return 0;
//}



//class Person
//{
//protected:
//	string _name = "С����";
//	int _num = 111;
//};
//
//class student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "����:" << _name << endl;
//		cout << "ѧ��:" << _num << endl;
//		cout << "����:" << Person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
//
//int main()
//{
//	student s;
//	s.Print();
//	return 0;
//}


//class A
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(1);
//	return 0;
//}




class Person
{
protected:
	string _name;   //����
	string _sex;   //�Ա�
	int _age;     //����
};

class Student :public Person
{
public:
	int _NO;
};

int main()
{
	Student sobj;

	//���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;


	return 0;
}


















