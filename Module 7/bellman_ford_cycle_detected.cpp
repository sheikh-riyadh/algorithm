#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int my_distance[N];

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    bool isCycle = false;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    for (int i = 0; i < n; i++)
    {
        my_distance[i] = INT_MAX;
    }
    my_distance[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (Edge ed : edgeList)
        {
            if (my_distance[ed.u] < INT_MAX && my_distance[ed.u] + ed.c < my_distance[ed.v])
            {
                my_distance[ed.v] = my_distance[ed.u] + ed.c;
            }
        }
    }

    for (Edge ed : edgeList)
    {
        if (my_distance[ed.u] < INT_MAX && my_distance[ed.u] + ed.c < my_distance[ed.v])
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
    {
        cout << "Cycle found no anwer";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << my_distance[i] << endl;
        }
    }

    return 0;
}