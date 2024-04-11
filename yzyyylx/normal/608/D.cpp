#include<bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;

ll dp[N][N],num[N],n;

ll ss(ll u,ll v)
{
	if(dp[u][v]!=-1)
	{
		return dp[u][v];
	}
//	if(u>v) return 1000000000;
	
	ll i,ans=1000000000;
	if(num[u]==num[v])
	{
		ans=ss(u+1,v-1);
	}
	for(i=u;i<v;i++)
	{
		ans=min(ans,ss(u,i)+ss(i+1,v));
	}
	dp[u][v]=ans;
	return ans;
}

int main()
{
	ll i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n-1;i++)
	{
		if(num[i]!=num[i+1]) dp[i][i+1]=2;
		else dp[i][i+1]=1;
		dp[i][i]=1;
	}
	dp[n][n]=1;
	cout<<ss(1,n);
	/*
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
}