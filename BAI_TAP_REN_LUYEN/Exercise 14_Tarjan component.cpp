#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

// Thuat toan Tarjan de in ra thanh phan lien thong cua do thi

/*
5 5
1 2 
2 3
3 4
4 2
1 5
*/

class Graph {
private:
	int n, m;
	vector<vector<int>> adjList;
	int timer = 0;
	int scc = 0;
public:
	Graph() : n(0), m(0) {}
	void nhap() {
		cin >> n >> m;
		adjList.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			adjList[x].push_back(y);
		}
	}

	void Tarjan() {
		vector<bool> visited(n + 1, false);
		vector<bool> in_stack(n + 1, false);
		vector<int> low(n + 1, 0);
		vector<int> disc(n + 1, 0);
		stack<int> st;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i, visited, in_stack, low, disc, st);
			}
		}
	}

	void DFS(int u, vector<bool>& visited, vector<bool>& in_stack, vector<int>&low, vector<int> &disc, stack<int>&st) {
		visited[u] = true; in_stack[u] = true;
		low[u] = disc[u] = timer++;
		st.push(u);
		for (int x : adjList[u]) {
			if (!visited[x]) {
				DFS(x, visited, in_stack, low, disc, st);
				low[u] = min(low[u], low[x]);
			}
			else low[u] = min(low[u], disc[x]);
		}
		if (low[u] == disc[u]) {
			scc++;
			cout << "SCC " << scc << " : ";
			while (st.top() != u) {
				cout << st.top() << " ";
				in_stack[st.top()] = 0;
				st.pop();
			}
			cout << st.top() << endl;
			in_stack[st.top()] = 0;
			st.pop();
		}
	}


};

int main() {
	Graph g;
	g.nhap();
	g.Tarjan();
	return 0;
}