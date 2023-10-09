#pragma once
#include<vector>
#include<iostream>
#include<bitset>
using namespace std;

namespace bit
{
	template<size_t N>
	class bit_Set
	{
	public:
		bit_Set()
		{
			_bits.resize(N / 8 + 1, 0);

		}

		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] |= (1 << j);

		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)    //xÔÚ²»ÔÚ
		{
			size_t i = x / 8;
			size_t j = x % 8;

			return _bits[i] & (1 << j);
		}

	private:
		vector<char> _bits;
	};

	void test_set()
	{
		bit_Set<100> bs1;

		bs1.set(8);
		bs1.set(9);
		bs1.set(20);

		cout << bs1.test(8) << endl;
		cout << bs1.test(9) << endl;
		cout << bs1.test(20) << endl;

		bs1.reset(8);
		bs1.reset(9);
		bs1.reset(20);

		cout << bs1.test(8) << endl;
		cout << bs1.test(9) << endl;
		cout << bs1.test(20) << endl;

	}


	template<size_t N>
	class two_bit_set
	{
	public:
		void set(size_t x)
		{
			bool insert1 = _bs1.test(x);
			bool insert2 = _bs2.test(x);
			
			//00
			if (insert1 == false && insert2 == false)
			{
				// 00  -->   01
				_bs2.set(x);
			}

			//01
			else if (insert1 == false && insert2 == true)
			{
				 //01  -->  10
				_bs2.reset(x);
				_bs1.set(x);
			}
		}

		void print_once_num()
		{
			for (size_t i = 0; i < N; i++)
			{
				if (_bs1.test(i) == false && _bs2.test(i) == true)
				{
					cout << i << endl;
				}
			}
		}

	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};

	void test_bit_set3()
	{
		int a[] = { 3,5,1,7,9,45,7,5,4,63,3,1 };
		two_bit_set<100>  bs;
		for (auto e : a)
		{
			bs.set(e);
		}

		bs.print_once_num();

	}
}







































