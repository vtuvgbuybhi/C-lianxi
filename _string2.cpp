#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>
using namespace std;



//����һ���ַ��� s ��������������ת�ַ�����
//���з�Ӣ����ĸ������ԭ��λ�á�
//����Ӣ����ĸ��Сд���д��λ�÷�ת��
//���ط�ת��� s ��

//class Solution {
//public:
//    bool IsLetter(char s)
//    {
//        if ((s >= 'A' && s <= 'Z')||(s>='a'&&s<='z'))
//        {
//            return true;
//        }
//        return false;
//    }
//
//    string reverseOnlyLetters(string s)
//    {
//        size_t begin = 0;
//        size_t end = s.size()-1;
//        while (begin < end)
//        {
//            while (begin < end && !IsLetter(s[begin]))
//            {
//                begin++;
//            }
//            while (begin < end && !IsLetter(s[end]))
//            {
//                end--;
//            }
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//        return s;
//    }
//};




//int main()
//{
//	char s = 'a';
//	return 0;
//}



//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� - 1

//class Solution {
//public:
//    int firstUniqChar(string s) 
//    {
//        int CountArray[26] = { 0 };
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            CountArray[s[i] - 'a']++;
//        }
//        for (size_t j = 0; j < s.size(); j++)
//        {
//            if (CountArray[s[j] - 'a'] == 1)
//            {
//                return j;
//            }
//        }
//        return -1;
//    }
//};






//int main()
//{
//	string s1("hello");
//
//	//����
//	//��ʽһ
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;
//	}
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//��ʽ��
//
//	//������
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	
//	//��ʽ��
//	// auto �Զ��Ƶ�����
//	//��Χfor  �﷨��  �Զ�����������Զ��жϽ���(ÿ���ַ���ֵ����e)
//	for (auto& e : s1)  //���� ��Ҫ�޸�ÿ���ַ�  ��e��ÿ���ַ��ı���
//	{
//		e -= 1;
//	}
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	
//	return 0;
//}



//int main()
//{
//	string s1("hello");
//
//	//���������
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	return 0;
//}


//�����������壺
//����string �����������ű��������ű������±�+[] ���㹻���ã�Ϊʲô��Ҫ��������
//����string���±�+[]���㹻���ã�ȷʵ���Բ��õ�����
//����������������������ݽṹ���� ��   list ��map\set  �����������ǲ�֧��  �±�+[]������
//��������������ʹ�õ��������ַ�ʽ�����޸�



//string ����  capacity

//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "capaacity ��" << sz << endl;
//	cout << "making s grow ��\n";
//	for (int i = 0; i < 100; i++)
//	{
//		//s.push_back('c');
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "acpacity changed : " << sz << endl;
//		}
//	}
//	return 0;
//}



//reverse   ����
//reserve   ����


//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//
//	//ÿ�����ݶ�Ҫ��������
//	//���Ѿ�֪��Ҫ���ٿռ��ˣ����ǿ�����reserve ����ռ䣬һ���Կ��ã���������
//	s.reserve(100);  //���������ܴ洢100�����ݵĿռ�
//
//	cout << "capaacity ��" << sz << endl;
//	cout << "making s grow ��\n";
//	for (int i = 0; i < 100; i++)
//	{
//		//s.push_back('c');
//		s += 'c';    
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "acpacity changed : " << sz << endl;
//		}
//	}
//	return 0;
//}


//
//int main()
//{
//	string s;
//	string s1;
//	string s2;
//
//	s.reserve(100);   //ֻ���ռ䣬Ӱ������
//	s1.resize(100);  //���������ռ䣬�������˳�ʼ��(Ĭ�ϳ�ʼ����"\0")
//
//	s2.resize(100, 'c');//��һ��ָ����ֵ
//
//	return 0;
//}



//��ӡ�ַ���

//int main()
//{
//	string s1("hello world");
//
//	//���ܴ�ӡ
//	cout << s1 << endl;       //���� operator<< ����������
//
//	//const charT* c_str() const;
//	cout << s1.c_str() << endl;  //�����ַ�����ӡ
//
//	//ʹ��c_str�ĳ���
//	string file("test.txt");
//	FILE* fout = fopen(file.c_str(), "w");
//
//
//
//	return 0;
//}



//��
//int main()
//{
//	string file("test.txt");
//
//	//Ҫ����ȡ���ļ��ĺ�׺��
//	//size_type find(charT c, size_type pos = 0) const;
//
//	size_t pos = file.find(".");
//	if (pos != string::npos)
//	{
//		//basic_string substr(size_type pos = 0, size_type len = npos) const;
//		string suffix = file.substr(pos, file.size() - pos);
//		cout << suffix << endl;
//	}
//	return 0;
//}



int main()
{
	string file("test.txt.zip");

	//Ҫ��ȡ���ļ���׺�� .zip
	size_t pos = file.rfind(".");
	if (pos != string::npos)
	{
		string suffix = file.substr(pos, file.size() - pos);
		cout << suffix << endl;
	}

	return 0;
}











