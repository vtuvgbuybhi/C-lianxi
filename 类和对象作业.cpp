#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//�����Ѿ��� A B C D �ĸ���Ķ���  ��������A B C D ������������˳��Ϊ ?

//class C
//{
//public:
//	C()
//	{
//		cout << "C()" << endl;
//	}
//
//	~C()
//	{
//		cout <<"~C()" << endl;
//	}
//};
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//class D
//{
//public:
//	D()
//	{
//		cout << "D()" << endl;
//	}
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};
//
//C c;
//
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return 0;
//}


//����˳�� :   c��ȫ�ֱ�������mian����֮ǰ��һ�����ȹ���
//�ֲ��������ֲ���̬���� :  ˭�ȶ���˭�ȹ���
//  C A B D


//�ȶ��������
//����˳��   :  ����main�������Ȱ������������ľֲ����������
//��̬�ֲ���������main������������֮��Ż�����
// B A D C 




//���´��빲���ö��ٴο������캯��

//class Widget
//{
//public:
//	Widget()
//	{
//		//cout << "Widget()" << endl;
//	}
//	Widget(const Widget&)
//	{
//		cout << "Widget(const Widget&)" << endl;
//	}
//};
//
//
//Widget f(Widget u)
//{
//	return u;
//}
//
//int main()
//{
//	Widget x;
//	Widget y = f(x);
//	return 0;
//}

//������� һ��������3�ο������캯��
//  ��x��u����ʱ������һ�ο������캯��  ��   �ڷ���ֵ  u ����yʱ  ���������2��
      //             ----------
      // u   -----> | �м���� | ------  > y
	//		һ��	-----------   һ��

//����������������������Ż�     u����yʱ ��ʡ�����м����  ���϶�Ϊһ����uֱ�Ӵ���y��

//һ�ε������棬�����Ŀ������캯�����ᱻ�������Ż����϶�Ϊһ

//Ҳ����˵����ĳ����ܹ�������2�ο������캯��



//�����Ӿ� �Ż�������

class Widget
{
public:
	Widget()
	{
		//cout << "Widget()" << endl;
	}
	Widget(const Widget&)
	{
		cout << "Widget(const Widget&)" << endl;
	}
	Widget& operator=(const Widget&)
	{
		cout << "Widget& operator=(const Widget&)" << endl;
		return *this;
	}

};


Widget f(Widget u)
{
	return u;
}

int main()
{
	Widget x;
	Widget y;
	y = f(x);
	return 0;
}

















































