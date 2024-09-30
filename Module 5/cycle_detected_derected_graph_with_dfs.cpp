#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> v[N];
bool isVisited[N];
int pathVisited[N];
bool answer;

void dfs(int parent)
{
    isVisited[parent] = true;
    pathVisited[parent] = true;

    for (int children : v[parent])
    {
        if (pathVisited[children]==true)
        {
            answer = true;
        }
        if (isVisited[children] == false)
        {
            dfs(children);
        }
    }

    pathVisited[parent] = false;
}

int main()
{

    int n, e;
    cin >> n >> e;

    memset(isVisited, false, sizeof(isVisited));
    memset(pathVisited, false, sizeof(pathVisited));
    answer = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == false)
        {
            dfs(i);
        }
    }
    answer ? cout << "Cycle detected!" : cout << "Cycle not found!";
    return 0;
}