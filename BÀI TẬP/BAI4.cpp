#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int s, t, u, v;
vector<int> ke[1005];
int parent[1005];
int visited[1005];

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));
}

bool bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int v : ke[x]) {
			if (!visited[v]) {
				parent[v] = x;
				q.push(v);
				visited[v] = 1;
			}
			else if (visited[v] && v != parent[x]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (bfs(i))
			{
				cout << 0 << endl; 
				return 0;
			}
		}
	}
	cout << 1 << endl;
	return 0;
}