#include <bits/stdc++.h>
using namespace std;
int dp[1004][2][34]; // time,tree,move
int n, m, b[1004];

int go(int idx, int tree, int cnt)
{
    if (cnt < 0)
        return -1e9; // base case
    if (idx == n)
        return 0;
    int &ret = dp[idx][tree][cnt]; // memoization
    if (~ret)
        return ret;
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp)); // initialize
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
    return 0;
}