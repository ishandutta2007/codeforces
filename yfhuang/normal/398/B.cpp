//
//  main.cpp
//  B
//
//  Created by  on 9/8/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

const int maxn = 2005;

bool vis[maxn][maxn];

int n,m;


double dp[maxn][maxn];

void dfs(int x,int y){
    if(vis[x][y]) return;
    vis[x][y] = true;
    double p1 = ((n - x) * (n - y) + 0.0) / (1.0 * n * n);
    double p2 = ((n - y) * x + 0.0 ) / (1.0 * n * n);
    double p3 = (y * (n - x) + 0.0) / (1.0 * n * n);
    double p4 = (x * y + 0.0) / (1.0 * n * n);
    if(x > 0){
        dfs(x - 1,y);
        dp[x][y] += (dp[x - 1][y] + 1.0) * p2;
    }if(y > 0){
        dfs(x,y - 1);
        dp[x][y] += (dp[x][y - 1] + 1.0) * p3;
    }if(x > 0 && y > 0){
        dfs(x - 1,y - 1);
        dp[x][y] += (dp[x - 1][y - 1] + 1.0) * p4;
    }
    dp[x][y] += p1;
    dp[x][y] /= (1 - p1);
}

set <int> x,y;

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        x.insert(u);
        y.insert(v);
    }
    dp[0][0] = 0.0;
    vis[0][0] = true;
    dfs(n - x.size(),n - y.size());
    printf("%.10lf",dp[n - x.size()][n - y.size()]);
    return 0;
}