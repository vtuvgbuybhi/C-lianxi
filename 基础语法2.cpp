#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<iostream>
using namespace std;


//int main()
//{
//	int a = 0;
//	char b = 'c';
//
//
//	//cout 流插入运算符     cin流提取运算符
//
//	//自动识别类型
//	cout << a << " " << b << endl;
//	char c;
//	cin >> c;
//	cout << c << endl;
//
//	return 0;
//}


//struct Student
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	struct Student s = { "鹏哥",18 };
//
//	cout << "姓名:" << s.name << endl;
//	cout << "年龄:" << s.age << endl;
//	printf("姓名:%s\n年龄:%d\n", s.name, s.age);
//
//	cin >> s.name >> s.age;
//	cout << "姓名:" << s.name << endl;
//	cout << "年龄:" << s.age << endl;
//
//	scanf("%s%d", s.name,&s.age);//s.name是字符串的首元素地址，不需要加取地址符号
//	printf("姓名:%s\n年龄:%d\n", s.name, s.age);
//
//	return 0;
//}



//缺省参数

//全缺省:所有参数都给了缺省值
//void Func(int a = 10, int b = 20)
//{
//	cout <<"a="<< a << endl;
//	cout <<"b="<< b << endl << endl;
//}
//
//int main()
//{
//	Func();//什么都不传，使用默认的参数
//	Func(1);//不使用默认的参数  使用我们传的   b还是使用默认的(从左往右)
//	Func(1, 2);
//	return 0;
//}


//半缺省  --> 缺省部分参数  --> 必须从右往左缺省（连续）
//void Func(int a,int b,int c=20)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl << endl;
//}
//int main()
//{
//	Func(17, 20);
//	Func(1, 2, 3);
//	return 0;
//}


//缺省参数的用处

//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void InitStack(struct Stack* ps,int capacity=4)
//{
//	ps->a = (int*)malloc(sizeof(int) * capacity);
//	if (ps->a == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	ps->top = 0;
//	ps->capacity = capacity;
//}
//
//void PushStack(struct Stack* ps)
//{
//	//...
//}
//
//int main()
//{
//	struct Stack st;
//
//	InitStack(&st);//不知道栈最多存多少数据，就用缺省值初始化
//	InitStack(&st,100);//知道栈最多存100个数据，显示次数，这样可以减少增容次数，提高效率
//
//	return 0;
//}


//注意的是  ：   缺省参数不能在声明和定义中同时出现

//   .h文件
//void Func(int a=10);      ---
//                          这样子就是重定义  --> 只能声明一个
//   .cpp文件                |
//void Func(int a=20);      ---


//函数重载
//概念: 同一个作用域中声明几个功能类似的同名函数   这些同名函数的参数列表(参数个数不同或类型或顺序不同)

//返回值不同不能构成重载    -- 调用的时候不能区分

//函数参数类型不同
//int Add(int x, int y)
//{
//	cout << "int Add(int x int y)" << endl;
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	cout << "int Add(double x,double y)" << endl;
//	return x + y;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1.1, 2.2);
//	return 0;
//}



//函数参数个数不同
//int Add(int x, int y)
//{
//	cout << "int Add(int x int y)" << endl;
//	return x + y;
//}
//
//int Add(int x)
//{
//	cout << "int Add(int x)" << endl;
//	return x;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1);
//	return 0;
//}


//参数顺序不同
//void Add(char x, int y)
//{
//	cout << "void Add(char x int y)" << endl;
//}
//
//void Add(int x,char y)
//{
//	cout << "void Add(int x,char y)" << endl;
//}
//
//int main()
//{
//	Add('a', 2);
//	Add(1,'b');
//	return 0;
//}


//缺省值不同，不能构成重载
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 10)
//{
//	cout << "f(int )" << endl;
//}


//构成重载，不过使用时会有问题
void f()
{
	cout << "f()" << endl;
}

void f(int a = 0)
{
	cout << "f(int a)" << endl;
}
int main()
{
	f();
	f(1);
	return 0;
}


















