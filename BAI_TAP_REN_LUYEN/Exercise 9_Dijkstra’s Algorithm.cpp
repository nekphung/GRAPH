// File : Exercise_9 .cpp
# include < iostream >
# include < vector >
# include < climits >


using namespace std;

/*
Input:
V = 6
Edges : (0, 1, 5), (0, 2, 3), (1, 3, 6), (1, 2, 2), (2, 3, 7), (2, 4, 4), (2, 5, 2), (3, 4, 1),
(4, 5, 2)
Source : 0

Output :
Shortest paths from vertex 0 using Dijkstra’ s algorithm :
Vertex Distance from Source
0 0
1 5
2 3
3 10
4 7
5 5
*/

class Graph {
private:
	int V;
	vector <vector <int> > adjMatrix;

public:
	Graph(int vertices) : V(vertices) {
		adjMatrix.resize(V, std::vector <int >(V, 0));
	}

	void addEdge(int src, int dest, int weight) {
		adjMatrix[src][dest] = weight;
	}

	// TODO : Implement Dijkstra ’s algorithm
	void dijkstra(int source) {
		// 1. Create arrays to store the shortest distance and whether a vertex is finalized
		// - dist []: Shortest distance from source to i
		// - sptSet []: True if vertex i is included in shortest path tree
		vector<int> dist(V, 1e9);
		vector<bool> sptSet(V, false);
		vector<int> parent(V, -1);
		dist[0] = 0;
		for (int i = 0; i < V; i++) {
			int u = minDistance(dist, sptSet);
			if (u == -1) {
				break;
			}
			sptSet[u] = true;
			for (int v = 0; v < V; v++) {
				if (adjMatrix[u][v] > 0 && !sptSet[v] && (dist[u] + adjMatrix[u][v] < dist[v]) && dist[u] != 1e9) {
					dist[v] = dist[u] + adjMatrix[u][v];
					parent[v] = u;
				}
			}
		}
		// 2. Initialize all distances as INFINITE and sptSet as false

		// 3. Set distance of source vertex as 0

		// 4. Find shortest path for all vertices :
		// a. Pick the vertex with minimum distance that is not yet processed
		// b. Mark the picked vertex as processed
		// c. Update dist [] values of adjacent vertices

		// 5. Print the shortest distances
		printSolution(dist, parent);
	}

	// TODO : Implement function to find the vertex with the minimum distance
	int minDistance(const vector <int>& dist, const vector <bool>& sptSet) {
		int min = INT_MAX, min_index = -1;
		// Find the vertex with the minimum distance value
		for (int i = 0; i < V; i++)
		{
			if (!sptSet[i] && dist[i] < min) {
				min = dist[i];
				min_index = i;
			}
		}
		return min_index;
	}

	// TODO : Implement function to print the shortest distances
	void printSolution(const std::vector <int >& dist, const vector<int> parent) {
		cout << "Vertex \t Distance from Source \t  Path \n";
		// Print each vertex and its distance from the source
		for (int i = 0; i < V; i++) {
			if (dist[i] == 1e9) {
				cout << i << " " << "INF" << endl;
			}
			else cout << i << " " << dist[i] << " ";
			printPath(parent, i);
			cout << endl;
		}
	}

	void printPath(const vector<int>& parent, int dest) {
		if (parent[dest] == -1) {
			cout << dest;
			return;
		}
		else {
			printPath(parent, parent[dest]);
			cout << " -> " << dest;
		}
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
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int source = 0;
	std::cout << " Shortest paths from vertex " << source << " using Dijkstra ’s algorithm :" << std::endl;
	g.dijkstra(source);

	return 0;
}
