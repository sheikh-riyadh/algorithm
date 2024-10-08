#include <bits/stdc++.h>
using namespace std;
const long long int INFI = 1e18 + 5;

int main() {
    int n, e;
    cin >> n >> e;
    long long int adj[n+1][n+1];

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INFI;
            if (i == j) {
                adj[i][j] = 0;
            }
        }
    }

    while (e--) {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] < INFI && adj[k][j] < INFI && adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int x, y;
        cin >> x >> y;
        if (adj[x][y] == INFI) {
            cout << -1 << endl;
        } else {
            cout << adj[x][y] << endl;
        }
    }

    return 0;
}
