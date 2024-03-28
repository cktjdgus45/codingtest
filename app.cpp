#include <bits/stdc++.h>
using namespace std;

int a[104][104], visited[104][104];
int dy[]={-1,0,1,0}, dx[] = {0,1,0,-1};   
int n,m,cnt,cnt2;
vector <pair<int,int>>v;

void go(int y,int x){
    visited[y][x]=1;
    if(a[y][x]==1){
        v.push_back({y,x});
        return;
    }
    for(int i = 0 ; i < 4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
        go(ny,nx);
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        fill(&visited[0][0],&visited[0][0]+104*104,0);
        cnt2= 0;
        v.clear();
        go(0,0);
        for(pair<int,int>p:v){
            cnt2++;
            a[p.first][p.second]=0;
        }
        bool flag = 0;
       for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j]!=0) flag =1;
        }
    }
    cnt++;
    if(!flag) break;
    }
    cout << cnt<<"\n" << cnt2 << "\n";
}