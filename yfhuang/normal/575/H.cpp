//
//  main.cpp
//  H
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const LL Mod=1e9+7;
const int maxn=2*(1e6+5);

LL mod_pow(LL x,LL n){
    LL ans=1;
    while(n>0){
        if(n & 1) ans = ans * x % Mod;
        x = x * x % Mod;
        n>>=1;
    }
    return ans;
}

LL fac[maxn],cfac[maxn];

void init(){
    memset(fac,0,sizeof(fac));
    memset(cfac,0,sizeof(cfac));
    fac[0]=cfac[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=fac[i-1]*i%Mod;
        cfac[i]=mod_pow(fac[i], Mod-2);
    }
}

LL c(LL m,LL n){
    return fac[m]*cfac[n]%Mod*cfac[m-n]%Mod;
}

int main(int argc, const char * argv[]) {
    LL n;
    cin>>n;
    init();
    LL ans;
    ans=(2*c(2*n+1,n)%Mod+Mod-1)%Mod;
    cout<<ans<<endl;
    return 0;
}