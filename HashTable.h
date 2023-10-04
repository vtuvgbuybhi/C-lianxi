#pragma once

namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashDate
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto ch : key)
			{
				val *= 131;
				val += ch;
			}
			return val;
		}
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			if (_tables.size() == 0 || _size * 10 / _tables.size() >= 7)  //����
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);
				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);
			}

			Hash hash;

			size_t hashi = hash(kv.first) % _tables.size(); //
			//����̽��
			while (_tables[hashi]._state == EXIST)
			{
				hashi++;
				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;
			return true;
		}

		HashDate<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;

			size_t hashi = hash(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi++;
				hashi %= _tables.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashDate<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;
				return true;
			}
			else
				return false;
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._state == EXIST)
				{
					printf(" [%d : %d]", i, _tables[i]._kv.first);
				}
				else
				{
					printf("[%d : *]", i);
				}
			}
			cout << endl;
		}


	private:
		vector<HashDate<K, V>> _tables;
		size_t _size = 0;    //�洢���ٸ���Ч����
	};

	//void TestHT1()
	//{
	//	int a[] = {1,11,4,15,26,7,44,9};
	//	HashTable<int, int>  ht;
	//	for (auto e : a)
	//	{
	//		ht.Insert(make_pair(e, e));
	//	}
	//
	//	ht.Erase(4);
	//	cout << ht.Find(44)->_kv.first << endl;
	//	cout << ht.Find(4) << endl;
	//
	//	ht.Print();
	//
	//}


	void TestHT2()
	{
		string arr[] = { "ƻ��","�㽶","ƻ��","����","ƻ��","����","����" };
		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			HashDate<string, int>* ptr = countHT.Find(str);
			if (ptr)
			{
				ptr->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}

	}


	void TestHT3()
	{
		HashFunc<string> hash;
		cout << hash("abcd") << endl;
		cout << hash("badc") << endl;
		cout << hash("cbad") << endl;
		cout << hash("eat") << endl;
		cout << hash("aet") << endl;

	}
}


namespace OpenBucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K , class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}



		bool Insert(const pair<K, V>& kv)
		{
			//ȥ��
			if (Find(kv.first))
			{
				return false;
			}

			//����     ���������ӵ�1������
			if (_size == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize, nullptr);

				//�ɱ��нڵ��ƶ�ӳ���±�
				for (size_t i=0 ; i<_tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = cur->_kv.first % newTables.size();
						//ͷ��
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;
						
						cur = next;
						
					} 
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}
			size_t hashi = kv.first % _tables.size();
			//ͷ��
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_size;
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return true;
			}
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					Node* _nextt = cur->_next;

					//ͷɾ
					if (prev == nullptr)
					{
						_tables[hashi] = _nextt;
					}
					//�м�ɾ
					else
					{
						prev->_next = _nextt;
					}
					delete cur;
					_size--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}


	private:
		vector<Node*> _tables;
		size_t _size = 0;  //�洢����Ч����
	};

	void TestHT1()
	{
		int a[] = { 1,11,4,15,26,7,44,55,99,78 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(11);
	}
}









