#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct edge {
	int x, y, w;
};

int n, m;
vector<edge> dscanh;
long long d[20005];

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		dscanh.push_back({ x, y, w });
		//dscanh.push_back({ y, x, w });
	}
}

bool BellmanFord(int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e18;
	}
	d[s] = 0;
	bool finish = true;
	for (int i = 1; i <= n - 1; i++) {
		finish = true;
		for (edge e : dscanh) {
			int u = e.x, v = e.y, w = e.w;
			if (d[u] < 1e18) {
				if (d[v] > d[u] + w)  
				{
					d[v] = d[u] + w;
					finish = false;
				}
			}
		}
		if (finish) break;
	}

	// Duyet lai mot lan nua neu no van update duoc thi no ton tai chu trinh am
	for (edge e : dscanh) {
		int u = e.x, v = e.y, w = e.w;
		if (d[u] < 1e18) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				return true;
			}
		}
	}
	return false;
}


int main() {
	nhap();
	for (int i = 1; i <= n; i++) {
		if (BellmanFord(i)) {
			cout << "28tech" << endl;
			return 0;
		}
	}
	cout << "29tech" << endl;
	return 0;
}