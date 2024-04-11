//
//  main.cpp
//  E
//
//  Created by  on 16/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod=1e9+7;

const int d2=(mod+1)/2;

typedef long long ll;

ll n,m;


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    ll res=0;
    ll q=1;
    ll l = 0, r = 1e9;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (mid * mid < n) l = mid + 1; else r = mid;
    }
    ll d=l;
    for(ll i=1;i<=d;i++){
        l=n/(i+1)+1;
        r=min(n/i,m);
        if(l>r) continue;
        ll t;
        if((l+r)%2==0){
            t=(l+r)/2%mod;
            t=t*((r-l+1)%mod)%mod;
            res=(res+t*i)%mod;
        }else{
            t=(r-l+1)/2%mod;
            t=t*((r+l)%mod)%mod;
            res=(res+t*i)%mod;
        }
    }
    for(int i=1;i<=min(m,d);i++){
        if(n/i>d){
            res=(res+n/i%mod*i) %mod;
        }
    }
    res = (n % mod * (m % mod) - res + mod) % mod;
    cout<<res<<endl;
    return 0;
}