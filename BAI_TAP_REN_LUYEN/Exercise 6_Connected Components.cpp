// File : Exercise_6 .cpp
# include < iostream >
# include < vector >

/*
Input :
V = 8
Edges : (0, 1), (1, 2), (2, 0), (3, 4), (4, 5), (6, 7)

Output :
Connected Components :
Component 1 : 0 1 2
Component 2 : 3 4 5
Component 3 : 6 7

Is the graph connected ? No
*/

using namespace std;

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
		adjList[dest].push_back(src); // For undirected graph
	}

	// TODO : Implement function to find all connected components
	void findConnectedComponents() {
		// 1. Create a boolean array ’visited ’ and mark all vertices as not visited
		// 2. For each unvisited vertex , call the DFS or BFS function to explore its component
		// 3. Print each component
		vector<bool> visited(V, false);
		vector<int> component; 
		int countComponent = 0;
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				component.clear();
				DFSUtil(i, visited, component);
				countComponent++;
				cout << "Component " << countComponent << " : ";
				for (int x : component) {
					cout << x << " ";
				}
				cout << endl;
			}

		}
	}

	// TODO : Implement DFS to explore a connected component
	void DFSUtil(int vertex, std::vector <bool >& visited, std::vector <int >& component) {
		// 1. Mark the current vertex as visited and add it to the component
		// 2. Recursively visit all the adjacent vertices that are not visited
		component.push_back(vertex);
		visited[vertex] = true;
		for (int v : adjList[vertex]) {
			if (!visited[v]) {
				DFSUtil(v, visited, component);
			}
		}
	}

	// Optional : Implement function to check if the graph is connected
	bool isConnected() {
		// 1. Start DFS from the first vertex
		// 2. Check if all vertices are visited after the DFS
		if (V == 0) return true;
		vector<int> component;
		vector<bool> visited(V, false);
		DFSUtil(0, visited, component);
		for (int i = 0; i < V; i++) {
			if (!visited[i])  return false;
		}
		return true; // Replace with your implementation
	}
};

int main() {
	Graph g(8); // Create a graph with 8 vertices (0 to 7)

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(6, 7);

	std::cout << "Connected Components :" << std::endl;
	g.findConnectedComponents();

	std::cout << "\nIs the graph connected ? "
		<< (g.isConnected() ? "Yes " : "No") << std::endl;

	return 0;
}
