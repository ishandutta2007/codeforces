//
//  main.cpp
//  B
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, q;

const int maxq=40;

char a[maxq][5],b[maxq][2];

long long grid[10][10];
long long dp[8][10];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&q);
    memset(grid,0,sizeof(grid));
    for(int i=1;i<=q;i++){
        scanf("%s",a[i]);
        scanf("%s",b[i]);
        grid[b[i][0]-'a'][a[i][0]-'a']++;
    }
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                dp[i][j]+=dp[i-1][k]*grid[k][j];
            }
        }
    }
    long long ans=0;
    for(int i=0;i<6;i++){
        ans+=(long long)dp[n][i];
    }
    cout<<ans<<endl;
    return 0;
}