#include <bits/stdc++.h>
using namespace std;

void bfs(int lvl, vector<int> v[], bool isVisited[], vector<int> &levl)
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        int parent = pr.first;
        int level = pr.second;
        q.pop();

        if (level == lvl)
        {
            levl.push_back(parent);
        }

        for (int i = 0; i < v[parent].size(); i++)
        {
            int children = v[parent][i];
            if (isVisited[children] == false)
            {
                isVisited[children] = true;
                q.push({children, level + 1});
            }
        }
    }
}

int main()
{
    vector<int> levl;
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
    int level;
    cin >> level;
    memset(isVisited, false, sizeof(isVisited));
    bfs(level, v, isVisited, levl);
    for (int i = levl.size() - 1; i >= 0; i--)
    {
        if (levl[i] != 0)
        {
            cout << levl[i] << " ";
        }
    }

    return 0;
}