#include <bits/stdc++.h>
using namespace std;
int a[54][54];    // 미세먼지 좌표.
int temp[54][54]; // 확산 동시성.
int n, m, t, ret;
vector<pair<int, int>> v1, v2;

int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

void mise_populate()
{
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != -1 && a[i][j])
            {
                q.push({i, j});
            }
        }
    }
    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int spread = a[y][x] / 5;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1)
                continue;
            temp[ny][nx] += spread; // 화살표 spread 더하기 (동시성)
            a[y][x] -= spread;      // 본체 spread 뺴기 (동시성)
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] += temp[i][j]; // 본체에 화살표spread 더하기 (동시성)
        }
    }
    return;
};
void wind_go(vector<pair<int, int>> &v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second]; // 바람방향대로 i = i-1
    }
    a[v[0].first][v[0].second] = 0; // 시작지점.
    return;
}
vector<pair<int, int>> wind_coords(int sy, int sx, int dy[], int dx[])
{
    vector<pair<int, int>> v;
    int cnt = 0;
    int y = sy; // start y coords
    int x = sx; // start x coords
    while (true)
    {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if (ny == sy && nx == sx)
            break;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (ny == sy && nx == sx)
            break; // sy,sx 제자리
        y = ny;
        x = nx;
        v.push_back({ny, nx}); // 바람예정방향대로 좌표넣어두기.
    }
    return v;
}

int main()
{
    cin >> n >> m >> t;
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            { // 공기청정기 좌표라면. 그기점으로.
                if (flag)
                {
                    v1 = wind_coords(i, j, dy1, dx1);
                    flag = false;
                }
                else
                {
                    v2 = wind_coords(i, j, dy2, dx2);
                }
            }
        }
    }
    while (t--)
    {
        mise_populate();
        wind_go(v1);
        wind_go(v2);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != -1)
                ret += a[i][j];
        }
    }

    cout << ret << "\n";
}