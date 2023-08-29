#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int max_n = 130;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int N,INF = 987654321,a[max_n][max_n],dist[max_n][max_n],t;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int main(){
	while(++t){
		scanf("%d",&N);
		fill(&a[0][0],&a[0][0]+max_n*max_n,0);
		fill(&dist[0][0],&dist[0][0]+max_n*max_n,INF);
		for(int i = 0 ; i  < N ; i++){
			for(int j = 0 ; j< N;j++){
				scanf("%d",&a[i][j]);
			}
		}
		pq.push(make_pair(a[0][0],0));
		dist[0][0] = a[0][0];
		while(pq.size()){
			int herey = pq.top().second /1000;
			int herex = pq.top().second %1000;
			int here_dist = pq.top().first;
			pq.pop();
			if(dist[herey][herex] != here_dist) continue;
			for(int i = 0 ; i < 4 ; i++){
				int ny = y +dy[i];
				int nx = x +dx[i];
				if(dist[ny][nx] > dist[herey][herex] + here_dist){
					dist[ny][nx] = dist[herey][herex] + here_dist;
					pq.push(dist[ny][nx],ny*1000+nx);
				}
			}
		}
		printf("Problem %d: %d\n",t,dist[N-1][N-1]);
	}
	return 0;
}