#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int, int> P;
P L[1000004];
int n, from, to, l, r, ret;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        L[i] = P(from, to);
    }
    sort(L, L + n); // sort
    l = L[0].first;
    r = L[0].second;
    for (int i = 1; i < n; i++) // logic
    {
        if (r < L[i].first)
        {
            ret += (r - l);
            r = L[i].first;
            l = L[i].second;
        }
        else if (r <= L[i].second && r >= L[i].first)
        {
            r = L[i].second;
        }
    }
    ret += (r - l);
    cout << ret << "\n";
}