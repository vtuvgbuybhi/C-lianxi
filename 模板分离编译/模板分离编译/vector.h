#define _CRT_SECURE_NO_WARNINGS
#pragma once 

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

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator end = pos + 1;
			while (end < _finish)
			{
				*(end - 1) = *end;
				end--;
			}
			_finish--;
			return pos;
		}


		void reverse(size_t n);
		iterator insert(iterator pos, const T& val);
		void push_back(const T& x);


	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}




















