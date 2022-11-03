//
//  main.cpp
//  C
//
//  Created by  on 15/11/12.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(x) x&(-x)
int n,k;
long long dp[100000+5][15];
long long c[100000+5];
int a[100000+5];

void add(int x,long long d){
    while(x<=n){
        c[x]+=d;x+=lowbit(x);
    }
}

long long sum(int x){
    long long ret=0;
    while(x>0){
        ret+=c[x];x-=lowbit(x);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    k++;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        dp[i][1]=1;
    for(int i=2;i<=k;i++){
        memset(c,0,sizeof(c));
        for(int j=1;j<=n;j++){
            dp[j][i]=sum(a[j]-1);
            add(a[j],dp[j][i-1]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i][k];
    printf("%I64d\n",ans);
    return 0;
}