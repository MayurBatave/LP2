#include <iostream>
#include <vector>
using namespace std;

class GraphColoring
{

    int V;
    vector<vector<int>> graph;
    vector<int> color;

public:
    GraphColoring(int v)
    {

        V = v;

        graph.resize(V, vector<int>(V, 0));

        color.resize(V, 0);
    }

    // Add edge
    void addEdge(int u, int v)
    {

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Check whether color can be assigned
    bool isSafe(int node, int c)
    {

        for (int i = 0; i < V; i++)
        {

            if (graph[node][i] == 1 && color[i] == c)
                return false;
        }

        return true;
    }

    // Backtracking function
    bool solve(int node, int m)
    {

        // All vertices colored
        if (node == V)
            return true;

        // Try all colors
        for (int c = 1; c <= m; c++)
        {

            if (isSafe(node, c))
            {

                color[node] = c;

                // Recursive call
                if (solve(node + 1, m))
                    return true;

                // Backtracking
                color[node] = 0;
            }
        }

        return false;
    }

    // Print colors
    void printSolution()
    {

        cout << "\nVertex Colors:\n"
             << endl;

        for (int i = 0; i < V; i++)
        {

            cout << "Vertex " << i
                 << " --> Color " << color[i] << endl;
        }
    }
};

int main()
{

    int V, E, m;

    cout << "Enter number of vertices: ";
    cin >> V;

    GraphColoring g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++)
    {

        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    cout << "Enter number of colors: ";
    cin >> m;

    if (g.solve(0, m))
    {

        g.printSolution();
    }
    else
    {

        cout << "Solution does not exist.";
    }

    return 0;
}