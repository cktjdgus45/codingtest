#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int dp[10001];
int n, k, value;
int main()
{
    scanf("%d %d", &n, &k);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &value);
        if (value >= 10001)
            continue;
        for (int j = value; value <= k; j++)
        {
            dp[j] += dp[j - value];
        }
    }
    printf("%d\n", dp[k]);
}