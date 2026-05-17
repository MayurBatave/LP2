#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{

    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v)
    {

        V = v;

        adj.resize(V);
    }

    // Add edge
    void addEdge(int u, int v, int w)
    {

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra Algorithm
    void dijkstra(int source)
    {

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        vector<int> dist(V, 1e9);

        dist[source] = 0;

        pq.push({0, source});

        while (!pq.empty())
        {

            int distance = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto neighbour : adj[node])
            {

                int next = neighbour.first;
                int weight = neighbour.second;

                if (dist[node] + weight < dist[next])
                {

                    dist[next] = dist[node] + weight;

                    pq.push({dist[next], next});
                }
            }
        }

        // Print shortest distances
        cout << "\nShortest Distance from Source Node:\n";

        for (int i = 0; i < V; i++)
        {

            cout << "Node " << i
                 << " -> " << dist[i] << endl;
        }
    }
};

int main()
{

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {

        int u, v, w;

        cin >> u >> v >> w;

        g.addEdge(u, v, w);
    }

    int source;

    cout << "Enter source node: ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}