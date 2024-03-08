#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

class Graph {
private:
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // Since the graph is undirected
    }

    int primMST() {
        vector<int> key(V, INF); // Key values used to pick minimum weight edge in cut
        vector<int> parent(V, -1); // Array to store constructed MST
        vector<bool> inMST(V, false); // To represent set of vertices not yet included in MST

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Add source vertex to priority queue and initialize its key as 0
        pq.push(make_pair(0, 0));
        key[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            // Traverse all adjacent vertices of u
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If v is not in MST and weight of (u,v) is less than current key of v
                if (!inMST[v] && weight < key[v]) {
                    // Update key of v
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Calculate the total weight of MST
        int totalWeight = 0;
        for (int i = 1; i < V; ++i)
            totalWeight += key[i];

        return totalWeight;
    }
};

int main() {
    int V, E; // V - number of vertices, E - number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    // Input edges
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // Output the weight of the minimum spanning tree
    cout << "Weight of MST: " << g.primMST() << endl;

    return 0;
}