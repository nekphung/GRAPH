#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<int> ke[20005];
int visited[20003];
int recStack[3399];

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
}

void dfs(int u) {
	cout << u << " ";
	visited[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		int top = q.front(); q.pop();
		cout << top << " ";
		for (int x : ke[top]) {
			if (visited[x]) {
				q.push(x);
				visited[x] = 1;
			}
		}
	}
}

bool isCyclicUtil(int u) {
	visited[u] = 1;
	recStack[u] = 1;
	for (int v : ke[u]) {
		if (!visited[v] && isCyclicUtil(v)) {
			return true;
		}
		else if (recStack[v]) return true;
	}
	recStack[u] = false;
	return false;
}


int color[20003];
bool isCycle(int u) {
	color[u] = 1;
	for (int x : ke[u]) {
		if (color[x] == 0) {
			if (isCycle(x)) return true;
		}
		else if (color[x] == 1) return true;
	}
	color[u] = 2;
	return false;
}


int main() {
	nhap();
	//dfs(1);
	cout << endl;
	//bfs(1);
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (isCyclicUtil(i)) {
			cout << "Co chu trinh" << endl;
			return 0;
		}
	}
	cout << "Khong ton tai chu trinh" << endl;
	return 0;
}

/*
6 5
1 2 
1 3
2 4
4 5
5 6

*/