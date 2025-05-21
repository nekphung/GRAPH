// File : Exercise_4 .cpp
# include < iostream >
# include < vector >
# include < queue >
# include < stack >

using namespace std;

/*
V = 6
Edges : (0, 1), (0, 2), (1, 3), (3, 4), (4, 5)
Source : 0
Additional edge : (5, 3)

DFS traversal starting from vertex 0 :
	0 1 3 4 5 2
	Does the graph have a cycle ? No
	After adding edge 5 - > 3, does the graph have a cycle ? Yes
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

	// TODO : Implement DFS traversal starting from source vertex
	void DFS(int source) {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. Call the recursive DFSUtil function
		vector<bool> visited(V, false);
		DFSUtil(source, visited);
	}

	// TODO : Implement the recursive DFS utility function
	void DFSUtil(int vertex, std::vector <bool >& visited) {
		// 1. Mark the current vertex as visited and print it
		// 2. Recursively visit all the adjacent vertices that are not visited
		visited[vertex] = true;
		cout << vertex << " ";
		for (int v : adjList[vertex]) {
			if (!visited[v]) {
				DFSUtil(v, visited);
			}
		}
	}

	// TODO : Implement function to detect cycle in the graph
	bool hasCycle() {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. Create a boolean array ’recStack ’ to keep track of vertices in the recursion stack
		// 3. Call the recursive isCyclicUtil function for all vertices
		vector<bool> visited(V, false);
		vector<bool> recStack(V, false);
		for (int i = 0; i < V; i++) {
			if (isCyclicUtil(i, visited, recStack)) return true;
		}
		return false; // Replace with your implementation
	}

	// TODO : Implement the recursive cycle detection utility function
	bool isCyclicUtil(int vertex, std::vector <bool >& visited, std::vector <bool >& recStack) {
		// 1. Mark the current vertex as visited and add it to the recursion stack
		// 2. Check all adjacent vertices :
		// a. If an adjacent vertex is not visited , recursively check if it leads to a cycle
		// b. If an adjacent vertex is in the recursion stack , there is a cycle
		// 3. Remove the vertex from the recursion stack and return false
		visited[vertex] = true;
		recStack[vertex] = true;
		for (int v : adjList[vertex]) {
			if (!visited[v] && isCyclicUtil(v, visited, recStack)) {
				return true;
			}
			else if (recStack[v]) {
				return true;
			}
		}
		recStack[vertex] = false;
		return false; // Replace with your implementation
	}
};

int main() {
	Graph g(6); // Create a graph with 6 vertices (0 to 5)

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	std::cout << "DFS traversal starting from vertex 0:" << std::endl;
	g.DFS(0);

	std::cout << "\nDoes the graph have a cycle ? "
		<< (g.hasCycle() ? "Yes " : "No") << std::endl;

	// Adding an edge that creates a cycle
	g.addEdge(5, 3);

	std::cout << "After adding edge 5 -> 3 , does the graph have a cycle ? "
		<< (g.hasCycle() ? "Yes " : "No") << std::endl;

	return 0;
}
