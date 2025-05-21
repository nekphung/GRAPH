#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
6 5
1 2
4 2
1 5
2 6
6 4
*/
class Graph {
private:
	int n, m;
	vector<vector<int>> ke;
	vector<vector<int>> t_ke;
public:
	Graph() : n(0), m(0) {};

	void nhap() {
		cin >> n >> m;
		ke.resize(n + 1);
		t_ke.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			ke[x].push_back(y);
			t_ke[y].push_back(x);
		}
	}


	void DFS1(int u, vector<int>& visited, stack<int>& st) {
		visited[u] = 1;
		for (int x : ke[u]) {
			if (!visited[x]) {
				DFS1(x, visited, st);
			}
		}
		st.push(u);
	}

	void DFS2(int u, vector<int>& visited) {
		cout << u << " ";
		visited[u] = 1;
		for (int x : t_ke[u]) {
			if (!visited[x]) {
				DFS2(x, visited);
			}
		}
	}
	void Kasaraju() {
		stack<int> st;
		vector<int> visited1(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (!visited1[i]) {
				DFS1(i, visited1, st);
			}
		}
		vector<int> visited2(n + 1, 0);
		int scc = 0;
		while (!st.empty()) {
			int u = st.top(); st.pop();
			if (!visited2[u]) {
			++scc;
			cout << "Component " << scc << " : ";
			DFS2(u, visited2);
			cout << endl;
			}
		}
	}
};


int main() {
	Graph g;
	g.nhap();
	g.Kasaraju();
	return 0;
}