#include <iostream>
#include <vector>

using namespace std;

// Check chu trinh am

struct Edge {
	int x, y, w;
};
class Graph {
private:
	int n, m;
	vector<Edge> dscanh;

public:
	Graph() : n(0), m(0) {};
	
	void nhap() {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			dscanh.push_back(Edge{x, y, w});
		}
	}

	bool BellManFord(int u) {
		vector<int> dist(n + 1, 1e9);
		dist[u] = 0;
		bool finish;
		for (int i = 1; i <= n - 1; i++) {
			finish = true;
			for (Edge edge : dscanh) {
				int u = edge.x, v = edge.y, w = edge.w;
				if (dist[u] != 1e9 && dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					finish = false;
				}
			}
			if (finish) break;
		}
		for (Edge edge : dscanh) {
			int u = edge.x, v = edge.y, w = edge.w;
			if (dist[u] != 1e9 && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				return true;
			}
		}
		return false;
	}

	bool ans() {
		for (int i = 1; i <= n; i++) {
			if (BellManFord(i)) return true; // Nếu có chu trình âm thì return true
		}
		return false; // Không có chu trình âm
	}
};


int main() {
	Graph g;
	g.nhap();
	if (g.ans()) {
		cout << "Ton tai chu trinh am" << endl;
	}
	else cout << "Khong ton tai chu trinh am" << endl;
	return 0;
}

/*
7 6
1 2 1
1 3 1
1 4 1
1 5 1
6 7 -1
7 6 -1
*/