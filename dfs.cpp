#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dfs_order) 
{
    visited[start] = true;
    dfs_order.push_back(start);
    for (int j : graph[start])
    {
        if (!visited[j])
        {
            dfs(j, graph, visited, dfs_order);
        }
    }
}


int main()
{
    vector<vector<int>> graph;
    int n, m;
    cout << "Enter the number of vertices (n) and edges (m): "; 
    cin >> n >> m;
    graph.resize(n);
    cout << "Enter the edges (u v) for each edge:" << endl;
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    vector<bool> visited(n, false);
    vector<int> dfs_order;
    cout << "DFS Traversal starting from vertex 0:" << endl;
    dfs(0, graph, visited, dfs_order);
    for (int v : dfs_order) {
        cout << v << " ";
    }
    cout << endl;
}