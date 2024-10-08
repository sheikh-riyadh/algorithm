#include <bits/stdc++.h>
using namespace std;
const long long int INFI = 1e18 + 5;
const int N = 1e5;
long long int my_distance[N];
bool isVisited[N] = {false};
int source, testCase;

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
    cin >> source >> testCase;

    for (int i = 1; i <= n; i++)
    {
        my_distance[i] = INFI;
    }
    my_distance[source] = 0;

    for (int i = 1; i < n; i++)
    {
        for (Edge ed : edgeList)
        {
            if (my_distance[ed.u] < INFI && my_distance[ed.u] + ed.c < my_distance[ed.v])
            {
                my_distance[ed.v] = my_distance[ed.u] + ed.c;
                isVisited[ed.v] = true;
            }
        }
    }
    for (Edge ed : edgeList)
    {
        if (my_distance[ed.u] < INFI && my_distance[ed.u] + ed.c < my_distance[ed.v])
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        for (int i = 1; i <= testCase; i++)
        {
            int destination;
            cin >> destination;

            if (my_distance[destination] == INFI)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << my_distance[destination] << endl;
            }
        }
    }

    return 0;
}
