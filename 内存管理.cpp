#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;



//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：O(n) ，空间复杂度：O(1)


//int GetMonthDay(int year, int month)
//{
//	static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	
//	int day = monthDayArray[month];
//	if (month==2&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		day += 1;
//	}
//	return day;
//}
//
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//
//	int n = 0;
//	for (int i = 1; i < month; i++)
//	{
//		n += GetMonthDay(year, i);
//	}
//	n += day;
//	cout << n << endl;
//	return 0;
//}



//class StackCPP
//{
//public:
//	StackCPP(StackCPP* ps)
//	{}
//	void Push(StackCPP*ps,int x)
//	{}
//	int Top(StackCPP*ps)
//	{}
//	~StackCPP(StackCPP* ps)
//	{}
//private:
//	int* _a;
//	int top;
//	int capacity;
//};
//
//
//void TestStack_CPP()
//{
//	StackCPP st;
//}
//
//int main()
//{
//	TestStack_CPP();
//	return 0;
//}




//class StackCPP
//{
//public:
//	//直接用this指针，访问私有成员变量
//	StackCPP()
//	{}
//	void Push(int x)
//	{}
//	int Top()
//	{}
//	~StackCPP()
//	{}
//private:
//	int* _a;
//	int top;
//	int capacity;
//};
//
//
//void TestStack_CPP()
//{
//	StackCPP st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//}
//
//int main()
//{
//	TestStack_CPP();
//
//	return 0;
//}



//int  globalvar       = 1;
//static int staticvar = 1;
//
//void Test()
//{
//	static int staticvar = 1;
//	int localvar         = 1;
//	char char2[]         = "abcd";
//
//	const char* pchar3   = "abcd";
//
//	int* ptr1            = (int*)malloc(sizeof(sizeof(int) * 4));
//	int* ptr2            = (int*)malloc(sizeof(sizeof(int) * 4));
//	int* ptr3            = (int*)malloc(sizeof(sizeof(int) * 4));
//
//	free(ptr1);
//	free(ptr2);
//}



//C语言中动态内存管理方式

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	//malloc/calloc/realloc的区别是什么
//
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//
//	//这里需要free(p2)嘛
//	free(p3);
//}

//calloc和malloc的区别??
//calloc会初始化，相当于，malloc+memset,按字节初始化，空间每个字节初始化为0

//realloc   -->  扩容    异地扩、原地扩



//int main()
//{
//	//动态申请int和5个int数组
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 5);
//
//	int* p3 = new int;
//	int* p4 = new int[5];
//
//	free(p1);
//	free(p2);
//	delete p3;
//	delete[] p4;
//
//	p1 = nullptr;
//	p2 = nullptr;
//	p3 = nullptr;
//	p4 = nullptr;
//
//	return 0;
//}

//总结  : malloc/free  和  new/delete 对内置类型没有本质区别，只有用法上的区别

//int main()
//{
//	int* p3 = new int(5);//动态申请一个int空间，这块空间初始化为5
//	int* p4 = new int[5];//动态申请5个int空间
//
//	p4[0] = 1;
//	p4[1] = 2;
//
//
//	return 0;
//}



//那么我们再试试对自定义类型 malloc 和new 还会是仅仅只有语法区别了嘛

class A
{
public:
	A(int a=0)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//
//	//动态申请单个A对象和5个A对象数组
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)malloc(sizeof(A) * 5);
//	A* p5 = (A*)calloc(sizeof(A),4);
//
//
//	//new在堆上申请空间+调用构造函数初始化对象
//	A* p3 = new A;   //调用构造函数初始化
//	A* p4 = new A[5];  //调用5次构造函数
//
//	free(p1);
//	free(p2);
//
//	//   先调用指针类型析构函数 + 释放空间给堆上
//	delete p3;    //调用析构函数，资源清理
//	delete[] p4;  
//
//	return 0;
//}



int main()
{
	//面向对象的语言  : 处理错误的方式一般是抛异常，C++中也要求出错抛异常   --- try  catch
	//面向过程的语言，处理错误的方式一般是  --> 返回值  + 错误码解决

	//C语言处理错误的方式
	//char* p1 = (char*)malloc(1024 * 1024 * 1024*2);
	//if (p1 == nullptr)
	//{
	//	printf("%d\n", errno);//打印错误码
	//	perror("malloc fail");//perror库函数，打印错误码对应的原因
	//	exit(-1);
	//}
	//else
	//{
	//	printf("%p\n", p1);
	//}


	//C++处理错误的方式
	char* p2 = nullptr;
	try
	{
		p2 = new char[1024 * 1024 * 1024 * 2u-1];
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	printf("%p\n", p2);

	return 0;
}








































