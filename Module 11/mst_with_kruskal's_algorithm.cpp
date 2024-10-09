#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int level[N];

class Edges
{
public:
    int u, v, w;
    Edges(int u, int v, int w)
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

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
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

    int n, e, totalCost = 0;
    cin >> n >> e;
    vector<Edges> edgeList;
    dsu_initialize(n);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edges(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), comp);

    for (auto ed : edgeList)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if (leaderU != leaderV)
        {
            dsu_union_by_level(ed.u, ed.v);
            totalCost += ed.w;
        }
    }

    cout << totalCost;
    return 0;
}