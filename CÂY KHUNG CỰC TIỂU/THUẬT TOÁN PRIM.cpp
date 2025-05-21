#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
int n, m;
int used[1000];
vector<ii> ke[1000];

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y, w });
		ke[y].push_back({ x, w });
	}
	memset(used, 0, sizeof(used));
}

void Prim(int s) {
	priority_queue <ii, vector<ii>, greater<ii>> Q;
	for (ii x : ke[s]) {
		Q.push({ x.second, x.first });
	}
	used[s] = 1;
	int d = 0;
	int count = 1;
	while (!Q.empty()) {
		ii e = Q.top(); Q.pop();
		int w = e.first, u = e.second;
		if (used[u] == 1) continue;
		d += w;
		count++;
		used[u] = 1;
		for (ii x : ke[u]) {
			if (used[x.first] == 0) {
				Q.push({ x.second, x.first });
			}
		}
	}
	if (count == n) cout << d << endl;
	else cout << "Do thi khong lien thong" << endl;
}


int main() {
	nhap();
	Prim(1);
	return 0;
}