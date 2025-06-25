#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 1e9;

// Bellman-Ford function
bool bellmanFord(int V, int src, vector<tuple<int, int, int>>& edges, vector<int>& dist) {
    dist.assign(V, INF);
    dist[src] = 0;

    // Step 2: Relax all edges (V - 1) times
    for (int i = 0; i < V - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // Negative cycle found
        }
    }

    return true; // No negative cycles
}

int main() {
    int V = 5, E = 7;
    vector<tuple<int, int, int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        // Uncomment the line below to create a negative cycle:
        // {4, 3, -10}
    };

    vector<int> dist;
    int source = 0;

    if (bellmanFord(V, source, edges, dist)) {
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << ": ";
            if (dist[i] == INF)
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }
    } else {
        cout << "Negative weight cycle detected!\n";
    }

    return 0;
}
