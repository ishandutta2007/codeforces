//
//  main.cpp
//  E
//
//  Created by  on 10/9/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 5;

int dp[maxn];
int tmp[maxn];
int n,m;

struct edge{
    int u,v,w;
    bool operator < (const edge & rhs) const{
        return w < rhs.w;
    }
}e[maxn];

int main(int argc, const char * argv[]) {
    memset(dp,0,sizeof(dp));
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e + 1,e + 1 + m);
    for(int i = 1,j = 1;i <= m;i = j + 1,j = i){
        while(j < m && e[j].w == e[j + 1].w) j++;
        for(int  k = i;k <= j;k++){
            //cout << e[k].u << " " << e[k].v << endl;
            tmp[e[k].u] = dp[e[k].u];
            tmp[e[k].v] = dp[e[k].v];
        }
        for(int k = i;k <= j;k++){
            int v = e[k].v;
            int u = e[k].u;
            if(tmp[v] < tmp[u] + 1){
                dp[v] = max(dp[v],tmp[u] + 1);
            }
        }
//        for(int k = 1;k <= n;k++){
//            cout << dp[k] << " " ;
//        }
//        cout << endl;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}