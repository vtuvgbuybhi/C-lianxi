#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;



//int main()
//{
//	//���캯��
//	//string();  ��ʼ��һ���ַ���
//	string s1;
//
//	string s2("hello world");
//
//	//string(const string & str);  ���ý��г�ʼ��
//	string s3(s2);
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	//string(const string & str, size_t pos, size_t len = npos);
//	//           �������ַ���      λ��         ��������
//	string s4(s3, 2, 5);
//	cout << s4 << endl;
//
//	string s5(s3, 2); //��ָ���������ȣ�ֱ�ӿ�����"\0"λ��
//	cout << s5 << endl;
//
//	string s6(s3, 2, 100); 
//	cout << s6 << endl;
//
//
//	//string (const char* s, size_t n);
//	string s7("hello world", 2);
//	cout << s7 << endl;
//
//	//string(size_t n, char c);
//	string s8(5, 'c');
//	cout << s8 << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1;
//	cin >> s1;
//
//	//���ַ�������
//	//�����������Ϊ��β��ʶ����\0�����򳤶�
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//
//	////����
//	//cout << s1.capacity() << endl;
//
//	//clear  ����Ч�������
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//
//	return 0;
//}
// 





//operator[]
//char& operator[](size_t pos)   //��������÷��ز���Ϊ�˼��ٿ�����������Ϊ��֧���޸ķ��ض���
//{
//	return _str[pos];
//}


//int main()
//{
//	string s1("hello wold");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		//������  s1.operator[](i)
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;  //�޸ķ��ض���
//	}
//	cout << s1 << endl;
//
//
//	return 0;
//}



//at������operator[]ͬ���Ĺ���
//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1.at(i) << " ";
//	}
//	cout << endl;
//	for (size_t j = 0; j < s1.size(); j++)
//	{
//		s1.at(j) += 1;
//	}
//	//cout << endl;
//	cout << s1 << endl;
//	for (size_t j = 0; j < s1.size(); j++)
//	{
//		s1.at(j) -= 1;
//	}
//	cout << s1 << endl;
//
//	return 0;
//}


// at  ��  []
//���Խ��ķ�ʽ��һ�� operator[]: ����       at : ���쳣


//char& operator[](size_t pos)
//{
//	assert(pos < _size);
//	return _str[pos];
//}

//int main()
//{
//	string s1("hello world");
//	//cout << s1[100] << endl;//����
//
//	try
//	{
//		s1.at(100);//���쳣
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}



//β��

int main()
{
	string s1;

	//β���ַ�
	s1.push_back('c');
	cout << s1 << endl;

	//β���ַ���
	s1.append("hello");
	cout << s1 << endl;


	s1  += "world";
	cout << s1 << endl;

	return 0;
}

























































