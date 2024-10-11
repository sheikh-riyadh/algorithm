#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
bool isVisited[N][N];
char matrix[N][N];
int n, m;
map<pair<int, int>, pair<int, int>> par;

vector<pair<int, int>> movePoints = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool isVilid(int x, int y, int n, int m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && matrix[x][y] == '.' || matrix[x][y] == 'D' || matrix[x][y] == 'R')
    {
        return true;
    }
    return false;
}

void bfs(int sx, int sy, int n, int m)
{
    isVisited[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});

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
                par[{cx, cy}] = {parentX, parentY};
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    if (n == 0 || m == 0)
    {
        cout << 0;
        return 0;
    }

    pair<int, int> start, destination;

    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'D')
            {
                destination = {i, j};
            }
            else if (matrix[i][j] == 'R')
            {
                start = {i, j};
            }
        }
    }

    bfs(destination.first, destination.second, n, m);

    if (isVisited[start.first][start.second])
    {
        int stp = start.first;
        int enp = start.second;
        while (true)
        {

            int newStp = par[{stp, enp}].first;
            int newEnp = par[{stp, enp}].second;
            stp = newStp;
            enp = newEnp;
            if (matrix[stp][enp] == 'D')
                break;
            matrix[stp][enp] = 'X';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
