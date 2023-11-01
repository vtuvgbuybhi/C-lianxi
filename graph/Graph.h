#pragma once
#include<vector>
#include"UnionFindSet.h"
#include<map>
#include<set>
#include<assert.h>
#include<queue>
#include<functional>

namespace matrix
{
	//weight 权值
	template<class V, class W, W MAX_W=INT_MAX, bool Direction = false>
	class graph
	{
		typedef graph<V, W, MAX_W, Direction> Self;

	public:

		//graph() = default;

		//图的创建    --->  1.IO输入   2.图的结构关系写到文件     3.手动添加边

		graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			//把邻接矩阵开出来，并初始化
			_matrix.resize(n);
			for (size_t i = 0; i < _matrix.size(); i++)
			{
				_matrix[i].resize(n, MAX_W);
			}
		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}

			else
			{
				assert(false);
				return -1;
			}
		}

		//添加边
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_matrix[srci][dsti] = w;
			//无向图
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}

		void Print()
		{
			//顶点
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			//横下标
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				//cout << i << " ";
				printf("%4d", i);
			}

			cout << endl;

			for (size_t i = 0; i < _matrix.size(); i++)
			{
				cout << i << " ";   //竖下表
				for (size_t j = 0; j < _matrix[i].size(); j++)
				{
					//cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == MAX_W)
					{
						//cout << "*" << " ";
						printf("%4c", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;
		}

		void BFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);

			//队列
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false);  //标记数组

			q.push(srci);
			visited[srci] = true;

			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				cout << front <<":"<< _vertexs[front] << endl;
				//把front顶点的邻接顶点入队列

				for (size_t i = 0; i < _vertexs.size(); i++)
				{
					if (_matrix[front][i] != MAX_W)
					{
						if (visited[i] == false)   //防止重复入
						{
							q.push(i);
							visited[i] = true;    //入队列我们就标记
						}
					}
				}
				cout << endl;
			}
		}


		void _DFS(size_t srci, vector<bool>& visited)
		{
			cout << srci << ":" << _vertexs[srci] << endl;
			visited[srci] = true;

			//找一个srci相邻的没有访问过的点，去往深度遍历
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				if (_matrix[srci][i] != MAX_W && visited[i] == false)
				{
					_DFS(i, visited);
				}
			}
		}

		void DFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);
			vector<bool> visited(_vertexs.size(), false);
			_DFS(srci, visited);
		}



		struct Edge
		{
			size_t _srci;
			size_t _dsti;

			W _w;
			Edge(size_t srci, size_t dsti, const W& w)
				:_srci(srci)
				, _dsti(dsti)
				, _w(w)
			{}

			bool operator>(const Edge& e) const
			{
				return _w > e._w;
			}

		};


		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			//无向图
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}



		W kruskal(Self& minTree)
		{
			//minTree._vertexs = _vertexs;
			//minTree._indexMap = _indexMap;
			//minTree._matrix.resize(_vertexs.size());
			//for (size_t i = 0; i < _vertexs.size(); i++)
			//{
			//	minTree._matrix[i].resize(_vertexs.size(), MAX_W);
			//}

			priority_queue<Edge, vector<Edge>, greater<Edge>> minque;
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				for (size_t j = 0; j < _vertexs.size(); j++)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						minque.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}

			//从优先级队列当中选出n-1条边
			int size = 0;
			//搞一个并查集
			UnionFindSet ufs(_vertexs.size());

			W totalW = W(); //总的权值

			while (!minque.empty() && size<_vertexs.size()-1)
			{
				Edge min = minque.top();
				minque.pop();

				//判断选出的边在不在一个集合
				if (!ufs.IsInSet(min._srci, min._dsti))
				{
					//不在一个集合
					cout << _vertexs[min._srci] << "-" << _vertexs[min._dsti] <<":"<< min._w << endl;
					minTree._AddEdge(min._srci, min._dsti, min._w);
					ufs.Union(min._srci, min._dsti);
					size++;
					totalW += min._w;
				}
			}
			if (size == _vertexs.size() - 1)
			{
				return totalW;
			}
			else
			{
				return W();
			}
		}


		W Prim(Self& minTree, const V& src)
		{
			//minTree._vertexs = _vertexs;
			//minTree._indexMap = _indexMap;
			//minTree._matrix.resize(_vertexs.size());
			//for (size_t i = 0; i < _vertexs.size(); i++)
			//{
			//	minTree._matrix[i].resize(_vertexs.size(), MAX_W);
			//}


			//起点-->转成下标
			size_t srci = GetVertexIndex(src);

			//set<int> X;
			//set<int> Y;
			//
			//X.insert(srci);
			//for (size_t i = 0; i < _vertexs.size(); i++)
			//{
			//	if (i != srci)
			//	{
			//		Y.insert(i);
			//	}
			//}

			vector<bool> X(_vertexs.size(), false);
			vector<bool> Y(_vertexs.size(), true);
			X[srci] = true;
			Y[srci] = false;

			//从 X->Y集合连接的边里面选出最小的边
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
			//先把srci连接的边添加到队列当中
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				if (_matrix[srci][i] != MAX_W)
				{
					minq.push(Edge(srci, i,_matrix[srci][i]));
				}
			}

			size_t i = 0;
			W totalW = W();
			while (!minq.empty())
			{
				Edge min = minq.top();
				minq.pop();
				
				if (X[min._dsti])
				{
					cout << "构成环的边:";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
				}

				else
				{
					minTree._AddEdge(min._srci, min._dsti, min._w);
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
					++i;
					X[min._dsti] = true;
					Y[min._dsti] = false;
					totalW += min._w;

					if (i == _vertexs.size() - 1)
					{
						break;
					}


					for (size_t i = 0; i < _vertexs.size(); i++)
					{
						if (_matrix[min._dsti][i] != MAX_W && Y[i])
						{
							minq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
						}
					}
				}
			}
			if (i == _vertexs.size() - 1)
			{
				return totalW;
			}
			else
			{
				return W();
			}
		}

		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);

			dist[srci] = 0;
			pPath[srci] = srci;

			//已经确定的最短路径顶点集合
			vector<bool> S(n,false);
			for (size_t j = 0; j < n; j++)   //n个顶点全要去更新
			{
				//去选最短路径的顶点,且这个顶点不在S
				int u = 0;
				W min = MAX_W;
				for (size_t i = 0; i < n; i++)
				{
					if (S[i] == false && dist[i] < min)
					{
						u = i;
						min = dist[i];
					}
				}

				S[u] = true;
				//u最小的顶点--->松弛更新u连接出去的顶点v       srci--> u     u->和u连接的顶点v
				for (size_t v = 0; v < n; v++)
				{
					if (S[v] == false && _matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v])
					{
						//进行更新
						dist[v] = dist[u] + _matrix[u][v];
						pPath[v] = u;
					}
				}
			}
		}


		void PrintShortPath(const V& src,const vector<W>& dist, const vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			for (size_t i = 0; i < n; i++)
			{
				if (i != srci)  //自己到自己就不算了,不打印
				{
					//  找出i顶点的路径
					vector<int> path;
					size_t parent = i;

					while (parent != srci)
					{
						path.push_back(parent);
						parent = pPath[parent];
					}
					path.push_back(srci);//原点没进path
					reverse(path.begin(),path.end());    //逆置

					for (auto index : path)
					{
						cout << _vertexs[index] << "->";
					}
					cout <<"  "<< dist[i] << endl;  //打印这个路径的距离
				}
			}
		}


		//
		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t n = _vertexs.size();
			size_t srci = GetVertexIndex(src);

			dist.resize(n, MAX_W);
			pPath.resize(n, -1);

			//先更新 srci  -->  srci为缺省值
			dist[srci] = W();


			//总体最多更新n轮
			for (size_t k = 0; k < n; k++)
			{
				bool update = false;
				//cout << "更新边" << endl;
				//  i-->j 更新一次
				cout << "更新第：" << k <<"轮"<< endl;
				for (size_t i = 0; i < n; i++)
				{
					for (size_t j = 0; j < n; j++)
					{
						// srci --> i + i->j   < dist[j]   ---更新它
						if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						{
							update = true;
							cout << _vertexs[i] << "->" << _vertexs[j] << ":" << _matrix[i][j] << endl;
							dist[j] = dist[i] + _matrix[i][j];
							pPath[j] = i;
						}
					}
				}

				//如果这个轮次中没有更新出更短的路径 ， 那么后续轮次就不需要在走了
				if (update == false)
				{
					break;
				}

			}

			//理论上更新n轮之后，一般是不能在更新了，要是还能更新，说明带负权回路了
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					// srci --> i + i->j   < dist[j]   ---更新它
					if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
					{
						return false;
					}
				}
			}

			return true;

		}


		void FloydWarshall(vector<vector<W>>& vvdist, vector<vector<int>>* vvpPath)
		{
			size_t n = _vertexs.size();
			vvdist.resize(n);
			vvpPath.resize(n);

			for (size_t i = 0; i < n; i++)
			{
				vvdist[i].resize(n, MAX_W);
				vvpPath[i].resize(n, -1);
			}

			//直接相连的边更新一下
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvdist[i][j] = _matrix[i][j];
						vvpPath[i][j] = i;
					}
					if (i == j)
					{
						vvdist[i][j] = 0;

					}
				}
			}


			//abcdef   a {} f    ||   b {} c
			//最短路径的更新   i  -->  {其它顶点}  -->j
			size_t k =0 ;  //k最为i-->j 中间点尝试去更新 i-->j 的路径
			for (size_t k = 0 ; k < n; k++)
			{
				for (size_t i = 0; i < n; i++)
				{
					for (size_t j = 0; j < n; j++)
					{
						if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W && vvdist[k][j] + vvdist[i][k] < vvdist[i][j])
						{
							vvdist[i][j] = vvdist[k][j] + vvdist[i][k];
							//找跟j相连的上一个邻接顶点
							//如果k-->j 是直接相连的，那么上一个点就是k ，vvpPath[k][j]存的就是k
							//如果k-->j 是不直接相连的，k-->  ..   --> x--> j   , vvpPath[k][j]存的就是x
							vvpPath[i][j] = vvpPath[k][j];
						}
					}
				}
			}
		}



	private:
		vector<V> _vertexs;       //顶点集合
		map<V, int> _indexMap;     //顶点和映射的下标

		vector<vector<W>> _matrix;   //邻接矩阵
	};


	void TestGraph1()
	{
		graph<char, int, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);

		g.Print();
	}


	void TestBDFS()
	{
		string a[] = { "张三","李四","王五","赵六","周七" };
		graph<string, int> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四",100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);

		g1.Print();
		g1.BFS("张三");
	}


	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
		graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('a', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		graph<char, int> kminTree(str,strlen(str));
		cout << "kruskal:" << g.kruskal(kminTree) << endl;
		kminTree.Print();

		cout << endl;

	}


	void TestGraphMinTree1()
	{
		const char* str = "abcdefghi";
		graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('a', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		cout << endl;
		graph<char, int> pminTree(str ,strlen(str));
		cout <<"Prim:" <<  g.Prim(pminTree,'a') << endl;
		pminTree.Print();
	}


	void TestGraphDijkstra()
	{
		const char* str = "syztx";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('y', 't', 3);
		g.AddEdge('y', 'x', 9);
		g.AddEdge('y', 'z', 2);
		g.AddEdge('z', 's', 7);
		g.AddEdge('z', 'x', 6);
		g.AddEdge('t', 'y', 2);
		g.AddEdge('t', 'x', 1);
		g.AddEdge('x', 'z', 4);

		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);
	}


	void TestGrapBellmanFord()
	{
		//const char* str = "syztx";
		//graph<char, int, INT_MAX, true> g(str, strlen(str));
		//g.AddEdge('s', 't', 6);
		//g.AddEdge('s', 'y', 7);
		//g.AddEdge('y', 'z', 9);
		//g.AddEdge('y', 'x', -3);
		//g.AddEdge('z', 's', 2);
		//g.AddEdge('z', 'x', 7);
		//g.AddEdge('t', 'x', 5);
		//g.AddEdge('t', 'y', 8);
		//g.AddEdge('t', 'z', -4);
		//g.AddEdge('x', 't', -2);

		//vector<int> dist;
		//vector<int> pPath;
		//g.BellmanFord('s', dist, pPath);
		//g.PrintShortPath('s', dist, pPath);


		const char* str = "syztx";
		graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('y', 's', 1);    //新增
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', -8);  //修改
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);

		vector<int> dist;
		vector<int> pPath;
		//g.BellmanFord('s', dist, pPath);
		//g.PrintShortPath('s', dist, pPath);

		if (g.BellmanFord('s', dist, pPath))
		{
			g.PrintShortPath('s', dist, pPath);
		}

		else
			cout << "带负权回路" << endl;

	}








}



