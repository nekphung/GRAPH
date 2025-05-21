#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
DFS - based Topo Sort
Kahn’s Algorithm(BFS - based)

- Ap dung cho do thi co huong khong co chu trinh
- Topological Sorting
- Co the co nhieu cau hinh topo khac nhau trong do thi
- Vi du theo thu tu cua canh thi u->v thi theo sap xep topo  thi u luon dung truoc v
--> nếu không tạo được topo nghĩa là đồ thị có chu trình.
--> lập lịch công việc, công việc A phải làm xong trước công việc B.
*/

int visited[1000];
stack<int> st;
int n, m;
vector<int> ke[1000];
int degree[1000];

void dfs(int u) {
	//cout << u << " ";
	visited[u] = 1;
	for (int x : ke[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
	st.push(u);
}

void Kahn() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> topo;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		topo.push_back(x);
		for (int y : ke[x]) {
			degree[y]--;
			if (degree[y] == 0) q.push(y);
		}
	}
	if (topo.size() < n) {
		cout << "Do thi ton tai chu trinh" << endl;
	}
	else {
		for (int x : topo) {
			cout << x << " ";
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		degree[y]++;
	}
	Kahn();
	return 0;
}


//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y; cin >> x >> y;
//		ke[x].push_back(y);
//		//ke[y].push_back(x);
//	}
//
//	Kahn();
//	/*for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			dfs(i);
//		}
//	}
//	cout << endl;
//	while (!st.empty()) {
//		cout << st.top() << " ";
//		st.pop();
//	}*/
//	return 0;
//}