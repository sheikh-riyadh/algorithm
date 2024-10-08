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
    parent[1] = 3;
    parent[2] = 2;
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

void dsu_union(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    parent[leaderA] = leaderB;
}

int main()
{

    cout << endl;
    dsu_initialize(4);
    cout << dsu_find(0) << endl;
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;
    return 0;
}