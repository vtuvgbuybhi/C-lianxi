#pragma once
#include<utility>
#include<iostream>
#include<assert.h>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K , class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _col(RED)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
	{}
};

template<class K ,class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);
			assert(grandfater->_col == BLACK);
			//关键看叔叔
			if (parent == grandfater->_left)
			{
				Node* uncle = grandfater->_right;
				//情况一  ： uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;
					//继续往上处理

					cur = grandfater;
					parent = cur->_parent;
				}
				//情况二+三 ： uncle不存在  + 存在且为黑
				else
				{
					if (cur == parent->_left) // 情况二 ： 单旋＋变色
					{
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					
					else
					{
						//情况三 ：  双旋 + 变色
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}
					break;
				}

			}
			else
			{
				Node* uncle = grandfater->_left;
				//情况一
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;
					//继续往上处理

					cur = grandfater;
					parent = cur->_parent;
				}
				//情况二+三 ： uncle不存在  + 存在且为黑
				else
				{
					if (cur == parent->_right) // 情况二 ： 单旋＋变色
					{
						RotateL(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}

					else
					{
						//情况三 ：  双旋 + 变色
						RotateR(parent);
						RotateL(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}
					break;
				}

			}

		}
		_root->_col = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_col == RED)
		{
			cout << " 违反了根节点不是黑色 " << endl;
			return false;
		}

		//黑色节点数量的基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}
			cur = cur->_left;
		}

		return PrevCheck(_root, 0,benchmark);
	}

private:

	bool PrevCheck(Node* root,int blackNum,int benchmark)
	{
		if (root == nullptr)
		{
			if (blackNum != benchmark)
			{
				cout << "某条黑色节点的数量不相等" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}
		if (root->_col == BLACK)
		{
			++blackNum;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续的红节点" << endl;
			return false;
		}


		return PrevCheck(root->_left, blackNum,benchmark) && PrevCheck(root->_right, blackNum,benchmark);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}

			subR->_parent = ppNode;
		}
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppNode = parent->_parent;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}

		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}


private:
	Node* _root = nullptr;

};



void TestRBTree1()
{
	int a[] = { 4,2,6,1,3,5,15,7,16,14,17,29,27 };
	RBTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
	}
	t1.InOrder();
	cout << "IsBlance: " << t1.IsBalance() << endl;
}







