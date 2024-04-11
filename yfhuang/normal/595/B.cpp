//
//  main.cpp
//  B
//
//  Created by  on 15/11/9.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long mod=1e9+7;
int n,k;
long long a[100000+16];
long long b[100000+16];
long long c[15];
long long ans;

int main(int argc, const char * argv[]) {
    while(scanf("%d%d",&n,&k)==2){
        ans=1;
        for(int i=1;i<=n/k;i++){
            scanf("%I64d",&a[i]);
        }
        for(int i=1;i<=n/k;i++){
            scanf("%I64d",&b[i]);
        }
        c[1]=1;
        for(int i=2;i<=14;i++){
            c[i]=c[i-1]*10;
        }
        for(int i=1;i<=n/k;i++){
            if(b[i]==0) ans=ans*(((c[k+1]-1)/a[i]-(c[k]-1)/a[i])%mod)%mod;
            else ans=ans*(((c[k+1]-1)/a[i]+1-((b[i]+1)*c[k]-1)/a[i]+(b[i]*c[k]-1)/a[i])%mod)%mod;
        }
        printf("%I64d\n",ans);
    }
    
    return 0;
}