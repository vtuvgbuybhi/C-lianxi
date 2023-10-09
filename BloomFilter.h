#pragma once
#include<bitset>

struct HashBKDR
{
	size_t operator()(const string& key)
	{
		//BKDR
		size_t val = 0;
		for (auto ch : key)
		{
			val *= 131;
			val += ch;
		}
		return val;
	}
};

struct HashAP
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		size_t ch;
		for (size_t i = 0; i < key.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ key[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ key[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


struct HashDJB
{
	size_t operator()(const string& key)
	{
		size_t hash = 5318;
		for (auto e : key)
		{
			hash += (hash << 5) + e;
		}
		return hash;
	}
};




//N表示要映射N个值
template<size_t N,class K = string, class Hash1 = HashBKDR, class Hash2 = HashAP , class Hash3 = HashDJB>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t hash1 = Hash1()(key) % (_ratio * N);
		_bits.set(hash1);

		size_t hash2 = Hash2()(key) % (_ratio * N);
		_bits.set(hash2);

		size_t hash3 = Hash3()(key) % (_ratio * N);
		_bits.set(hash3);
	}

	bool Test(const K& key)
	{
		size_t hash1 = Hash1()(key) % (_ratio * N);
		if (!_bits.test(hash1))
			return false;

		size_t hash2 = Hash2()(key) % (_ratio * N);
		if (!_bits.test(hash2))
			return false;

		size_t hash3 = Hash3()(key) % (_ratio * N);
		if (!_bits.test(hash3))
			return false;

		return true;//存在误判
	}


private:
	const static size_t _ratio = 5;
	bitset<_ratio*N> _bits;
};


void TestBloomFilter1()
{
	BloomFilter<10> bf;
	string arr[] = { "梨子","葡萄","香蕉","百度","阿里","字节","苹果","腾讯","字节","苹果" };
	for (auto e : arr)
	{
		bf.Set(e);
	}

	for (auto e : arr)
	{
		cout << bf.Test(e) << endl;
	}

}



























