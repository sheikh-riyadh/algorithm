#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const long long int INFI = 1e18 + 5;
vector<pair<int, int>> adj[N];
long long int dis[N];
int nodes, edge, source, testCase;

void dijktra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] =0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentCost = parent.first;
        int parentNode = parent.second;

        for (int i = 0; i < adj[parentNode].size(); i++)
        {
            pair<int, int> children = adj[parentNode][i];
            int childrenCost = children.first;
            int childrenNode = children.second;

            if (dis[parentNode] + childrenCost < dis[childrenNode])
            {
                dis[childrenNode] = dis[parentNode] + childrenCost;
                pq.push({dis[childrenNode], childrenNode});
            }
        }
    }
}

int main()
{
    cin >> nodes >> edge;
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    cin >> source >> testCase;

    dijktra(source);

    while (testCase--)
    {
        int destination, cost;
        cin >> destination >> cost;

        if (dis[destination] <= cost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}