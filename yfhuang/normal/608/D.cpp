//
//  main.cpp
//  D
//
//  Created by  on 15/12/24.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=505;

int a[maxn];
int dp[maxn][maxn];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int l=1;l<=n;l++){
        for(int L=1;L<=n+1-l;L++){
            int R=L+l-1;
            if(l==1) dp[L][R]=1;
            else if(l==2){
                if(a[L]==a[R]) {
                    dp[L][R]=1;
                }
                else dp[L][R]=2;
            }
            else{
                if(a[L]==a[R]) dp[L][R]=dp[L+1][R-1];
                else dp[L][R]=0x3f3f3f3f;
                for(int c=L+1;c<=R;c++){
                    dp[L][R]=min(dp[L][R],dp[L][c-1]+dp[c][R]);
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}