#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class stu
{

};

int main()
{
	cout << sizeof(stu) << endl;

	return 0;
}





//���6��Ĭ�ϳ�Ա����

//���ࣨû���κεĳ�Ա��������������ʲô��û��--> �κ�һ���������ǲ�д������¶����Զ�����6��Ĭ�ϵĳ�Ա����
//���Ĭ�ϵĳ�Ա����������ĳ�Ա����������ĵ�ǳ��ǳ��࣬���ǲ�ʵ�֣��������Զ�����һ�ݣ�

//��ʼ��������   ---  > �൱�� Init����  �� Destroy ����

//���캯��  - ��ʼ��
//���캯��������ĳ�Ա�����������ǿ��ռ䴴�����󣬶��ǳ�ʼ������

//���캯������
//1.��������������ͬ
//2.�޷���ֵ
//3.����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯��
//4.���캯����������

//class Data
//{
//public:
//	//Data()
//	//{
//	//	_year = 0;
//	//	_month = 12;
//	//	_day = 5;
//	//}
//	//Data(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//ȫȱʡ
//	Data(int year=2022, int month = 2, int day = 5)
//	{
//		_year = year;
//	    _month = month;
//	    _day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//���������ʱ����ʵ����  --> �Զ����ö�Ӧ�Ĺ��캯��
//	Data D3;
//
//	Data D2(2023, 1, 9);
//
//	return 0;
//}


//������û���Զ��幹�캯��ʱ �� C++��������Ĭ�����ɹ��캯��
//��������֤---C++Ĭ�����ɵĹ��캯��

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_aa = 0;
//	}
//private:
//	int _aa;
//};
//
//
//class Data  //û���Զ��幹�캯��
//{
//public:
//private:
//
//	//C++��������ͷֳ�����  : �������ͣ��������ͣ� �� �Զ�������
//	// ��������  : int /char/double/ָ��/������������  �ȵ�
//	// �Զ�����������  struct / class ���������
//
//	//���ǲ�д���캯�� ��������Ĭ�����ɹ��캯���������������Ͳ�������
//	//�����Զ������ͳ�Ա������ȥ��������Ĭ�Ϲ��캯����ʼ�������û��Ĭ�Ϲ��캯���ͻᱨ��
//
//	//�κ�һ�����Ĭ�Ϲ��캯������ - ���ò����Ϳ��Ե��õģ�ȫȱʡ  �� �޲� �����ǲ�д������Ĭ�����ɣ�
//
//
//	//�������������������� �����ɵ�Ĭ�Ϲ��캯����������
//	int _year;
//	int _month;
//	int _day;
//
//	A aa;  //�Զ������ͣ�Ĭ�Ϲ��캯����Ҫ����������Ĵ���  - ����ȥ�������Լ�Ĭ�ϵĹ��캯��
// };
//
//
//int main()
//{
//	Data D1;
//
//	return 0;
//}









//��������  : �빹�캯�������෴����������������ɶ�������� �� �ֲ���������ٹ������ɱ�������ɵģ�
//������������ʱ���Զ�����������������ɶ����һЩ��Դ������


//��������������ĳ�Ա����

//���� :
//1.������������������ǰ�����ַ�   ~
//2.�޲����޷���ֵ
//3.һ����ֻ����������������ʾδ���壬��ͬ���Զ�����Ĭ�ϵ���������
//4.�����������ڽ����ǣ�C++����ϵͳ�Զ�������������
//
//class Data
//{
//public:
//
//	Data(int year=2022, int month = 2, int day = 5)
//	{
//		_year = year;
//	    _month = month;
//	    _day = day;
//	}
//	~Data()
//	{
//		//Data��û����Դ��Ҫ����  -- ����Data��ʵ�������������ǿ��Ե�
//		cout << "~Data()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data D1(2023, 1, 9);
//
//	return 0;
//}




//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//��������
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//};
//
//int main()
//{
//	//�Զ����ù��캯��
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}




//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//������ǲ�д�������������������Զ�Ĭ��������������  ��  ���캯������
//	//�������ó�Ա���Ͳ�������
//	//�����Զ������ͻ�ȥ����������������
//
//
//	//��������
//	//~Stack()
//	//{
//	//	free(_a);
//	//	_a = nullptr;
//	//	_top = _capacity = 0;
//	//}
//
//};
//
//int main()
//{
//	//�Զ����ù��캯��
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}




//��ô������Ĭ�����ɵ�����������û��������   -->   ��ʵ���кܴ����õ�  ������������ջʵ�ֶ��У�

//class Stack
//{
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//};
//
//class MyQueue {
//public:
//	MyQueue() {
//
//	}
//
//	void push(int x) {
//
//	}
//
//	int pop() {
//
//	}
//
//	int peek() {
//
//	}
//
//	bool empty() {
//
//	}
//
//private:
//	Stack Push1;
//	Stack Pop;
//};
//
//
//
//int main()
//{
//	//�Զ����ù��캯��
//	Stack s1;
//	Stack s2(20);
//
//	//����û����MyQueue���幹�캯������������
//	//���ǿ���ֱ��ʹ��Ĭ�ϵ�����������Ĭ�ϵĹ��캯����Push1��Pop��������ͳ�ʼ��
//
//	MyQueue q1;
//
//	return 0;
//}















