#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
long long int parent[N];
long long int level[N];

class Edges
{
public:
    long long int u, v, w;
    Edges(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool comp(Edges a, Edges b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}

void dsu_initialize(long long int n)
{
    for (long long int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}

long long int dsu_find(long long int node)
{
    if (parent[node] == -1)
        return node;
    long long int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_level(long long int node1, long long int node2)
{
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);
    if (level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}

int main()
{

    long long int n, e, totalCost = 0;
    cin >> n >> e;
    vector<Edges> edgeList;
    dsu_initialize(n);
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edges(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), comp);

    for (auto ed : edgeList)
    {
        long long int leaderU = dsu_find(ed.u);
        long long int leaderV = dsu_find(ed.v);
        if (leaderU != leaderV)
        {
            dsu_union_by_level(ed.u, ed.v);
            totalCost += ed.w;
        }
    }

    int leader = dsu_find(1);
    bool isConnected = true;

    for (int i = 1; i <= n; i++)
    {
        if (dsu_find(i) != leader)
        {
            isConnected = false;
        }
    }

    !isConnected ? cout << -1 : cout << totalCost;

    return 0;
}