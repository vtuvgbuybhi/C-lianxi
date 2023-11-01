#pragma once
#include<vector>
#include<map>


//template<class T>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const T* a, size_t n)
//	{
//		for (size_t i = 0; i < n; i++)
//		{
//			_a.push_back(a[i]);
//			_IndexMap[a[i]] = i;
//		}
//	}
//
//private:
//	vector<T> _a;                       //编号找人
//	map<T, int> _IndexMap;              //人找编号
//};



class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n,-1)
	{}

	//合并
	void Union(int x1 , int x2)
	{
		int Parent1 = FindRoot(x1);
		int Parent2 = FindRoot(x2);
		
		//在一个集合就没必要合并了
		if (Parent1 == Parent2)
		{
			return;
		}

		//控制数量少的往数量大的合并
		if (abs(_ufs[Parent1]) < abs(_ufs[Parent2]))
		{
			swap(Parent1, Parent2);
		}

		//合并
		_ufs[Parent1] +=  _ufs[Parent2];
		_ufs[Parent2] = Parent1;
	}

	//找根
	int FindRoot(int x)
	{
		int root = x;
		while (_ufs[root] >=0)
		{
			root = _ufs[root];
		}

		//路径压缩
		while (_ufs[x] >= 0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;
			x = parent;
		}

		return root;
	}

	//是否在同一个集合
	bool IsInSet(int x1, int x2)
	{
		int Parent1 = FindRoot(x1);
		int Parent2 = FindRoot(x2);

		return (Parent1 == Parent2);
	}

	//求有多少个集合
	int SetSize()
	{
		int n = 0;
		for (int i = 0; i < _ufs.size(); i++)
		{
			if (_ufs[i] < 0)
				n++;
		}
		return n;
	}

private:
	vector<int> _ufs;
};

void Test_UnionFindSet()
{
	UnionFindSet ufs(10);
	ufs.Union(8, 9);
	ufs.Union(7, 8);
	ufs.Union(6, 7);
	ufs.Union(5, 6);
	ufs.Union(4, 5);

}
















