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




//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
//ʵ�� MinStack �� :
//
//MinStack() ��ʼ����ջ����
//void push(int val) ��Ԫ��val�����ջ��
//void pop() ɾ����ջ������Ԫ�ء�
//int top() ��ȡ��ջ������Ԫ�ء�
//int getMin() ��ȡ��ջ�е���СԪ��


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





//����
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//1. 0 <= pushV.length == popV.length <= 1000
//2. - 1000 <= pushV[i] <= 1000
//3. pushV ���������־�����ͬ


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
//			//��ջ����ƥ���Ҫ����ƥ�䣬���ܻ��ж��ƥ��
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




//����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��
//
//�������ñ��ʽ������һ����ʾ���ʽֵ��������
//
//ע�⣺
//
//��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
//ÿ����������������󣩶�������һ������������һ�����ʽ��
//��������֮��ĳ������� ����ض� ��
//���ʽ�в����������㡣
//������һ�������沨����ʾ����ʾ���������ʽ��
//�𰸼������м������������ 32 λ ������ʾ��



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
//				//stoi  C++11���ַ���ת������
//				//stoll   ���ַ���ת�ɳ�����
//				st.push(stoll(str));
//			}
//		}
//		return st.top();
//	}
//};




































