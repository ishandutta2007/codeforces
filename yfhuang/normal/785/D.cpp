//
//  main.cpp
//  D
//
//  Created by  on 2017/3/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;
const int maxn = 200000 + 5;

LL fac[maxn * 2];
LL inv[maxn * 2];

LL mod_pow(LL a,LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    fac[0] = 1;
    for(int i = 1;i < maxn * 2;i++){
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn * 2 - 1] = mod_pow(fac[maxn * 2 - 1],mod - 2);
    for(int i = maxn * 2 - 2;i >= 0;i--){
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

char s[maxn];
int L[maxn];
int R[maxn];

long long C(LL n,LL m){
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main(int argc, const char * argv[]) {
    init();
    scanf("%s",s + 1);
    L[0] = 0;
    int n = strlen(s + 1);
    R[n + 1] = 0;
    for(int i = 1;i <= n;i++){
        L[i] = L[i - 1] + (s[i] == '(');
    }
    for(int i = n;i >= 1;i--){
        R[i] = R[i + 1] + (s[i] == ')');
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '(' && R[i + 1] > 0){
            //cout << L[i] + R[i + 1] << " " << min(L[i],R[i + 1]) << endl;
           // cout << C(L[i] - 1 + R[i + 1],min(L[i],R[i + 1] - 1))  << endl;
            ans = (ans + C(L[i] - 1 + R[i + 1],min(L[i],R[i + 1] - 1)) ) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}