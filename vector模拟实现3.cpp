#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<ostream>
#include<assert.h>
#include<algorithm>
using namespace std;

namespace cdc
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_star(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//一个类模板的成员函数，又可以是一个函数模板
		template<class Inputiterator>
		vector(Inputiterator first, Inputiterator last)
			:_star(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		size_t size() const
		{
			return _finish - _star;
		}

		size_t capacity() const
		{
			return _endofstorage - _star;
		}

		//传统写法
		//vector(const vector<T>& v)
		//{
		//	_star = new T[v.capacity()];
		//	_finish = _star + v.size();
		//	_endofstorage = _star + v.capacity();
		//	memcpy(_star, v._star, sizeof(T) * v.size());
		//}


		void swap(vector<T>& v)
		{
			std::swap(_star, v._star);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}



		//现代写法
		vector(const vector<T>& v)
			:_star(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			//swap(_star, tmp._star);
			//swap(_finish, tmp._finish);
			//swap(_endofstorage, tmp._endofstorage);

			swap(tmp);

		}


		//v1=v2
		vector<T>& operator=(vector<T> v)
		{
			//swap(_star, v._star);
			//swap(_finish, v._finish);
			//swap(_endofstorage, v._endofstorage);

			this->swap(v);

			return *this;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				//扩容
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				//T* tmp = new T[newcapacity];
				//if (_star)
				//{
				//	memcpy(tmp, _star, sizeof(T) * size());
				//	//释放原空间
				//	delete[] _star;
				//}
				//_finish = tmp + size();
				//_star = tmp;
				//_endofstorage = _star + newcapacity;


				//复用
				reserve(newcapacity);

			}
			*_finish = x;
			_finish++;
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _star[i];
		}

		iterator begin()
		{
			return _star;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _star;
		}

		const_iterator end() const
		{
			return _finish;
		}

		//增容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_star)
				{
					memcpy(tmp, _star, sizeof(T) * size());
					delete[] _star;
				}
				_finish = tmp + size();
				_star = tmp;
				_endofstorage = _star + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _star + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _endofstorage)
				{
					_finish = val;
					_finish++;
				}
			}
		}

		void pop_back()
		{
			assert(_finish > _star);
			_finish--;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _star);
			assert(pos <= _finish);
			//满了 扩容
			if (_finish == _endofstorage)
			{
				//扩容会导致pos失效  ，  扩容需要更新一下pos
				size_t len = pos - _star;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _star + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;
			_finish++;
		}

		//void erase(iterator pos)
		//{
		//	assert(pos >= _star);
		//	assert(pos < _finish);

		//	iterator end = pos + 1;
		//	while(end < _finish)
		//	{
		//		*(end - 1) = *end;
		//		end++;
		//	}
		//	_finish--;
		//}

		iterator erase(iterator pos)
		{
			assert(pos >= _star);
			assert(pos < _finish);

			iterator end = pos + 1;
			while (end < _finish)
			{
				*(end - 1) = *end;
				end++;
			}
			_finish--;
			return pos;
		}


		~vector()
		{
			if (_star)
			{
				delete[] _star;
				_star = _finish = _endofstorage = nullptr;
			}
		}

	private:
		iterator _star;
		iterator _finish;
		iterator _endofstorage;
	};
}



void testvector1()
{
	cdc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//cdc::vector<int> v1(v);
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}

	cdc::vector<int> v1;
	v1 = v;

	for (auto e : v1)
	{
		cout << e << " ";
	}
}


void testvector2()
{
	cdc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cdc::vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		// 如果insert中发生扩容，那么会导致it指向的空间被释放
		// it 本质就是一个野指针，这种问题，我们就叫迭代器失效
		v.insert(it, 5);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}

}


void testvector3()
{
	cdc::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);

	//迭代器遍历  + 删除所以的偶数
	cdc::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto e : v1)
	{
		cout << e << " ";
	}

}


int main()
{
	//testvector1();
	//testvector2();
	testvector3();

	return 0;
}










