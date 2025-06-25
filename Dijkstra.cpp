#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Min-priority queue (min-heap)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Visit all adjacent nodes
        for (auto [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V = 6;
    vector<vector<pii>> adj(V);

    // Add edges (u, v, weight)
    adj[0].push_back({1, 1});
    adj[1].push_back({1, 0});

    adj[0].push_back({4, 2});
    adj[2].push_back({4, 0});

    adj[1].push_back({2, 2});
    adj[2].push_back({2, 1});

    adj[1].push_back({6, 3});
    adj[3].push_back({6, 1});

    adj[2].push_back({3, 3});
    adj[3].push_back({3, 2});

    adj[3].push_back({1, 4});
    adj[4].push_back({1, 3});

    int source = 1;
    dijkstra(V, adj, source);

    return 0;
}
