#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
using namespace std;


//���ͱ��
// ģ��

//void swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void swap(double& x1, double& x2)
//{
//	double x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	swap(a, b);
//	swap(c, d);
//
//	cout << a <<" "<< b << endl;
//	cout << c <<" "<< d << endl;
//
//	return 0;
//}



//ģ��   ��ģ��    ��  ����ģ��


//����ģ��
//template<class T1,class T2>
//template<class T>    //tmplate<typename T>   ��ģ������б�  --��������
//
//void Swap(T& x1, T& x2)  //���������б�   --��������
//{
//	T x= x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	Swap(a, b);    //ģ��ʵ����  --���ɶ�Ӧ�ĺ���
//	Swap(c, d);
//
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	return 0;
//}



//template<class T>
//
//T Add(const T& x1,const T& x2)
//{
//	return x1 + x2;
//}
//
//
//int main()
//{
//	int a = 10, b = 20;
//	double c = 1.2, d = 2.5;
//
//	cout << Add(a, b) << endl;;
//	cout<<Add(c, d)<<endl;
//
//	//cout<<Add(a,c)<<endl;//û�ж�Ӧ�ĺ���ģ��
//	cout << Add((double)a, c) << endl;  //��aǿת��double����
//
//	//��ʾʵ����
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, d) << endl;
//
//	return 0;
//}



//���庯��
int Add(int& x, int& y)
{
	return x + y;
}


//ģ�庯��
template <class T>

T Add(const T& x, const T& y)
{
	return x + y;
}

int main()
{
	int a = 10, b = 20;
	double c = 1.2, d = 2.5;

	cout << Add(a, b) << endl;;
	cout<<Add(c, d)<<endl;

	return 0;
}

















