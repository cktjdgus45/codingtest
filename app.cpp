#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[300004], ret = 1e18;

bool check(ll mid)
{
	ll num = 0;
	for (int i = 0; i < m; i++)
	{
		num += a[i] / mid; // 4/3 =1 , 4%3 = 1 ,2명 , 7/3 = 2명 , 7%3 =1  ,3명 mid =질투심
		if (a[i] % mid)
			num++;
	}
	return n >= num;
}

int main()
{
	cin >> n >> m; // 5,2
	ll lo = 1, hi = 0, mid;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i]; // 7,4
		hi = max(hi, a[i]);
	}
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	cout << ret << "\n";
	return 0;
}