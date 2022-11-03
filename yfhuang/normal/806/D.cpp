//
//  main.cpp
//  D
//
//  Created by  on 2017/5/8.
//  Copyright  2017 . All rights reserved.
//


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2005;
typedef long long LL;
int n;
int g[maxn][maxn];
int mi[maxn];
LL ans[maxn];

struct edge{
    int from,to;
    int cost;
    bool operator < (const edge & rhs) const{
        return cost < rhs.cost;
    }
    edge(int from = 0,int to = 0,int cost = 0) :from(from),to(to),cost(cost){}
};
edge E[maxn * maxn];
int e = 0;
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            scanf("%d",&g[i][j]);
            g[j][i] = g[i][j];
            E[++e] = edge(i,j,g[i][j]);
        }
    }
    for(int i = 1;i <= n;i++) ans[i] = 1e18;
    LL mm = 1e18;int x = 0,y = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(g[i][j] < mm){
                mm = g[i][j];
                x = i,y = j;
            }
        }
    }
    ans[x] = 1LL * (n - 1) * mm;ans[y] = ans[x];
    sort(E + 1,E + 1 + e);
    for(int i = 1;i <= e;i++){
        int x = E[i].from;int y = E[i].to;int len = E[i].cost;
        ans[x] = min(ans[x],min(len * 2 + 1LL * (n - 3) * mm,ans[y] + len - mm));
        ans[y] = min(ans[y],min(len * 2 + 1LL * (n - 3) * mm,ans[x] + len - mm));
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}