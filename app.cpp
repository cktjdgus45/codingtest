#include <bits/stdc++.h>
using namespace std;
int n, ret, x;
int main()
{
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	sort(a.begin(), a.end());
	int l = 0;
	int r = n - 1;
	while (l < r)
	{
		if (a[l] + a[r] == x)
			r--, ret++;
		else if (a[l] + a[r] < x)
			l++;
		else if (a[l] + a[r] > x)
			r--;
	}
	cout << ret << "\n";
	return 0
}