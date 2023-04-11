#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void test_priority_queue1()
{
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(6);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top()<<" ";
		pq.pop();
	}

	cout << endl;
	
	int a[] = { 1,5,7,3,7,8,34,5 };
	priority_queue<int> Heap(a, a + sizeof(a) / sizeof(a[0]));
	while (!Heap.empty())
	{
		cout << Heap.top() << " ";
		Heap.pop();
	}
}


void test_priority_queue2()
{
	int a[] = { 34,2,4,6,2,7,4,6,3 };
	priority_queue<int, vector<int>, greater<int>> pq(a,a+sizeof(a)/sizeof(a[0]));
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}


//int main()
//{
//	//test_priority_queue1();
//	//test_priority_queue2();
//	return 0;
//}




//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/xx4gT2
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) 
//	{
//		//建堆 --- O（N）
//		priority_queue<int> maxHeap(nums.begin(), nums.end());
//		while (k--)
//		{
//			maxHeap.pop();
//		}
//		return maxHeap.top();
//	}
//};




//namespace cdc
//{
//	//大堆
//	template<class T,class Container = vector<T>>
//	class priority_queue
//	{
//	public:
//
//		priority_queue()
//		{
//
//		}
//
//
//		template<class InputIterator>
//		priority_queue(InputIterator first, InputIterator last)
//		{
//			while (first != last)
//			{
//				_con.push_back(*first);
//				first++;
//			}
//			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
//			{
//				Adjust_down(i);
//			}
//		}
//
//		void Adjust_up(size_t child)
//		{
//			size_t parent = (child - 1) / 2;
//			while (child>0)
//			{
//				if (_con[child] > _con[parent])
//				{
//					std::swap(_con[child], _con[parent]);
//					child = parent;
//					parent = (child - 1) / 2;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//
//		void push(const T& x)
//		{
//			_con.push_back(x);
//			//向上调整
//			Adjust_up(_con.size()-1);
//		}
//
//		void Adjust_down(size_t parent)
//		{
//			size_t child = parent * 2 + 1;
//			while (child<_con.size())
//			{
//				//选出大孩子
//				if (child + 1 < _con.size() && _con[child + 1] > _con[child])
//				{
//					++child;
//				}
//				if (_con[child] > _con[parent])
//				{
//					std::swap(_con[child], _con[parent]);
//					parent = child;
//					child = parent * 2 + 1;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//
//		void pop()
//		{
//			std::swap(_con[0], _con[_con.size() - 1]);
//			_con.pop_back();
//			Adjust_down(0);
//		}
//
//		const T& top()
//		{
//			return _con[0];
//		}
//
//		size_t size() const
//		{
//			return _con.size();
//		}
//
//		bool empty()
//		{
//			return _con.empty();
//		}
//
//
//	private:
//		Container _con;
//	};
//
//}


//void test_priority_queue3()
//{
//	cdc::priority_queue<int> Heap;
//	Heap.push(1);
//	Heap.push(5);
//	Heap.push(3);
//	Heap.push(9);
//	Heap.push(7);
//
//	while (!Heap.empty())
//	{
//		cout << Heap.top() << " ";
//		Heap.pop();
//	}
//
//}
//
//
//void test_priority_queue4()
//{
//	int a[] = { 4,2,67,5,4,7,4,3,5,32 };
//	cdc::priority_queue<int> heap(a, a + sizeof(a) / sizeof(a[0]));
//
//	while (!heap.empty())
//	{
//		cout << heap.top() << " ";
//		heap.pop();
//	}
//}



//int main()
//{
//	//test_priority_queue3();
//	//test_priority_queue4();
//	return 0;
//}



//仿函数/ 函数对象    --类，重载operator()
//类对象可以像函数一样去使用

//namespace cdc1
//{
//	//class less
//	//{
//	//public:
//	//	bool operator()(const int& l, const int& r) const
//	//	{
//	//		return l < r;
//	//	}
//	//};
//
//	template<class T>
//	class less
//	{
//	public:
//		bool operator()(const T& l, const T& r) const
//		{
//			return l < r;
//		}
//	};
//
//	template<class T>
//	class greater
//	{
//	public:
//		bool operator()(const T& l, const T& r) const
//		{
//			return l > r;
//		}
//	};
//
//}

//int main()
//{
//	cdc1::less IsFunc;
//	cout << IsFunc(1, 2) << endl;
//	//等价于下面
//	cout << IsFunc.operator()(1, 2) << endl;
//
//	return 0;
//}



//int main()
//{
//	cdc1::less<int> IsFunc;
//	cout << IsFunc(1, 2) << endl;
//
//	cdc1::greater<int>  gtFunc;
//	cout << gtFunc(2, 3) << endl;
//
//
//	return 0;
//}



namespace cdc
{
	//大堆
	template<class T, class Container = vector<T>,class Compare=std::less<T>>
	class priority_queue
	{
	public:

		priority_queue()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				first++;
			}
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				Adjust_down(i);
			}
		}

		void Adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				//if(_con[parent]<_con[child])
				if(com(_con[parent],_con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			//向上调整
			Adjust_up(_con.size() - 1);
		}

		void Adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//选出大孩子
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				//if(child+1<_con.size()&&_con[child]<_con[child+1])
				if(child+1<_con.size()&&com(_con[child],_con[child+1]))
				{
					++child;
				}
				//if (_con[child] > _con[parent])
				//if(_con[parent]<_con[child])
				if(com(_con[parent],_con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}


	private:
		Container _con;
	};

}



void test_priority_queue4()
{
	int a[] = { 4,2,67,5,4,7,4,3,5,32 };
	cdc::priority_queue<int,vector<int>,greater<int>> heap(a, a + sizeof(a) / sizeof(a[0]));

	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
}

int main()
{
	test_priority_queue4();

	return 0;
}
























