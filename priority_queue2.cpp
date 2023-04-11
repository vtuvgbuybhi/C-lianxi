#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;



namespace cdc
{
	template<class T,class Container =vector<T>,class Compare=std::less<T>>
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
			while (child>0)
			{
				//if (_con[child] > _con[parent])
				//if (_con[parent]<_con[child])
				if (com(_con[parent], _con[child]))
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
			Adjust_up(_con.size()-1);
		}

		void Adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child<_con.size())
			{
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child] , _con[child + 1]))
				{
					child++;
				}
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if (com(_con[parent] , _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent *2 +1;
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
			//进行向下调整
			Adjust_down(0);
		}

		const T& top() const 
		{
			return _con[0];
		}

		bool empty() const 
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

	private:
		Container _con;
	};

}


void test_priority_queue1()
{
	cdc::priority_queue<int,vector<int>,greater<int>> heap;
	heap.push(1);
	heap.push(9);
	heap.push(5);
	heap.push(8);

	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
}


int main()
{
	test_priority_queue1();
	return 0;
}



//namespace cdc
//{
//	template<class T>
//	class less
//	{
//	public:
//		bool operator()(const T& x, const T& y)
//		{
//			return x < y;
//		}
//	};
//
//	template<class T>
//	class greater
//	{
//	public:
//		bool opeartor()(const T& x, const T& y)
//		{
//			return x > y;
//		}
//	};
//}
//
//int main()
//{
//	cdc::less<int> Isfunc;
//	cout << Isfunc(1, 2) << endl;
//
//	return 0;
//}












































