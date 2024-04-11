//
//  main.cpp
//  B
//
//  Created by  on 7/24/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 200000 + 5;

int n,k;

int u[maxn];
bool vis[maxn];

vector<int> G[maxn];

int f[maxn];

int dfs(int u,int fa){
    int ret = 0;
    if(vis[u]) ret = 1;
    else ret = 0;
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        ret += dfs(v,u);
    }
    return f[u] = ret;
}

long long ans;

void solve(int u,int fa){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        ans += min(f[v],2 * k - f[v]);
        solve(v,u);
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    memset(vis,false,sizeof(vis));
    memset(f,0,sizeof(f));
    for(int i = 1;i <= 2 * k;i++) scanf("%d",u + i),vis[u[i]] = true;
    int x,y;
    for(int i = 1;i < n;i++) scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
    ans = 0;
    dfs(1,-1);
    //for(int i = 1;i <= n;i++) cout << f[i] << endl;
    solve(1,-1);
    cout << ans << endl;
    return 0;
}