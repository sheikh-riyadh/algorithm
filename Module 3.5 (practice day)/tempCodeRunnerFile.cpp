#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> v[], bool visited[], int &counter)
{

    visited[src] = true;
    for (int i = 0; i < v[src].size(); i++)
    {
        int children = v[src][i];
        if (visited[children] == false)
        {
            counter++;
            visited[children] = true;
            dfs(children, v, visited, counter);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    bool visited[n] = {false};
    vector<int> nodes;
    int counter = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        counter = 0;
        if (visited[i] == false)
        {
            dfs(i, v, visited, counter);
        }
        if (counter != 0)
        {
            nodes.push_back(counter + 1);
        }
    }

    sort(nodes.begin(), nodes.end());

    for (int i = 0; i < nodes.size(); i++)
    {

        cout << nodes[i] << " ";
    }

    return 0;
}