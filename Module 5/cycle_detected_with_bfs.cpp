#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;

vector<int> v[N];
bool isVisited[N];
int parentArray[N];
bool answer;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    isVisited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int children : v[parent])
        {
            if (isVisited[children] == true && children != parentArray[parent])
            {
                answer = true;
            }
            if (isVisited[children] == false)
            {
                isVisited[children] = true;
                parentArray[children] = parent;
                q.push(children);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    memset(isVisited, false, sizeof(isVisited));
    memset(parentArray, -1, sizeof(parentArray));
    answer = false;

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
            bfs(i);
        }
    }
    answer ? cout << "Cycle detected!" : cout << "Cycle not found!";
    return 0;
}
