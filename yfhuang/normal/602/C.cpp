//
//  main.cpp
//  C
//
//  Created by  on 15/11/25.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
int a[405][405];
int d[405];
bool vis[405];

void solve(){
    memset(vis,false,sizeof(vis));
    memset(d,INF,sizeof(d));
    queue<int>q;
    d[1]=0;
    vis[1]=true;
    q.push(1);
    int common=a[1][n];
    while(!q.empty()){
        int s=q.front();q.pop();
        for(int i=1;i<=n;i++){
            if(!vis[i]&&a[s][i]!=common){
                d[i]=d[s]+1;
                q.push(i);
                vis[i]=true;
            }
        }
    }
    if(d[n]!=INF) printf("%d\n",d[n]);
    else printf("-1\n");
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    solve();
    return 0;
}