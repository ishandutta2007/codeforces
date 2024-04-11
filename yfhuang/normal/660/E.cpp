//
//  main.cpp
//  E
//
//  Created by  on 16/4/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 5;
const long long mod = 1e9 + 7;

long long dp[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    dp[1] = 1;
    long long y = m;
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i - 1] * m % mod;
        dp[i] = (dp[i] + y) % mod;
        dp[i] = (dp[i] + dp[i - 1] * ( m - 1)) % mod;
        y = y * m % mod;
    }
    cout << (dp[n] * m + y) % mod << endl;
    
    return 0;
}