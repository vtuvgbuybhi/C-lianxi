#define _CRT_SECURE_NO_WARNINGS

#include<ostream>
#include<iostream>
#include<assert.h>
using namespace std;


namespace cdc
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_star(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		size_t size() const 
		{
			return _finish - _star;
		}

		size_t capacity() const
		{
			return _endofstorage - _star;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				//À©ÈÝ
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[newcapacity];

				if (_star)
				{
					memcpy(tmp, _star, sizeof(T) * size());
					delete[] _star;
				}

				_finish = tmp + size();
				_star = tmp;
				_endofstorage = newcapacity + _star;
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

	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << " ";
	//}

	cdc::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}

}


int main()
{
	testvector1();

	return 0;
}
























































