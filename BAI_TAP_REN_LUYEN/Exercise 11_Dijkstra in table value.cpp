#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

/*
6 7
0 3 6 0 5 9 1
6 5 4 4 0 7 6
4 0 2 1 5 6 1
2 7 7 3 3 1 6
4 4 9 6 9 7 2
3 6 4 4 1 9 2

--> 28, remove four direct
*/

class Graph {
private:
	int n, m;
	vector<vector<int>> adjMatrix;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

public:
	Graph() : n(0), m(0) {}
	/*
	Graph() 
	{
		n = 0;
		m = 0;
	}
	*/
	void nhap() {
		cin >> n >> m;
		adjMatrix.resize(n, vector<int> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> adjMatrix[i][j];
			}
		}
	}

	void xuatMatrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	int Dijkstra(int i, int j) {
		vector<vector<int>> dist;
		vector<vector<bool>> visited;
		visited.assign(n, vector<bool>(m, false)); // Init all the indate into matrix have value 0
		priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> Q;
		dist.assign(n, vector<int>(m, 1e9));

		dist[i][j] = adjMatrix[i][j];
		Q.push({ dist[i][j], {i, j}});

		while (!Q.empty())
		{
			pair<int, ii> top = Q.top(); Q.pop();
			int w = top.first, i1 = top.second.first, j1 = top.second.second;
			if (i1 == n - 1 && j1 == m - 1) return dist[i1][j1];
			if (visited[i1][j1] == true) continue;
			visited[i1][j1] = true;
			for (int k = 0; k < 4; k++)
			{
				int i2 = i1 + dx[k], j2 = j1 + dy[k];
				if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && !visited[i2][j2] && dist[i2][j2] > dist[i1][j1] + adjMatrix[i2][j2]) 
				{
					dist[i2][j2] = dist[i1][j1] + adjMatrix[i2][j2];
					Q.push({ dist[i2][j2], { i2, j2} });
				}
			}
		}
		return -1;
	}
};

int main() {
	Graph g;
	g.nhap();
	//g.xuatMatrix();
	cout << g.Dijkstra(0, 0) << endl;

	return 0;
}


