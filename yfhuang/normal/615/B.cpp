//
//  main.cpp
//  B
//
//  Created by  on 16/1/8.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+5;
const int maxm=2e5+5;

int n,m;

long long num[maxn];

struct edge{
    int from,to;
}E[maxm];

bool cmp( edge a,edge b){
    return a.from<b.from;
}

long long dp[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
        dp[i]=1;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        num[u]++;
        num[v]++;
        if(u>v) swap(u,v);
        E[i].from=u,E[i].to=v;
    }
    sort(E+1,E+1+m,cmp);
    for(int i=1;i<=m;i++){
        dp[E[i].to]=max(dp[E[i].to],dp[E[i].from]+1);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]*num[i]);
    }
    cout<<ans<<endl;
    return 0;
}