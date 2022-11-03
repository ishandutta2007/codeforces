//
//  main.cpp
//  a
//
//  Created by  on 16/3/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1005;

int prea[maxn],preb[maxn];
int sufa[maxn],sufb[maxn];
int a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    memset(prea,0,sizeof(prea));
    memset(preb,0,sizeof(preb));
    memset(sufa,0,sizeof(sufa));
    memset(sufb,0,sizeof(sufb));
    for(int i=1;i<=n;i++){
        prea[i]=prea[i-1]|a[i];
        preb[i]=preb[i-1]|b[i];
    }
    for(int i=n;i>=1;i--){
        sufa[i]=sufa[i+1]|a[i];
        sufb[i]=sufb[i+1]|b[i];
    }
    int ans=-1e9;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int f1=prea[j]|sufa[i]|prea[n];
            int f2=preb[j]|sufb[i]|preb[n];
            if(f1+f2>ans){
                ans=f1+f2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}