//
//  main.cpp
//  F
//
//  Created by  on 16/3/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1005;

long long n,m,k;

int a[maxn][maxn];

int fa[maxn * maxn],Rank[maxn * maxn];
bool vis[maxn][maxn];

int dx[4] = {-1,0,1,0} , dy[4] = {0,1,0,-1};

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void Union(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    else {
        fa[y] = x;
        Rank[x] += Rank[y];
    }
}

struct point{
    int x, y;
    int cnt;
    bool operator < (const point & rhs) const {
        return cnt < rhs.cnt;
    }
}p[maxn * maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&a[i][j]);
            p[(i - 1) * m + j - 1].x = i;
            p[(i - 1) * m + j - 1].y = j;
            p[(i - 1) * m + j - 1].cnt = a[i][j];
        }
    }
    sort(p,p + n * m);
    for(int i = 0;i <= n * m; i++){
        fa[i] = i;
        Rank[i] = 1;
    }
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= m; j++){
            vis[i][j] = false;
        }
    }
    int ans = -1;
    for(int i = (int)n * m - 1; i >= 0; i--){
        int x = p[i].x;
        int y = p[i].y;
        vis[x][y] = true;
        for(int l = 0; l < 4; l++){
            int nx = x + dx[l];
            int ny = y + dy[l];
            if(nx  > 0 && nx <= n && ny > 0 && ny <= m && vis[nx][ny]){
                Union((x - 1) * (int) m + y - 1, (nx - 1) *(int)m + ny- 1);
            }
        }
        if(k % p[i].cnt == 0){
            if((long long)Rank[(p[i].x - 1) * m + p[i].y - 1] >= k /(long long) p[i].cnt){
                ans = i;
                break;
            }
        }else{
            continue;
        }
    }
    if(ans >= 0) {
        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= m; j++){
                vis[i][j] = false;
            }
        }
        queue<pair<int,int> > q;
        q.push(make_pair(p[ans].x,p[ans].y));
        long long t = k / p[ans].cnt;
        while(!q.empty() && t > 0){
            pair<int,int > pp = q.front();q.pop();
            int x = pp.first;
            int y = pp.second;
            if(vis[x][y]) continue;
            vis[x][y] = true;
            t--;
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx > 0 && nx <= n && ny > 0 && ny <= m && !vis[nx][ny]&&a[nx][ny] >= p[ans].cnt){
                    q.push(make_pair(nx,ny));
                }
            }
        }
        puts("YES");
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j]){
                    printf("%d",p[ans].cnt);
                }else{
                    printf("0");
                }
                printf("%c",j == m ? '\n' : ' ');
            }
        }
    }else{
        puts("NO");
    }
    return 0;
}