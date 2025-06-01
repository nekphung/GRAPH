// File : Exercise_8 .cpp
# include < iostream >
# include < vector >
# include < queue >
# include < utility > // for std :: pair


using namespace std;
typedef pair<int, int> ii;

/*
Input:
V = 9
Edges : (0, 1, 4), (0, 7, 8), (1, 2, 8), (1, 7, 11), (2, 3, 7), (2, 8, 2), (2, 5, 4), (3, 4, 9),
(3, 5, 14), (4, 5, 10), (5, 6, 2), (6, 7, 1), (6, 8, 6), (7, 8, 7)

Output :
Minimum Spanning Tree using optimized Prim ’ s algorithm :
Edge Weight
0 - 1 4
1 - 2 8
2 - 3 7
2 - 5 4
2 - 8 2
5 - 6 2
6 - 7 1
3 - 4 9
Total MST weight : 37
*/

struct Edge {
	int dest;
	int weight;

	Edge(int d, int w) : dest(d), weight(w) {}
};

class Graph {
private:
	int V;
	std::vector < std::vector < Edge > > adjList;

public:
	Graph(int vertices) : V(vertices) {
		adjList.resize(V);
	}

	void addEdge(int src, int dest, int weight) {
		adjList[src].push_back(Edge(dest, weight));
		adjList[dest].push_back(Edge(src, weight)); 
	}

	void primMST() {
		priority_queue<ii, vector<ii>, greater<ii>> q;
		vector<int> key(V, 1e9);
		vector<int> parent(V, -1);
		vector<bool> inMST(V, false);

		q.push({ 0, 0 });
		key[0] = 0;

		while (!q.empty()) {
			ii top = q.top(); q.pop();
			int w = top.first, u = top.second;
			if (inMST[u] == true) continue;
			inMST[u] = true;
			for (Edge e : adjList[u]) {
				int v = e.dest, w = e.weight;
				if (!inMST[v] && key[v] > w) {
					key[v] = w;
					parent[v] = u;
					q.push({ w, v });
				}
			}
		}
		printMST(parent);
		for (int i = 0; i < V; i++) {
			cout << key[i] << " ";
		}
	}

	// TODO : Implement function to print the MST
	void printMST(const std::vector <int >& parent) {
		cout << "Edge \t Weight \n";
		int totalWeight = 0;
		// Print each edge and its weight in the MST
		for (int i = 0; i < V; i++) {
			if (parent[i] != -1) {
				for (Edge e : adjList[i]) {
					if (e.dest == parent[i]) {
						cout << parent[i] << " - " << i << " " << e.weight << endl;
						totalWeight += e.weight;
					}
				}

			}
		}
		cout << "Total MST weight : " << totalWeight << std::endl;
	}
};

int main() {
	//Graph g(9); // Create a graph with 9 vertices (0 to 8)

	/*g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);*/
	Graph g(6);

	/*g.addEdge(0, 1, 2);
	g.addEdge(0, 4, 7);
	g.addEdge(1, 3, 4);
	g.addEdge(3, 5, 1);
	g.addEdge(1, 5, 3);*/

	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 2);
	g.addEdge(0, 4, 4);
	g.addEdge(0, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 3);
	g.addEdge(4, 5, 8);
	g.addEdge(3, 5, 7);
	g.addEdge(3, 4, 3);

	std::cout << "Minimum Spanning Tree using optimized Prim ’s algorithm :" << std::endl;
	g.primMST();

	return 0;
}