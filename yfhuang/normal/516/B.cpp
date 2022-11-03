//
//  main.cpp
//  B
//
//  Created by  on 10/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;

const int maxn = 2000 + 5;

vector<int> G[maxn * maxn];

int deg[maxn * maxn];

int cal(int x,int y){
    return 2000 * x + y;
}

char s[maxn][maxn];

bool in(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};



int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        scanf("%s",s[i]);
    }
    memset(deg,0,sizeof(deg));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(s[i][j] == '.'){
                for(int k = 0;k < 4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(in(nx,ny) && s[nx][ny] == '.'){
                        int u = cal(i,j);
                        int v = cal(nx,ny);
                        G[u].push_back(v);
                        deg[u]++;
                    }
                }
            }
        }
    }
    queue<int> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int now = cal(i,j);
            if(deg[now] == 1){
                q.push(now);
            }
        }
    }
    //cout << 1 << endl;
    while(!q.empty()){
        int p = q.front();
        int x = p / 2000;
        int y = p % 2000;
        q.pop();
        if(s[x][y] != '.') continue;
        for(int i = 0;i < G[p].size();i++){
            int v = G[p][i];
            int nx = v / 2000;
            int ny = v % 2000;
            if(s[nx][ny] == '.')
            if(deg[v] > 0){
                if(nx == x){
                    s[x][max(y,ny)] = '>';
                    s[x][min(y,ny)] = '<';
                }else{
                    s[min(x,nx)][y] = '^';
                    s[max(x,nx)][y] = 'v';
                }
                deg[v]--;
                for(int j = 0;j < G[v].size();j++){
                    int to = G[v][j];
                    deg[to]--;
                    int xx = to / 2000;
                    int yy = to % 2000;
                    if(s[xx][yy] == '.' && deg[to] == 1){
                        q.push(to);
                    }
                }
                break;
            }
            
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(s[i][j] == '.'){
                printf("Not unique\n");
                return 0;
            }
        }
    }
    for(int i = 0;i < n;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}