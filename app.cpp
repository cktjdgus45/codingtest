#include <bits/stdc++.h>
using namespace std;

int n;

ll go(int whole, int not_whole)
{
    if (whole == 0 && not_whole == 0)
        return 1; // escape.
    if (dp[whole][not_whole])
        return dp[whole][not_whole]; // momoization.
    ll &ret = dp[whole][not_whole];  // initialize
    if (while > 0)
        ret += go(whole - 1, not_whole + 1); // logic. 두가지 경우의수. 경우의수는 더하기.
    if (not_whole > 0)
        ret += go(whole, not_whole - 1); // logic.
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