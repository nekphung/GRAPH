// File : Exercise_3 .cpp
# include < iostream >
# include < vector >
# include < queue >
# include < cstring > 
using namespace std;

/*Input:
V = 6
Edges : (0, 1), (0, 2), (1, 3), (2, 3), (2, 4), (3, 4), (3, 5), (4, 5)
Source : 0

Output :
	BFS traversal starting from vertex 0 :
	0 1 2 3 4 5
	
	Shortest paths from vertex 0 :
	Vertex 0 : distance = 0, path = 0
	Vertex 1 : distance = 1, path = 0 -> 1
	Vertex 2 : distance = 1, path = 0 -> 2
	Vertex 3 : distance = 2, path = 0 -> 1 -> 3 or 0 -> 2 -> 3
	Vertex 4 : distance = 2, path = 0 -> 2 -> 4
	Vertex 5 : distance = 3, path = 0 -> 2 -> 4 -> 5
*/
class Graph {
private:
	int V;
	std::vector < std::vector <int > > adjList;

public:
	Graph(int vertices) : V(vertices) {
		adjList.resize(V);
	}

	void addEdge(int src, int dest) {
		adjList[src].push_back(dest);
	}

	// TODO : Implement BFS traversal starting from source vertex
	void BFS(int source) {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. Create a queue for BFS
		// 3. Mark the source vertex as visited and enqueue it
		// 4. While the queue is not empty :
		// a. Dequeue a vertex and print it
		// b. Get all adjacent vertices of the dequeued vertex
		// c. If an adjacent vertex has not been visited , mark it as visited and enqueue it
		vector<bool> visited(V, false);
		queue<int> q;
		visited[source] = true;
		q.push(source);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			cout << x << " ";
			for (int v : adjList[x]) {
				if (!visited[v]) {
					q.push(v);
					visited[v] = true;
				}
			}
		}
	}

	// TODO : Implement function to find shortest paths from source to all vertices
	void shortestPath(int source) {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. Create an integer array ’distance ’ and initialize all entries as -1 ( infinity )
		// 3. Create an integer array ’parent ’ to store the shortest path tree
		// 4. Mark source as visited , set its distance as 0 , and enqueue it
		// 5. While the queue is not empty :
		// a. Dequeue a vertex
		// b. For all its adjacent vertices :
		// i. If not visited , mark as visited , set distance , set parent , and enqueue it
		// 6. Print the shortest distances and paths
		vector<bool> visited(V, false);
		vector<int> distance(V, -1);
		vector<int> parent(V, -1);
		queue<int> q;
		visited[source] = true;
		q.push(source);
		distance[source] = 0;
		while (!q.empty()) {
			int top = q.front(); q.pop();
			for (int v : adjList[top]) {
				if (!visited[v]) {
					parent[v] = top;
					visited[v] = true;
					q.push(v);
					distance[v] = distance[top] + 1;
				}
			}
		}
		for (int i = 0; i < V; i++) {
			if (distance[i] != -1) {
				cout << "Vertex " << i << " : " << "distance = " << distance[i] << ", paths = ";
				Printpath(parent, i);
			}
			cout << endl;
		}
	}

	void Printpath(const vector<int>& parent, int dest) {
		vector<int> res;
		while (dest != 0) {
			res.push_back(dest);
			dest = parent[dest];
		}
		res.push_back(0);
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size() ; i++) {
			if (i == res.size() - 1) {
				cout << res[i];
			}
			else cout << res[i] << " -> ";
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

	int printpath(const vector<int>& parent, int dest) {
		if (parent[dest] == -1) {
			cout << dest;
			return;
		}

		printpath(parent, parent[dest]);
		cout << " -> " << dest;
	}


};

int main() {
	Graph g(6); // Create a graph with 6 vertices (0 to 5)

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	std::cout << "BFS traversal starting from vertex 0:" << std::endl;
	g.BFS(0);

	std::cout << "\nShortest paths from vertex 0:" << std::endl;
	g.shortestPath(0);

	return 0;
}
