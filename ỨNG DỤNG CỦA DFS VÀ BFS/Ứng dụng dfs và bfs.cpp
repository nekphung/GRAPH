#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ke[1000];
int visited[1000];
int n, m;
int parent[1000];

void dfs(int u) {
	cout << u << " ";
	visited[u] = 1;
	for (int x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
			parent[x] = u;
		}
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << " ";
		for (int y : ke[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
				parent[y] = x;
			}
		}
	}
}
// Dem so thanh phan lien thong cua do thi
int tplt() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++count;
			dfs(i); // bfs(i);
		}
	}
	return count;
}
// Duong di trong do thi
void path(int s, int t) {
	dfs(s);
	if (!visited[t]) {
		cout << "Khong ton tai duong di giua hai dinh do" << endl;
	}
	else {
		vector<int> res;
		while (t != s) {
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		reverse(res.begin(), res.end());
		for (int x : res) {
			cout << x << " ";
		}
	}
}

// Kiem tra chu trinh vo huong cua do thi
bool DFS(int u) {
	visited[u] = 1;
	for (int x : ke[u]) {
		if (!visited[x]) {
			parent[x] = u;
			if (DFS(x)) return true;
		}
		if (visited[x] && x != parent[u]) {
			return true;
		}
	}
	return false;
}


bool BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : ke[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
				parent[y] = x;
			}
			if (visited[y] && y != parent[x]) {
				return true;
			}
		}
	}
	return false;
}
// Kiem tra chu trinh co huong cua do thi
// Su dung mau de danh dau

// Thuat toan Kahn 
int degree[1000];
bool Kahn(int u) {
	for (int i = 1; i <= n; i++) {
		for (int x : ke[i]) {
			degree[x]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		++cnt;
		for (int v : ke[u]) {
			--degree[v];
			if (degree[v] == 0) {
				q.push(v);
			}
		}
	}
	if (cnt != n) return true;
	else return false;
}


// DFS tren mang 2 chieu
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int visited1[10005][10005];
int a[1000][1000];

void DFS(int i, int j) {
	visited1[i][j] = 1;
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited1[i1][j1]) {
			DFS(i1, j1);
		}
	}
}

// BFS tren mang 2 chieu
void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited1[i][j] = 1;
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		for (int k = 0; k < 8; k++) {
			int i1 = x.first + dx[k], j1 = x.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited1[i1][j1]) {
				q.push({ i1, j1 });
				visited1[i1][j1] = 1;
			}
		}
	}
}

//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke[y].push_back(x);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			if (BFS(i)) {
//				cout << 1 << endl;
//				return 0;
//			}
//		}
//	}
//	cout << 0 << endl;
//	return 0;
//}

int color[1000];
bool DFS1(int u) {
	color[u] = 1;
	for (int v : ke[u]) {
		if (color[v] == 0) {
			if (DFS1(v)) return true;
		}
		else if (color[v] == 1) {
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	memset(color, 0, sizeof(color));

	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (DFS1(i)) {
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}