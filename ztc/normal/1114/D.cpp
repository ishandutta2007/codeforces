#include<stdio.h>
#include<queue>
#define Max(a,b) (a>(b)?a:(b))
int a[100002],n=0,m,b,Next[100002],Last[100002],dp[5002][5002],k;
main()
{
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&b);
		if(b!=a[n])a[++n]=b;
	}
	for(int i=1;i<=n;i++)
	{
		Next[i]=Last[a[i]];Last[a[i]]=i;
	}k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			dp[i][j]=Max(dp[i][j+1],dp[i-1][j]);
			if(a[i]&&a[j]&&a[i]==a[j])dp[i][j]=dp[i-1][j+1]+1;
		}k=Max(k,dp[i][i]);
	}printf("%d",n-k);
}