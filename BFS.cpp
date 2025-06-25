#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

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
    queue<int> q;
    cout << "BFS Traversal starting from vertex 0:" << endl;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) 
        {
            if (!visited[neighbor]) 
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

}