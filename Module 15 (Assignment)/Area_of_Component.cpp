#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

bool isVisited[N][N];
char matrix[N][N];

vector<pair<int, int>> movePoints = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isVilid(int x, int y, int n, int m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && matrix[x][y] == '.')
    {
        return true;
    }
    return false;
}

void bfs(int sx, int sy, int n, int m, int &componentsCount)
{
    isVisited[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    componentsCount += 1;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int parentX = parent.first;
        int parentY = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = parentX + movePoints[i].first;
            int cy = parentY + movePoints[i].second;

            if (isVilid(cx, cy, n, m) && isVisited[cx][cy] == false)
            {
                q.push({cx, cy});
                isVisited[cx][cy] = true;
                bfs(cx, cy, n, m, componentsCount);
            }
        }
    }
}

int main()
{
    int n, m, componentsCount = 0, answer = INT_MAX;
    cin >> n >> m;

    if (n == 0 || m == 0)
    {
        cout << 0;
        return 0;
    }

    vector<pair<int, int>> start;

    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == '.')
            {
                start.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < start.size(); i++)
    {
        if (isVisited[start[i].first][start[i].second] == false)
        {
            componentsCount = 0;
            bfs(start[i].first, start[i].second, n, m, componentsCount);

            answer = min(componentsCount, answer);
        }
    }

    answer != INT_MAX ? cout << answer : cout << -1;

    return 0;
}
