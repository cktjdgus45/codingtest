#include <bits/stdc++.h>
using namespace std;
int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> virusList, wallList;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// dfs
void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int solve()
{
    // virus set-up
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (pair<int, int> b : virusList)
    {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }
    // brute force , counting
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0 && !visited[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    // set-up
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; m++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                virusList.push_back({i, j});
            if (a[i][j] == 0)
                wallList.push_back({i, j});
        }
    }

    // combination
    for (int i = 0; i < wallList.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; j < j; k++)
            {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                ret = max(ret, solve());
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}