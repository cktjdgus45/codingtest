#include <bits/stdc++.h>
using namespace std;
int n, ret;

struct Board
{
    int a[24][24];
    void move()
    {
        int temp[24][24];
        for (int i = 0; i < n; i++)
        {
            int c = -1, d = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                    continue;
                if (d && a[i][j] == temp[i][c])
                    temp[i][c] *= 2, d = 0;
                else
                    temp[i][++c] = a[i][j], d = 1; // push
            }
            for (c++; c < n; c++)
                temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }
    void rotate_90()
    {
        int temp[24][24];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
    void get_max()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board c, int here)
{
    if (here == 5)
    {
        c.get_max(); // 한쪽방면 max값 축적.
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        Board d = c;
        d.move();        // 한쪽으로 더하기(한쪽방면) ,한쪽으로 더하기(한쪽방면) ,한쪽으로 더하기(한쪽방면),한쪽으로 더하기(한쪽방면) (90도씩 회전후)
        go(d, here + 1); // here=0 move ,here=1 move , here =2 move ... 총5번 이동.
        d.rotate_90();   // 회전
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    Board c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c.a[i][j];
        }
    }
    go(c, 0);
    cout << ret << "\n";
    return 0;
}