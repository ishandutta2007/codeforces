//
//  main.cpp
//  C
//
//  Created by  on 8/29/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,K;

typedef long long ll;

ll p[105][105];

int c[105];

ll dp[105][105][105];
bool vis[105][105][105];

int main(int argc, const char * argv[]) {
    cin >> n >> m >> K;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> p[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= K;j++){
            for(int k = 0;k <= m;k++){
                dp[i][j][k] = 1e15;
            }
        }
    }
    if(c[1] == 0){
        for(int i = 1;i <= m;i++){
            vis[1][1][i] = true;
            dp[1][1][i] = p[1][i];
        }
    }else{
        vis[1][1][c[1]] = true;
        dp[1][1][c[1]] = 0;
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= K;j++){
            if(c[i] != 0){
                for(int k = 1;k <= m;k++){
                    if(k != c[i]){
                        if(vis[i - 1][j - 1][k]){
                            vis[i][j][c[i]] = true;
                            dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i - 1][j - 1][k]);
                        }
                    }else{
                        if(vis[i - 1][j][k]){
                            vis[i][j][c[i]] = true;
                            dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i - 1][j][k]);
                        }
                    }
                }
            }else{
                for(int k = 1;k <= m;k++){
                    for(int l = 1;l <= m;l++){
                        if(l == k){
                            if(vis[i - 1][j][k]){
                                vis[i][j][k] = true;
                                dp[i][j][l] = min(dp[i][j][l],dp[i - 1][j][k] + p[i][l]);
                            }
                        }else{
                            if(vis[i - 1][j - 1][k]){
                                vis[i][j][l] = true;
                                dp[i][j][l] = min(dp[i][j][l],dp[i - 1][j - 1][k] + p[i][l]);
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 1e15;
    for(int i = 1;i <= m;i++) ans = min(ans,dp[n][K][i]);
    if(ans == 1e15){
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0;
}