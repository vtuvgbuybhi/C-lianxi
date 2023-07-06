#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//	K _key;
//
//	BSTreeNode(const K& key)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _key(key)
//	{}
//};
//
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)   
//		{
//			if (cur->_key < key){
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key){
//				parent = cur;
//				cur = cur->_left;
//			}
//			else{
//				return false;
//			}
//		}
//		cur = new Node(key);
//		if (parent->_key < key) {
//			parent->_right = cur;
//		}
//		else {
//			parent->_left = cur;
//		}
//		return true;
//	}
//
//	bool InsertR(const K& key)
//	{
//		return _InsertR(_root, key);
//	}
//
//
//	bool Find(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			return false;
//		}
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_left;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	bool FindR(const K& key)
//	{
//		return _FindR(_root, key);
//	}
//
//
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				找到了  开始删除
//				if(cur->_left == nullptr)  //左为空
//				{
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//					delete cur;
//					cur = nullptr;
//				}
//				else if (cur->_right == nullptr)   //右为空
//				{
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//					delete cur;
//					cur = nullptr;
//				}
//				else//左右都不为空
//				{
//					Node* minParent = cur;
//					Node* min = cur->_right;
//					while (min->_left)
//					{
//						minParent = min;
//						min = min->_left;
//					}
//					swap(cur->_key, min->_key);
//					if (minParent->_left == min)
//					{
//						minParent->_left = min->_right;
//					}
//					else
//					{
//						minParent->_right = min->_right;
//					}
//					delete min;
//					min = nullptr;
//				}
//				return true;
//			}
//		}
//		return false;
//	}
//
//	bool EraseR(const K& key)
//	{
//		return _EraseR(_root,key);
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	~BSTree()
//	{
//		_Destory(_root);
//	}
//
//	BSTree()
//	{}
//	c++11的用法，强制编译器生成默认的拷贝构造
//	BSTree() = default;
//
//	BSTree(const BSTree<K>& t)
//	{
//		_root = _Copy(t._root);
//	}
//
//	 t2  =   t1
//	BSTree<K>& operator=(BSTree<K> t)
//	{
//		swap(_root, t._root);
//		return *this;
//	}
//
//private:
//	Node* _root = nullptr;
//
//	Node* _Copy(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return nullptr;
//		}
//		Node* copyRoot = new Node(root->_key);
//		copyRoot->_left = _Copy(root->_left);
//		copyRoot->_right = _Copy(root->_right);
//		return copyRoot;
//	}
//
//	void _Destory(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		_Destory(root->_left);
//		_Destory(root->_right);
//		delete root;
//		root = nullptr;
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr) {
//			return;
//		}
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//
//	bool _FindR(Node* root, const K& key)
//	{
//		if (root == nullptr)
//		{
//			return false;
//		}
//		if (root->_key < key)
//		{
//			return _FindR(root->_right, key);
//		}
//		else if(root->_key > key)
//		{
//			return _FindR(root->_left, key);
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//	bool _InsertR(Node* &root, const K& key)
//	{
//		if (root == nullptr)
//		{
//			root = new Node(key);
//			return true;
//		}
//		if (root->_key < key)
//		{
//			return _InsertR(root->_right, key);
//		}
//		else if (root->_key > key)
//		{
//			return _InsertR(root->_left, key);
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool _EraseR(Node* &root, const K& key)
//	{
//		if (root == nullptr)
//		{
//			return false;
//		}
//		if (root->_key < key)
//		{
//			return _EraseR(root->_right, key);
//		}
//		else if (root->_key > key)
//		{
//			return _EraseR(root->_left, key);
//		}
//		else
//		{
//			Node* del = root;
//			if (root->_left == nullptr)
//			{
//				root = root->_right;
//			}
//			else if (root->_right == nullptr)
//			{
//				root = root->_left;
//			}
//			else
//			{
//				Node* min = root->_right;
//				while (min->_left)
//				{
//					min = min->_left;
//				}
//				swap(root->_key, min->_key);
//				return _EraseR(key);
//				return _EraseR(root->_right, key);
//			}
//			delete del;
//			del = nullptr;
//			return true;
//		}
//	}
//};


//void TestBSTree1()
//{
//	BSTree<int> t;
//	int a[] = { 8,3,3,1,10,6,4,7,14,13 };
//	for (auto e : a) {
//		t.Insert(e);
//	}
//	t.InOrder();
//}
//
//void TestBSTree2()
//{
//	BSTree<int> t;
//	int a[] = { 8,3,1,10,6,4,7,14,13 };
//	for (auto e : a) {
//		t.Insert(e);
//	}
//	t.InOrder();
//	for (auto e : a)
//	{
//		t.Erase(e); 
//		t.InOrder();
//	}
//	//t.Erase(1);
//	//t.InOrder();
//	//t.Erase(8);
//	//t.InOrder();
//}

//void TestBSTree3()
//{
//	BSTree<int> t;
//	int a[] = { 8,3,3,1,10,6,4,7,14,13 };
//	for (auto e : a) {
//		t.InsertR(e);
//	}
//	//t.InOrder();
//	//BSTree<int> copy = t;
//	//copy.InOrder();
//	//t.InOrder();
//
//	BSTree<int> t1;
//
//	t1 = t;
//
//}





template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		,_value(value)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	bool Insert(const K& key,const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(key,value);
		if (parent->_key < key) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_left;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		//.....
		return  true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;

	void _InOrder(Node* root)
	{
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;;
		_InOrder(root->_right);
	}
};


void TestBSTree1()
{
	BSTree<string, string> dict;
	dict.Insert("sort", "排序");
	dict.Insert("left", "左边");
	dict.Insert("right", "右边");
	dict.Insert("string", "字符串");
	dict.Insert("insert", "插入");
	string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << str << "对应的中文是:" << ret->_value << endl;
		}
		else
		{
			cout << "-->无此单词" << endl;
		}
	}
}


void TestBSTree2()
{
	string arr[] = { "苹果","香蕉","苹果","草莓","苹果","香蕉","草莓" };
	BSTree<string, int> countTree;
	for (auto str : arr)
	{
		auto ret = countTree.Find(str);
		if (ret)
		{
			ret->_value++;
		}
		else
		{
			countTree.Insert(str, 1);
		}
	}
	countTree.InOrder();

}
















