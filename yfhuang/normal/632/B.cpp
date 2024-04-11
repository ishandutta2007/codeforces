//
//  main.cpp
//  b
//
//  Created by  on 16/3/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn=5e5+5;

int n;
int p[maxn];
char str[maxn];

ll prea[maxn],preb[maxn],sufa[maxn],sufb[maxn];


int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    memset(prea,0,sizeof(prea));
    memset(sufa,0,sizeof(sufa));
    memset(preb,0,sizeof(preb));
    memset(sufb,0,sizeof(sufb));
    scanf("%s",str+1);
    
    for(int i=1;i<=n;i++){
        if(str[i]=='A') {prea[i]=prea[i-1]+(ll)p[i];preb[i]=preb[i-1];}
        else {preb[i]=preb[i-1]+(ll)p[i];prea[i]=prea[i-1];}
    }
    for(int i=n;i>=1;i--){
        if(str[i]=='B') {sufb[i]=sufb[i+1]+(ll)p[i];sufa[i]=sufa[i+1];}
        else {sufa[i]=sufa[i+1]+(ll)p[i];sufb[i]=sufb[i+1];}
    }
    ll ans=-1e18;
    for(int i=0;i<=n;i++){
        if(prea[i]+sufb[i+1]>ans){
            ans=prea[i]+sufb[i+1];
        }
    }
    for(int i=0;i<=n;i++){
        if(preb[i]+sufa[i+1]>ans){
            ans=preb[i]+sufa[i+1];
        }
    }
    cout<<ans<<endl;
    return 0;
}