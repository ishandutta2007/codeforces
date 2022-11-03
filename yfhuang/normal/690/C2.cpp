//
//  main.cpp
//  C(medium)
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

const int maxn = 1e5 + 5;

vector<int> G[maxn];

int n,m;

int d[maxn][2];

void dfs(int u,int fa){
    int max1 = 0,max2 = 0;
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v,u);
        if(d[v][0] > max1 - 1){
            max2 = max1;
            max1 = d[v][0] + 1;
        }else{
            if(d[v][0] > max2 - 1){
                max2 = d[v][0] + 1;
            }
        }
    }
    d[u][0] = max1,d[u][1] = max2;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> m;
    for(int i = 1;i <= m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,-1);
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,d[i][0] + d[i][1]);
    }
    cout << ans << endl;
    return 0;
}