#define _CRT_SECURE_NO_WARNINGS

#include"vector.h"

namespace cdc
{
	template<class T>
	void cdc::vector<T>::push_back(const T& x)
	{
		insret(_finish, x);
	}

	template<class T>
	typename cdc::vector<T>::iterator cdc::vector<T>::insert(typename cdc::vector<T>::iterator pos, const T& val)
	{
		assert(pos >= _start);
		assert(pos <= _finish);
		if (_finish == _endofstorage)
		{
			size_t len = pos - _start;
			reverse(capacity() == 0 ? 4 : capacity() * 2);
			pos = _start + len;
		}

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*end = *end + 1;
			end--;
		}
		*pos = val;
		_finish++;
		return pos;
	}

	template<class T>
	void cdc::vector<T>::reverse(size_t n)
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

	template
	vector<int>;
}















