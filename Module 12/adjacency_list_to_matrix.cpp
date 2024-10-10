#include <bits/stdc++.h>
using namespace std;




void convert(int n, vector<int> adj[])
{
    int matrix[n][n];

    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < n; i++)
    {
        for (int child : adj[i])
        {
            matrix[i][child] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> v[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    convert(n, v);

    return 0;
}