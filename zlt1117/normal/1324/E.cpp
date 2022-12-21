#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2005;
int n,h,l,r,a;
int dp[maxn][maxn],ans;
int main()
{
	memset(dp,0xcf,sizeof(dp));
	dp[0][0]=0;
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		for(int j=0;j<=h-1;++j)
		{
			dp[i][(j+a)%h]=max(dp[i][(j+a)%h],dp[i-1][j]+((j+a)%h>=l&&(j+a)%h<=r));
			dp[i][(j+a-1+h)%h]=max(dp[i][(j+a-1+h)%h],dp[i-1][j]+((j+a+h-1)%h>=l&&(j+a+h-1)%h<=r));
		}
	}
	for(int i=0;i<=h-1;++i)ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}