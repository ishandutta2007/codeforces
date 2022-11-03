//
//  main.cpp
//  383D
//
//  Created by  on 9/8/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2][20010];
bool vis[2][20010];

int n;
const int maxn = 1005;
const int maxm = 20010;

int a[maxn];
const int mod = 1e9 + 7;



int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int now = 1;
    memset(vis,false,sizeof(vis));
    memset(dp,0,sizeof(dp));
    vis[0][10003] = true;
    dp[0][10003] = 1;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        memset(vis[now],false,sizeof(vis[now]));
        memset(dp[now],0,sizeof(dp[now]));
        for(int j = 0;j < maxm;j++){
            if(j - a[i] >= 0 && vis[now ^ 1][j - a[i]]){
                dp[now][j] = (dp[now][j] + dp[now ^ 1][j - a[i]]) % mod;
                vis[now][j] = true;
            }
            if(j + a[i] < maxm && vis[now ^ 1][j + a[i]]){
                dp[now][j] = (dp[now][j] + dp[now ^ 1][j + a[i]]) % mod;
                vis[now][j] = true;
            }
        }
        ans = (ans + dp[now][10003]) % mod;
        //cout << ans << endl;
        dp[now][10003] = (dp[now][10003] + 1) % mod;
        vis[now][10003] = true;
        now = now ^ 1;
    }
    cout << ans << endl;
    return 0;
}