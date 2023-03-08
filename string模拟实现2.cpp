#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<assert.h>

//namespace cdc 
//{
//	class string
//	{
//	public:
//		string(const char* str)
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		//传统写法
//		//string(const string& s)
//		//	:_str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//现代写法
//		string(const string& s) 
//			:_str(nullptr)
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		//传统写法
//		//string& operator=(const string& s)
//		//{
//		//	assert(&s);
//		//	if (this != &s)
//		//	{
//		//		char* tmp = new char[strlen(s._str) + 1];
//		//		delete[] this->_str;
//		//		this->_str = tmp;
//		//		strcpy(tmp, s._str);
//		//	}
//		//	return *this;
//		//}
//
//		//现代 写法
//		//string& operator=(const string& s)
//		//{
//		//	assert(&s);
//		//	if (this != &s)
//		//	{
//		//		string tmp(s);
//		//		swap(_str,tmp._str);
//		//	}
//		//	return *this;
//		//}
//
//		//更简洁
//		//string operator=(string s)
//		//{
//		//	swap(_str, s._str);
//		//	return *this;
//		//}
//
//
//	private:
//		char* _str;
//	};
//}














//namespace cdc
//{
//	class string
//	{
//	public:
//
//		string(char* str)
//			:_size(strlen(str))
//			,_capacity(_size)
//		{
//			char* tmp = new char[_capacity+1];
//			strcpy(tmp, str);
//		}
//
//		void Swap(string& tmp)
//		{
//			swap(_str, tmp._str);
//			swap(_size, tmp._size);
//			swap(_capacity, tmp._capacity);
//		}
//
//
//		//现代写法
//		//string(const string& s)
//		//	:_str(nullptr)
//		//	,_size(0)
//		//	,_capacity(0)
//		//{
//		//	string tmp(s);
//		//	swap(_str, tmp._str);
//		//	swap(_size, tmp._size);
//		//	swap(_capacity, tmp._capacity);
//		//}
//
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s);
//			Swap(tmp);
//		}
//
//		//string& operator=(string s)
//		//{
//		//	assert(&s);
//		//	swap(_str, s._str);
//		//	swap(_size, s._size);
//		//	swap(_capacity, s._capacity);
//		//	return *this;
//		//}
//
//		string& operator=(string s)
//		{
//			assert(&s);
//			Swap(s);
//			return *this;
//		}
//	
//		~string()
//		{
//			delete[] _str;
//			_size = 0;
//			_capacity = 0;
//		}
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;//能存储有效字符的空间数，不包含'\0'
//	};
//}
//
//
//int main()
//{
//	string s1("hello");
//	string s2("world");
//
//	//都可以完成交换
//	s1.swap(s2);       //效率高 -- 仅仅对成员变量进行交换即可 
//	swap(s1, s2);     //  代价很大  -- 三次string的深拷贝，效率低
//
//	return 0;
//}




namespace cdc
{
	class string
	{
	public:

		string(const char* str)
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void Swap(string& tmp)
		{
			swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);
		}


		//现代写法
		//string(const string& s)
		//	:_str(nullptr)
		//	,_size(0)
		//	,_capacity(0)
		//{
		//	string tmp(s);
		//	swap(_str, tmp._str);
		//	swap(_size, tmp._size);
		//	swap(_capacity, tmp._capacity);
		//}

		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s);
			Swap(tmp);
		}

		//string& operator=(string s)
		//{
		//	assert(&s);
		//	swap(_str, s._str);
		//	swap(_size, s._size);
		//	swap(_capacity, s._capacity);
		//	return *this;
		//}

		string& operator=(string s)
		{
			assert(&s);
			Swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos<_size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const 
		{
			return _str + _size;
		}

		char* c_str()
		{
			return _str;
		}


		void push_back();


	private:
		char* _str;
		size_t _size;
		size_t _capacity;//能存储有效字符的空间数，不包含'\0'
	};
}

int main()
{
	cdc::string s1("hello");
	
	cdc::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << s1.c_str() << endl;


	//s1.push_back(' ');
	//s1.push_back('@');
	//s1.append("hello bit");



	return 0;
}
















































