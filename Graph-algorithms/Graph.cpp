#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> graph;

    int n, m;
    cout << "Enter the number of vertices (n) and edges (m): ";
    cin >> n >> m;
    graph.resize(n + 1);

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));

    cout << "Enter the edges (u v) for each edge:\n";
    for (int i =0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming undirected graph
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    cout << "Adjacency list representation of the graph:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "Adjacency matrix representation of the graph:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}