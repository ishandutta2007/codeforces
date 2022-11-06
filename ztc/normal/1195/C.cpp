#include<stdio.h>
long long dp[100002][2];
int n,h[100002][2];
inline long long Max(long long a,long long b){return a>b?a:b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i][0]);
	for(int i=1;i<=n;i++)scanf("%d",&h[i][1]);
	for(int i=1;i<=n;i++){
		dp[i][0]=Max(dp[i-1][0],dp[i-1][1]+h[i][0]);
		dp[i][1]=Max(dp[i-1][1],dp[i-1][0]+h[i][1]);
	}printf("%lld",Max(dp[n][0],dp[n][1]));
}