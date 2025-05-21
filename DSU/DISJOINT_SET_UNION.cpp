#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
int parent[10000], sz[100000];

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

// tim dai dien cho dinh u bat ki
int find(int u) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}


// Toi uu nen duong
int Find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}


bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	else {
		if (u < v) parent[v] = u;
		else parent[u] = v;
		return true;
	}
}

// Toi uu gop duong di
bool UNION(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	else {
		if (sz[u] > sz[v]) {
			parent[v] = u;
			sz[u] += sz[v];
		}
		else {
			parent[u] = v;
			sz[v] += sz[u];
		}
		return true;
	}
}

// Neu hai dinh khong gop vo duoc nua thi no ton tai chu trinh
int main() {
	cin >> n >> m;
	init();
	bool check = true;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		if (!Union(x, y)) {
			check = false;
		}
	}
	if (check) cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}