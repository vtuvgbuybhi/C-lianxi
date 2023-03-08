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
//		//��ͳд��
//		//string(const string& s)
//		//	:_str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//�ִ�д��
//		string(const string& s) 
//			:_str(nullptr)
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		//��ͳд��
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
//		//�ִ� д��
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
//		//�����
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
//		//�ִ�д��
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
//		size_t _capacity;//�ܴ洢��Ч�ַ��Ŀռ�����������'\0'
//	};
//}
//
//
//int main()
//{
//	string s1("hello");
//	string s2("world");
//
//	//��������ɽ���
//	s1.swap(s2);       //Ч�ʸ� -- �����Գ�Ա�������н������� 
//	swap(s1, s2);     //  ���ۺܴ�  -- ����string�������Ч�ʵ�
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


		//�ִ�д��
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

		//������
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
		size_t _capacity;//�ܴ洢��Ч�ַ��Ŀռ�����������'\0'
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
















































