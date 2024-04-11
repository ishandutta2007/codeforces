#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
const int maxn=505;
bitset<maxn>dp[maxn][maxn];
int n,k,a,cnt;
int main()
{
	scanf("%d%d",&n,&k);
	dp[0][0].set(0,1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		for(int j=0;j<=k-a;++j)
		{
			dp[i][j+a]|=dp[i-1][j]|(dp[i-1][j]<<a);
		}
		for(int j=0;j<=k;++j)
		{
			dp[i][j]|=dp[i-1][j];
		}
	}
	printf("%d\n",dp[n][k].count());
	for(int i=0;i<=k;++i)
	{
		if(dp[n][k][i])printf("%d ",i);
	}
	printf("\n");
	return 0;
}