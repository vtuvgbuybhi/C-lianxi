#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//
//	return 0;
//}

//����Ƶ�����ú��� ��ҪƵ����������ջ֡�������ģ�

//C������  �ú������  ����������ӵĺ꣩  ����һ���滻
//#define ADD(x,y) ((x)+(y))
//
//int main()
//{
//	cout << ADD(1, 2) << endl;
//
//	return 0;
//}


//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//int main()
//{
//	Add(1, 2);//ֱ�ӽ�Add����չ�����������������ջ֡��
//
//	return 0;
//}

//��������: �ʺ϶̵ĺ���(10������) �����ʺϵݹ麯��(���ٿ���C���Ժ��ʹ��)



//�����﷨��ϰ

//���� ���

//int main()
//{
//	//IO��
//	int i = 0;
//	double d = 1.11;
//
//	//   >>  ����ȡ�����
//	//   <<  �����������
//
//	//�Զ�ʶ����������
//	cin >> i;
//	cin >> d;
//
//	cout << i <<" "<< d << endl;
//
//	return 0;
//}



//using namespace std  //C++�Ŀ⺯�����Ǵ���һ������std�������ռ��� 
//using  ��std�������ռ亯��ȫ��չ��  ��������ʹ��


//չ�����ֳ��õ�  --> ȫ��չ�����ײ���������Ⱦ�����⣩
//using std::cin  //����˼��ֻ��std�е�cin����չ����ʣ�µĺ�����չ��
//using std::cout  



//ȱʡ���� (Ĭ�ϲ���)

//ȫȱʡ

//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func();//ֱ����Ĭ�ϵ�
//	Func(1, 2, 3);//�����Ǵ���
//	return 0;
//}

//��ȱʡ

//��ȱʡ�����������δ����������θ������ܼ����
//ȱʡ���������ں��������Ͷ�����ͬʱ����
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func(2);//ֱ����Ĭ�ϵ�
//	Func(1, 2, 3);//�����Ǵ���
//	return 0;
//}



//��������  (��������ͬ ��������ͬ �������ǲ������͡���������������˳��ͬ��)


//����

//int main()
//{
//	int a = 10;
//	
//	int& b = a;//����
//	int* p = &b;//ȡ��ַ
//
//	return 0;
//}

//���õĵײ�ԭ��

//int main()
//{
//	int a = 10;
//
//	int& b = a;
//
//	cout << sizeof(b) << endl;
//
//	int* p = &a;
//
//	cout << sizeof(p) << endl;
//
//	//���������
//	//int& b = a;
//	//00007FF77A131994  lea         rax, [a]    lea��ȡ��ַ��  ȡa�ĵ�ַ����rax�ļĴ�����
//	//	00007FF77A131998  mov         qword ptr[b], rax    move�ƶ�     ��rax�ϵ�ֵ��a�ĵ�ַ���ƶ���b�������ռ���
//	//	int* p = &a;
//	//00007FF77A13199C  lea         rax, [a]
//	//	00007FF77A1319A0  mov         qword ptr[p], rax
//
//	//�﷨��  : ָ�����������ȫ��ͬ�ĸ���
//	//ָ���ǿ��ռ䣬�洢�����ĵ�ַ
//	//���ò����ռ䣬�����ǶԱ���ȡ����
//
//	//�ײ���ʵ��ʱ: ��������ָ��ʵ�ֵ�
//
//	return 0;
//}



//auto �ؼ���

int main()
{
	int a = 1;
	
	//auto �Զ��Ƶ�����������

	auto c = a;
	auto d = 'A';
	auto e = 10.11;

	//typeid ��ӡ����������
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;

	return 0;
}
























