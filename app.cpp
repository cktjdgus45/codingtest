#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int dp[100001]; // 1<= K <= 100000
int n, k, w, v;
int main()
{
    scanf("%d %d", &n, &k);
    while (n--)
    {
        scanf("%d %d", &w, &v);
        for (int j = k; j >= w; j--) // �ִ� k��ŭ�� ���Ը��� ������ �ִ� �賶.
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    printf("%d", dp[k]);
    return 0;
}