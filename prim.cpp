#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

int prim(int V, vector<vector<pii>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);  // Track parent to reconstruct edges

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    int total_weight = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        total_weight += weight;

        for (auto [v_weight, v] : adj[u]) {
            if (!inMST[v] && v_weight < key[v]) {
                key[v] = v_weight;
                parent[v] = u;
                pq.push({v_weight, v});
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int v = 1; v < V; ++v) {
        if (parent[v] != -1)
            cout << parent[v] << " - " << v << " (weight " << key[v] << ")\n";
    }

    return total_weight;
}

int main()
{
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add undirected edges (u, v, weight)
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});

    adj[0].push_back({3, 3});
    adj[3].push_back({3, 0});

    adj[1].push_back({4, 2});
    adj[2].push_back({4, 1});

    adj[1].push_back({1, 3});
    adj[3].push_back({1, 1});

    adj[2].push_back({5, 4});
    adj[4].push_back({5, 2});

    adj[3].push_back({7, 4});
    adj[4].push_back({7, 3});

    int total_weight = prim(V, adj);
    cout << "Total cost of MST: " << total_weight << endl;

    return 0;
}
// This code implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a graph.
// It uses a priority queue to efficiently select the next edge with the minimum weight.