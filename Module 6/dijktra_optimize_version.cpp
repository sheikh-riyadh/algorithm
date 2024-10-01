#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

vector<pair<int, int>> v[N];
int my_distance[N];

class compaire
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijktra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compaire> pq;
    pq.push({src, 0});
    my_distance[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        int parentNode = parent.first;
        int parentCost = parent.second;
        pq.pop();

        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int, int> children = v[parentNode][i];
            int childNode = children.first;
            int childCost = children.second;
            if (parentCost + childCost < my_distance[childNode])
            {
                my_distance[childNode] = parentCost + childCost;
                pq.push({childNode, parentCost + childCost});
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