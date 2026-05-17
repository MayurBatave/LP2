#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wt;
};

// Comparator for sorting edges
bool cmp(Edge a, Edge b)
{
    return a.wt < b.wt;
}

class DSU
{
    vector<int> parent, rank1;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank1.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank1[pu] < rank1[pv])
        {
            parent[pu] = pv;
        }
        else if (rank1[pv] < rank1[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank1[pu]++;
        }
    }
};

int kruskal(int V, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int minCost = 0;

    cout << "\nEdges in MST:\n";

    for (auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        // If no cycle formed
        if (dsu.findParent(u) != dsu.findParent(v))
        {
            dsu.unionSet(u, v);

            minCost += wt;

            cout << u
                 << " - "
                 << v
                 << "  Weight = "
                 << wt
                 << endl;
        }
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

    vector<Edge> edges;

    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        Edge e;

        cin >> e.u >> e.v >> e.wt;

        edges.push_back(e);
    }

    int ans = kruskal(V, edges);

    cout << "\nMinimum Cost of MST = "
         << ans;

    return 0;
}