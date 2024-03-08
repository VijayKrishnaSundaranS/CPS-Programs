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
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();

            if (dist_u > dist[u]) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight_uv = neighbor.second;

                if (dist[u] + weight_uv < dist[v]) {
                    dist[v] = dist[u] + weight_uv;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
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

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<int> distances = g.dijkstra(source);

    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < V; ++i) {
        if (distances[i] == INF)
            cout << "Vertex " << i << ": unreachable" << endl;
        else
            cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}