#include<bits/stdc++.h>
#define ll long long
#define N 2010
#define M 1000000007
using namespace std;

ll n,m,dp[N][N],num[N],jc[N],cnt,ct;
bool use[N];

ll ask(ll u,ll v)
{
	if(v<0) return 0;
	if(!v) return jc[u];
	if(dp[u][v]!=-1) return dp[u][v];
	return dp[u][v]=((v-1)*ask(u-1,v-2)%M+(u-v)*ask(u-1,v-1))%M;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int i,j,p,q,o;
	cin>>n;jc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		jc[i]=jc[i-1]*i%M;
		if(num[i]!=-1) use[num[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(num[i]==-1)
		{
			cnt++;
			if(!use[i]) ct++;
		}
	}
//	cout<<cnt<<" "<<ct<<endl;
	cout<<ask(cnt,ct);
}