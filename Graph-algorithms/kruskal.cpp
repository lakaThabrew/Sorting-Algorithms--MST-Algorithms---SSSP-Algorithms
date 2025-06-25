#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU // Disjoint Set Union (Union-Find) data structure
{
private:
    vector<int> parent, rank;

public:
    DSU(int n) 
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) 
        {
            parent[i] = i;
        }
    }

    int find(int x) 
    {
        if (parent[x] != x) 
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) 
        {
            // Union by rank
            if (rank[rootX] < rank[rootY]) 
            {
                parent[rootX] = rootY;
            } 
            else if (rank[rootX] > rank[rootY]) 
            {
                parent[rootY] = rootX;
            } 
            else 
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};


int kruskal(int V, vector<tuple<int, int, int>>& edges) 
{
    sort(edges.begin(), edges.end()); // Sort edges by weight
    DSU dsu(V);
    int mst_weight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto [weight, u, v] : edges) 
    {
        if (dsu.unite(u, v)) {
            cout << u << " - " << v << " (weight " << weight << ")\n";
            mst_weight += weight;
        }
    }

    return mst_weight;
}


int main()
{
    int V = 6; // number of vertices
    vector<tuple<int, int, int>> edges = {
        {4, 0, 1},
        {4, 0, 2},
        {2, 1, 2},
        {5, 1, 3},
        {3, 2, 3},
        {6, 3, 4},
        {1, 4, 5}
    };

    int mst_cost = kruskal(V, edges);
    cout << "Total cost of MST: " << mst_cost << endl;
    return 0;
}