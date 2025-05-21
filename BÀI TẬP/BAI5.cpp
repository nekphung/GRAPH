#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

struct Edge {
	int dest;
	int weight;
	Edge(int m, int n) {
		dest = m;
		weight = n;
	}
};

class Graph {
private:
	int V;
	vector <vector<Edge>> adjList;

public:
	Graph(int vertices) : V(vertices) {
		adjList.resize(V);
	}

	void addEdge(int src, int dest, int weight) {
		adjList[src].push_back(Edge(dest, weight));
		adjList[dest].push_back(Edge(src, weight));
	}

	// TODO : Implement optimized Dijkstra ’s algorithm using priority queue
	void dijkstra(int source) {
		priority_queue<ii, vector<ii>, greater<ii>> q;
		vector<int> dist(V, 1e9);
		vector<int> parent(V, -1);
		vector<bool> visited(V, false);
		dist[source] = 0;
		parent[source] = -1;
		q.push({ 0, source });

		while (!q.empty()) {
			ii e = q.top(); q.pop();
			int w = e.first, u = e.second;
			if (visited[u] == true) continue;
			visited[u] = true;
			for (Edge E : adjList[u]) {
				int x = E.dest, y = E.weight;
				if (!visited[x] && dist[x] > dist[u] + y) {
					dist[x] = dist[u] + y;
					parent[x] = u;
					q.push({ dist[x], x });
				}
			}
		}
		for (int i = 0; i < V; i++) {
			cout << dist[i] << " ";
		}
	}
};

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	Graph gt(n);
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		gt.addEdge(x - 1, y - 1, w);
	}
	gt.dijkstra(s - 1);
	return 0;
}

class Solution {
public:
	void init(int V, vector<int>& parent, vector<int>& sz) {
		for (int i = 0; i < V; i++) {
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int u, vector<int>& parent) {
		if (u == parent[u]) return u;
		else return parent[u] = Find(parent[u], parent);
	}

	bool Union(int u, int v, vector<int>& parent, vector<int>& sz) {
		u = Find(u, parent);
		v = Find(v, parent);
		if (u == v) return false;
		else {
			if (sz[u] < sz[v]) {
				swap(u, v);
			}
			parent[v] = u;
			sz[u] += sz[v];
			return true;
		}
	}
	bool isCycle(int V, vector<vector<int>>& edges) {
		vector<int> parent(V, -1);
		vector<int> sz(V, -1);
		init(V, parent, sz);
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			if (!Union(u, v, parent, sz)) return true;
		}
		return false;
	}
};

//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke[y].push_back(x);
//	}
//}
//
//void dfs(int u) {
//	cnt++;
//	visited[u] = 1;
//	tplt.push_back(u);
//	for (int x : ke[u]) {
//		if (!visited[x]) {
//			dfs(x);
//		}
//	}
//}
//
//void bfs(int u) {
//	queue<int> q;
//	cnt++;
//	visited[u] = 1;
//	tplt.push_back(u);
//	q.push(u);
//	while (!q.empty()) {
//		int top = q.front(); q.pop();
//		for (int v : ke[top]) {
//			if (!visited[v]) {
//				cnt++;
//				visited[v] = 1;
//				q.push(v);
//				tplt.push_back(v);
//			}
//		}
//	}
//}
//
//bool cmp(pair<int, int> a, pair<int, int> b) {
//	if (a.first != b.first) {
//		return a.first > b.first;
//	}
//	else {
//		return a.second < b.second;
//	}
//}
//
//int main() {
//	nhap();
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			cnt = 0;
//			tplt.clear();
//			ans.clear();
//			bfs(i);
//			for (int x : tplt) {
//				ans.push_back({ ke[x].size(), x });
//			}
//			sort(ans.begin(), ans.end(), cmp);
//			cout << ans[0].second << " ";
//		}
//	}
//	//cout << ans[0].second << endl;
//	return 0;
//}
//


//void init() {
//	for (int i = 1; i <= n; i++) {
//		parent[i] = i;
//		sz[i] = 1;
//	}
//}
//
//int Find(int u) {
//	if (u == parent[u]) return u;
//	return parent[u] = Find(parent[u]);
//}
//
//bool Union(int u, int v) {
//	u = Find(u);
//	v = Find(v);
//	if (u == v) return false;
//	else {
//		if (sz[u] < sz[v]) {
//			swap(u, v);
//		}
//		parent[v] = u;
//		sz[u] += sz[v];
//		return true;
//	}
//}
//
//
//int main() {
//	cin >> n >> m;
//	init();
//    
//	return 0;
//}



