//
//  main.cpp
//  D
//
//  Created by  on 16/4/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 3000 + 5;

int dist[maxn][maxn];
int d[maxn];
int k_shortto[maxn][3];
int k_shortfrom[maxn][3];

bool vis[maxn];

int n,m;

vector<int> G[maxn];

const int INF = 0x3f3f3f3f;

void Dij(int s){
    //priority_queue<pair<int,int>> pq;
    queue<pair<int,int>> pq;
    memset(d,INF,sizeof(d));
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.front().second;
        //int dis = pq.top().second;
        if(d[u] < pq.front().first) continue;
        pq.pop();
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                pq.push({d[v],v});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        //cout << d[i] << ' ';
        dist[s][i] = d[i];
    }
    //cout << endl;
}

bool check(int a,int b,int c,int d){
    if(a == 0 || b == 0 || c == 0 || d == 0) return false;
    if(a == c || d == b) return false;
    if(a == d) return false;
    return true;
}



int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    for(int i = 1;i <= n;i++){
        Dij(i);
    }
    //for(int i = 1;i <= n;i++){
    //    for(int j = 1;j <= n;j++){
    //        cout << dist[i][j] << ' ';
    //    }
     //   cout << endl;
    //}
    for(int v = 1;v <= n;v++){
        memset(vis,false,sizeof(vis));
        for(int i = 0;i < 3;i++){
            int maxu = 0,maxd = 0;
            for(int u = 1;u <= n;u++){
                if(u == v || vis[u]) continue;
                if(dist[u][v] != INF && dist[u][v] > maxd){
                    maxu = u;
                    maxd = dist[u][v];
                }
            }
            k_shortto[v][i] = maxu;
            vis[maxu] = true;
        }
    }
    for(int v = 1;v <= n;v++){
        memset(vis,false,sizeof(vis));
        for(int i = 0;i < 3;i++){
            int maxu = 0,maxd = 0;
            for(int u = 1;u <= n;u++){
                if(u == v || vis[u]) continue;
                if(dist[v][u] != INF && dist[v][u] > maxd){
                    maxu = u;
                    maxd = dist[v][u];
                }
            }
            k_shortfrom[v][i] = maxu;
            vis[maxu] = true;
        }
    }
    int ans = 0;
    int ansa = 0,ansb = 0,ansc = 0,ansd = 0;
    for(int u = 1;u <= n;u++){
        for(int v = 1;v <= n;v++){
            if(u == v) continue;
            if(dist[u][v] == INF) continue;
            for(int i = 0;i < 3;i++){
                for(int j = 0;j < 3;j++){
                    if(check(k_shortto[u][i],u,v,k_shortfrom[v][j])){
                        if(ans < dist[k_shortto[u][i]][u] + dist[u][v] + dist[v][k_shortfrom[v][j]]){
                            ans = dist[k_shortto[u][i]][u] + dist[u][v] + dist[v][k_shortfrom[v][j]];
                            ansa = k_shortto[u][i];
                            ansb = u;
                            ansc = v;
                            ansd = k_shortfrom[v][j];
                        }
                    }
                }
            }
        }
    }
    cout << ansa << ' ' << ansb << ' ' << ansc << ' ' << ansd << endl;
    //cout << dist[7][2] << dist[2][8] << dist[8][1] << endl;
    //cout << dist[3][4] << ' ' << dist[5][4] << ' ' << dist[6][4] << endl;
    //for(int i = 0;i < 3;i++){
    //    cout << k_shortto[2][i] << ' ';
    //}
    //for(int i = 0;i < 3;i++){
    //    cout << k_shortfrom[8][i] << ' ';
    //}
    //cout << ans << endl;
    /*for(int u = 1;u <= n;u++){
        for(int v = 1;v <= n;v++){
            if(u == v) continue;
            if(dist[u][v] == INF) continue;
            for(int i = 0;i < 3;i++){
                for(int j = 0;j < 3;j++){
                    if(check(k_shortto[u][i],u,v,k_shortfrom[v][j])){
                        if(dist[k_shortto[u][i]][u] + dist[u][v] + dist[v][k_shortfrom[v][j]] == ans) {cout << k_shortto[u][i] << ' ' << u << ' ' << v << ' ' << k_shortfrom[v][j] << endl;return 0;}
                    }
                }
            }
        }
    }*/
    
    return 0;
}