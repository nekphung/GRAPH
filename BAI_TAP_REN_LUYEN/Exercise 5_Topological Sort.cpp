// File : Exercise_5 .cpp
# include < iostream >
# include < vector >
# include < stack >

using namespace std;

/*
Input:
V = 6
Edges : (5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)
Graph :
	5 -> 2 -> 3 -> 1
	-> 0 ^
	4 -------- > |
Output :
Topological Sort : 5 4 2 3 1 0
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

	// TODO : Implement function to perform topological sort
	void topologicalSort() {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. Create a stack to store the topological sort result
		// 3. Call the recursive topologicalSortUtil function for all unvisited vertices
		// 4. Pop and print the elements from the stack
		vector<bool> visited(V, false);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				topologicalSortUtil(i, visited, st);
			}
		}
		while (!st.empty()) {
			int top = st.top(); st.pop();
			cout << top << " ";
		}

	}

	// TODO : Implement the recursive topological sort utility function
	void topologicalSortUtil(int vertex, std::vector <bool >& visited, std::stack <int >& stack) {
		// 1. Mark the current vertex as visited
		// 2. Recursively visit all the adjacent vertices that are not visited
		// 3. Push the current vertex to the stack after visiting all adjacent vertices
		visited[vertex] = true;
		for (int v : adjList[vertex]) {
			if (!visited[v]) {
				topologicalSortUtil(v, visited, stack);
			}
		}
		stack.push(vertex);
	}

	// Helper function to check if the graph has a cycle (optional, for validation)
	bool hasCycle() {
		std::vector <bool > visited(V, false);
		std::vector <bool > recStack(V, false);

		for (int i = 0; i < V; i++) {
			if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
				return true;
			}
		}

		return false;
	}

	bool isCyclicUtil(int vertex, std::vector <bool >& visited, std::vector <bool >& recStack) {
		visited[vertex] = true;
		recStack[vertex] = true;

		for (int neighbor : adjList[vertex]) {
			if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) {
				return true;
			}
			else if (recStack[neighbor]) {
				return true;
			}
		}

		recStack[vertex] = false;
		return false;
	}
};

int main() {
	Graph g(6); // Create a graph with 6 vertices (0 to 5)

	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	if (g.hasCycle()) {
		std::cout << "Graph has a cycle . Topological sort is not possible ." << std::endl;
	}
	else {
		std::cout << "Topological Sort : ";
		g.topologicalSort();
	}

	return 0;
}
