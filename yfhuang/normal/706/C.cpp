//
//  main.cpp
//  C
//
//  Created by  on 8/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

const int maxn = 1e5 + 5;

string s[maxn];

int n;

int c[maxn];
typedef long long ll;

ll dp[maxn][2];
const ll INF = 1e18;

string rever(string s){
    int len = s.length();
    string s1 = "";
    for(int i = len - 1;i >= 0;i--){
        s1 += s[i];
    }
    return s1;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= n;i++){
        scanf("%d",c + i);
    }
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    dp[1][1] = c[1];
    for(int i = 2;i <= n;i++){
        if(s[i] >= s[i - 1]) dp[i][0] = min(dp[i][0],dp[i - 1][0]);
        if(s[i] >= rever(s[i - 1])) dp[i][0] = min(dp[i][0],dp[i - 1][1]);
        if(rever(s[i]) >= s[i - 1]) dp[i][1] = min(dp[i][1],dp[i - 1][0] + c[i]);
        if(rever(s[i]) >= rever(s[i - 1])) dp[i][1] = min(dp[i][1],dp[i - 1][1] + c[i]);
    }
    ll ans =  min(dp[n][0],dp[n][1]);
    if(ans == INF) printf("-1\n");
    else cout << ans << endl;
    return 0;
}