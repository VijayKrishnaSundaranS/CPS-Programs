#include <iostream>
#include <vector>

using namespace std;

// Function to create adjacency matrix
vector<vector<int> > createAdjacencyMatrix(int vertices) {
    // Initialize matrix with all 0's
    vector<vector<int> > adjMatrix(vertices, vector<int>(vertices, 0));

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (in the format: vertex1 vertex2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        // Assuming it's an undirected graph, so marking both edges
        adjMatrix[vertex1][vertex2] = 1;
        adjMatrix[vertex2][vertex1] = 1;
    }

    return adjMatrix;
}

// Function to print adjacency matrix
void printAdjacencyMatrix(const vector<vector<int> >& adjMatrix) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int> > adjMatrix = createAdjacencyMatrix(vertices);
    printAdjacencyMatrix(adjMatrix);

    return 0;
}
