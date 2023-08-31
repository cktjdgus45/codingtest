#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		int ret = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
		{
			auto pos = lower_bound(b.begin(), b.end(), a[i]);
			ret += (int)(pos - b.begin());
		}
		cout << ret << "\n";
	}
}