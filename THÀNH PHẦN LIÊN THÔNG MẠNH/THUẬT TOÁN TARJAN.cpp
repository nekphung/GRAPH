// Xay dung 2 mang disc va low cho cac dinh cua do thi
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;

int n, m, timer = 0, scc = 0;
vector<int> ke[1000];
int disc[1000], low[1000];
int visited[1000], in_stack[1000];
stack<int> st;

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	memset(visited, 0, sizeof(visited));
	memset(in_stack, 0, sizeof(in_stack));
}

// chi su dung 1 lan thuat toan dfs
void DFS(int u) {
	visited[u] = 1; in_stack[u] = 1;
	disc[u] = low[u] = ++timer;
	st.push(u);
	for (int x : ke[u]) {
		if (!visited[x]) {
			DFS(x);
			low[u] = min(low[u], low[x]);
		}
		else {
			low[u] = min(low[u], disc[x]);
		}
	}
	if (disc[u] == low[u]) {
		++scc;
		cout << "SCC " << scc << ": ";
		while (st.top() != u) {
			cout << st.top() << " ";
			in_stack[st.top()] = 0;
			st.pop();
		}
		cout << st.top() << " " << endl;
		in_stack[st.top()] = 0;
		st.pop();
	}
}

int main() {
	nhap();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}
	/*cout << scc << endl;
	for (int i = 1; i <= n; i++) {
		cout << disc[i] << " " << low[i] << endl;
	}*/
	return 0;
}

/*
8 7
1 2
1 3
2 4
4 5
5 6
6 4
7 8
*/