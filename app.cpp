#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, temp;

int binarySearch(int temp, vector<int> &v)
{
	int l = 0;
	int r = v.size() - 1;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (v[mid] > temp)
			r = mid - 1;
		else if (v[mid] == temp)
			return 1;
		else
			l = mid + 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		vector<int> v;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{ // ¼öÃ¸1
			scanf("%d", &temp);
			v.push_back(temp);
		}
		srot(v.begin(), v.end());
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{ // ¼öÃ¸2
			scanf("%d", &temp);
			binarySearch(temp, v);
		}
	}
}