//
//  main.cpp
//  E
//
//  Created by  on 8/30/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const ll mod = 1000000 + 3;

ll n,k;

ll mod_pow(ll a,ll n){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    ll power = 0;
    while((1LL << power) < k) power++;
    if(power > n){
        printf("1 1\n");
        return 0;
    }else{
        ll p = 0;
        for(ll i = 2;i <= k - 1;i <<= 1){
            p += (k - 1) / i;
        }
        if(k - 1 >= mod){
            ll num = mod_pow(mod_pow(2,n),k - 1) * mod_pow(2,mod - 1 - (p % (mod - 1))) % mod;
            cout << num << " " << num << endl;
        }else{
            ll num = mod_pow(mod_pow(2,n),k - 1) * mod_pow(2,mod - 1 - (p % (mod - 1))) % mod;
            ll dom = 1;
            for(ll i = 1;i < k;i++){
                dom = dom * (mod_pow(2,n) - i + mod) % mod;
            }
            dom = dom * mod_pow(2,mod - 1 - (p % (mod - 1))) % mod;
            cout << ((num - dom) % mod + mod) % mod << " " << num << endl;
        }
    }
    return 0;
}