//namespace link_table
//{
//	template<class W>
//	struct Edge
//	{
//		int _dsti;  //目标点的下标
//		W _w;       //权值
//		Edge<W>* _next;
//
//		Edge(int dsti,const W& w)
//			:_dsti(dsti)
//			,_w(w)
//			,_next(nullptr)
//		{}
//
//	};
//
//	template<class V, class W , bool Direction = false>
//	class graph
//	{
//		typedef Edge<W> Edge;
//	public:
//		//图的创建    --->  1.IO输入   2.图的结构关系写到文件     3.手动添加边
//		graph(const V* a, size_t n)
//		{
//			_vertexs.reserve(n);
//			for (size_t i = 0; i < n; i++)
//			{
//				_vertexs.push_back(a[i]);
//				_indexMap[a[i]] = i;
//			}
//
//			_tables.resize(n,nullptr);
//		}
//
//		size_t GetVertexIndex(const V& v)
//		{
//			auto it = _indexMap.find(v);
//			if (it != _indexMap.end())
//			{
//				return it->second;
//			}
//
//			else
//			{
//				assert(false);
//				return -1;
//			}
//		}
//
//		//添加边
//		void AddEdge(const V& src, const V& dst, const W& w)
//		{
//			size_t srci = GetVertexIndex(src);
//			size_t dsti = GetVertexIndex(dst);
//
//
//			// 1 --> 2
//			Edge* eg = new Edge(dsti, w);  //把边节点new出来
//
//			//头插
//			eg->_next = _tables[srci];
//			_tables[srci] = eg;
//
//			//无向图
//			//   2---> 1
//			if (Direction == false)
//			{
//				Edge* eg = new Edge(srci, w);
//				eg->_next = _tables[dsti];
//				_tables[dsti] = eg;
//			}
//		}
//
//		void Print()
//		{
//			for (size_t i = 0; i < _vertexs.size(); i++)
//			{
//				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
//			}
//			cout << endl;
//
//			for (size_t i = 0; i < _tables.size(); i++)
//			{
//				cout << _vertexs[i] << "[" << i << "]->";
//				Edge* cur = _tables[i];
//				while (cur)
//				{
//					cout << _vertexs[cur->_dsti] << "[" << cur->_dsti << "]" << cur->_w << "->";
//					cur = cur->_next;
//				}
//				cout << "nullptr" << endl;
//			}
//		}
//
//	private:
//		vector<V> _vertexs;       //顶点集合
//		map<V, int> _indexMap;     //顶点和映射的下标
//
//		vector<Edge*> _tables;   //邻接表
//	};
//
//
//	void TestGraph1()
//	{
//		graph<char, int, true> g("0123", 4);
//		g.AddEdge('0', '1', 1);
//		g.AddEdge('0', '3', 4);
//		g.AddEdge('1', '3', 2);
//		g.AddEdge('1', '2', 9);
//		g.AddEdge('2', '3', 8);
//		g.AddEdge('2', '1', 5);
//		g.AddEdge('2', '0', 3);
//		g.AddEdge('3', '2', 6);
//
//		g.Print();
//	}
//
//}


















