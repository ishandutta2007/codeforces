//
//  main.cpp
//  C
//
//  Created by  on 16/2/21.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;

const int maxm=100005;

char str[maxm];

const int mod=1e9+7;

int dp[2005][2005];
int dp1[2005][2005];

void add(int &x,int y){
    x+=y;
    while(x>=mod) x-=mod;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    int l=strlen(str+1);
    int mina=0x3f3f3f3f;
    int a=0;
    for(int i=1;i<=l;i++){
        if(str[i]=='(')a++;
        else a--;
        mina=min(mina,a);
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            if(j>i) continue;
            add(dp[i][j],dp[i-1][j+1]);
            if(j>0)
                add(dp[i][j],dp[i-1][j-1]);
        }
    }
    long long ans=0;
    for(int i=0;i<=n-m;i++){
        for(int j= mina>=0? 0: -mina;j<=i&&(j+a)<=2000;j++){
            ans+=(long long)dp[i][j]*(long long)dp[n-m-i][j+a]%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}