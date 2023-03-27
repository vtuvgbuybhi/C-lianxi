#define _CRT_SECURE_NO_WARNINGS

//#include<list>
#include<iostream>
#include<algorithm>
using namespace std;

//void test_list1()
//{
//	list<int> it;
//	it.push_back(1);
//	it.push_back(2);
//	it.push_back(3);
//
//	list<int>::iterator It = it.begin();
//	while (It != it.end())
//	{
//		cout << *It << " ";
//		It++;
//	}
//
//	It = it.begin();
//	while (It != it.end())
//	{
//		*It *= 2;
//		It++;
//	}
//	cout << endl;
//
//	for (auto& e : it)
//	{
//		cout << e << " ";
//	}
//}
//
//
//void test_list2()
//{
//	list<int> it;
//	it.push_back(1);
//	it.push_back(2);
//	it.push_back(3);
//
//	auto pos = find(it.begin(), it.end(), 2);
//	if (pos != it.end())
//	{
//		it.insert(pos, 20);
//	}
//
//	for (auto e : it)
//	{
//		cout << e << " ";
//	}
//}
//
//int main()
//{
//	//test_list1();
//	//test_list2();
//
//
//	return 0;
//}



//namespace cdc
//{
//	template<class T>
//	struct list_node
//	{
//		T _data;
//		list_node<T>* _next;
//		list_node<T>* _prev;
//
//		list_node(const T& x=T())
//			:_data(x)
//			,_next(nullptr)
//			,_prev(nullptr)
//		{}
//	};
//
//	template<class T>
//	struct __list_iterator
//	{
//		typedef list_node<T> Node;
//		typedef __list_iterator<T> iterator;
//
//		Node* _node;
//
//		__list_iterator(Node*node)
//			:_node(node)
//		{}
//
//		bool operator!=(const iterator& it)const
//		{
//			return _node != it._node;
//		}
//
//		T& operator*()
//		{
//			return _node->_data;
//		}
//
//		iterator& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//	};
//
//
//	template<class T>
//	class list
//	{
//		typedef list_node<T> Node;
//	public:
//		typedef __list_iterator<T> iterator;
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		list()
//		{
//			_head = new Node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		void push_back(const T& x)
//		{
//			Node* tail = _head->_prev;
//
//			Node* newnode = new Node(x);
//			_head->_prev = newnode;
//			tail->_next = newnode;
//			newnode->_prev = tail;
//			newnode->_next = _head;
//		}
//
//	private:
//		Node* _head;
//	};
//}
//
//
//void test_list1()
//{
//	cdc::list<int> it;
//	it.push_back(1);
//	it.push_back(2);
//	it.push_back(3);
//	it.push_back(4);
//
//	cdc::list<int>::iterator It = it.begin();
//	while (It != it.end())
//	{
//		cout << *It << " ";
//		++It;
//	}
//
//}
//
//int main()
//{
//	test_list1();
//	return 0;
//}





























