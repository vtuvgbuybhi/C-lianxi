#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//void test_stack()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//
//void test_queue()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//}
//
//
//
//int main()
//{
//	test_stack();
//	test_queue();
//
//	return 0;
//}




//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//实现 MinStack 类 :
//
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素


class MinStack {
public:
	MinStack() 
	{

	}

	void push(int val) 
	{
		_st.push(val);

		if (_minist.empty() || val <= _minist.top())
		{
			_minist.push(val);
		}
	}

	void pop() 
	{
		if (_minist.top() == _st.top())
		{
			_minist.top();
		}
		_st.pop();
	}

	int top() 
	{
		return _st.top();
	}

	int getMin() 
	{
		return _minist.top();
	}

private:

	stack<int> _st;
	stack<int> _minist;

};





//描述
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//1. 0 <= pushV.length == popV.length <= 1000
//2. - 1000 <= pushV[i] <= 1000
//3. pushV 的所有数字均不相同


//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
//	{
//		int length = pushV.size();
//		int k = 0;
//		int j = 0;
//		while (k < length)
//		{
//			pushv.push(pushV[k]);
//			if (pushv.top() == popV[j])
//			{
//				while (pushv.size() > 0 && j < length && pushv.top() == popV[j])
//				{
//					pushv.pop();
//					j++;
//				}
//				k++;
//			}
//			else
//			{
//				k++;
//			}
//		}
//		return pushv.empty();
//	}
//
//private:
//	stack<int> pushv;
//};



//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
//	{
//		stack<int> st;
//		int popi = 0;
//
//		for (auto pushVal : pushV)
//		{
//			st.push(pushVal);
//
//			//出栈序列匹配后要持续匹配，可能会有多个匹配
//			while (!st.empty()&&popV[popi] == st.top())
//			{
//				popi++;
//				st.pop();
//			}
//		}
//		//return !st.empty();
//		return popi == pushV.size();
//	}
//};




//给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
//
//请你计算该表达式。返回一个表示表达式值的整数。
//
//注意：
//
//有效的算符为 '+'、'-'、'*' 和 '/' 。
//每个操作数（运算对象）都可以是一个整数或者另一个表达式。
//两个整数之间的除法总是 向零截断 。
//表达式中不含除零运算。
//输入是一个根据逆波兰表示法表示的算术表达式。
//答案及所有中间计算结果可以用 32 位 整数表示。



//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) 
//	{
//		stack<int> st;
//		for (auto& str : tokens)
//		{
//			if (str == "+" || str =="-" || str == "*" || str == "/")
//			{
//				long long right = st.top();
//				st.pop();
//				long long left = st.top();
//				st.pop();
//				switch (str[0])
//				{
//				case '+':
//					st.push(right + left);
//					break;
//				case '-':
//					st.push(left - right);
//					break;
//				case '*':
//					st.push(left * right);
//					break;
//				case '/':
//					st.push(left / right);
//					break;
//				}
//			}
//			else
//			{
//				//stoi  C++11将字符串转成整形
//				//stoll   将字符串转成长整形
//				st.push(stoll(str));
//			}
//		}
//		return st.top();
//	}
//};




































