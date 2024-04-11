//
//  main.cpp
//  F
//
//  Created by  on 10/19/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 505;
typedef long long LL;

const LL mod = 1e9 + 7;
LL dp[maxn][maxn];
LL a[maxn];
int n;

LL solve(int l,int r){
    if(l >= r) return dp[l][r] = 1;
    if(dp[l][r] != -1) return dp[l][r];
    LL &ans = dp[l][r];
    ans = 0;
    for(int i = l + 1;i <= r;i++) if(i == r || a[l + 1] < a[i + 1]){
        ans = (ans + solve(l + 1,i) * solve(i,r)) % mod;
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <=  n;i++){
        cin  >> a[i];
    }
    int res = solve(1,n);
    cout << res << endl;
    return 0;
}