#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;





//int main()
//{
//	//����10�����δ�С�Ŀռ�
//	int* p1 = new int[10];
//
//	cout <<"p1:"<< p1 << endl;
//
//	//����
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
//	Stack st;  //��ջ��
//
//	Stack* pst2 = new Stack;  //���ռ� + ���캯����ʼ��
//
//	delete pst2;     //�ȵ�����������(��������е���Դ)  + �ͷſռ�  
//
//	return 0;
//}



//operator  new  ��  operator delete  ȫ�ֺ���

//new�ڵײ����operator newȫ�ֺ���������ռ䣬delete�ڵײ�ͨ��operator delete ȫ�ֺ������ͷ�

//operator new : �ú���ʵ����ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�ʧ�ܣ����쳣
//operator delete : �ĺ���������ͨ��free���ͷſռ�

//int main()
//{
//	//��malloc���÷�һ��
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//
//	delete pst1;
//
//	return 0;
//}



//int main()
//{
//	//����ʧ��
//	char* p1 = (char*)malloc(0x7fffffff);
//	char* p2 = new char[0x7fffffff];     
//	return 0;
//}



//int main()
//{
//	//����ʧ��
//	char* p1 = (char*)malloc(0x7fffffff);
//	if (p1 == nullptr)
//	{
//		printf("malloc fail");
//	}
//
//	try
//	{
//		char* p2 = new char[0x7fffffff];  //new�׳��쳣
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;  //catch�����쳣
//	}
//
//	return 0;
//}



//void f()
//{
//	char* p2 = new char[0x7fffffff];   //new�׳��쳣 ��ֱ������catch ���������ִ��
//
//	cout << "hello" << endl;//��ִ��
//}
//
//int main()
//{
//	//����ʧ��
//	char* p1 = (char*)malloc(0x7fffffff);
//	if (p1 == nullptr)
//	{
//		printf("malloc fail");
//	}
//
//	try
//	{
//		f();  //f�����е�new�׳��쳣����main�����в���
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;  //catch�����쳣
//	}
//
//	cout << "hello bit" << endl;
//
//	return 0;
//}



// operator new ��operator delete  ���Ƕ�malloc��free�ķ�װ
//operator new �е���malloc�����ڴ棬ʧ���Ժ󣬸�Ϊ���쳣����������ַ���C++����������Դ������ķ�ʽ



//int main()
//{
//	Stack* p1 = new Stack[10];
//
//	Stack* p2 = (Stack*)operator new[](sizeof(Stack) * 10);
//
//
//	return 0;
//}




//��λnew    --  �ֶ����ù��캯����ʼ��


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
//	A* p = (A*)malloc(sizeof(A));  //����A�Ŀռ�û�г�ʼ��
//
//	//���캯����֧����ʾ����  ��Ĭ���Զ����ã�
//
//	//�����������A��������ռ��ʼ��
//	//��λnew���ʽ�����ѷ���ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
//
//
//	//��ʾ�ĵ��ù��캯����ʼ��
//	//��������
//	new(p)A;
//
//	//������
//	new(p)A(2);
//
//
//
//	A* p1 = new A(2);
//	//�ȼ���
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
//	//���������ǿ�����ʾ���õ�
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




//�ڴ�й¶  --  ��̬������ڴ棬��ʹ���ˣ���û�������ͷţ��ʹ����ڴ�й¶
//�ڴ�й¶��Σ��  -----

//a.�����ڴ�й¶�Ľ����������������̽���ʱ��Щ�ڴ�ỹ��ϵͳ��������ʲô���˺�
//b.�����ڴ�й¶�Ľ��̷��������������罩ʬ����
//c.��Ҫ�������еĳ��򣬳����ڴ�й¶��Σ���ܴ�ϵͳ��Խ��Խ������������崻�

//int main()
//{
//	//�ڴ������ˣ����ͷ�
//	int* p = new int[10];
//	int* p1 = (int*)malloc(sizeof(int));
//
//}
//
//
////�쳣��ȫ����
//void Func()
//{
//	int* p4 = new int[0x7ffffff];
//}
//
//void MemoryLeaks()
//{
//	int* p3 = new int[10];
//
//	Func();//���쳣����delete[] p3δִ�У�p3û���ͷ�  ---ֱ������catch
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



















