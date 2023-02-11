#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//面向对象和面向过程的初步认识
//C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题
//C++是面向对象的，关注的是对象，将一件事情分成不同的对象，靠对象之间交互完成

//struct /class

// C++兼容C里面结构体的用法
//同时struct在C++中也升级成了类

//struct student
//{
//	char name[20];
//	int age;
//	int id;
//};

//int main()
//{
//	struct student s1;//兼容C
//
//	student s2;        //升级到类，student类名，也是类型
//
//	//scanf("%s", s1.name);
//	//cout << s1.name  ;
//
//	//数组是不支持，直接赋值的(用拷贝函数)
//	strcpy(s1.name, "张三");
//	s1.age = 11;
//	s1.id = 5;
//
//	strcpy(s2.name, "张三");
//	s2.age = 11;
//	s2.id = 5;
//
//	return 0;
//}



//C++类跟结构体不同的是除了可以定义变量，还可以定义方法/函数
//struct student
//{
//	char _name[20];
//	int _age;
//	int _id;
//
//	//成员方法//成员函数
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//
//};
//
//int main()
//{
//	struct student s1;
//	student s2;
//
//	s1.Init("张三", 12, 4);
//	s2.Init("李四", 78, 99);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}




//class

//面向对象三大特性 : 封装  、 继承  、 多态

//封装  : 1.数据和方法（函数）都放到一个类里面去  2.访问限定符


//               -  public(公有)   （struct默认是公有  -- 要兼容C）
//              |
//访问限定符  -- -  protected(保护)
//              |
//               -  private（私有）  class默认是私有

class student
{
	char _name[20];
	int _age;
	int _id;

public:
	//成员方法//成员函数
	void Init(const char* name, int age, int id)
	{
		strcpy(_name, name);
		_age = age;
		_id = id;
	}

	void Print()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _id << endl;
	}

};

int main()
{
	struct student s1;
	student s2;

	s1.Init("张三", 12, 4);
	s2.Init("李四", 78, 99);

	s1.Print();
	s2.Print();

	return 0;
}




























