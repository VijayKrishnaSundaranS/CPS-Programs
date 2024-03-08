#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Perform Breadth-First Search
void BFS(const vector<vector<int> >& adjList, int startVertex) {
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        // Traverse all adjacent vertices of currentVertex
        for (int i = 0; i < adjList[currentVertex].size(); ++i) {
            int adjVertex = adjList[currentVertex][i];
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int> > adjList(numVertices);

    cout << "Enter the edges (in the format: vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        // Assuming undirected graph
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(adjList, startVertex);
    cout << endl;

    return 0;
}
