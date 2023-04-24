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
//	int _stuid;//学号
//};
//
//
//
//int main()
//{
//	student s;
//	s._name = "张三";
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
//	int _stuid;//学号
//};
//
////protected / private 类外面不能访问，类里面可以访问
////不可见   隐身了，类里面类外面都无法访问
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
//	int _stuid;//学号
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
//	string _name = "小李子";
//	int _num = 111;
//};
//
//class student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名:" << _name << endl;
//		cout << "学号:" << _num << endl;
//		cout << "父亲:" << Person::_num << endl;
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
	string _name;   //姓名
	string _sex;   //性别
	int _age;     //年龄
};

class Student :public Person
{
public:
	int _NO;
};

int main()
{
	Student sobj;

	//子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;


	return 0;
}


















