#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> v[], int parent_track[], bool isVisited[])
{
    queue<int> q;
    isVisited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int i = 0; i < v[p].size(); i++)
        {
            int children = v[p][i];
            if (isVisited[children] == false)
            {
                isVisited[children] = true;
                q.push(children);
                parent_track[children] = p;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    bool isVisited[n];
    int parent_track[n];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int count = 0;
        int src, des;
        cin >> src >> des;
        memset(isVisited, false, sizeof(isVisited));
        memset(parent_track, -1, sizeof(parent_track));
        bfs(src, v, parent_track, isVisited);
        int x = des;
        while (x != -1)
        {
            if (x != des)
            {
                count++;
            }
            x = parent_track[x];
        }

        cout << count << endl;
    }

    return 0;
}