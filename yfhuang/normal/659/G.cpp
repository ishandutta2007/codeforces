//
//  main.cpp
//  G
//
//  Created by  on 16/3/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

const int maxn = 1000000 + 5;
const long long mod = 1e9 +7;

int h[maxn];
long long dp[maxn];


int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",h + i);
    }
    dp[2] = min(h[2] - 1,h[1] - 1) % mod;;
    for(int i  = 2; i < n; i++){
        dp[i + 1] = (dp[i] * (long long) min(h[i - 1] - 1, min (h[i] - 1, h[i + 1] -1) ) + (long long) min(h[i] - 1, h[i + 1] - 1)) % mod;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (long long) (h[i] - 1);
        ans %= mod;
    }
    for(int i = 2; i <= n; i++){
        ans = (ans + (long long)min(h[i - 1] - 1, h[i] - 1) * dp[i]) % mod;
    }
    cout << ans <<endl;
    return 0;
}