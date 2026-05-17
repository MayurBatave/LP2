#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int vertex;
    int cost;

    bool operator<(const Node &other) const
    {
        return cost > other.cost;
    }
};

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

    // A* Algorithm
    void AStar(int start, int goal)
    {

        priority_queue<Node> pq;

        vector<int> cost(V, 1e9);
        vector<int> parent(V, -1);

        cost[start] = 0;

        pq.push({start, 0});

        while (!pq.empty())
        {

            int current = pq.top().vertex;
            pq.pop();

            if (current == goal)
                break;

            for (auto neighbour : adj[current])
            {

                int next = neighbour.first;
                int weight = neighbour.second;

                int newCost = cost[current] + weight;

                if (newCost < cost[next])
                {

                    cost[next] = newCost;
                    parent[next] = current;

                    pq.push({next, cost[next]});
                }
            }
        }

        // Print path
        vector<int> path;

        int temp = goal;

        while (temp != -1)
        {
            path.push_back(temp);
            temp = parent[temp];
        }

        cout << "\nShortest Path: ";

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }

        cout << "\nTotal Cost: " << cost[goal] << endl;
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

    int start, goal;

    cout << "Enter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    g.AStar(start, goal);

    return 0;
}