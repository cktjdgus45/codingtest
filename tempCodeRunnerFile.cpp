#include <bits/stdc++.h>
using namespace std;
#define time ff
typedef long long ll;
int n, k, l, y, x, t, ret, idx, dir = 1;
int a[104][104], visited[104][104], time;
char c;
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    { // 사과배열
        cin >> y >> x;
        a[--y][--x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    { // 시간
        cin >> t >> c;
        if (c == 'D')
            _time.push_back({t, 1});
        else
            _time.push_back({t, 3});
    }
    dq.push_back({0, 0});
    while (dq.size())
    {
        time++;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny >= n || nx >= n || ny < 0 || nx < 0 || visited[ny][nx])
            break; // 벽,자신몸

        if (!a[ny][nx])
        { // 사과가없다면 꼬리짜르기
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        else
            a[ny][nx] = 0; // 사과먹음

        visited[ny][nx] = 1;          // 먹든안먹든 이동. visited
        dq.push_front({ny, nx});      // 좌표 front,머리이동.
        if (time == _time[idx].first) // time이되면
        {
            dir = (dir + _time[idx].second) % 4; // dy,dx 방향돌리기.
            idx++;
        }
    }
    cout << time << "\n";
    return 0;
}
