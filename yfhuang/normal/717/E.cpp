//
//  main.cpp
//  E
//
//  Created by  on 9/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 200000 + 5;

vector<int> G[maxn];

int tot;

int color[maxn];
vector<int> ans;

void update(int u){
    if(!tot) return;
    ans.push_back(u);
    color[u] = -color[u];
    if(color[u] == 1) tot--;
    else tot++;
}

void dfs(int u,int fa){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        update(v);
        dfs(v,u);
        update(u);
        if(color[v] == -1){
            update(v);
            update(u);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
        for(int i = 1;i <= n;i++) G[i].clear();
        tot = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d",color + i);
            if(color[i] == -1){
                tot++;
            }
        }
        for(int i = 1;i < n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans.clear();
        ans.push_back(1);
        dfs(1,-1);
        for(int i = 0;i < ans.size();i++) printf("%d ",ans[i]);
    }
    return 0;
}