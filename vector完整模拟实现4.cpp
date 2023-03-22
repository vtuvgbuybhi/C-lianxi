#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<ostream>
#include<assert.h>
#include<algorithm>
using namespace std;


namespace cdc
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		template<class Inputiterator>
		vector(Inputiterator first, Inputiterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T>& x)
		{
			std::swap(_start, x._start);
			std::swap(_finish, x._finish);
			std::swap(_endofstorage, x._endofstorage);
		}

		vector(const vector<T>& x)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(x.begin(), x.end());
			swap(tmp);
		}



		vector<T>& operator=(const vector<T> x)
		{
			vector<T> tmp(x.begin(), x.end());
			swap(x);
			return *this;
		}


		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		iterator begin()
		{
			return _start;
		}
		iterator end() 
		{
			return _finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}


		void push_back(const T&x)
		{
			if (_finish == _endofstorage)
			{
				//À©ÈÝ
				reverse(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			_finish++;
		}


		void reverse(size_t n)
		{
			if (n > capacity())
			{
				iterator tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_finish = tmp + size();
				_start = tmp;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T&val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reverse(n);
				}
				while (_finish!=_start+n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}

void testvector1()
{
	cdc::vector<int> v1;
	v1.reverse(5);
}

void testvector2()
{
	cdc::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (auto e : v1)
	{
		cout << e << " ";
	}
}





int main()
{
	//testvector1();
	testvector2();


	return 0;
}























































