#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,dp[100005],cnt[100005];

int main()
{
	ll i,j,a,mx=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		mx=max(a,mx);
		cnt[a]++;
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	dp[1]=cnt[1];
	for(i=2;i<=mx;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
	}
	printf("%lld",dp[mx]);
}