//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke[y].push_back(x);
//	}
//}
//
//void bfs(int u) {
//	queue<int> q;
//	visited[u] = 1;
//	q.push(u);
//	while (!q.empty()) {
//		int x = q.front(); q.pop();
//		for (int v : ke[x]) {
//			if (!visited[v]) {
//				q.push(v);
//				visited[v] = 1;
//			}
//		}
//	}
//}
//
//
//int main() {
//	nhap();
//	vector<int> res;
//	int ans = -1;
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			res.push_back(i);
//			ans++;
//			bfs(i);
//		}
//	}
//	cout << ans << endl;
//	for (int i = 0; i < res.size() - 1; i++) {
//		cout << res[i] << " " << res[i + 1] << endl;
//	}
//	return 0;
//}
//

//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke[y].push_back(x);
//	}
//}
//
//void dfs(int u) {
//	visited[u] = 1;
//	for (int x : ke[u]) {
//		if (!visited[x]) {
//			dfs(x);
//		}
//	}
//}
//
//int tplt() {
//	int dem = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			++dem;
//			dfs(i);
//		}
//	}
//	return dem;
//}
//
//int main() {
//	nhap();
//	int scc = tplt();
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		memset(visited, 0, sizeof(visited));
//		visited[i] = 1;
//		int dem = 0;
//		for (int i = 1; i <= n; i++) {
//			if (!visited[i]) {
//				++dem;
//				dfs(i);
//			}
//		}
//		if (dem > scc) {
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke_t[y].push_back(x);
//	}
//}
//
//void dfs1(int u) {
//	visited[u] = 1;
//	for (int x : ke[u])
//	{
//		if (!visited[x]) {
//			dfs1(x);
//		}
//	}
//	st.push(u);
//}
//
//void dfs2(int u) {
//	cout << u << " ";
//	visited[u] = 1;
//	for (int x : ke_t[u]) {
//		if (!visited[x]) {
//			dfs2(x);
//		}
//	}
//}
//
//void Kasaraju() {
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			dfs1(i);
//		}
//	}
//	memset(visited, 0, sizeof(visited));
//	int scc = 0;
//	while (!st.empty()) {
//		int top = st.top(); st.pop();
//		if (!visited[top]) 
//		{
//			++scc;
//			cout << "SCC " << scc << ": ";
//			dfs2(top);
//		}
//	}
//}
//
//int main() {
//	nhap();
//	Kasaraju();
//	return 0;
//}

//int n, m, q;
//int Mat[2005][2005];
//int a[2005][2005];
//
//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i == j)  Mat[i][j] = 0;
//			else  Mat[i][j] = 1e9;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		int x, y, w;
//		cin >> x >> y >> w;
//		Mat[x][y] = Mat[y][x] = w;
//	}
//}
//
//void Floyd() {
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
//			}
//		}
//	}
//}
//
//int main() {
//	nhap();
//	Floyd();
//	cin >> q;
//	for (int i = 0; i < q; i++) {
//		int x, y; cin >> x >> y;
//		cout << Mat[x][y] << endl;
//	}
//	return 0;
//}
//










//typedef pair<int, int> ii;
//
//int n, m;
//int a[2005][2005];
//int d[1005][1005];
//
//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//void nhap() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//}
//
//// Giong Prim
//int Dijkstra(int i, int j) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			d[i][j] = 1e9;
//		}
//	}
//	d[i][j] = 0;
//	priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<>> Q;
//	Q.push({ 0, {i, j} });
//	while (!Q.empty()) {
//		pair<int, ii> top = Q.top(); Q.pop();
//		int dis = top.first, i1 = top.second.first, j1 = top.second.second;
//		if (i1 == n && j1 == m) return d[n][m];
//		if (dis > d[i1][j1]) continue;
//		for (int k = 0; k < 4; k++) {
//			int i2 = i1 + dx[k], j2 = j1 + dy[k];
//			if (i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m) {
//				if (d[i2][j2] > d[i1][j1] + a[i2][j2]) {
//					d[i2][j2] = d[i1][j1] + a[i2][j2];
//					Q.push({ d[i2][j2], {i2, j2} });
//				}
//			}
//		}
//	}
//	return -1;
//}
//
//int main() {
//	nhap();
//	cout << Dijkstra(1, 1) << endl;
//	return 0;
//}