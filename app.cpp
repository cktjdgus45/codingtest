#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // 경우의 수 ll박고시작.
ll n, dp[31][31];     // N <= 30

int go(int whole, int not_whole)
{
    if (whole == 0 && not_whole == 0) // base case
        return 1;
    if (dp[whole][not_whole])
        return dp[whole][not_whole];
    ll &ret = dp[whole][not_whole]; // memoization
    if (whole > 0)                  // logic
        ret += go(whole - 1, not_whole + 1);
    if (not_whole > 0)
        ret += go(whole, not_whole - 1);
    return ret;
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << go(n, 0) << "\n";
    }
}