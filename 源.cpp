#define _CRT_SECURE_NO_WARNINGS



//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string.h>
//
//const int N = 15;
//int t, n;
////t  测试数据的组数
////n  飞机的数量
//
//bool flag, visit[N];
////visit数组用于判断每架飞机是否都访问过
////flag   判断本次所有飞机能否安全降落
//
//struct p
//{
//    int Ti, Di, Li;
//};
//
//
//void dfs(int cnt, int last, vector<p> v)
//{
//    if (!cnt)
//    {
//        flag = true;
//        return;
//    }
//
//    for (size_t j = 0 ; j < 3; j++)
//    {
//        if (!visit[j] && v[j].Ti + v[j].Di >= last)
//        {
//            visit[j] = true;
//            dfs(cnt - 1, max(last, v[j].Ti) + v[j].Li, v);
//            visit[j] = false;
//        }
//    }
//}
//
//
//int main()
//{
//    memset(visit, false, sizeof(visit));
//    vector<p> v(N);
//    v[0].Ti = 0;
//    v[0].Di = 10;
//    v[0].Li = 20;
//
//    v[1].Ti = 10;
//    v[1].Di = 10;
//    v[1].Li = 20;
//   
//    v[2].Ti = 20;
//    v[2].Di = 10;
//    v[2].Li = 20;
//  
//
//
//    flag = false;
//    dfs(3, 0, v);
//    if (flag)
//    {
//        cout << "Yes" << endl;
//    }
//    else
//    {
//        cout << "No" << endl;
//    }
//
//    return 0;
//}





//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> k[10];
//	
//	k[1].push_back(5);
//
//	return 0;
//}







//#include<iostream> 
//#include<queue>
//using namespace std;
//typedef long long LL;
//const int MAX_N = 5e5 + 5;
//int N, K, pre[MAX_N], nxt[MAX_N];
//LL A[MAX_N];
//
//typedef pair<LL, int> PLI;
////#define val first;
////#define pos second;
//priority_queue<PLI> q;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> A[i];
//		pre[i] = i - 1;
//		nxt[i] = i + 1;
//		q.push({ -A[i] , -i });
//	}
//	pre[1] = -1;
//	nxt[N] = -1;
//	while (K--)
//	{
//		PLI now;
//		do
//		{
//			now = q.top();
//			q.pop();
//			now.first = -now.first;
//			now.second = -(now.second);
//		} while (A[now.second] != now.first);
//
//		int PRE = pre[now.second];
//		int NXT = nxt[now.second];
//
//		if (PRE != -1)
//		{
//			A[PRE] += now.first;
//			q.push({ -A[PRE] , -PRE });
//			nxt[PRE] = NXT;
//		}
//
//		if (NXT != -1)
//		{
//			A[NXT] += now.first;
//			q.push({ -A[NXT],-NXT });
//			pre[NXT] = PRE;
//		}
//		A[now.second] = -1;
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (A[i] != -1)
//		{
//			cout << A[i] << " ";
//		}
//	}
//
//	return 0;
//}



//#include<iostream> 
//using namespace std;
//#include<vector> 
//#include<string>
//
//int main()
//{
//	int k;
//	string s;
//	char c1, c2;
//	cin >> k;
//	cin >> s >> c1 >> c2;
//
//	vector<int> sum(s.size());
//	int ans = 0;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (i > 0)
//		{
//			sum[i] = sum[i - 1];
//		}
//		if (s[i] == c1)
//		{
//			sum[i]++;
//		}
//		if (s[i] == c2 && i >= k - 1)
//		{
//			ans = ans + sum[i - k + 1];
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}



//#include<iostream> 
//using namespace std;
//#include<string>
//#define MAX_N 
//char c1, c2;
//int Xc1[MAX_N];
//int Xc2[MAX_N];
//
//int main()
//{
//	string s;
//	int k = 0;
//	cin >> k;
//	cout << endl;
//	cin >> s >> c1 >> c2;
//
//	int h = 0;
//	int z = 0;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (s[i] == c1)
//		{
//			Xc1[h++] = i;
//		}
//		if (s[i] == c2)
//		{
//			Xc2[z++] = i;
//		}
//	}
//
//	int sizelength = 0;
//	for (size_t i = 0; i < h; i++)
//	{
//		for (size_t j = 0; j < z; j++)
//		{
//			if (Xc1[i] - Xc2[j] >= k)
//			{
//				sizelength++;
//			}
//		}
//	}
//
//	cout << sizelength << endl;
//	return 0;
//}






















