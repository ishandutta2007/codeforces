#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[2010][2010],n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	dp[1][0]=m;
	for(int i=1;i<n;++i)
		for(int j=0;j<=k;++j)
			dp[i+1][j+1]=(dp[i+1][j+1]+1ll*(m-1)*dp[i][j])%mod,
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
	printf("%d",dp[n][k]);
}