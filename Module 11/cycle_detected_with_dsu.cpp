#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N] = {-1};
int level[N] = {0};




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
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    bool flag = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA ==leaderB)
        {
            flag = true;
        }
        else
        {
            dsu_union_by_level(a, b);
        }
    }

    flag ? cout << "Cycle detected" : cout << "Cycle not found";

    return 0;
}