#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int parent_track[1005];
int level[1005];
bool isVisited[1005];

void bsf(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = true;
    level[src] = 0;

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
                level[children] = level[p] + 1;
                parent_track[children] = p;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(parent_track, -1, sizeof(parent_track));
    memset(level, -1, sizeof(level));
    memset(isVisited, false, sizeof(isVisited));
    int src, destination;
    cin >> src >> destination;
    bsf(src);
    int x = destination;

    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent_track[x];
    }
    reverse(path.begin(), path.end());

    for (int p : path)
    {
        cout << p << " ";
    }

    return 0;
}