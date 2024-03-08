#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Perform Depth-First Search
void DFS(const vector<vector<int> >& adjList, int startVertex) {
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);
    stack<int> st;

    visited[startVertex] = true;
    st.push(startVertex);
    cout << startVertex << " ";

    while (!st.empty()) {
        int currentVertex = st.top();
        bool hasUnvisitedNeighbor = false;

        // Traverse all adjacent vertices of currentVertex
        for (int i = 0; i < adjList[currentVertex].size(); ++i) {
            int adjVertex = adjList[currentVertex][i];
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                st.push(adjVertex);
                cout << adjVertex << " ";
                hasUnvisitedNeighbor = true;
                break; // Move to the next neighbor immediately
            }
        }

        // If there are no unvisited neighbors, backtrack
        if (!hasUnvisitedNeighbor) {
            st.pop();
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFS(adjList, startVertex);
    cout << endl;

    return 0;
}
