#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> v[], bool visited[])
{

    visited[src] = true;
    for (int i = 0; i < v[src].size(); i++)
    {
        int children = v[src][i];
        if (visited[children] == false)
        {
            visited[children] = true;
            bfs(src, v, visited);
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    bool visited[n] = {false};
    int componentCount = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            bfs(i, v, visited);
            componentCount++;
        }
    }

    cout << componentCount;

    return 0;
}