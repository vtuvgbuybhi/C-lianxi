#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//������ͻ����

//1.�����Լ�����ı������������ܸ�������������ͻ��
//2.��Ŀ�ϴ󣬶���Э����������ͻ

//c����û�а취�ܺý���������

#include<stdlib.h>  //ͷ�ļ��а��� rand����

//CPP�����  --> �����ռ�

//������һ����bit�������ռ�   -- ��
//�����ռ��п��Զ������/����/����

//namespace cdc
//{
//	//ȫ�ֱ���-->��̬��
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
//	printf("%d ",cdc::rand);//�������޶���
//
//	struct cdc::Node;
//	cdc::Add(1, 2);
//
//	return 0;
//}



//�����ռ�Ƕ��


//namespace cdc
//{
//	//ȫ�ֱ���-->��̬��
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
////ָ��������������õ��������룬����������ʹ��
//int main()
//{
//	printf("%d ", N::b);
//	return 0;
//}
//
//
//using N::b;  //����չ�������ռ��г��õ�
//int main()
//{
//	printf("%d ", b);
//	return 0;
//}
//
//using namespace N;//�������ռ�ȫ��չ��������ʧЧ
//int main()
//{
//	printf("%d ", b);
//	return 0;
//}









//#include<iostream>
//using namespace std;   //C++���ʵ���Ƕ�����һ����std�������ռ���  �������ռ�ȫ��չ��
//
//int main()
//{
//	//cout << "hello world" << endl;
//
//	//ָ�������ռ�  --> �������
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































































