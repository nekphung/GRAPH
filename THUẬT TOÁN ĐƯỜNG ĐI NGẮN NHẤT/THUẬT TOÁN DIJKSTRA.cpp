#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class MyPriorityQueue {
public:
	void heapifyUp(vector<ii>& arr, int i) {
		while (i > 0) {
			int dad = (i - 1) / 2;
			if (arr[dad].first >  arr[i].first) {
				swap(arr[dad], arr[i]);
				i = dad;
			}
			else return;
		}
	}

	void heapifyDown(vector<ii>& arr, int i) {
		int n = arr.size();
		int dad = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && arr[dad].first > arr[left].first) {
			dad = left;
		}
		if (right < n && arr[dad].first > arr[right].first) {
			dad = right;
		}
		if (dad != i)
		{
			swap(arr[dad], arr[i]);
			heapifyDown(arr, dad);
		}
	}

	void push(vector<ii>& arr, ii item) {
		arr.push_back(item);
		heapifyUp(arr, arr.size() - 1);
	}

	void pop(vector<ii>& arr) {
		swap(arr[0], arr[arr.size() - 1]);
		arr.pop_back();
		heapifyDown(arr, 0);
	}

	ii top(vector<ii>& arr) {
		if (arr.empty()) return { -1, -1 };
		return arr[0];
	}

	bool empty(vector<ii>& arr) {
		return arr.empty();
	}

	void heap(vector<ii>& arr) {
		int n = arr.size();
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapifyDown(arr, i);
		}
	}
	void push(ii item) {
		push(arr, item);
	}
	void pop() {
		pop(arr);
	}

	bool empty() {
		return empty(arr);
	}

	ii top() {
		return top(arr);
	}

private:
	vector<ii> arr;
};

int n, m, s;
vector<ii> ke[10000];
int d[10000];

void nhap() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({ y, w });
		ke[y].push_back({ x, w });
	}
}

void Dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	MyPriorityQueue Q;
	Q.push({ 0, s });
	while (!Q.empty()) {
		ii tmp = Q.top(); Q.pop();
		int dis = tmp.first, u = tmp.second;
		if (dis > d[u]) continue;
		for (ii x : ke[u]) {
			int v = x.first, w = x.second;
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

int main() {
	nhap();
	Dijkstra(s);
	return 0;
}