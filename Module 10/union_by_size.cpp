#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int dsu_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        dsu_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    if (dsu_size[leaderA] > dsu_size[leaderB])
    {
        parent[leaderB] = leaderA;
        dsu_size[leaderA] += dsu_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        dsu_size[leaderB] += dsu_size[leaderA];
    }
}

int main()
{

    cout << endl;
    dsu_initialize(7);
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;
    return 0;
}