//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//int x;
//	//cin >> x;
//	//cout << x;
//
//	string s = "hyui";
//	cout << s.size() << endl;
//
//	//string s[2];
//	//s[0] = "hbunihn";
//	//s[1] = "huihuh";
//
//	//printf("%c\n", s[0][1]);
//	return 0;
//}












//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//const int N = 1e5 + 10;
//int L[N], R[N], dp[N];
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (size_t i = 0; i < n; i++)
//    {   
//        string s;
//        cin >> s;
//        L[i] = s[0] - '0';
//        R[i] = s[s.size() - 1] - '0';
//    }
//
//    int res = 0;
//    for (size_t i = 0; i < n; i++)
//    {
//        dp[i] = 1;
//        for (size_t j = 0; j < i; j++)
//        {
//            if (L[i] == R[j])
//            {
//                dp[i] = max(dp[j]+1 , dp[i]);
//                res = max(dp[i], res);
//            }
//        }
//    }
//    return n - res;
//
//    return 0;
//}













//#include <assert.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//typedef char BTDataType;
//typedef struct BTNode
//{
//    BTDataType data;
//    struct BTNode* left;
//    struct BTNode* right;
//
//}BTNode;
//BTNode* buyBtNode(BTDataType x)
//{
//    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
//    if (newNode == NULL)
//    {
//        assert(0);
//        return NULL;
//    }
//    newNode->data = x;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//BTNode* CreatBinaryTree()
//{
//    BTNode* nodeA = buyBtNode('A');
//    BTNode* nodeB = buyBtNode('B');
//    BTNode* nodeC = buyBtNode('C');
//    BTNode* nodeD = buyBtNode('D');
//    BTNode* nodeE = buyBtNode('E');
//    BTNode* nodeH = buyBtNode('H');
//    nodeA->left = nodeB;
//    nodeA->right = nodeD;
//    nodeB->left = nodeC;
//    nodeD->left = nodeE;
//    nodeD->right = nodeH;
//    return nodeA;
//}
//
//
//void Preorder(BTNode* _root)
//{
//    if (_root == nullptr)
//    {
//        return;
//    }
//    cout << _root->data;
//    Preorder(_root->left);
//    Preorder(_root->right);
//}
//
//void Inorder(BTNode* _root)
//{
//    if (_root == nullptr)
//    {
//        return;
//    }
//    Inorder(_root->left);
//    cout << _root->data;
//    Inorder(_root->right);
//}
//
//
//void Postorder(BTNode* _root)
//{
//    if (_root == nullptr)
//    {
//        return;
//    }
//
//    Postorder(_root->left);
//    Postorder(_root->right);
//    cout << _root->data;
//}
//
////求节点总数
//int BTreeCount(BTNode* _root)
//{
//    if (_root==nullptr)
//    {
//        return 0;
//    }
//
//    int left = BTreeCount(_root->left);
//    int right = BTreeCount(_root->right);
//
//    return (left + right + 1);
//}
//
////求叶子数
//int LeafCount(BTNode* _root)
//{
//    if (_root == nullptr)
//    {
//        return 0;
//    }
//    if (_root->right == nullptr && _root->left==nullptr)
//    {
//        return 1;
//    }
//    int left = LeafCount(_root->left);
//    int right = LeafCount(_root->right);
//    return right + left;
//}
//
//
////树的高度
//int BTreeHeigh(BTNode* _root)
//{
//    if (_root == nullptr)
//    {
//        return 0;
//    }
//
//    int left = BTreeHeigh(_root->left);
//    int right = BTreeHeigh(_root->right);
//
//    if (left > right)
//    {
//        return left+1;
//    }
//    else
//    {
//        return right+1;
//    }
//}
//
//
//int main()
//{
//    BTNode* root = CreatBinaryTree();
//    cout << "先序遍历:";
//    Preorder(root);
//    cout << endl;
//    cout << "中序遍历:";
//    Inorder(root);
//    cout << endl;
//    cout << "后续遍历:";
//    Postorder(root);
//
//    cout << endl;
//    cout <<"节点总数:"<<BTreeCount(root) << endl;
//    cout <<"叶子节点树:"<<LeafCount(root) << endl;
//    cout <<"树的高度:"<< BTreeHeigh(root) << endl;
//    return 0;
//}

















