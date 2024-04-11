#include<bits/stdc++.h>
#define ll long long
#define N 100000
#define M 1000000007
using namespace std;

ll n,m,dp[N+10],ans[N+10];

int main()
{
	ll i,j,p,q;
	scanf("%lld%lld",&m,&n);
	memset(dp,-1,sizeof(dp));
	for(i=0;i<=n-1;i++)
	{
		dp[i]=1;
	}
	for(i=n;i<=N;i++)
	{
		dp[i]=dp[i-1]+dp[i-n];
		dp[i]=dp[i]%M;
	}
	ans[0]=0;
	for(i=1;i<=N;i++)
	{
		ans[i]=dp[i]+ans[i-1];
		ans[i]=ans[i]%M;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		printf("%lld\n",(ans[q]+M-ans[p-1])%M);
	}
}