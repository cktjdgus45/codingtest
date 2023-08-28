#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int V, E, K, u, v, w;
vector<pair<int, int>> adj[20001];
int dist[20001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
	// set-up
	scanf("%d %d %d", &V, &E, &K);
	fill(dist, dist + 20001, INF);
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(w, v));
	}
	pq.push(make_pair(0, K)); // adj (w,v) == pt (w.v)
	dist[K] = 0;			  // dist[V] = w(E);

	// Dijkstra
	while (pq.size())
	{
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist)
			continue;
		for (pair<int, int> there : adj[here])
		{
			int _there = there.second;
			int _there_dist = there.first;
			if (dist[_there] > dist[here] + _there_dist)
			{
				dist[_there] = dist[here] + _there_dist;
				pq.push(dist[_there], _there);
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			pust("INF");
		else
			printf("%d", dist[i]);
	}
	return 0;
}