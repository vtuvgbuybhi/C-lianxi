#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;



//                                C++��ε�C�ľ�̬��

      
//1.Ŀǰ������Ҫ����һ��ջ������һ����̬���У�C����д�ģ���   --> ����Ŀǰ�ĳ�����C++����   ������Ҫȥ����C��һ����


//������������һ��C++��Ŀ �����ǵľ�̬����һ��C�Ŀ�  --> ���������Ǳ���һ�����κ�ĺ������Ҳ����������ܹ����������Ӳ��ϣ�
//#include"../../../../Stack/StaticLib1/StaticLib1/Stack.h"
//������Stack.h  ֻ������  û�ж�����û�е�ַ��  -->������Ҫȥ���Ӿ�̬��

//���Ӷ�̬��  -->   ������ -->������ -->����  --> ���ӿ�Ŀ¼���ð� .lib ��Ŀ¼�Ź���(Debug)����Ӿ�̬��Ŀ¼
//            -->   ����   --> ����������(����StaticLib1.lib) ��Ӿ�̬��

//�����Ҳ���
//ԭ������C++��C�ĺ��������ι���ͬ 



//Ϊ���ܹ��ҵ���������˵���ܹ�������

//����C++������  �������Щ��������C�ı����������  �������ӵ�ʱ����C�ĺ���������ȥ�ң��ſ���������
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



//                     C��ε���C++�ľ�̬��


//�Ҳ������������� --> ���Ӵ���
#include"../../../../Stack/StaticLib1/StaticLib1/Stack.h"


//C++��̬�⣬�ͻᰴC�ĺ�����ȥ����ȥ�������º���
//extern "C"
//{
//	void StackInit(ST* ps);
//	void StackPush(ST* ps, SLTDataType x);
//	void StackDestroy(ST* ps);
//	bool StackEmpty(ST* ps);
//	void StackPop(ST* ps);
//	SLTDataType StackTop(ST* ps);
//	int Stacksize(ST* ps);
//}//  ���Ǳ��벻��  C����ʶextern(�Ὣ��������滻Stack.h)


////����������   --> ����1
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


//��������  --> ����2

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




//�ܽ�  :   C++����  ����C�Ŀ�  �� C++�����м�extern "C"
//          C����   ����C++��  ��C++���м�extern "C"























































