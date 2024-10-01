#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

vector<pair<int, int>> v[N];
int my_distance[N];

void dijktra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    my_distance[src] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int parentNode = parent.first;
        int parentCost = parent.second;
        q.pop();

        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int, int> children = v[parentNode][i];
            int childNode = children.first;
            int childCost = children.second;
            if (parentCost + childCost < my_distance[childNode])
            {
                my_distance[childNode] = parentCost + childCost;
                q.push({childNode, parentCost + childCost});
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
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        my_distance[i] = INT_MAX;
    }

    dijktra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << my_distance[i] << endl;
    }

    return 0;
}