#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> v[], bool isVisited[])
{
    cout << src << " ";
    isVisited[src] = true;
    for (int i = 0; i < v[src].size(); i++)
    {
        int children = v[src][i];
        if (isVisited[children] == false)
        {
            dfs(children, v, isVisited);
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    bool isVisited[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));
    dfs(0, v, isVisited);

    return 0;
}