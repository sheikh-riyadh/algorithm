#include <bits/stdc++.h>
using namespace std;

void convert(int n, vector<pair<int, int>> adj[])
{
    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = -1;
            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            if (i == child.first)
            {
                matrix[i][child.first] = 0;
            }
            matrix[i][child.first] = child.second;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

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
        // adj[v].push_back({u, w});
    }

    convert(n, adj);
    return 0;
}