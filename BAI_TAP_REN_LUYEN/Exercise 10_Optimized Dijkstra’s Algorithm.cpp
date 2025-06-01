// File : Exercise_10 .cpp
# include < iostream >
# include < vector >
# include < queue >
# include < utility > // for std :: pair
# include < climits >


using namespace std;

typedef pair<int, int> ii;

/*
Input:
V = 6
Edges : (0, 1, 5), (0, 2, 3), (1, 3, 6), (1, 2, 2), (2, 3, 7), (2, 4, 4), (2, 5, 2), (3, 4, 1),
(4, 5, 2)
Source : 0

Output :
Shortest paths from vertex 0 using optimized Dijkstra ’ s algorithm :
Vertex Distance Path
0 0 0
1 5 0 -> 1
2 3 0 -> 2
3 10 0 -> 2 -> 3
4 7 0 -> 2 -> 4
5 5 0 -> 2 -> 5
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
	}

	// TODO : Implement optimized Dijkstra ’s algorithm using priority queue
	void dijkstra(int source) {
		priority_queue<ii, vector<ii>, greater<ii>> q;
		vector<int> dist(V, 1e9);
		vector<int> parent(V, -1);
		vector<bool> visited(V, false);
		dist[source] = 0;
		q.push({ 0, source });

		while (!q.empty()) {
			ii e = q.top(); q.pop();
			int w = e.first, u = e.second;
			if (visited[u] == true) continue;
			visited[u] = true;
			for (Edge E : adjList[u]) {
				int x = E.dest, y = E.weight;
				if (!visited[x] && dist[x] > dist[u] + y) {
					dist[x] = dist[u] + y;
					parent[x] = u;
					q.push({ dist[x], x });
				}
			}
		}
		printPaths(dist, parent);
	}

	void printPaths(const std::vector <int >& dist, const std::vector <int >& parent) {
		// For each vertex , print its distance and path from the source
		cout << "Vertex \tDistance \tPath " << std::endl;
		for (int i = 0; i < V; i++) {
			cout << i << " " << dist[i] << " ";
			printPath(parent, i);
			cout << endl;
		}
	}

	// Helper function to print path from source to destination
	void printPath(const vector <int>& parent, int dest) {
		if (parent[dest] == -1) {
			cout << dest;
			return;
		}
		printPath(parent, parent[dest]);
		cout << " -> " << dest;
	}
};

int main() {
	Graph g(6); // Create a graph with 6 vertices (0 to 5)

	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 5, 2);

	int source = 0;
	std::cout << " Shortest paths from vertex " << source << " using optimized Dijkstra’s algorithm :" << std::endl;
	g.dijkstra(source);

	return 0;
}
