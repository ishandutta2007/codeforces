//
//  main.cpp
//  A
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;

const int N=30004;
int dp[N][505];

int a[N]={};

int n,d;

int main(int argc, const char * argv[]) {
    int r=0;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=0;i<=30000;i++) for(int j=0;j<=500;j++) dp[i][j]=-1e9;
    dp[d][250]=0;
    for(int i=0;i<=30000;i++)for(int j=0;j<=500;j++)
    {
        dp[i][j]+=a[i];
        r=std::max(r,dp[i][j]);
        if(d+j-250>0&&i+d+j-250<=30000)dp[i+d+j-250][j]=std::max(dp[i+d+j-250][j],dp[i][j]);
        if(j>0&&d+j-251>0&&i+d+j-251<=30000)dp[i+d+j-251][j-1]=std::max(dp[i+d+j-251][j-1],dp[i][j]);
        if(j<500&&d+j-249>0&&i+d+j-249<=30000)dp[i+d+j-249][j+1]=std::max(dp[i+d+j-249][j+1],dp[i][j]);
    }
    printf("%d\n",r);
    return 0;
}
 /*
#include<cstdio>
#include<algorithm>

int a[30001];
int d[30001][501];

int main()
{
    int r=0;
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%d",&i);
        a[i]++;
    }
    for(i=0;i<=30000;i++)for(j=0;j<=500;j++)d[i][j]=-1e9;
    d[m][250]=0;
    for(i=0;i<=30000;i++)for(j=0;j<=500;j++)
    {
        d[i][j]+=a[i];
        r=std::max(r,d[i][j]);
        if(m+j-250>0&&i+m+j-250<=30000)d[i+m+j-250][j]=std::max(d[i+m+j-250][j],d[i][j]);
        if(j>0&&m+j-251>0&&i+m+j-251<=30000)d[i+m+j-251][j-1]=std::max(d[i+m+j-251][j-1],d[i][j]);
        if(j<500&&m+j-249>0&&i+m+j-249<=30000)d[i+m+j-249][j+1]=std::max(d[i+m+j-249][j+1],d[i][j]);
    }
    printf("%d",r);
}
*/