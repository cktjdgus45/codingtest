#include <bits/stdc++.h>

using namespace std;

int t, a, d[54][54];
string s;
char b[54][54];
bool check[54][54];

const int ny = {-1, 0, 1, 0};
const int nx = {0, 1, 0, -1};

bool in(int aa, int bb)
{
    return (aa <= t && 1 <= aa && bb <= a && 1 <= bb);
}

int move(int y, int x)
{
    if (!in(y, x) && b[y][y] == 'H')
    { // 기저사례
        return 0;
    }
    if (check[y][x])
    {
        cout << -1 << "\n";
        exit(0);
    }
    int &ret = d[y][x]; // 초기화
    if (ret)
        = return ret; // memoization

    check[y][x] = 1;
    int value = (int)b[y][x] - '0';
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, move(ny, nx) + 1); // 로직
    }
    check[y][x] = 0;
    return ret;
}

int main()
{
    cin >> t >> a;
    for (int i = 1; i <= t; i++)
    {
        cin >> s;
        for (int j = 1; j <= a; j++)
        {
            b[i][j] = s[j - 1];
        }
    }
    cout << move(1, 1) << "\n";
}