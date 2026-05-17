#include <bits/stdc++.h>
using namespace std;

int prims(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    int minCost = 0;

    // {weight, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    // Start from vertex 0
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // Skip if already visited
        if (inMST[u])
            continue;

        inMST[u] = true;
        minCost += wt;

        // Traverse adjacent vertices
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // Update only if smaller weight found
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;

                pq.push({weight, v});
            }
        }
    }

    // Print MST Path
    cout << "\nEdges in MST:\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i]
             << " - "
             << i
             << "  Weight = "
             << key[i]
             << endl;
    }

    return minCost;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Adjacency List
    vector<vector<pair<int, int>>> adj(V);

    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;

        cin >> u >> v >> wt;

        // Undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int ans = prims(V, adj);

    cout << "\nMinimum Cost of MST = "
         << ans;

    return 0;
}