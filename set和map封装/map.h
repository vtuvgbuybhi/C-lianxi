#pragma once

#include "RBTree.h"

namespace cdc
{
	template<class K,class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const pair<K,V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<K, V>,MapKeyOfT> _t;

	};

	void test_map()
	{
		map<int , int> m;
		m.insert(make_pair(1,2));
		m.insert(make_pair(5,2));
		m.insert(make_pair(6,3));

	}


}
