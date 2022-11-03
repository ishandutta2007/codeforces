//
//  main.cpp
//  C(easy)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1010;

vector<int> G[maxn];

int n,m;

bool vis[maxn];

void dfs(int u,int fa){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        if(!vis[v]){
            vis[v] = true;
            dfs(v,u);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(m != n - 1){
        cout << "no" << endl;
        return 0;
    }else{
        memset(vis,false,sizeof(vis));
        vis[1] = true;
        dfs(1,-1);
        bool flag = true;
        for(int i = 1;i <= n;i++) if(!vis[i]) flag = false;
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}