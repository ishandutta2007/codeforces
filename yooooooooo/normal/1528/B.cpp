#include<bits/stdc++.h>
using namespace std;
int n,dp[1000005],sum[1000005],d[1000005];
const int mod=998244353;
int M(int x){return x>=mod?x-mod:x;}
int main()
{
	for(int i=1;i<=1000000;i++)for(int j=i+i;j<=1000000;j+=i)d[j]++;
	dp[0]=dp[1]=1;
	sum[0]=1;sum[1]=2;
	for(int i=2;i<=1000000;i++)
	{
		dp[i]=M(sum[i-1]+d[i]);
		sum[i]=M(sum[i-1]+dp[i]);
	}
	scanf("%d",&n);
	printf("%d\n",dp[n]);
	return 0;
}