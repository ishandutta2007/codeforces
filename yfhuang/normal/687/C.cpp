//
//  main.cpp
//  687C
//
//  Created by  on 16/7/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 505;

bool dp[maxn][maxn][maxn];

int c[maxn];
int n,k;

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> c[i];
    memset(dp,false,sizeof(dp));
    dp[0][0][0] = true;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            for(int l = 0;l <= k;l++){
                if(dp[i - 1][j][l]) dp[i][j][l] = true;
                if(j - c[i] >= 0 && dp[i - 1][j - c[i]][l]) dp[i][j][l] = true;
                if(j - c[i] >= 0 && l - c[i] >= 0 && dp[i - 1][j - c[i]][l - c[i]]) dp[i][j][l] = true;
            }
        }
    }
    vector<int> ans;
    ans.clear();
    for(int i = 0;i <= k;i++){
        if(dp[n][k][i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        printf("%d%c",ans[i],i == ans.size() - 1 ? '\n' : ' ');
    }
    
    return 0;
}