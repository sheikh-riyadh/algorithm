#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005] = {false};

void bfs(int src)
{
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << endl;
        for (int i = 0; i < v[parent].size(); i++)
        {
            int children = v[parent][i];
            if (visited[children] == false)
            {
                visited[children] = true;
                q.push(children);
            }
        }
    }
};

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

    int src;
    cin >> src;
    bfs(src);

    return 0;
}