#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#include"UnionFindSet.h"
#include"Graph.h"

int main()
{
	//string a[] = { "张三" ,"李四", "狗蛋","王武" };
	//UnionFindSet<string> ufs(a , 4);

	//UnionFindSet ufs(10);

	//TestGraph1();
	
	//Test_UnionFindSet();

	//link_table::TestGraph1();

	//matrix::TestBDFS();

	//matrix::TestGraphMinTree();
	//matrix:: TestGraphMinTree1();


	//matrix::TestGraphDijkstra();

	matrix::TestGrapBellmanFord();

	return 0;
}



