#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;



//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���
//���ף�ʱ�临�Ӷȣ�O(n) ���ռ临�Ӷȣ�O(1)


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
//	//ֱ����thisָ�룬����˽�г�Ա����
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



//C�����ж�̬�ڴ����ʽ

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	//malloc/calloc/realloc��������ʲô
//
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//
//	//������Ҫfree(p2)��
//	free(p3);
//}

//calloc��malloc������??
//calloc���ʼ�����൱�ڣ�malloc+memset,���ֽڳ�ʼ�����ռ�ÿ���ֽڳ�ʼ��Ϊ0

//realloc   -->  ����    �������ԭ����



//int main()
//{
//	//��̬����int��5��int����
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

//�ܽ�  : malloc/free  ��  new/delete ����������û�б�������ֻ���÷��ϵ�����

//int main()
//{
//	int* p3 = new int(5);//��̬����һ��int�ռ䣬���ռ��ʼ��Ϊ5
//	int* p4 = new int[5];//��̬����5��int�ռ�
//
//	p4[0] = 1;
//	p4[1] = 2;
//
//
//	return 0;
//}



//��ô���������Զ��Զ������� malloc ��new �����ǽ���ֻ���﷨��������

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
//	//��̬���뵥��A�����5��A��������
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)malloc(sizeof(A) * 5);
//	A* p5 = (A*)calloc(sizeof(A),4);
//
//
//	//new�ڶ�������ռ�+���ù��캯����ʼ������
//	A* p3 = new A;   //���ù��캯����ʼ��
//	A* p4 = new A[5];  //����5�ι��캯��
//
//	free(p1);
//	free(p2);
//
//	//   �ȵ���ָ�������������� + �ͷſռ������
//	delete p3;    //����������������Դ����
//	delete[] p4;  
//
//	return 0;
//}



int main()
{
	//������������  : �������ķ�ʽһ�������쳣��C++��ҲҪ��������쳣   --- try  catch
	//������̵����ԣ��������ķ�ʽһ����  --> ����ֵ  + ��������

	//C���Դ������ķ�ʽ
	//char* p1 = (char*)malloc(1024 * 1024 * 1024*2);
	//if (p1 == nullptr)
	//{
	//	printf("%d\n", errno);//��ӡ������
	//	perror("malloc fail");//perror�⺯������ӡ�������Ӧ��ԭ��
	//	exit(-1);
	//}
	//else
	//{
	//	printf("%p\n", p1);
	//}


	//C++�������ķ�ʽ
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








































