#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<Edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            edgelist.push_back(Edge(i, child.first, child.second));
        }
    }

    for (Edge child : edgelist)
    {
        cout << child.u << " " << child.v << " " << child.w << endl;
    }

    return 0;
}