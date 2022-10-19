#include<bits/stdc++.h>
#define ll long long
#define N 2004
#define M 1000000007
using namespace std;

ll len,n,dp[N][N];

int dg(ll ch,ll zq)
{
	if(dp[ch][zq]!=-1)
	{
		return dp[ch][zq];
	}
	ll ans=0,i;
	for(i=1;i<=n/zq;i++)
	{
		ans+=dg(ch+1,i*zq);
		ans=ans%M;
	}
	dp[ch][zq]=ans;
	return ans;
}

int main()
{
	ll i,j;
	cin>>n>>len;
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		dp[len][i]=1;
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=dg(1,i);
		ans=ans%M;
	}
	cout<<ans;
}