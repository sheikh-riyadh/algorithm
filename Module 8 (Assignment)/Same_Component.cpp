#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool isVisited[N][N];
char matrix[N][N];

vector<pair<int, int>> movePoints = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isVilid(int x, int y, int n, int m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && (matrix[x][y] == '.'))
    {
        return true;
    }
    return false;
}

void dfs(int sx, int sy, int n, int m)
{
    isVisited[sx][sy] = true;

    for (int i = 0; i < 4; i++)
    {
        int cx = sx + movePoints[i].first;
        int cy = sy + movePoints[i].second;

        if (isVilid(cx, cy, n, m) && isVisited[cx][cy] == false)
        {
            dfs(cx, cy, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    pair<int, int> start, end;

    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            int sourceStart, sourceEnd;
            cin >> sourceStart >> sourceEnd;
            start = {sourceStart, sourceEnd};
        }
        else
        {
            int destinationStart, destinationEnd;
            cin >> destinationStart >> destinationEnd;
            end = {destinationStart, destinationEnd};
        }
    }

    dfs(start.first, start.second, n, m);

    if (isVisited[end.first][end.second])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
