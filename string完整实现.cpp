#define _CRT_SECURE_NO_WARNINGS

#include<assert.h>
#include<string>
#include<iostream>
using namespace std;


namespace cdc
{
	class string
	{
	public:
		string(const char* str="\0")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];  //_capacity是不包括'\0'的，所以我们加1
			strcpy(_str, str);
		}

		//传统写法  -- 深拷贝
		//string(const string& s)
		//	:_size(strlen(s._str))
		//	,_capacity(_size)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}

		void Swap(string& tmp)
		{
			swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);
		}
		//现代写法
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			Swap(tmp);
		}

		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		string& operator=(const string& s)
		{
			string tmp(s);
			Swap(tmp);
			return *this;
		}

		size_t size() const 
		{
			return _size;
		}

		char* c_str() const
		{
			return _str;
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
			return _str + _size;
		}

		typedef const char* const_iterator;
		iterator begin() const 
		{
			return _str;
		}
		iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* str = new char[n + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
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

		string& append(const char* str)
		{
			assert(str);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}
			strcpy(_str+_size, str);
			_size += len;
			return *this;
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
			if (_size >= n)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, ch, n - _size);
				_size = n;
				_str[_size] = '\0';
			}
		}

		size_t find(char ch)
		{
			for (size_t n = 0; n < size(); n++)
			{
				if (_str[n] == ch)
				{
					return n;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t n = 0)
		{
			const char* ptr = strstr(_str + n, str);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - str;
			}
		}

		string& insert(char ch, size_t pos)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}

		string& insert(const char* str, size_t pos)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end >= pos+len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			for (size_t n = 0; n < len; n++)
			{
				_str[n + pos] = str[n];
			}
			_size += len;
			return *this;
		}



	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
}
const size_t cdc::string::npos = -1;

int main()
{
	cdc::string s1("hello");

	//s1.push_back('a');
	//cout << s1.c_str() << endl;
	//s1.append("hello");
	//cout << s1.c_str() << endl;

	s1.insert("wodbhub", 5);
	cout << s1.c_str() << endl;

	return 0;
}



//int main()
//{
//	cdc::string s1("hello");
//	cdc::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	return 0;
//}









//int main()
//{
//	cdc::string s1("bhuvft");
//
//	cdc::string s2;
//
//	s2 = s1;
//
//	for (size_t n = 0; n < s1.size(); n++)
//	{
//		cout << s1[n] << " ";
//
//	}
//	cout << endl;
//	for (size_t n = 0; n < s1.size(); n++)
//	{
//		s1[n]++;
//	}
//	cout << s1.c_str() << endl;
//
//	return 0;
//}










































































