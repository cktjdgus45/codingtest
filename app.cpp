#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	vector<ll> vv(k);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> vv[i];
	}
	sort(v.begin(), v.end());	// 보석 무게,가치
	sort(vv.begin(), vv.end()); // 가방 최대무게
	priority_queue<ll> pq;		// 내림차순 , top == max.
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && v[j].first <= vv[i])
			pq.push(v[j++].second);
		if (pq.size())
		{
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret << "\n";
	return 0;
}