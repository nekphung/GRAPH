#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int n, m, q;
vector<ii> ke[1000];
int visited[1000];
int d[1000];

void Prime(int u) {
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	for (ii x : ke[u]) {
		Q.push({ x.second, x.first });
	}
	visited[u] = 1;
	int d = 0;
	int count = 1;
	while (!Q.empty()) {
		ii e = Q.top(); Q.pop();
		int w = e.first, u = e.second;
		if (visited[u] == 1) continue;
		d += w;
		count++;
		visited[u] = 1;
		for (ii x : ke[u]) {
			if (!visited[x.first]) {
				Q.push({ x.second, x.first });
			}
		}
	}
}

void Dijkstra(int s) {
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	Q.push({ 0, s });
	while (!Q.empty()) {
		ii e = Q.top(); Q.pop();
		int dis = e.first, u = e.second;
		if (dis > d[u]) continue;
		for (ii x : ke[u]) {
			int w = x.first, v = x.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({ d[v], v });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
}