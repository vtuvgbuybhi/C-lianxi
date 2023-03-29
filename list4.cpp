#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
using namespace std;

namespace cdc
{
	template<class T>
	struct __list_Node
	{
		T _data;
		__list_Node<T>* _next;
		__list_Node<T>* _prev;

		__list_Node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	 template<class T,class Ref,class Ptr>
	 struct __list_iterator
	 {
		 typedef __list_Node<int> Node;
		 typedef __list_iterator<T,Ref,Ptr> iterator;
		 Node* _node;

		 __list_iterator(Node* x)
			 :_node(x)
		 {}

		 bool operator!=(const iterator& x)
		 {
			 return _node != x._node;
		 }

		 bool operator==(const iterator& x)
		 {
			 return _node == x._node;
		 }

		 Ref operator*()
		 {
			 return _node->_data;
		 }

		 iterator& operator++()
		 {
			 _node = _node->_next;
			 return *this;
		 }

		 iterator operator++(int)
		 {
			 iterator tmp(*this);
			 _node = _node->_next;
			 return tmp;
		 }

		 iterator& operator--()
		 {
			 _node = _node->_prev;
			 return *this;
		 }

		 iterator operator--(int)
		 {
			 iterator tmp(*this);
			 _node = _node->_prev;
			 return tmp;
		 }

		 Ptr operator->()
		 {
			 return &(operator*());
		 }

	 };



	 template<class T>
	 class list
	 {
		 typedef __list_Node<T> Node;
	 public:

		 typedef __list_iterator<T, T&, T*> iterator;
		 typedef __list_iterator<T, const T&, const T* >const_iterator;

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

		 void Push_back(const T& x)
		 {
			 //Node* prev = _head->_prev;
			 //Node* newnode = new Node(x);

			 //prev->_next = newnode;
			 //newnode->_next = _head;
			 //newnode->_prev = prev;
			 //_head->_prev = newnode;

			 Insert(end(), x);
		 }

		 void Push_front(const T&x)
		 {
			 Insert(begin(), x);
		 }


		 iterator Insert(iterator pos, const T& x)
		 {
			 Node* cur = pos._node;
			 Node* prev = cur->_prev;
			
			 Node* newnode = new Node(x);
			 cur->_prev = newnode;
			 newnode->_next = cur;
			 newnode->_prev = prev;
			 prev->_next = newnode;

			 return iterator(newnode);
		 }

		 iterator erase(iterator pos)
		 {
			 assert(pos != _head);
			 Node* cur = pos._node;
			 Node* prev = cur->_prev;
			 Node* next = cur->_next;

			 prev->_next = next;
			 next->_prev = prev;
			 delete cur;
			 return iterator(next);
		 }

		 void Pop_back()
		 {
			 erase(--end());
		 }

		 void Pop_front()
		 {
			 erase(begin());
		 }

		 void clear()
		 {
			 iterator it = begin();
			 while (it != _head)
			 {
				 it = erase(it);
			 }
		 }

		 void empty_Init()
		 {
			 _head = new Node;
			 _head->_next = _head;
			 _head->_prev = _head;
		 }

		 template<class Inputiterator>
		 list(Inputiterator first, Inputiterator last)
		 {
			 empty_Init();
			 while (first != last)
			 {
				 Push_back(*first);
				 first++;
			 }
		 }

		 void swap(list<T>& x)
		 {
			 std::swap(_head, x._head);
		 }

		 list(const list<T>& x)
		 {
			 empty_Init();
			 list<T> temp(x.begin(), x.end());
			 swap(temp);
		 }




		 ~list()
		 {
			 clear();
			 delete _head;
			 _head = nullptr;
		 }


	 private:
		 Node* _head;
	 };


}

void test_list1()
{
	cdc::list<int> it;
	it.Push_back(1);
	it.Push_back(2);
	it.Push_back(3);
	it.Push_back(4);


	cdc::list<int>::iterator It = it.begin();
	while (It != it.end())
	{
		*It *= 2;
		It++;
	}
	//cout << endl;

	cdc::list<int>::iterator It1 = it.begin();
	while (It1 != it.end())
	{
		cout << *It1 << " ";
		It1++;
	}
}




int main()
{
	test_list1();

	return 0;
}













































































































































































































