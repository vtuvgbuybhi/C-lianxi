#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
using namespace std;

namespace cdc
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x=T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};


	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;

		Node* _node;

		__list_iterator(Node*node)
			:_node(node)
		{}

		bool operator!=(const iterator& it)const
		{
			return _node != it._node;
		}

		bool operator==(const iterator& it)const
		{
			return _node == it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		//++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//it++
		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//--it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		Ptr operator->()
		{
			return &(operator* ());
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			//Node* tail = _head->_prev;

			//Node* newnode = new Node(x);
			//_head->_prev = newnode;
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_next = cur;
			newnode->_prev = prev;
			cur->_prev = newnode;
			return iterator(newnode);
		}

	private:
		Node* _head;
	};
}


void test_list1()
{
	cdc::list<int> it;
	it.push_back(1);
	it.push_back(2);
	it.push_back(3);
	it.push_back(4);


	it.pop_back();
	it.pop_front();

	cdc::list<int>::iterator It = it.begin();
	while (It != it.end())
	{
		cout << *It << " ";
		++It;
	}
}


void Func(const cdc::list<int>& it)
{
	cdc::list<int>::const_iterator It = it.begin();
	while (It != it.end())
	{
		cout << *It << " ";
		It++;
	}

}


void test_list2()
{
	cdc::list<int> it;
	it.push_back(1);
	it.push_back(2);
	it.push_back(3);
	it.push_back(4);

	Func(it);
}



int main()
{
	//test_list1();
	test_list2();

	return 0;
}



































