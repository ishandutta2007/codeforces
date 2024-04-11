//
//  main.cpp
//  C
//
//  Created by  on 16/2/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

const int maxn=1e4+5;

const int base=98765431;

const int mod=1e9;

ll par[maxn];

map<ll,string>htos;

void print(int n){
    if(n==0) return ;
    string t=htos[par[n]];
    print(n-t.size());
    cout<<t<<" ";
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio( false );
    cout.tie(0); cin.tie(0);
    
    string s;int n;
    cin>>n>>s;
    
    memset(par,-1,sizeof(par));
    par[0]=0;
    
    int m;cin>>m;
    while(m--){
        string t;cin>>t;
        ll hash=0;
        for(int i=0;i<t.size();i++)
            hash=(hash*base+tolower(t[i]))%mod;
        htos[hash]=t;
    }
    for(int i=1;i<=n;i++){
        ll hash=0;
        for(int j=i-1;j>=0;j--){
            hash=(hash*base+tolower(s[j]))%mod;
            if(par[j]!=-1&&htos.count(hash)){
                par[i]=hash;
                break;
            }
        }
    }
    
    print(n);
    
    return 0;
}