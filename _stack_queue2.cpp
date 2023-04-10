#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;

//namespace cdc
//{
//	template<class T>
//	class stack
//	{
//	public:
//		void Push_back(const T& x)
//		{
//			_con.push_back(x);
//		}
//		void pop()
//		{
//			_con.pop_back();
//		}
//		T& top()
//		{
//			return _con.back();
//		}
//
//		const T& top() const
//		{
//			return _con.back();
//		}
//
//		bool empty() const
//		{
//			return _con.empty();
//		}
//
//		size_t size() const
//		{
//			return _con.size();
//		}
//
//	private:
//		vector<T> _con;
//	};
//
//}
//
//int main()
//{
//	cdc::stack<int> s;//��ʵ����һ������ջ����
//
//	return 0;
//}




//namespace cdc
//{
//	template<class T,class container=deque<T>>
//	class stack
//	{
//	public:
//		void Push_back(const T& x)
//		{
//			_con.push_back(x);
//		}
//		void pop()
//		{
//			_con.pop_back();
//		}
//		T& top()
//		{
//			return _con.back();
//		}
//
//		const T& top() const 
//		{
//			return _con.back();
//		}
//
//		bool empty() const
//		{
//			return _con.empty();
//		}
//
//		size_t size() const 
//		{
//			return _con.size();
//		}
//
//	private:
//		container _con;//������    -- �ȿ���ʵ��һ������ջ��Ҳ������������ʵ��ջ
//	};
//}


//int main()
//{
//	cdc::stack<int,vector<int>> s;//������
//
//	return 0;
//}



namespace cdc
{
	template<class T, class container = deque<T>>
	class queue
	{
	public:
		void Push_back(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}

		const T& back() const
		{
			return _con.back();
		}

		const T& front() const
		{
			return _con.front();
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
		container _con;//������    -- �ȿ���ʵ��һ������ջ��Ҳ������������ʵ��ջ
	};
}



int main()
{
	cdc::queue<int> q;
	q.Push_back(1);
	q.Push_back(2);
	q.Push_back(3);
	q.Push_back(4);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}


	return 0;
}






































