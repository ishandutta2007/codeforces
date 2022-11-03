//
//  main.cpp
//  F
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

void add(int &a,ll b) {a = ( a + b ) % mod; }

const int maxn = 210;
const int maxk = 1010;

int n,v,a[maxn],ans;

int dp[maxn][maxn][maxk];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&v);
    for(int i = 0; i < n; i++)
        scanf("%d",a + i);
    sort(a,a + n);
    reverse(a,a + n);
    dp[0][0][0]=1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= v; k++){
                if(dp[i][j][k]){
                    int s=j*a[i]+k,ret=dp[i][j][k];
                    if(j>0&&s-a[i]-(j-1)*a[i+1]<=v)
                        add(dp[i+1][j-1][s-a[i]-(j-1)*a[i+1]],(ll)ret*j);
                    if(s+a[i]-(j+1)*a[i+1]<=v)
                        add(dp[i+1][j+1][s+a[i]-(j+1)*a[i+1]],ret);
                    if(s-j*a[i+1]<=v)
                        add(dp[i+1][j][s-j*a[i+1]],(ll)ret*(j+1));
                }
            }
        }
    }
    ans=0;
    for(int k=0;k<=v;k++){
        add(ans,dp[n][0][k]);
    }
    cout<<ans<<endl;
    return 0;
}