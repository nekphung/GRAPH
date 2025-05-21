#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char a[20005][20005];
int visited[20005][20005];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dem = 1;
void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == '.') {
			dem++;
			dfs(i1, j1);
		}
	}
}

void nhap() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}
int main() {
	nhap();
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && a[i][j] == '.') {
				dfs(i, j);
				ans.push_back(dem);
				dem = 1;
			}
		}
	}

	for (int x : ans) {
		cout << x << " ";
	}
	return 0;
}