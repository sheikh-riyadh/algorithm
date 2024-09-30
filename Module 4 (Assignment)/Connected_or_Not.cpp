#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (matrix[a][b] == 1)
        {
            cout << "YES" << endl;
        }
        else if (a == b && a < n && b < n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}