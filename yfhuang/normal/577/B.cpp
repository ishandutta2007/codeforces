//
//  main.cpp
//  B
//
//  Created by  on 16/1/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxm=1e3+5;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;

int m,n;

int dp[maxm][maxm];
int a[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n>m) printf("YES\n");
    else{
        for(int i=0;i<=n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-INF;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                dp[i][(j+a[i])%m]=max(dp[i-1][j]+1,dp[i-1][(j+a[i])%m]);
            }
        }
        if(dp[n][0]>0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}