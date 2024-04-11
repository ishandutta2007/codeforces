//
//  main.cpp
//  D
//
//  Created by  on 16/6/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;



int n,m,p;

const int maxn = 300 + 5;

int a[maxn][maxn];

long long dis[maxn][maxn];
bool inq[maxn][maxn];

vector<pair<int,int> > type[maxn * maxn];

bool _in(int x,int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
    return false;
}

int dx[4] =  {0,1,0,-1},dy[4] = {1,0,-1,0};

int sz[maxn * maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> m >> p;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&a[i][j]);
            type[a[i][j]].push_back(make_pair(i,j));
            sz[a[i][j]]++;
            dis[i][j] = 1e18;
        }
    }
    for(int i = 0;i < type[1].size();i++){
        int x = type[1][i].first;
        int y = type[1][i].second;
        dis[x][y] = x - 1 + y - 1;
    }
    for(int i = 1;i < p;i++){
        if(sz[i] * sz[i + 1] < n * m){
            for(int j = 0;j < sz[i];j++){
                for(int l = 0;l < sz[i + 1];l++){
                    int sx = type[i][j].first;
                    int sy = type[i][j].second;
                    int ex = type[i + 1][l].first;
                    int ey = type[i + 1][l].second;
                    dis[ex][ey] = min(dis[ex][ey],dis[sx][sy] + abs(sx - ex) + abs(ey - sy));
                }
            }
        }else{
            queue<pair<int,int> > q;
            long long d[maxn][maxn];
            for(int j = 1;j <= n;j++) for(int l = 1;l <= m;l++) d[j][l] = 1e18,inq[j][l] = false;
            for(int j = 0;j < sz[i];j++){
                int x = type[i][j].first;
                int y = type[i][j].second;
                d[x][y] = dis[x][y];
                inq[x][y] = true;
                q.push(make_pair(x,y));
            }while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                inq[x][y] = false;
                for(int k = 0;k < 4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(_in(nx,ny) && d[nx][ny] > d[x][y] + 1){
                        d[nx][ny] = d[x][y] + 1;
                        if(!inq[nx][ny]){
                            q.push(make_pair(nx,ny));
                            inq[nx][ny] = true;
                        }
                    }
                }
            }
            for(int j = 0;j < sz[i + 1];j++){
                int x = type[i + 1][j].first;
                int y = type[i + 1][j].second;
                dis[x][y] = d[x][y];
            }
        }
    }
    cout << dis[type[p][0].first][type[p][0].second] << endl;
    return 0;
}