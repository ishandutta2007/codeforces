//
//  main.cpp
//  A(easy)
//
//  Created by  on 16/7/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const long long mod = 1e6 + 3;
const int maxn = 7e5 + 5;


long long n,c;

long long fac[maxn],inv[maxn];

typedef  long long ll;

ll mod_pow(ll a,ll n){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    fac[0] = fac[1] = 1;
    for(long long i = 2;i < maxn;i++){
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[0] = inv[1] = 1;
    for(int i = 2;i < maxn;i++){
        inv[i] = mod_pow(fac[i], mod - 2);
    }
}

ll C(ll n,ll k){
    return fac[n] * inv[n - k] % mod * inv[k] % mod;
}

int main(int argc, const char * argv[]) {
    init();
    cin >> n >> c;
    long long ans = 0;
    for(long long i = 1;i <= n;i++){
        ans = (ans + C(c - 1 + i,c - 1)) % mod;
    }
    cout << ans % mod  << endl;
    return 0;
}