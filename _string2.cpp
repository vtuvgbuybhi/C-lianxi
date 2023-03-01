#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>
using namespace std;



//给你一个字符串 s ，根据下述规则反转字符串：
//所有非英文字母保留在原有位置。
//所有英文字母（小写或大写）位置反转。
//返回反转后的 s 。

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



//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1

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
//	//遍历
//	//方式一
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
//	//方式二
//
//	//迭代器
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	
//	//方式三
//	// auto 自动推导类型
//	//范围for  语法糖  自动往后迭代，自动判断结束(每个字符赋值给给e)
//	for (auto& e : s1)  //引用 需要修改每个字符  ，e是每个字符的别名
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
//	//反向迭代器
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


//迭代器的意义：
//对于string ，无论是正着遍历，倒着遍历，下标+[] 都足够好用，为什么还要迭代器呢
//对于string，下标+[]就足够好用，确实可以不用迭代器
//但是如果是其它容器（数据结构）呢 ？   list 、map\set  链表、二叉树是不支持  下标+[]遍历的
//所有容器都可以使用迭代器这种方式访问修改



//string 增容  capacity

//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "capaacity ：" << sz << endl;
//	cout << "making s grow ：\n";
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



//reverse   逆置
//reserve   保留


//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//
//	//每次增容都要付出代价
//	//我已经知道要多少空间了，我们可以用reserve 请求空间，一次性开好，减少增容
//	s.reserve(100);  //申请至少能存储100个数据的空间
//
//	cout << "capaacity ：" << sz << endl;
//	cout << "making s grow ：\n";
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
//	s.reserve(100);   //只开空间，影响容量
//	s1.resize(100);  //不仅仅开空间，还进行了初始化(默认初始化成"\0")
//
//	s2.resize(100, 'c');//给一个指定的值
//
//	return 0;
//}



//打印字符串

//int main()
//{
//	string s1("hello world");
//
//	//都能打印
//	cout << s1 << endl;       //调用 operator<< 流插入重载
//
//	//const charT* c_str() const;
//	cout << s1.c_str() << endl;  //调用字符串打印
//
//	//使用c_str的场景
//	string file("test.txt");
//	FILE* fout = fopen(file.c_str(), "w");
//
//
//
//	return 0;
//}



//查
//int main()
//{
//	string file("test.txt");
//
//	//要求你取出文件的后缀名
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

	//要求取出文件后缀名 .zip
	size_t pos = file.rfind(".");
	if (pos != string::npos)
	{
		string suffix = file.substr(pos, file.size() - pos);
		cout << suffix << endl;
	}

	return 0;
}











