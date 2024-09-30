#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> v[], bool visited[], int &totalNode)
{

    visited[src] = true;
    for (int i = 0; i < v[src].size(); i++)
    {
        int children = v[src][i];
        if (visited[children] == false)
        {
            totalNode += 1;
            visited[children] = true;
            dfs(children, v, visited, totalNode);
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    bool visited[n] = {false};
    int totalNode = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;

    dfs(src, v, visited, totalNode);
    cout << "Total nodes: " << totalNode+1;

    return 0;
}