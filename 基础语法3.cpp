#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//����

//int main()
//{
//	int a = 10;
//
//	//����
//	int& b = a;
//
//	//ȡ��ַ
//	int* p = &a;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	//���� ��	����û�п����¿ռ䣬���Ƕ�ԭ���ռ�ȡһ�������ƽ���b
//	int& b = a;
//
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//
//	//�����ڶ���ʱ�����ʼ��  --> ����ָ�����
//	//int& b = a;
//	//int& b;ָ�����
//
//
//	//һ�����������ж������
//	int a = 10;
//	int& b = a;
//	int& c = a;
//
//	return 0;
//}


//int main()
//{
//	//����һ������һ��ʵ�壬�ٲ�����������ʵ��
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//
//	b = c;
//	//�ǰ�c��ֵ����b
//
//	return 0;
//}



//���õ��÷�

//void swap(int* px, int* py)  //����ַ
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//void swap(int& px, int& py)  //������
//{
//	int tmp = px;
//	px = py;
//	py = tmp;
//}
//
////void swap(int x, int y)   //��ֵ
////{
////	int tmp = x;
////	x = y;
////	y = tmp;
////}
//
//
////�����������ɺ�������
////����swap��x,y��������ʱ�������壬Ҳ��֪�����ô�ֵ���Ǵ�����
//
////������������ǹ������أ����Ǵ�������
////  void func();
////  void func(int x=0,int y=0);
//
//
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x,&y);
//	swap(x, y);
//	return 0;
//}



//����������ֵ


//��ֵ����

//int Add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//
////c��ֵ����ڼĴ������䵱��ʱ��������(������ջ֡����ʱ����ֵ���ظ�ret)
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

//��ʱ��������������أ�
//1.���c�Ƚ�С��4or8��(�Ĵ���Ҳ�����ô��)��һ��Ĵ����䵱��ʱ����
//2.���c�Ƚϴ���ʱ��������ڵ���Add������ջ֡��



//�����÷���

//int& Add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//
////ֱ�ӷ���c�����ã����᷵��c�Ŀ���
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

//���ϴ��������
//1.���ڷǷ����ʣ���ΪAdd(1,2)�ķ���ֵ��c�����ã����Ե�����ջ֡�������Ժ󣬻�ȥ����c��ֵ
//2.���Add����ջ֡���٣�����ռ䣬��ôȡc��ֵʱ��ȡ���ľ������ֵ����ret�������ֵ�����ȡ���ڱ�����




//������
//int main()
//{
//	//Ȩ�޷Ŵ�  -->�����Ե�
//	//const int a = 10;  //ֻ�ܶ�
//	//int& b = a;       //�ɶ���д
//
//	//Ȩ�޲���
//	//const int a = 10;
//	//const int& b = a;
//
//	////Ȩ�ޱ�С
//	//int a = 10;
//	//const int& b = a;
//
//	//return 0;
//}



//���õļ�ֵ  --> 1.�����������Ч�ʣ�

#define N 100

struct Stack
{
	int a[N];
	int top;
};

void Func1(struct Stack st)
{

}

void Func2(struct Stack* st)
{

}

void Func3(struct Stack& st)
{

}


int main()
{
	struct Stack st;

	struct Stack* ps = &st;

	int a = 4;
	int* p = &a;

	char b = 'a';
	char* c = &b;

	printf("%d  %d  %d ", sizeof(ps),sizeof(p),sizeof(c));

	Func1(st);//��������404���ֽ�

	Func2(&st);//��������4���ֽ�

	Func3(st);//�����Ŀռ�

	return 0;
}





