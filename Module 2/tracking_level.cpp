#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool isVisited[1005] = {false};
int level[1005] = {-1};

void bsf(int src)
{
    queue<int> q;
    q.push(src);
    isVisited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            int children = v[parent][i];
            if (isVisited[children] == false)
            {
                isVisited[children] = true;
                q.push(children);
                level[children] = level[parent] + 1;
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

    int src;
    cin >> src;
    bsf(src);

    return 0;
}