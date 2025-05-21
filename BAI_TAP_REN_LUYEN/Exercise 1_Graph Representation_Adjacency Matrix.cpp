// File : Exercise_1 .cpp
# include < iostream >
# include < vector >

using namespace std;

class Graph {
private:
	int V; // Number of vertices
	std::vector < std::vector <int > > adjMatrix;

public:
	// TODO : Implement constructor to initialize the graph with V vertices
	Graph(int vertices) {
		// Initialize V and create a V x V adjacency matrix
		V = vertices;
		adjMatrix.resize(V, vector<int>(V, 0));
	}

	// TODO : Implement function to add an edge from src to dest with weight
	void addEdge(int src, int dest, int weight = 1) {
		// Set the weight in the adjacency matrix
		adjMatrix[src][dest] = weight;
	}

	// TODO : Implement function to check if there is an edge from src to dest
	bool isEdge(int src, int dest) {
		// Check if there is an edge ( weight > 0) in the adjacency matrix
		if (adjMatrix[src][dest] > 0) return true;
		return false; // Replace with your implementation
	}

	// TODO : Implement function to get the weight of an edge from src to dest
	int getWeight(int src, int dest) {
		// Return the weight from the adjacency matrix , or 0 if no edge exists
		if (adjMatrix[src][dest] > 0) return adjMatrix[src][dest];
		return 0; // Replace with your implementation
	}

	// TODO : Implement function to print the adjacency matrix
	void printGraph() {
		
	}
};

int main() {
	Graph g(5); // Create a graph with 5 vertices (0 to 4)

	g.addEdge(0, 1, 2);
	g.addEdge(0, 3, 1);
	g.addEdge(1, 2, 3);
	g.addEdge(2, 3, 4);
	g.addEdge(3, 4, 5);
	g.addEdge(4, 0, 6);

	std::cout << " Adjacency Matrix representation of the graph :" << std::endl;
	g.printGraph();

	// Test isEdge and getWeight
	std::cout << "\nTesting edges :" << std::endl;
	std::cout << "Is there an edge from 0 to 1? " << (g.isEdge(0, 1) ? "Yes" : "No") << std::endl;
	std::cout << "Is there an edge from 1 to 0? " << (g.isEdge(1, 0) ? "Yes" : "No") << std::endl;
	std::cout << " Weight of edge from 2 to 3: " << g.getWeight(2, 3) << std::endl;

	return 0;
}
