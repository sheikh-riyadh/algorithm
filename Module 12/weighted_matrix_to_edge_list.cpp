#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<Edge> edgelist;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > 0)
            {
                edgelist.push_back(Edge(i, j, matrix[i][j]));
            }
        }
    }

    for (Edge child : edgelist)
    {
        cout << child.u << " " << child.v << " " << child.w << endl;
    }
    return 0;
}