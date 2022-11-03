//
//  main.cpp
//  D
//
//  Created by  on 16/7/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


const int maxn = 200000 + 5;

int p[maxn];
vector<int> rp[maxn];//

int n;

int root[maxn];

bool vis[maxn];
bool viss[maxn];
int cycle[maxn];

void dfs(int u,int fa){
    vis[u] = true;
    for(int i = 0;i < rp[u].size();i++){
        int v = rp[u][i];
        if(v == fa) continue;
        dfs(v,u);
    }
}

void dfs1(int u,int fa){
    vis[u] = true;
    viss[u] = true;
    for(int i = 0;i < rp[u].size();i++){
        int v = rp[u][i];
        if(vis[v]) continue;
        if(v == fa) continue;
        dfs1(v,u);
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    int num = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) rp[i].clear();
    for(int i = 1;i <= n;i++){
        cin >> p[i];
        if(p[i] != i)rp[p[i]].push_back(i) ;
        if(p[i] == i){
            root[++num] = i;
        }
    }
    for(int i = 1;i <= num;i++){
        int now = root[i];
        dfs(now,-1);
    }
    int num1 = 0;
    for(int i = 1;i <= n;i++) if(vis[i]) viss[i] = true;
    for(int i = 1;i <= n;i++){
        if(vis[i]!= 0) continue;
        else{
            int now = i;
            while(!viss[now]){
                viss[now] = true;
                now = p[now];
            }
            cycle[++num1] = now;
            dfs1(now,-1);
        }
    }
    if(num > 0){
        cout << num1 + num - 1 << endl;
    for(int i = 2;i <= num;i++) p[root[i]] = root[1];
    for(int i = 1;i <= num1;i++) p[cycle[i]] = root[1];
        for(int i = 1;i <= n;i++) printf("%d%c",p[i],i == n ?'\n':' ');}
    else{
        cout << num1 << endl;
        //for(int i = 1;i <= num1;i++) cout << cycle[i] << endl;
        p[cycle[1]] = cycle[1];
        for(int i = 2;i <= n;i++) p[cycle[i]] = cycle[1];
        for(int i = 1;i <= n;i++) printf("%d%c",p[i],i == n ? '\n':' ');
    }
    return 0;
}