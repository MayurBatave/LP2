#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        visited[start] = true;
        stack<int> st;
        st.push(start);

        while (!st.empty())
        {
            int ele = st.top();
            st.pop();

            cout << ele << " ";
            for (int neighbour : adj[ele])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    st.push(neighbour);
                }
            }
        }
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> que;
        visited[start] = true;
        que.push(start);

        while (!que.empty())
        {
            int element = que.front();
            que.pop();

            cout << element << " ";

            for (int neighbour : adj[element])
            {
                if (visited[neighbour] == false)
                {
                    visited[neighbour] = true;
                    que.push(neighbour);
                }
            }
        }
    }
};

int main()
{
    cout << " Enter the Number of the Vertices : ";
    int n;
    cin >> n;
    Graph g(n);

    cout << " Enter the Number of Edges : ";
    int E;
    cin >> E;
    cout << " Enter the Edges : ";
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << " Enter the Starting Vertex : ";
    int st;
    cin >> st;

    while (true)
    {
        cout << "------------------MENU------------------" << endl;
        cout << " 1. DFS \n 2. BFS \n 3. Exit " << endl;
        int op;
        cin >> op;
        if (op == 3)
        {
            cout << " Thanks For Using our Program...";
            break;
        }
        else if (op == 1)
        {
            g.DFS(st);
            cout << endl;
        }
        else
        {
            g.BFS(st);
            cout << endl;
        }
    }

    return 0;
}