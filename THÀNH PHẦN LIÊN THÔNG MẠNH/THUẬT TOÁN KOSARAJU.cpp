#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
int visited[1000];
vector<int> ke[1000];
vector<int> t_ke[1000];
stack<int> st;
int n, m;

void dfs1(int u) {
	visited[u] = 1;
	for (int x : ke[u]) {
		if (!visited[x]) {
			dfs1(x);
		}
	}
	st.push(u);
}

void dfs2(int u) {
	cout << u << " ";
	visited[u] = 1;
	for (int x : t_ke[u]) {
		if (!visited[x]) {
			dfs2(x);
		}
	}
}

void Kosaraju() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i);
		}
	}
	memset(visited, 0, sizeof(visited));
	int scc = 0;
	while (!st.empty()) {
		int u = st.top(); st.pop();
		if (!visited[u]) {
			++scc;
			cout << "SCC " << scc << ": ";
			dfs2(u);
			cout << endl;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		t_ke[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));
	Kosaraju();
	return 0;
}