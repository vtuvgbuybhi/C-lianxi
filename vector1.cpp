#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void testvector1()
{
	//�޲ι���
	vector<int> v1;

	//���ι���
	vector<int> v2(10, 6);

	//����������
	vector<int> v3(v2.begin(), v2.end());

	string s("hello");
	vector<char> v4(s.begin(), s.end());
}

void testvector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//������ʽ1
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i];
	}
	cout << endl;

	//��ʽ��   ������
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;

	//��Χfor
	for (auto e: v1)
	{
		cout << e;
	}
}


void testvector3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//cout << v1.max_size() << endl;

	v1.reserve(100);    //����
	v1.resize(100,8);   //  ���ݼӳ�ʼ��   ��  ɾ������

	v1.resize(50);
}


void testvector4()
{
	vector<int> v1(5, 6);
	
	//assert���Խ��  ����
	//v1[7];
	
	//at   ���쳣
	//v1.at(5);
}


void testvector5()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
	if (ret != v1.end())
	{
		cout << "�ҵ���" << endl;
	}

}





int main()
{
	//testvector1();
	//testvector2();
	//testvector3();
	//testvector4();
	testvector5();

	return 0;
}





















