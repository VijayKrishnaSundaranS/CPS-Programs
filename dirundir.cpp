#include <iostream>
#include <vector>

using namespace std;

void displayDirectedGraph(const vector<vector<int> >& adjList) {
    cout << "Directed Graph:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

void displayUndirectedGraph(const vector<vector<int> >& adjList) {
    cout << "Undirected Graph:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Create adjacency list for directed graph
    vector<vector<int> > directedGraph(numVertices);

    // Create adjacency list for undirected graph
    vector<vector<int> > undirectedGraph(numVertices);

    cout << "Enter the edges (in the format: vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        // Assuming directed graph
        directedGraph[vertex1].push_back(vertex2);
        // Assuming undirected graph
        undirectedGraph[vertex1].push_back(vertex2);
        undirectedGraph[vertex2].push_back(vertex1);
    }

    displayDirectedGraph(directedGraph);
    displayUndirectedGraph(undirectedGraph);

    return 0;
}
