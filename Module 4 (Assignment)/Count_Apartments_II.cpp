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

void bfs(int sx, int sy, int n, int m, int &apartmentsRooms)
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
                apartmentsRooms += 1;
                bfs(cx, cy, n, m, apartmentsRooms);
            }
        }
    }
}

int main()
{
    int n, m, apartmentsRooms = 0;
    vector<int> rooms;
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
            apartmentsRooms = 0;
            bfs(start[i].first, start[i].second, n, m, apartmentsRooms);
            rooms.push_back(apartmentsRooms);
        }
    }

    sort(rooms.begin(), rooms.end());

    if (rooms.size())
    {
        for (int node : rooms)
        {
            cout << node + 1 << " ";
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}
