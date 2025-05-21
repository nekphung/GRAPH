// File : Exercise_7 .cpp
# include < iostream >
# include < vector >
# include < climits >
# include < queue >
using namespace std;

typedef pair<int, int> ii;

/*
Input :
V = 5
Edges : (0, 1, 2), (0, 3, 6), (1, 2, 3), (1, 3, 8), (1, 4, 5), (2, 4, 7), (3, 4, 9)

Output :
Minimum Spanning Tree using Prim’ s algorithm :
Edge Weight
0 - 1 2
1 - 2 3
1 - 4 5
0 - 3 6
Total MST weight : 16
*/

class Graph {
private:
	int V;
	vector<vector<ii>> adjList;
	vector<vector<int>> adjMatrix;
public:
	Graph(int vertices) : V(vertices) {
		adjList.resize(V);
		adjMatrix.resize(V, vector<int>(V, 0));
	}
	
	void addEdge(int src, int dest, int weight) {
		adjList[src].push_back({ dest, weight });
		adjList[dest].push_back({ src, weight });
		adjMatrix[src][dest] = weight;
		adjMatrix[dest][src] = weight;
	}

	void PrimMST1() {
		vector<int> MST;
		vector<bool> visited(V, false);
		int total = 0;
		int count = 1;
		priority_queue<ii, vector<ii>, greater<ii>> q;
		for (ii v : adjList[0]) {
			q.push({ v.second, v.first });
		}
		visited[0] = true;
		while (!q.empty()) {
			ii x = q.top(); q.pop();
			int w = x.first, u = x.second;
			if (visited[u] == true) continue;
			total += w;
			count++;
			MST.push_back(u);
			visited[u] = true;
			for (ii e : adjList[u]) {
				if (!visited[e.first]) {
					q.push({ e.second, e.first });
				}
			}
		}
		if (count == V) {
			for (int x : MST) {
				cout << x << endl;
			}
			cout << total << endl;
		}
		else cout << "Do thi khong lien thong" << endl;
	}

	void PrimMST2() {
		vector<pair<ii, int>> MST;
		vector<bool> visited(V, false);
		int total = 0;
		int count = 1;
		priority_queue<pair<ii, int>, vector<pair<ii, int>>, greater<pair<ii, int>>> q;
		for (ii v : adjList[0]) {
			q.push({{ v.second, v.first }, 0});
		}
		visited[0] = true;
		while (!q.empty()) {
			pair<ii, int> x = q.top(); q.pop();
			int w = x.first.first, u = x.first.second, v = x.second;
			if (visited[u] == true) continue;
			total += w;
			count++;
			MST.push_back({ {v, u}, w});
			visited[u] = true;
			for (ii e : adjList[u]) {
				if (!visited[e.first]) {
					q.push({ {e.second, e.first }, u });
				}
			}
		}
		if (count == V) {
			cout << "Edge - Weight" << endl;
			for (auto x : MST) {
				cout << x.first.first << " - " << x.first.second << " " << x.second << endl;
			}
			cout <<  "Total MST weight : " << total << endl;
		}
		else cout << "Do thi khong lien thong" << endl;
	}

	void PrimMST3() {
		vector<int> key(V, 1e9);
		vector<int> parent(V, -1);
		vector<bool> mstSet(V, false);
		key[0] = 0;
		for (int i = 0; i < V; i++) {
			int u = minKey(key, mstSet);
			mstSet[u] = true;
			for (int v = 0; v < V; v++) {
				if (adjMatrix[u][v] > 0 && !mstSet[v] && adjMatrix[u][v] < key[v]) {
					key[v] = adjMatrix[u][v];
					parent[v] = u;
				}
			}
		}
		printMST(parent);
	}

	// TODO : Implement function to find the vertex with minimum key value
	int minKey(const vector <int >& key, const vector <bool >& mstSet) {
		int min = INT_MAX, min_index = -1;
		for (int i = 0; i < V; i++) {
			if (!mstSet[i] && key[i] < min) {
				min = key[i];
				min_index = i;
			}
		}
		return min_index;
	}

	void printMST(const vector <int >& parent) {
		std::cout << "Edge \t Weight \n";
		int totalWeight = 0;
		// Print each edge and its weight in the MST
		for (int i = 1; i < V; i++) {
			if (parent[i] != -1) {
				cout << parent[i] << " - " << i << " " << adjMatrix[i][parent[i]] << endl;
				totalWeight += adjMatrix[i][parent[i]];
			}
		}
		std::cout << "Total MST weight : " << totalWeight << std::endl;
	}

};


int main() {
	Graph g(5); // Create a graph with 5 vertices (0 to 4)

	g.addEdge(0, 1, 2);
	g.addEdge(0, 3, 6);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 8);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 4, 7);
	g.addEdge(3, 4, 9);

	/*g.addEdge(0, 1, 3);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 2, 2);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 3, 6);*/

	std::cout << "Minimum Spanning Tree using Prim’s algorithm :" << std::endl;
	g.PrimMST3();

	return 0;
}
