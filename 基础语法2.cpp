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
//	//cout �����������     cin����ȡ�����
//
//	//�Զ�ʶ������
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
//	struct Student s = { "����",18 };
//
//	cout << "����:" << s.name << endl;
//	cout << "����:" << s.age << endl;
//	printf("����:%s\n����:%d\n", s.name, s.age);
//
//	cin >> s.name >> s.age;
//	cout << "����:" << s.name << endl;
//	cout << "����:" << s.age << endl;
//
//	scanf("%s%d", s.name,&s.age);//s.name���ַ�������Ԫ�ص�ַ������Ҫ��ȡ��ַ����
//	printf("����:%s\n����:%d\n", s.name, s.age);
//
//	return 0;
//}



//ȱʡ����

//ȫȱʡ:���в���������ȱʡֵ
//void Func(int a = 10, int b = 20)
//{
//	cout <<"a="<< a << endl;
//	cout <<"b="<< b << endl << endl;
//}
//
//int main()
//{
//	Func();//ʲô��������ʹ��Ĭ�ϵĲ���
//	Func(1);//��ʹ��Ĭ�ϵĲ���  ʹ�����Ǵ���   b����ʹ��Ĭ�ϵ�(��������)
//	Func(1, 2);
//	return 0;
//}


//��ȱʡ  --> ȱʡ���ֲ���  --> �����������ȱʡ��������
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


//ȱʡ�������ô�

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
//	InitStack(&st);//��֪��ջ����������ݣ�����ȱʡֵ��ʼ��
//	InitStack(&st,100);//֪��ջ����100�����ݣ���ʾ�������������Լ������ݴ��������Ч��
//
//	return 0;
//}


//ע�����  ��   ȱʡ���������������Ͷ�����ͬʱ����

//   .h�ļ�
//void Func(int a=10);      ---
//                          �����Ӿ����ض���  --> ֻ������һ��
//   .cpp�ļ�                |
//void Func(int a=20);      ---


//��������
//����: ͬһ�������������������������Ƶ�ͬ������   ��Щͬ�������Ĳ����б�(����������ͬ�����ͻ�˳��ͬ)

//����ֵ��ͬ���ܹ�������    -- ���õ�ʱ��������

//�����������Ͳ�ͬ
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



//��������������ͬ
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


//����˳��ͬ
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


//ȱʡֵ��ͬ�����ܹ�������
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 10)
//{
//	cout << "f(int )" << endl;
//}


//�������أ�����ʹ��ʱ��������
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


















