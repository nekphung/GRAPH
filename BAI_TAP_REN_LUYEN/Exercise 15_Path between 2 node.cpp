#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

class Graph {
private:
	int n, m, k;
	vector<vector<pair<int, int>>> ke;
public:
	Graph() : n(0), m(0), k(0) {}
	void nhap() {
		cin >> n >> m >> k;
		ke.resize(n);
		for (int i = 1; i <= m; i++) {
			int x, y, w; cin >> x >> y >> w;
			ke[x].push_back({y, w});
			//ke[y].push_back(x);
		}
	}

	void Dijkstra(int source, int &ans) {
		priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> q;
		vector<bool> visited(n, false);
		vector<int> disc(n, INT_MAX);
		vector<int> parent(n, -1);

		disc[source] = 0;

		q.push({ 0, source });
		while (!q.empty()) {
			pair<int, int> top = q.top(); q.pop();
			int u = top.second;
			if (u == k) ans = disc[k];
			if (visited[u] == true) continue;
			visited[u] = true;
			for (pair<int, int> x : ke[u]) {
				int v = x.first, w = x.second;
				if (!visited[v] && disc[v] > disc[u] + w) {
					disc[v] = disc[u] + w;
					parent[v] = u;
					q.push({ disc[v], v });
				}
			}
		}
		print(parent, k);
	}	

	void print(vector<int>& parent, int dest) {
		if (parent[dest] == -1) {
			cout << dest;
			return;
		}
		print(parent, parent[dest]);
		cout << " -> " << dest;
	}
};



int main() {
	Graph g;
	g.nhap();
	int ans = -1;
	g.Dijkstra(0, ans);
	cout << endl;
	cout << ans << endl;
	return 0;
}