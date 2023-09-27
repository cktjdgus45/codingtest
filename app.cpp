#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;
const int INF = 987654321;
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];
int tsp(int here, int visited)
{
    if (visited == (1 << n) - 1) // 기저사례
    {
        return dist[here][0] ? dist[here][0] : INF;
    }
    int &ret = dp[here][visited]; // 메모이제이션
    if (ret != -1)
        return ret;
    ret = INF;
    for (int i = 0; i < n; i++) // 로직
    {
        if (visited & (1 << i))
            continue;
        if (dist[here][i] == 0)
            continue;
        ret = min(ret, tsp(i, (visited | (1 << i))) + dist[here][i]);
        cout << ret << "\n";
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp)); // 초기화
    cout << tsp(0, 1) << '\n';
    return 0;
}