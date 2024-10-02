#include <bits/stdc++.h>
#define ll long long int;
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
long long int dis[N];
int parentArray[N] = {-1};
int nodes, edge;

void dijktra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
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
                parentArray[childrenNode] = parentNode;
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
        adj[v].push_back({w, u});
    }

    dijktra(1);

    int current = nodes;
    vector<int> path;

    while (true)
    {
        path.push_back(current);
        if (current == 1)
        {
            break;
        }
        current = parentArray[current];
    }

    reverse(path.begin(),path.end());

    for (int children : path)
    {
        cout << children << " ";
    }

    return 0;
}