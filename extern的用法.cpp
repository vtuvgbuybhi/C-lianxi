#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;



//                                C++如何掉C的静态库

      
//1.目前我们需要调用一个栈（放在一个静态库中（C语言写的））   --> 我们目前的程序是C++程序   我们需要去调用C的一个库


//这样子我们是一个C++项目 而我们的静态库是一个C的库  --> 这样子我们报了一个修饰后的函数名找不到（编译能过，但是链接不上）
//#include"../../../../Stack/StaticLib1/StaticLib1/Stack.h"
//这样子Stack.h  只有申明  没有定义是没有地址的  -->我们需要去链接静态库

//链接动态库  -->   点属性 -->链接器 -->常规  --> 附加库目录（得把 .lib 的目录放过来(Debug)）添加静态库目录
//            -->   输入   --> 附加依赖项(加上StaticLib1.lib) 添加静态库

//还是找不到
//原因在于C++和C的函数名修饰规则不同 



//为了能够找到函数或者说是能够链接上

//告诉C++编译器  下面的这些函数是用C的编译器编译的  我们链接的时候用C的函数名规则去找，才可以链接上
//extern "C"
//{
//	#include"../../../../Stack/StaticLib1/StaticLib1/Stack.h"
//}
//
//bool isValid(char* s)
//{
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				return false;
//			}
//			SLTDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == ']' && top != '[') || (*s == ')' && top != '(') || (*s == '}' && top != '{'))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//
//int main()
//{
//	char s[] = "[]";
//	cout << isValid(s) << endl;
//	return 0;
//}



//                     C如何调用C++的静态库


//找不到函数的问题 --> 链接错误
#include"../../../../Stack/StaticLib1/StaticLib1/Stack.h"


//C++静态库，就会按C的函数名去规则去处理以下函数
//extern "C"
//{
//	void StackInit(ST* ps);
//	void StackPush(ST* ps, SLTDataType x);
//	void StackDestroy(ST* ps);
//	bool StackEmpty(ST* ps);
//	void StackPop(ST* ps);
//	SLTDataType StackTop(ST* ps);
//	int Stacksize(ST* ps);
//}//  还是编译不过  C不认识extern(会将上面程序替换Stack.h)


////用条件编译   --> 方法1
////#ifdef __cplusplus
////extern "C"
////{
////#endif
////	void StackInit(ST* ps);
////	void StackPush(ST* ps, SLTDataType x);
////	void StackDestroy(ST* ps);
////	bool StackEmpty(ST* ps);
////	void StackPop(ST* ps);
////	SLTDataType StackTop(ST* ps);
////	int Stacksize(ST* ps);
////#ifdef __cplusplus
////}
////#endif


//条件编译  --> 方法2

//#ifdef __cplusplus
//	#define EXTERN_C extern "C"
//#else
//	#define EXTERN_C
//#endif
//EXTERN_C void StackInit(ST* ps);
//EXTERN_C void StackPush(ST* ps, SLTDataType x);
//EXTERN_C void StackDestroy(ST* ps);
//EXTERN_C bool StackEmpty(ST* ps);
//EXTERN_C void StackPop(ST* ps);
//EXTERN_C SLTDataType StackTop(ST* ps);
//EXTERN_C int Stacksize(ST* ps);





//bool isValid(char* s)
//{
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				return false;
//			}
//			SLTDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == ']' && top != '[') || (*s == ')' && top != '(') || (*s == '}' && top != '{'))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//
//int main()
//{
//	char s[] = "[]";
//	printf("%d ", isValid(s));
//
//	return 0;
//}




//总结  :   C++程序  调用C的库  在 C++程序中加extern "C"
//          C程序   调用C++库  在C++库中加extern "C"























































