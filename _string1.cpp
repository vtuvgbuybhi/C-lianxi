#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;



//int main()
//{
//	//构造函数
//	//string();  初始化一个字符串
//	string s1;
//
//	string s2("hello world");
//
//	//string(const string & str);  引用进行初始化
//	string s3(s2);
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	//string(const string & str, size_t pos, size_t len = npos);
//	//           拷贝的字符串      位置         拷贝长度
//	string s4(s3, 2, 5);
//	cout << s4 << endl;
//
//	string s5(s3, 2); //不指定拷贝长度，直接拷贝到"\0"位置
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
//	//求字符串长度
//	//不包含最后作为结尾标识符的\0，有序长度
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//
//	////容量
//	//cout << s1.capacity() << endl;
//
//	//clear  把有效数据清掉
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//
//	return 0;
//}
// 





//operator[]
//char& operator[](size_t pos)   //这里的引用返回不是为了减少拷贝，这里是为了支持修改返回对象
//{
//	return _str[pos];
//}


//int main()
//{
//	string s1("hello wold");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		//本质上  s1.operator[](i)
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;  //修改返回对象
//	}
//	cout << s1 << endl;
//
//
//	return 0;
//}



//at函数和operator[]同样的功能
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


// at  、  []
//检查越界的方式不一样 operator[]: 断言       at : 抛异常


//char& operator[](size_t pos)
//{
//	assert(pos < _size);
//	return _str[pos];
//}

//int main()
//{
//	string s1("hello world");
//	//cout << s1[100] << endl;//断言
//
//	try
//	{
//		s1.at(100);//抛异常
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}



//尾插

int main()
{
	string s1;

	//尾插字符
	s1.push_back('c');
	cout << s1 << endl;

	//尾插字符串
	s1.append("hello");
	cout << s1 << endl;


	s1  += "world";
	cout << s1 << endl;

	return 0;
}

























































