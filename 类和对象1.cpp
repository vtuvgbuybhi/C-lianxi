#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//��������������̵ĳ�����ʶ
//C������������̵ģ���ע���ǹ��̣��������������Ĳ��裬ͨ�����������𲽽������
//C++���������ģ���ע���Ƕ��󣬽�һ������ֳɲ�ͬ�Ķ��󣬿�����֮�佻�����

//struct /class

// C++����C����ṹ����÷�
//ͬʱstruct��C++��Ҳ����������

//struct student
//{
//	char name[20];
//	int age;
//	int id;
//};

//int main()
//{
//	struct student s1;//����C
//
//	student s2;        //�������࣬student������Ҳ������
//
//	//scanf("%s", s1.name);
//	//cout << s1.name  ;
//
//	//�����ǲ�֧�֣�ֱ�Ӹ�ֵ��(�ÿ�������)
//	strcpy(s1.name, "����");
//	s1.age = 11;
//	s1.id = 5;
//
//	strcpy(s2.name, "����");
//	s2.age = 11;
//	s2.id = 5;
//
//	return 0;
//}



//C++����ṹ�岻ͬ���ǳ��˿��Զ�������������Զ��巽��/����
//struct student
//{
//	char _name[20];
//	int _age;
//	int _id;
//
//	//��Ա����//��Ա����
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//
//};
//
//int main()
//{
//	struct student s1;
//	student s2;
//
//	s1.Init("����", 12, 4);
//	s2.Init("����", 78, 99);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}




//class

//��������������� : ��װ  �� �̳�  �� ��̬

//��װ  : 1.���ݺͷ��������������ŵ�һ��������ȥ  2.�����޶���


//               -  public(����)   ��structĬ���ǹ���  -- Ҫ����C��
//              |
//�����޶���  -- -  protected(����)
//              |
//               -  private��˽�У�  classĬ����˽��

class student
{
	char _name[20];
	int _age;
	int _id;

public:
	//��Ա����//��Ա����
	void Init(const char* name, int age, int id)
	{
		strcpy(_name, name);
		_age = age;
		_id = id;
	}

	void Print()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _id << endl;
	}

};

int main()
{
	struct student s1;
	student s2;

	s1.Init("����", 12, 4);
	s2.Init("����", 78, 99);

	s1.Print();
	s2.Print();

	return 0;
}




























