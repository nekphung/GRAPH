#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> ii;
struct edge {
	int x, y, w;
};

int n, m, s;
char a[1005][1005];
int visited1[1000][1000];
vector<int> ke[200005];
vector<ii> adj[200005];
int parent[200005];
int sz[200005];
vector<edge> dscanh;
int d[200005];
int visited[200005];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs1(int i, int j) {
	visited1[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited1[i1][j1] && a[i1][j1] == '.') {
			dfs1(i1, j1);
		}
	}
}
long long tplt1() {
   long long count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited1[i][j] && a[i][j] == '.') {
				++count;
				dfs1(i, j);
			}
		}
	}
	return count;
}

void nhap1() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		edge e{ x, y, w };
		dscanh.push_back(e);
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
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

void Dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({ 0, s });
	while (!Q.empty()) {
		ii e = Q.top(); Q.pop();
		int dis = e.first, u = e.second;
		if (d[u] < dis) continue;
		for (ii x : adj[u]) {
			int v = x.first, w = x.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({ d[v], v });
			}
		}
 	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void kruskal() {
	sort(dscanh.begin(), dscanh.end(), cmp);
	vector<edge> MST;
	long long d = 0;
	for (int i = 0; i < m; i++) {
		int u = dscanh[i].x, v = dscanh[i].y, w = dscanh[i].w;
		if (MST.size() == (n - 1)) break;
		if (Union(u, v)) {
			d += w;
			MST.push_back(dscanh[i]);
		}
	}
	if (MST.size() != (n - 1)) {
		cout << "IMPOSSIBLE" << endl;
	}
	else cout << d << endl;
}

void dfs(int u) {
	visited[u] = 1;
	for (int x : ke[u]) {
		if (!visited[x]) {
			cout << u << "->" << x << endl;
			dfs(x);
		}
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int top = q.front(); q.pop();
		//cout << top << " ";
		for (int x : ke[top]) {
			if (!visited[x]) {
				cout << top << "->" << x << endl;
				q.push(x);
				visited[x] = 1;
			}
		}
	}
}

void nhap2() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(ke[i].begin(), ke[i].end());
	}
	memset(visited, 0, sizeof(visited));
}

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));
}

bool dfs2(int u) {
	visited[u] = 1;
	for (int x : ke[u])
	{
		if (!visited[x]) {
			parent[x] = u;
			if (dfs2(x)) {
				return true;
			}
		}
		else if (visited[x] && x != parent[u]) {
			return true;
		}

	}
	return false;
}

int Max = 0;
int main() {
	cin >> n >> m;
	init();
	int dem = n;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		if (Union(x, y)) {
			dem--;
			Max = max(Max, sz[x]);
			cout << dem << " " << Max << endl;
		}
		else {
			cout << dem << " " << Max << endl;
		}
	}
	return 0;
}