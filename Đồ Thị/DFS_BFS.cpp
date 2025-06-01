#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;


/*
0 --- 2 ---- 4 --- 3
|     |
5	  1


*/
/*
6 5 5 4
0 2
2 1
3 4
2 4
0 5

*/
// In ra duong di tu goc toi mot dinh khac trong do thi

int n, m, u, v;
int visited[20005];
vector<int> ke[20005];
int parent[20005];

void nhap() {
	cin >> n >> m >> u >> v;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void DFS(int u) {
	visited[u] = true;
	for (int x : ke[u]) {
		if (!visited[x]) {
			parent[x] = u;
			DFS(x);
		}
	}
}

// Khong dung de quy
void path() {
	DFS(u);
	if (!visited[v]) {
		cout << "Khong ton tai duong di" << endl;
	}
	else {
		vector<int> res;
		while (v!=u) {
			res.push_back(v);
			v = parent[v];
		}
		res.push_back(u);
		reverse(res.begin(), res.end());
		for (int x : res) {
			cout << x << " ";
		}
	}
}

// In tat ca duong di thi sao
int main() {
	nhap();
	path();
	return 0;
}

// Dung de quy


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int a[1000][1000];
//int visited[1000];
//int TPLP[1000];
//int parent[10000];
//int cnt;
//vector<int> ke[1000];
//vector<pair<int, int>> dscanh;
//
//int n, m, t, s;
//// Danh sach ke
//void dfs1(int u) {
//	//cout << u << " ";
//	visited[u] = 1;
//	//TPLP[u] = cnt;
//	for (int x : ke[u]) {
//		if (!visited[x]) {
//			dfs1(x);
//			parent[x] = u;
//		}
//	}
//}
//
//
//bool dfs(int u) {
//	visited[u] = 1;
//	for (auto v : ke[u]) {
//		if (visited[v] && v != parent[u]) {
//			return true;
//		}
//		if (!visited[v]) {
//			if (dfs(v)) return true;
//		}
//	}
//	return false;
//}
//
//void dfs(int u, int x, int y) {
//	visited[u] = 1;
//	for (int v : ke[u]) {
//		if ((u == x && v == y) || (u == y && v == x)) {
//			continue;
//		}
//		if (!visited[v]) {
//			dfs(v, x, y);
//		}
//	}
//}
//
//// Ma tran ke
//void dfs2(int u) {
//	cout << u << " ";
//	visited[u] = 1;
//	for (int i = 1; i <= n; i++) {
//		if (a[u][i] == 1 && !visited[i]) {
//			dfs2(i);
//		}
//	}
//}
//
//
//// Danh sach canh
//void dfs3(int u) {
//	cout << u << " ";
//	visited[u] = 1;
//	for (pair<int, int> e : dscanh) {
//		if (e.first == u && !visited[e.second]) {
//			dfs3(e.second);
//		}
//	}
//}
//
//void bfs1(int u) {
//	queue<int> q;
//	q.push(u);
//	visited[u] = 1;
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		//cout << x << " ";
//		for (int y : ke[x]) {
//			if (!visited[y]) {
//				q.push(y);
//				visited[y] = 1;
//				parent[y] = x;
//			}
//		}
//	}
//}
//
//bool bfs(int u) {
//	queue<int> q;
//	q.push(u);
//	visited[u] = 1;
//	while (!q.empty()) {
//		int top = q.front();
//		q.pop();
//		for (auto x : ke[top]) {
//			if (!visited[x]) {
//				q.push(x);
//				visited[x] = 1;
//				parent[x] = top;
//			}
//			if (visited[x] && x != parent[top]) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//void DFS(int u) {
//	cout << u << " ";
//	visited[u] = 1;
//	for (int x : ke[u]) {
//		if (!visited[x]) {
//			DFS(x);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		ke[y].push_back(x);
//	}
//	DFS(1);
//	return 0;
//}