//
//  main.cpp
//  D
//
//  Created by  on 16/2/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

const int maxn=3e5+5;
const int INF=0x3f3f3f3f;

int k;

long long a[maxn];

long long dp[5005][5005];

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    //long long sum=0;
    //long long ans=0;
    for(int i=1;i<=n;i++){
        scanf("%I64d",a+i);
    }
    sort(a+1,a+1+n);
    int l=n/k;
    int S=n-l*k;//l+1
    int L=k-S;//l
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=S;i++){
        for(int j=0;j<=L;j++){
            if(i==0){
                if(j==0) continue;
                else dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i*(l+1)+j*l]-a[i*(l+1)+(j-1)*l+1]);
            }else{
                if(j==0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i*(l+1)+j*l]-a[(i-1)*(l+1)+j*l+1]);
                }else{
                    dp[i][j]=min(dp[i][j],min(dp[i-1][j]+a[i*(l+1)+j*l]-a[(i-1)*(l+1)+j*l+1],dp[i][j-1]+a[i*(l+1)+j*l]-a[i*(l+1)+(j-1)*l+1]));
                }
            }
        }
    }
    cout<<dp[S][L]<<endl;
    return 0;
}