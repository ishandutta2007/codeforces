//
//  main.cpp
//  F
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

const int maxk = 1e6+5;
const LL MOD = 1e9 + 7;

LL fac[maxk],inv[maxk];
LL p[maxk];

int n,k;

LL mod_pow(LL a,LL n){
    LL res=1;
    while(n>0){
        if(n&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return res;
}

void solve(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxk; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = mod_pow(fac[i],MOD-2);
    }
    for(int i=1;i<=k+2;i++){
        p[i] = (p[i-1] + mod_pow(i, k) )% MOD;
    }
    if(n <= k+2){
        cout<<p[n]<<endl;
        return;
    }else{
        LL prods=1;
        LL ans=0;
        for(int i=1;i<=k+2;i++){
            prods=(prods*(n-i))%MOD;
        }
        for(int j=1;j<=k+2;j++){
            LL d=inv[j-1]*inv[k+2-j]%MOD;
            if((k+2-j)&1) d=(MOD-d)%MOD;
            ans+=(prods*mod_pow(n-j,MOD-2)%MOD)*(d*p[j]%MOD)%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
        return;
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    solve();
    return 0;
}