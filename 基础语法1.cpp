#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//命名冲突问题

//1.我们自己定义的变量，函数可能跟库里面重名冲突了
//2.项目较大，多人协作，命名冲突

//c语言没有办法很好解决这个问题

#include<stdlib.h>  //头文件中包含 rand函数

//CPP提出了  --> 命名空间

//定义了一个叫bit的命名空间   -- 域
//命名空间中可以定义变量/函数/类型

//namespace cdc
//{
//	//全局变量-->静态区
//	int rand = 0;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//}

//int main()
//{
//	printf("hello world\n");
//	//printf(" %d ", rand);
//	printf("%d ",cdc::rand);//域作用限定符
//
//	struct cdc::Node;
//	cdc::Add(1, 2);
//
//	return 0;
//}



//命名空间嵌套


//namespace cdc
//{
//	//全局变量-->静态区
//	int rand = 0;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//	namespace cdc1
//	{
//		int a = 10;
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}
//
//int main()
//{
//	cdc::Add(1, 3);
//
//	cdc::cdc1::a = 10;
//
//	return 0;
//}




//namespace N
//{
//	int b=10;
//}
//
////指定作用域，做到最好的命名隔离，不过不方便使用
//int main()
//{
//	printf("%d ", N::b);
//	return 0;
//}
//
//
//using N::b;  //用于展开命名空间中常用的
//int main()
//{
//	printf("%d ", b);
//	return 0;
//}
//
//using namespace N;//将命名空间全部展开，隔离失效
//int main()
//{
//	printf("%d ", b);
//	return 0;
//}









//#include<iostream>
//using namespace std;   //C++库的实现是定义在一个叫std的命名空间中  将命名空间全部展开
//
//int main()
//{
//	//cout << "hello world" << endl;
//
//	//指定命名空间  --> 进行输出
//	//std::cout << "hello world" << std::endl;
//
//	return 0;
//}



#include<iostream>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	cout << "hello world\n";
	printf("hello world\n");
	
	int i = 10;
	double d = 1.11;
	cout << i << " " << d << endl;

	return 0;
}































































