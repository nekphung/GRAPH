#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int x, y, w;
};

int n, m;
int parent[1000];
int sz[10000];
vector<edge> E;

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		edge e{ x, y, w };
		E.push_back(e);
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


bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void Kruskal() {
	sort(E.begin(), E.end(), cmp);
	long long d = 0;
	vector<edge> MST; // Luu cay khung
	for (int i = 0; i < m; i++) {
		if (MST.size() == n - 1) break;
		int x = E[i].x, y = E[i].y, w = E[i].w;
		if (Union(x, y)) {
			d += w;
			MST.push_back(E[i]);
		}
	}
	if (MST.size() != n - 1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << d << endl;
	}
}

int main() {
	nhap();
	init();
	Kruskal();
	return 0;
}