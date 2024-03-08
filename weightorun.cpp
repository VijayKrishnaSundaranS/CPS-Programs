#include <iostream>
#include <vector>
#include <utility> // for std::pair

using namespace std;

// Pair for weighted graph (destination vertex, weight)
typedef pair<int, int> iPair;

// Function to add an edge to the unweighted graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v); // Add v to u's list
    adj[v].push_back(u); // Add u to v's list (for undirected graph)
}

// Function to add an edge to the weighted graph
void addEdge(vector<iPair> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // for undirected graph
}

// Function to print the adjacency list representation of unweighted graph
void printUnweightedGraph(vector<int> adj[], int V) {
    cout << "Unweighted Graph:" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "Vertex " << v << " -> ";
        for (auto x : adj[v])
            cout << x << " ";
        cout << endl;
    }
}

// Function to print the adjacency list representation of weighted graph
void printWeightedGraph(vector<iPair> adj[], int V) {
    cout << "Weighted Graph:" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "Vertex " << v << " -> ";
        for (auto x : adj[v])
            cout << x.first << " (weight: " << x.second << ") ";
        cout << endl;
    }
}

int main() {
    // Number of vertices
    int V = 5;
    // Adjacency list representation for unweighted graph
    vector<int> adjUnweighted[V];
    // Adjacency list representation for weighted graph
    vector<iPair> adjWeighted[V];

    // Adding edges to the unweighted graph
    addEdge(adjUnweighted, 0, 1);
    addEdge(adjUnweighted, 0, 4);
    addEdge(adjUnweighted, 1, 2);
    addEdge(adjUnweighted, 1, 3);
    addEdge(adjUnweighted, 1, 4);
    addEdge(adjUnweighted, 2, 3);
    addEdge(adjUnweighted, 3, 4);

    // Adding edges to the weighted graph
    addEdge(adjWeighted, 0, 1, 10);
    addEdge(adjWeighted, 0, 4, 20);
    addEdge(adjWeighted, 1, 2, 30);
    addEdge(adjWeighted, 1, 3, 40);
    addEdge(adjWeighted, 1, 4, 50);
    addEdge(adjWeighted, 2, 3, 60);
    addEdge(adjWeighted, 3, 4, 70);

    // Print the adjacency list for unweighted and weighted graphs
    printUnweightedGraph(adjUnweighted, V);
    cout << endl;
    printWeightedGraph(adjWeighted, V);

    return 0;
}