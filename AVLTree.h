#pragma once
#define _CRT_SECURE_NO_WARNINGS

template<class K , class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	int _bf; //平衡因子

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		,_bf(0)
	{}

};

template<class K , class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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
			else if(cur->_kv.first > kv.first)
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
		if (parent->kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		
		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				break;
			}

			else if(abs(parent->_bf) == 1)
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//说明parent所在的子树已经不平衡了，需要旋转

				//左单旋
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//右单旋
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}

				//左右双旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}

				//右左双旋
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}

				else
				{
					assert(false);
				}

				break;

			}
			else
			{
				//走到这，说明这棵树在插入新节点之前就已经有问题了
				assert(false);
			}
		}
		return true;
	}
private:
	//左单旋
	RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		
		parent->_right = subRL;
		if (subRL == nullptr)
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
			if (ppNode->_left == _parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		
		subL->_bf = parent->_bf = 0;
	}

	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_parent = -1;
		}
		else if ( bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
		subLR->_bf = 0;
	}

	//右左双旋
	RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = parent->_left;

		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = -1;
			parent->_bf = 0;
		}
		else
		{
			subR->_bf = 0;
			parent->_bf = 0;
		}
		subRL->_bf = 0;
	}


private:
	Node* _root;

};


void TestAVLTree()
{
	int a[] = { 16 , 3,7,11,9,26,18,14,15 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		//t1.insert(make_pair(e, e));
	}


}



































