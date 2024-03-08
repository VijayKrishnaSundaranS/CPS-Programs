#include <iostream>
#include <vector>

using namespace std;

// Function to create adjacency list
vector<vector<int> > createAdjacencyList(int vertices) {
    // Initialize adjacency list
    vector<vector<int> > adjList(vertices);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (in the format: vertex1 vertex2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        // Assuming it's an undirected graph, so adding both edges
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    return adjList;
}

// Function to print adjacency list
void printAdjacencyList(const vector<vector<int> >& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            if (i < adjList[i][j]) // Print only once for undirected graph
                cout << i << "->" << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int> > adjList = createAdjacencyList(vertices);
    printAdjacencyList(adjList);

    return 0;
}

