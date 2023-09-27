#include <bits/stdc++.h>
using namespace std;
int t, a, d[54][54];
char b[54][54];
bool check[54][54];
string s;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
bool in(int y, int x)
{
    return (1 <= y && y <= t && 1 <= x && x <= a);
}
int down(int y, int x)
{
    if (!in(y, x) || b[y][x] == 'H')
        return 0; // base case
    if (check[y][x])
    { // base case
        cout << -1 << "\n";
        exit(0);
    }
    int &ret = d[y][x]; // memoization
    if (ret)
        return ret; // base case

    check[y][x] = 1;
    int value = (int)b[y][x] - '0'; // to int
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, down(ny, nx) + 1);
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
    cout << down(1, 1) << "\n";
    return 0;
}