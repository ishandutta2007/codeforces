//
//  main.cpp
//  D
//
//  Created by  on 16/5/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1005;
const int INF = 1e18;

bool inq[maxn][maxn][5];

int n,m;
int xt,yt;
int xm,ym;

char grid[maxn][maxn];

long long d[maxn][maxn][5];

int can[4][maxn][maxn];

struct st{
    int x,y;
    int dir;
    long long t;
};

int dx[4] = {0,-1,0,1},dy[4] = {1,0,-1,0};

int op[4] = {2,3,0,1};

void bfs(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = 0;k < 4;k++){
                d[i][j][k] = INF;
            }
        }
    }
    memset(inq,false,sizeof(inq));
    queue<st> q;
    inq[xt][yt][0] = true;
    d[xt][yt][0] = 0;
    q.push(st{xt,yt,0,0});
    while(!q.empty()){
        st t = q.front();
        q.pop();
        inq[t.x][t.y][t.dir] = false;
        for(int i = 0;i < 4;i++){
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx >=1 && nx <= n && ny <= m && ny >= 1 && can[(i + t.dir) % 4][t.x][t.y] && can[(op[i] + t.dir) % 4][nx][ny]){
                if(d[nx][ny][t.dir] > d[t.x][t.y][t.dir] + 1){
                    d[nx][ny][t.dir] = d[t.x][t.y][t.dir] + 1;
                    if(!inq[nx][ny][t.dir]){
                        q.push(st{nx,ny,t.dir,d[nx][ny][t.dir]});
                        inq[nx][ny][t.dir] = true;
                    }
                }
            }
        }
        if(d[t.x][t.y][(t.dir + 1) % 4] > d[t.x][t.y][t.dir] + 1){
            d[t.x][t.y][(t.dir + 1) % 4] = d[t.x][t.y][t.dir] + 1;
            if(!inq[t.x][t.y][(t.dir + 1)% 4]){
                q.push(st{t.x,t.y,(t.dir + 1) % 4,d[t.x][t.y][t.dir] + 1});
                inq[t.x][t.y][(t.dir + 1) % 4] = true;
            }

        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%s",grid[i] + 1);
    }
    cin >> xt >> yt;
    cin >> xm >> ym;
    memset(can,0,sizeof(can));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(grid[i][j] == '+'){
                can[0][i][j] = can[1][i][j] = can[2][i][j] = can[3][i][j] = 1;
            }else if(grid[i][j] == '-'){
                can[0][i][j] = can[2][i][j] = 1;
            }else if(grid[i][j] == '|'){
                can[1][i][j] = can[3][i][j] = 1;
            }else if(grid[i][j] == '^'){
                can[1][i][j] = 1;
            }else if(grid[i][j] == '>'){
                can[0][i][j] = 1;
            }else if(grid[i][j]=='<'){
                can[2][i][j] = 1;
            }else if(grid[i][j]=='v'){
                can[3][i][j] = 1;
            }else if(grid[i][j]=='L'){
                for(int k = 0;k < 4;k++){
                    can[k][i][j] = 1;
                }
                can[2][i][j] = 0;
            }else if(grid[i][j]=='R'){
                for(int k = 0;k < 4;k++){
                    can[k][i][j] = 1;
                }
                can[0][i][j] = 0;
            }else if(grid[i][j]=='U'){
                for(int k = 0;k < 4;k++){
                    can[k][i][j] = 1;
                }
                can[1][i][j] = 0;
            }else if(grid[i][j]=='D'){
                for(int k = 0;k < 4;k++){
                    can[k][i][j] = 1;
                }
                can[3][i][j] = 0;
            }
        }
    }
    bfs();
    long long ans = INF;
    for(int i = 0;i < 4;i++){
        ans = min(ans,d[xm][ym][i]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}