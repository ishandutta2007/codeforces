//
//  main.cpp
//  D
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> G[maxn]; // 0~n
int c[maxn];

/*bool dfs(int u){
    c[u] = -1;
    for(int v = 0; v <= n; v++) if(G[u][v]) {
        if(c[v]<0) return false;
        else if(!c[v]) dfs(v);
    }
    c[u] = 1; topo.push_back(u);
    return true;
}

bool toposort(){
    topo.clear();
    memset(c, 0, sizeof(c));
    for(int u = 0; u <= n; u++) if(!c[u])
        if(!dfs(u)) return false;
    reverse(topo.begin(), topo.end());
    return true;
}*/

int n,m;
int d[maxn];
bool vis[maxn];
int topo[maxn];
int u[maxn],v[maxn];

bool check(int x){
    for(int i=1;i<=n;i++) G[i].clear(),d[i]=0;
    for(int i=1;i<=x;i++) G[u[i]].push_back(v[i]),d[v[i]]++;
    int t=0;
    for(int i=1;i<=n;i++) if(d[i]==0) topo[t++]=i;
    for(int i=0;i<t;i++){
        if(t!=i+1) return false;
        int u=topo[i];
        for(auto v:G[u]) if((--d[v])==0) topo[t++]=v;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
    }
    if(!check(m)) {puts("-1");return 0;}
    int l=-1,r=m;
    while(l+1<r){
        int mid=l+(r-l+1)/2;
        if(check(mid)) r=mid;else l=mid;
    }
    printf("%d\n",r);
    return 0;
}