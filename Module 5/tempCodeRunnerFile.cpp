#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;

vector<int> v[N];
bool isVisited[N];
int parentArray[N];
bool answer;

void dfs(int parent)
{
    isVisited[parent] = true;

    for (int children : v[parent])
    {
        if (isVisited[children] == true && parentArray[parent] != children)
        {
            answer = true;
        }
        if (isVisited[children] == false)
        {
            parentArray[children] = parent;
            dfs(children);
        }
    }
}

int main()
{
    int n, e;
    answer = false;
    cin >> n >> e;

    memset(isVisited, false, sizeof(isVisited));
    memset(parentArray, -1, sizeof(parentArray));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
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