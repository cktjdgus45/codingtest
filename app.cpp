#include <bits/stdc++.h>
using namespace std;
int n, m, mx, sum, ret, a[100004], lo, hi;
bool check(int mid)
{
	if (mx > mid)
		return false;
	int temp = mid;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		// 17
		if (mid - a[i] < 0)
		{
			mid = temp;
			cnt++
		}
		mid -= a[i];
	}
	if (mid != temp)
		cnt++;
	return cnt <= m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i]; // 크기의 합.
		mx = max(mx, a[i]);
	}
	lo = 0;
	hi = sum;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid - 1;
			ret = mid;
		}
		else
			lo = mid + 1;
	}
	cout << ret << "\n";
	return 0;
}