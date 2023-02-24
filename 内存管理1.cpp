#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;





//int main()
//{
//	//开辟10个整形大小的空间
//	int* p1 = new int[10];
//
//	cout <<"p1:"<< p1 << endl;
//
//	//销毁
//	delete[] p1;
//
//	return 0;
//}



class Stack
{
public:
	Stack(int capacity = 4)
		:_capacity(capacity)
		,_top(0)
	{
		_a = new int[capacity];
		cout << "Stack()" << endl;
	}
	~Stack()
	{
		_capacity = _top = 0;
		_a = nullptr;
		delete[] _a;
		cout << "~Stack()" << endl;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};
//
//int main()
//{
//	Stack* pst2 = new Stack;  
//
//	delete pst2;     
//
//	return 0;
//}

//
//int main()
//{
//	Stack st;  //在栈上
//
//	Stack* pst2 = new Stack;  //开空间 + 构造函数初始化
//
//	delete pst2;     //先调用析构函数(清理对象中的资源)  + 释放空间  
//
//	return 0;
//}



//operator  new  和  operator delete  全局函数

//new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete 全局函数来释放

//operator new : 该函数实际是通过malloc来申请空间，当malloc申请空间成功时直接返回，申请空间失败，抛异常
//operator delete : 改函数最终是通过free来释放空间

//int main()
//{
//	//跟malloc的用法一致
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//
//	delete pst1;
//
//	return 0;
//}



//int main()
//{
//	//开辟失败
//	char* p1 = (char*)malloc(0x7fffffff);
//	char* p2 = new char[0x7fffffff];     
//	return 0;
//}



//int main()
//{
//	//开辟失败
//	char* p1 = (char*)malloc(0x7fffffff);
//	if (p1 == nullptr)
//	{
//		printf("malloc fail");
//	}
//
//	try
//	{
//		char* p2 = new char[0x7fffffff];  //new抛出异常
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;  //catch捕获异常
//	}
//
//	return 0;
//}



//void f()
//{
//	char* p2 = new char[0x7fffffff];   //new抛出异常 ，直接跳到catch ，后面程序不执行
//
//	cout << "hello" << endl;//不执行
//}
//
//int main()
//{
//	//开辟失败
//	char* p1 = (char*)malloc(0x7fffffff);
//	if (p1 == nullptr)
//	{
//		printf("malloc fail");
//	}
//
//	try
//	{
//		f();  //f函数中的new抛出异常，在main函数中捕获
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;  //catch捕获异常
//	}
//
//	cout << "hello bit" << endl;
//
//	return 0;
//}



// operator new 和operator delete  就是对malloc和free的封装
//operator new 中调用malloc申请内存，失败以后，改为抛异常处理错误，这种符合C++面向对象语言处理错误的方式



//int main()
//{
//	Stack* p1 = new Stack[10];
//
//	Stack* p2 = (Stack*)operator new[](sizeof(Stack) * 10);
//
//
//	return 0;
//}




//定位new    --  手动调用构造函数初始化


class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << this << endl;
	}
	~A()
	{
		cout << "~A()" << this << endl;
	}
private:
	int _a;
};


int main()
{
	
	A* p = (A*)malloc(sizeof(A)); 

	new(p)A(5);


	return 0;
}












//int main()
//{
//	
//	A* p = (A*)malloc(sizeof(A));  //对象A的空间没有初始化
//
//	//构造函数不支持显示调用  （默认自动调用）
//
//	//现在我们想对A对象这个空间初始化
//	//定位new表达式是在已分配原始内存空间中调用构造函数初始化一个对象
//
//
//	//显示的调用构造函数初始化
//	//不传参数
//	new(p)A;
//
//	//传参数
//	new(p)A(2);
//
//
//
//	A* p1 = new A(2);
//	//等价于
//	A* p2 = (A*)operator new (sizeof(A));
//	new(p2)A(3);
//
//	return 0;
//}



//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A(3);
//
//	//析构函数是可以显示调用的
//	p1->~A();
//
//
//	A* p3 = new A(5);
//	delete p3;
//
//
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(4);
//	
//	operator delete(p2);
//
//	return 0;
//}




//内存泄露  --  动态申请的内存，不使用了，又没有主动释放，就存在内存泄露
//内存泄露的危害  -----

//a.出现内存泄露的进程正常结束，进程结束时这些内存会还给系统，不会有什么大伤害
//b.出现内存泄露的进程非正常结束，比如僵尸进程
//c.需要长期运行的程序，出现内存泄露。危害很大，系统会越来越慢，甚至卡死宕机

//int main()
//{
//	//内存申请了，不释放
//	int* p = new int[10];
//	int* p1 = (int*)malloc(sizeof(int));
//
//}
//
//
////异常安全问题
//void Func()
//{
//	int* p4 = new int[0x7ffffff];
//}
//
//void MemoryLeaks()
//{
//	int* p3 = new int[10];
//
//	Func();//抛异常导致delete[] p3未执行，p3没被释放  ---直接跳到catch
//	
//	delete[] p3;
//}
//
//int main()
//{
//	try
//	{
//		MemoryLeaks();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}



//int main()
//{
//	//cout << sizeof(void*) << endl;
//
//	void* p = new char[1024u * 1024u * 1024u * 2u - 1];
//	cout << "new:" << p << endl;
//
//	return 0;
//}



















