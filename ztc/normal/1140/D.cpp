#include<stdio.h>
inline long long Min(long long a,long long b){return a<b?a:b;}
long long dp[502][502],i,j,k;int n;
main()
{
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			dp[j][i+j]=10000000000000000ll;
			for(k=j+1;k<j+i;k++)dp[j][i+j]=Min(dp[j][i+j],dp[j][k]+dp[k][j+i]+j*k*(j+i));
		}
	}printf("%lld",dp[1][n]);
}