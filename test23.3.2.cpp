#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>
using namespace std;



//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//
//	string s2(s1, 6);
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//	
//	cout << s1.capacity() << endl;
//
//	return 0;
//}



//int main()
//{
//	string s1;
//	string s2("hello");
//	cout << s1.empty() << endl;
//	cout << s2.empty() << endl;
//
//	return 0;
//}



//char& operator[](size_t pos)
//{
//	return _str[pos];  //底层是一个字符串数组
//}



//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;
//	}
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1.at(i) << " ";
//	}
//	cout << endl;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1.at(i) += 1;
//	}
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1.at(i) << " ";
//	}
//	cout << endl;
//
//	return 0;
//}



//char& operator[](size_t pos)
//{
//	assert(pos < _size);
//	return _str[pos];
//}


//int main()
//{
//	string s1("hello");
//	try
//	{
//		cout << s1.at(100) << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}



//int main()
//{
//	string s1("hello");
//
//	cout << s1.back() << endl;
//	cout << s1.front() << endl;
//
//	return 0;
//}


//int main()
//{
//	string s;
//
//	s.push_back('a');
//	s.append("kkkkk");
//	cout << s << endl;
//
//	return 0;
//}



//int main()
//{
//	string s1;
//	string s2("kkk");
//	
//	s1 += "aaa";
//	s1 += 'b';
//
//	s1 += s2;
//
//	cout << s1 << endl;
//
//	return 0;
//}




//int main()
//{
//	string s1("hello");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	return 0;
//}



//int main()
//{
//	string s1("hello");
//	string::iterator it = s1.begin();
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		*it -= 1;
//		it++;
//	}
//	it = s1.begin();
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	for (auto& e : s1)
//	{
//		e += 1;
//	}
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}




//int main()
//{
//	string s1("hello");
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	return 0;
//}


//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "begin capacity: " << sz << endl;
//	cout << "making s grow : \n";
//	for (int i = 0; i < 100; i++)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//
//	return 0;
//}



//int main()
//{
//	string s;
//	size_t sz = s.capacity();
//	s.reserve(100);
//	cout << "begin capacity: " << sz << endl;
//	cout << "making s grow : \n";
//	for (int i = 0; i < 100; i++)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//
//	return 0;
//}




int main()
{
	string s1;
	s1.reserve(100);

	string s2;
	s2.resize(100,'c');

	return 0;
}












