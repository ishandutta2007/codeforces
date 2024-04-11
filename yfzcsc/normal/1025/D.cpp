#include<bits/stdc++.h>
using namespace std;
int dp[800][800][2],n,a[800],c[800][800];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=n+1;++j)
			c[i][j]=__gcd(a[i],a[j])>1;
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<i;++j)
			dp[i][j][0]=dp[i][j][1]=1;
	for(int i=1;i<=n;++i){
		dp[i][i][0]=c[i-1][i];
		dp[i][i][1]=c[i][i+1];
	}
	for(int i=2;i<=n;++i)
		for(int j=1;j+i-1<=n;++j){
			int l=j,r=j+i-1;
			dp[l][r][0]=dp[l][r][1]=0;
			for(int k=l;k<=r;++k){
				if(c[l-1][k]){
					dp[l][r][0]|=dp[l][k-1][1]&dp[k+1][r][0];
				} 
				if(c[k][r+1]){
					dp[l][r][1]|=dp[l][k-1][1]&dp[k+1][r][0];
				}
			}
//			printf("dp[%d,%d,%d]=%d\n",l,r,0,dp[l][r][0]);
//			printf("dp[%d,%d,%d]=%d\n",l,r,1,dp[l][r][1]);
		}
	puts(dp[1][n][0]?"Yes":"No");
}