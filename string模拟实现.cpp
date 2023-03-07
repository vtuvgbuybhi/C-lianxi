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
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//
//	};
//}
//
//
//int main()
//{
//	cdc::string s1("hello");
//  // 浅拷贝
//	//cdc::string s2(s1);//程序崩溃  ---  对同一块空间析构两次
//
//	return 0;
//}




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
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str,s._str);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//
//	};
//}
//
//
//int main()
//{
//	cdc::string s1("hello");
//	cdc::string s2(s1);
//
//	return 0;
//}




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
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//s1=s3
//		//string& operator=(const string& s)
//		//{
//		//	assert(&s);
//		//	if (this != &s)
//		//	{
//		//		delete[] this->_str;
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str,s._str);
//		//	}
//		//	return *this;
//		//}
//
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//
//
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	private:
//		char* _str;
//	};
//}
//
//
//int main()
//{
//	cdc::string s1("hello");
//
//	//深拷贝
//	cdc::string s2(s1);
//	cdc::string s3("root");
//	s1 = s3;
//
//	return 0;
//}





//namespace cdc
//{
//	class string
//	{
//	public:
//
//		string()
//			:_str(new char[1])
//			,_size(0)
//			,_capacity(0)
//		{
//			_str[0] = '\0';
//		}
//
//		string(const char* str)
//			:_size(strlen(str))
//			,_capacity(_size)
//		{
//			_str = new char[_capacity + 1];  //加一为'\0'准备
//			strcpy(_str, str);
//		}
//
//		string(const string& s)
//			:_size(s._size)
//			,_capacity(s._capacity)
//		{
//			char* _str = new char[_capacity + 1];
//			strcpy(_str, s._str);
//		}
//
//		//s1=s3
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[s._capacity + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				this->_size = s._size;
//				this->_capacity = s._capacity;
//				_str = tmp;
//			}
//			return *this;
//		}
//
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//
//int main()
//{
//	cdc::string s1("hello");
//
//	//深拷贝
//	cdc::string s2(s1);
//	cdc::string s3("root");
//	s1 = s3;
//
//	return 0;
//}




//namespace cdc
//{
//	class string
//	{
//	public:
//
//		string(const char* str="")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			_str = new char[_capacity + 1];  //加一为'\0'准备
//			strcpy(_str, str);
//		}
//
//		string(const string& s)
//			:_size(s._size)
//			, _capacity(s._capacity)
//		{
//			char* _str = new char[_capacity + 1];
//			strcpy(_str, s._str);
//		}
//
//		//s1=s3
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[s._capacity + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				this->_size = s._size;
//				this->_capacity = s._capacity;
//				_str = tmp;
//			}
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		const char* C_str() const
//		{
//			return _str;
//		}
//
//		size_t size() const
//		{
//			return _size;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		const char& operator[](size_t pos) const 
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}


//int main()
//{
//	//cdc::string s2;
//
//	cdc::string s1("hello");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//
//
//	return 0;
//}



namespace cdc
{
	class string
	{
	public:

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];  //加一为'\0'准备
			strcpy(_str, str);
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			char* _str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		//s1=s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				this->_size = s._size;
				this->_capacity = s._capacity;
				_str = tmp;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* C_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return  _str+_size;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
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

	return 0;
}





















