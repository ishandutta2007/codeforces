//
//  main.cpp
//  B
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
long long n,d;

struct friends{
    long long m,s;
}f[maxn];

long long mon[maxn];
long long sum[maxn];

bool cmp(friends a,friends b){
    return a.m<b.m;
}

int main(int argc, const char * argv[]) {
    cin>>n>>d;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d",&f[i].m,&f[i].s);
    }
    sort(f+1,f+1+n,cmp);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+f[i].s;
    for(int i=1;i<=n;i++)
        mon[i]=f[i].m;
    mon[n+1]=3e9;
    long long ans=0;
    for(int i=1;i<=n;i++){
        int e=upper_bound(mon+1, mon+2+n, f[i].m+d-1)-mon;
        //long long sum=0;
        ans=max(sum[e-1]-sum[i-1],ans);
    }
    cout<<ans;
    return 0;
}