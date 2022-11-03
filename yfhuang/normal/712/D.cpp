//
//  main.cpp
//  D
//
//  Created by  on 9/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 400220;

typedef long long ll;

ll num[maxn];
ll dp[2][maxn];

const ll mod = 1e9 + 7;

ll get(int l,int r){
    if(l <= 0) l = 1;
    if(r >= maxn) r = maxn - 1;
    return num[r] - num[l - 1];
}

int main(int argc, const char * argv[]) {
    int m = maxn >> 1;
    int a,b,k,t;
    scanf("%d%d%d%d",&a,&b,&k,&t);
    int z = 2 * k + 1;
    memset(dp,0,sizeof(dp));
    dp[0][a - b + m] = 1;
    for(int i = 1;i <= t;i++){
        num[0] = dp[(i - 1) % 2][0];
        for(int j = 1;j < maxn;j++) num[j] = num[j - 1] + dp[(i - 1) % 2][j];
        ll r = 0;
        int pre = (i - 1) % 2;
        int now = i % 2;
        memset(dp[now],0,sizeof(now));
        for(int j = 0;j < z;j++) r += (ll) (z - j) * dp[pre][j];
        dp[now][0] = r % mod;
        for(int j = 1;j < maxn;j++){
            r -= get(j - z,j - 1);
            r += get(j,j + z - 1);
            dp[now][j] = r % mod;
        }
    }
    int ans = 0;
    for(int i = m + 1;i < maxn;i++){
        ans = (ans + dp[t % 2][i] % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}