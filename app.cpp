#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int n ,m,a[10][10],visited[10][10],ret;
vector<pair<int,int>>virusList,wallList;

void dfs(int y,int x){
    visited[y][x]=1;
    for(int i = 0 ; i < 4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny <0 || nx <0 || ny >=n || nx >=m || visited[ny][nx] || a[ny][nx] ==1) continue;
        dfs(ny,nx);
    }
    return;
}

int solve(){
    //바이러스 퍼뜨리기
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0); 
    for(pair<int,int>b:virusList){
        visited[b.first][b.second] =1; //바이러스 표시.
        dfs(b.first,b.second);
    }
    int cnt = 0;        
    //안전영역 개수 구하기. 
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(a[i][j]==0 && !visited[i][j])cnt++;
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> a[i][j];
            if(a[i][j]==2)virusList.push_back({i,j});
            if(a[i][j]==0)wallList.push_back({i,j});
        }
    }
    for(int i = 0 ; i < wallList.size();i++){
        for(int j = 0 ; j < i;j++){
            for(int k = 0 ; k < j;k++){
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret,solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
        }
        }
    }
    cout << ret << "\n";
    return 0;
}