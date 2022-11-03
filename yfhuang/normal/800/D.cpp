//
//  main.cpp
//  D
//
//  Created by  on 2017/4/17.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int p10[10];
typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e6 + 5;
LL p2[maxn];
LL f1[maxn],f2[maxn],f0[maxn],G[maxn];

void add(LL &a,LL b){
    a += b;
    if(a >= mod) a -= mod;
}


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    p10[0] = 1;
    for(int i = 1;i <= 6;i++){
        p10[i] = p10[i - 1] * 10;
    }
    p2[0] = 1;
    for(int i = 1;i < maxn;i++){
        p2[i] = p2[i - 1] * 2LL % mod;
    }
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        f0[x]++;
        f1[x] = (f1[x] + x) % mod;
        f2[x] = (f2[x] + 1LL * x * x) % mod;
    }
    for(int i = 0;i < 6;i++){
        for(int j = 999999;j >= 0;j--){
            if(j / p10[i] % 10){
                add(f0[j - p10[i]],f0[j]);
                add(f1[j - p10[i]],f1[j]);
                add(f2[j - p10[i]],f2[j]);
            }
        }
    }
    for(int i = 0;i <= 999999;i++){
        if (f0[i]==0) G[i]=0;
        else if (f0[i]==1) G[i]=f2[i];
        else G[i]=((f2[i]*p2[f0[i]-1])+(f1[i]*f1[i]-f2[i])%mod*p2[f0[i]-2])%mod;
    }
    for(int i = 0;i < 6;i++){
        for(int j = 0;j <= 999999;j++){
            if(j / p10[i] % 10 != 9){
                (G[j] -= G[j + p10[i]]) %= mod;
            }
        }
    }
    LL ans = 0;
    for(int i = 0;i <= 999999;i++){
        if(G[i] < 0) G[i] += mod;
        ans = ans ^ (1LL * i * G[i]);
    }
    cout << ans << endl;
    return 0;
}