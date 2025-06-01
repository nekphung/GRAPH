#include <iostream> 
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

class Graph {
private:
	int V;
	vector<vector<ii>> ke;
public:
	Graph(int size) : V(size) {
		ke.resize(V+1);
	}

	void AddWells(vector<int>& wells) {
		for (int i = 0; i < wells.size(); i++) {
			ke[0].push_back({ i + 1, wells[i] });
			ke[i + 1].push_back({ 0, wells[i] });
		}
	}

	void AddEdge(vector<vector<int>>& dscanh) {
		for (int i = 0; i < dscanh.size(); i++) {
			int u = dscanh[i][0], v = dscanh[i][1], w = dscanh[i][2];
			ke[u].push_back({ v, w });
			ke[v].push_back({ u, w });
		}
	}

	int Prim() {
		priority_queue<ii, vector<ii>, greater<ii>> q;
		vector<bool> mstMT(V + 1, false);
		vector<int> key(V + 1, INT_MAX);
		int total = 0;
		key[0] = 0;
		q.push({ 0, 0 });
		while (!q.empty()) {
			ii top = q.top(); q.pop();
			int m = top.first, u = top.second;
			if (mstMT[u] == true) continue;
			mstMT[u] = true;
			total += m;
			for (ii x : ke[u]) {
				int v = x.first, w = x.second;
				if (!mstMT[v] && key[v] > w) {
					key[v] = w;
					q.push({ key[v], v });
				}
			}
		}
		return total;
	}
};

int main() {
	Graph g(3);
	vector<vector<int>> pipes = {{1, 2, 1}, { 2, 3, 1}};
	vector<int> wells = { 1, 2, 2 };
	g.AddWells(wells);
	g.AddEdge(pipes);
	cout << g.Prim() << endl;
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//
//vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
//    vector<int> ans(V, INT_MAX);
//    vector<vector<pair<int, int>>> adjList;
//    adjList.resize(V);
//    for (int i = 0; i < edges.size() - 1; i++) {
//        for (int j = 0; j < 3; j++) {
//            adjList[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
//            adjList[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
//        }
//    }
//    Dijkstra(V, src, adjList, ans);
//    return ans;
//}
//
//void Dijkstra(int V, int source, vector<vector<pair<int, int>>>& adjList, vector<int>& disc) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//    vector<bool> visited(V, false);
//    // vector<int> disc(V, INT_MAX);
//    q.push({ 0, source });
//    disc[source] = 0;
//
//    while (!q.empty()) {
//        pair<int, int> temp = q.top(); q.pop();
//        int w = temp.first, u = temp.second;
//        if (visited[u] == true) continue;
//        visited[u] = true;
//        for (pair<int, int> x : u) {
//            int v = x.first, w = x.second;
//            if (!visited[v] && disc[v] > disc[u] + w) {
//                disc[v] = disc[u] + w;
//                push({ disc[v], v });
//            }
//        }
//    }
//
//}
//
////#include <iostream>
////#include <vector>
////#include <queue>
////#include <cstring>
////
////using namespace std;
////
////int n, m;
////vector<int> ke[20005];
////int visited[20003];
////int recStack[3399];
////
////void nhap() {
////	cin >> n >> m;
////	for (int i = 1; i <= m; i++) {
////		int x, y; cin >> x >> y;
////		ke[x].push_back(y);
////	}
////}
////
////void dfs(int u) {
////	cout << u << " ";
////	visited[u] = 1;
////	for (int v : ke[u]) {
////		if (!visited[v]) {
////			dfs(v);
////		}
////	}
////}
////
////void bfs(int u) {
////	queue<int> q;
////	q.push(u);
////	visited[u] = 1;
////	while (!q.empty()) {
////		int top = q.front(); q.pop();
////		cout << top << " ";
////		for (int x : ke[top]) {
////			if (visited[x]) {
////				q.push(x);
////				visited[x] = 1;
////			}
////		}
////	}
////}
////
////bool isCyclicUtil(int u) {
////	visited[u] = 1;
////	recStack[u] = 1;
////	for (int v : ke[u]) {
////		if (!visited[v] && isCyclicUtil(v)) {
////			return true;
////		}
////		else if (recStack[v]) return true;
////	}
////	recStack[u] = false;
////	return false;
////}
////
////
////int color[20003];
////bool isCycle(int u) {
////	color[u] = 1;
////	for (int x : ke[u]) {
////		if (color[x] == 0) {
////			if (isCycle(x)) return true;
////		}
////		else if (color[x] == 1) return true;
////	}
////	color[u] = 2;
////	return false;
////}
////
////
////int main() {
////	nhap();
////	//dfs(1);
////	cout << endl;
////	//bfs(1);
////	memset(visited, 0, sizeof(visited));
////	for (int i = 1; i <= n; i++) {
////		if (isCyclicUtil(i)) {
////			cout << "Co chu trinh" << endl;
////			return 0;
////		}
////	}
////	cout << "Khong ton tai chu trinh" << endl;
////	return 0;
////}
////
/////*
////6 5
////1 2 
////1 3
////2 4
////4 5
////5 6
////
////*/