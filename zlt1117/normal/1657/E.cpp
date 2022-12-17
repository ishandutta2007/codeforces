#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;const int mod=998244353,maxn=255;int n,K,dp[maxn][maxn],c[maxn][maxn],pw[maxn][maxn*maxn];
int main(){scanf("%d%d",&n,&K);FOR(i,0,K)pw[i][0]=1;FOR(i,0,n){c[i][0]=1;FOR(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;}FOR(i,0,K)FOR(j,1,n*n)pw[i][j]=1ll*pw[i][j-1]*i%mod;dp[0][0]=1;FOR(i,1,K)FOR(j,0,n-1)FOR(k,0,n-1-j)dp[i][j+k]=(dp[i][j+k]+1ll*dp[i-1][j]*c[j+k][k]%mod*pw[K-i+1][k*j+k*(k-1)/2])%mod;printf("%d\n",dp[K][n-1]);return 0;}