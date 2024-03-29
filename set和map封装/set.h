#pragma once

#include"RBTree.h"

namespace cdc
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}



		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K,SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.insert(3);
		s.insert(6);
		s.insert(8);
		s.insert(1);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}




