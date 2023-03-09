#define _CRT_SECURE_NO_WARNINGS

#include<assert.h>
#include<iostream>
using namespace std;


namespace cdc
{
	class string
	{
	public:

		string(const char* str = "")
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
			assert(pos < _size);
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

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}


		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_size + _str, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
				_capacity = n;
			}
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				size_t t = n - _size;
				while (t>0)
				{
					*this += ch;
					t--;
				}
				_size = size();
				_str[_size] = '\0';
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;//能存储有效字符的空间数，不包含'\0'
	};
}


int main()
{
	cdc::string s1("hello");
	s1.resize(2,'w');

	cout << s1.c_str() << endl;

	return 0;
}





//int main()
//{
//	string s1("hello");
//
//	cout << s1 << endl;
//
//	s1.resize(8);
//	cout << s1 << endl;
//
//	return 0;
//}








































