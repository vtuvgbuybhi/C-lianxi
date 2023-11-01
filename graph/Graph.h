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
	//weight Ȩֵ
	template<class V, class W, W MAX_W=INT_MAX, bool Direction = false>
	class graph
	{
		typedef graph<V, W, MAX_W, Direction> Self;

	public:

		//graph() = default;

		//ͼ�Ĵ���    --->  1.IO����   2.ͼ�Ľṹ��ϵд���ļ�     3.�ֶ���ӱ�

		graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			//���ڽӾ��󿪳���������ʼ��
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

		//��ӱ�
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_matrix[srci][dsti] = w;
			//����ͼ
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}

		void Print()
		{
			//����
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			//���±�
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); i++)
			{
				//cout << i << " ";
				printf("%4d", i);
			}

			cout << endl;

			for (size_t i = 0; i < _matrix.size(); i++)
			{
				cout << i << " ";   //���±�
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

			//����
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false);  //�������

			q.push(srci);
			visited[srci] = true;

			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				cout << front <<":"<< _vertexs[front] << endl;
				//��front������ڽӶ��������

				for (size_t i = 0; i < _vertexs.size(); i++)
				{
					if (_matrix[front][i] != MAX_W)
					{
						if (visited[i] == false)   //��ֹ�ظ���
						{
							q.push(i);
							visited[i] = true;    //��������Ǿͱ��
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

			//��һ��srci���ڵ�û�з��ʹ��ĵ㣬ȥ����ȱ���
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
			//����ͼ
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

			//�����ȼ����е���ѡ��n-1����
			int size = 0;
			//��һ�����鼯
			UnionFindSet ufs(_vertexs.size());

			W totalW = W(); //�ܵ�Ȩֵ

			while (!minque.empty() && size<_vertexs.size()-1)
			{
				Edge min = minque.top();
				minque.pop();

				//�ж�ѡ���ı��ڲ���һ������
				if (!ufs.IsInSet(min._srci, min._dsti))
				{
					//����һ������
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


			//���-->ת���±�
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

			//�� X->Y�������ӵı�����ѡ����С�ı�
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
			//�Ȱ�srci���ӵı���ӵ����е���
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
					cout << "���ɻ��ı�:";
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

			//�Ѿ�ȷ�������·�����㼯��
			vector<bool> S(n,false);
			for (size_t j = 0; j < n; j++)   //n������ȫҪȥ����
			{
				//ȥѡ���·���Ķ���,��������㲻��S
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
				//u��С�Ķ���--->�ɳڸ���u���ӳ�ȥ�Ķ���v       srci--> u     u->��u���ӵĶ���v
				for (size_t v = 0; v < n; v++)
				{
					if (S[v] == false && _matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v])
					{
						//���и���
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
				if (i != srci)  //�Լ����Լ��Ͳ�����,����ӡ
				{
					//  �ҳ�i�����·��
					vector<int> path;
					size_t parent = i;

					while (parent != srci)
					{
						path.push_back(parent);
						parent = pPath[parent];
					}
					path.push_back(srci);//ԭ��û��path
					reverse(path.begin(),path.end());    //����

					for (auto index : path)
					{
						cout << _vertexs[index] << "->";
					}
					cout <<"  "<< dist[i] << endl;  //��ӡ���·���ľ���
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

			//�ȸ��� srci  -->  srciΪȱʡֵ
			dist[srci] = W();


			//����������n��
			for (size_t k = 0; k < n; k++)
			{
				bool update = false;
				//cout << "���±�" << endl;
				//  i-->j ����һ��
				cout << "���µڣ�" << k <<"��"<< endl;
				for (size_t i = 0; i < n; i++)
				{
					for (size_t j = 0; j < n; j++)
					{
						// srci --> i + i->j   < dist[j]   ---������
						if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						{
							update = true;
							cout << _vertexs[i] << "->" << _vertexs[j] << ":" << _matrix[i][j] << endl;
							dist[j] = dist[i] + _matrix[i][j];
							pPath[j] = i;
						}
					}
				}

				//�������ִ���û�и��³����̵�·�� �� ��ô�����ִξͲ���Ҫ������
				if (update == false)
				{
					break;
				}

			}

			//�����ϸ���n��֮��һ���ǲ����ڸ����ˣ�Ҫ�ǻ��ܸ��£�˵������Ȩ��·��
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					// srci --> i + i->j   < dist[j]   ---������
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

			//ֱ�������ı߸���һ��
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
			//���·���ĸ���   i  -->  {��������}  -->j
			size_t k =0 ;  //k��Ϊi-->j �м�㳢��ȥ���� i-->j ��·��
			for (size_t k = 0 ; k < n; k++)
			{
				for (size_t i = 0; i < n; i++)
				{
					for (size_t j = 0; j < n; j++)
					{
						if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W && vvdist[k][j] + vvdist[i][k] < vvdist[i][j])
						{
							vvdist[i][j] = vvdist[k][j] + vvdist[i][k];
							//�Ҹ�j��������һ���ڽӶ���
							//���k-->j ��ֱ�������ģ���ô��һ�������k ��vvpPath[k][j]��ľ���k
							//���k-->j �ǲ�ֱ�������ģ�k-->  ..   --> x--> j   , vvpPath[k][j]��ľ���x
							vvpPath[i][j] = vvpPath[k][j];
						}
					}
				}
			}
		}



	private:
		vector<V> _vertexs;       //���㼯��
		map<V, int> _indexMap;     //�����ӳ����±�

		vector<vector<W>> _matrix;   //�ڽӾ���
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
		string a[] = { "����","����","����","����","����" };
		graph<string, int> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("����", "����",100);
		g1.AddEdge("����", "����", 200);
		g1.AddEdge("����", "����", 30);
		g1.AddEdge("����", "����", 30);

		g1.Print();
		g1.BFS("����");
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
		g.AddEdge('y', 's', 1);    //����
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', -8);  //�޸�
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
			cout << "����Ȩ��·" << endl;

	}








}



//namespace link_table
//{
//	template<class W>
//	struct Edge
//	{
//		int _dsti;  //Ŀ�����±�
//		W _w;       //Ȩֵ
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
//		//ͼ�Ĵ���    --->  1.IO����   2.ͼ�Ľṹ��ϵд���ļ�     3.�ֶ���ӱ�
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
//		//��ӱ�
//		void AddEdge(const V& src, const V& dst, const W& w)
//		{
//			size_t srci = GetVertexIndex(src);
//			size_t dsti = GetVertexIndex(dst);
//
//
//			// 1 --> 2
//			Edge* eg = new Edge(dsti, w);  //�ѱ߽ڵ�new����
//
//			//ͷ��
//			eg->_next = _tables[srci];
//			_tables[srci] = eg;
//
//			//����ͼ
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
//		vector<V> _vertexs;       //���㼯��
//		map<V, int> _indexMap;     //�����ӳ����±�
//
//		vector<Edge*> _tables;   //�ڽӱ�
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


















