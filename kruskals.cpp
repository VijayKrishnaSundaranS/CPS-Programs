#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;

        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    int kruskalMST() {
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int totalWeight = 0;

        for (const Edge& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (ds.find(u) != ds.find(v)) {
                ds.merge(u, v);
                totalWeight += weight;
            }
        }

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
    cout << "Weight of MST: " << g.kruskalMST() << endl;

    return 0;
}