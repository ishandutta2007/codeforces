#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[64][11][2048],num[100],T;

ll dfs(ll len,ll b,ll con,bool lng,bool H)
{
	ll ans,p,i;
	if(len==0)
		return con==0&&!lng;
	if(dp[len][b][con]!=-1&&!H&&!lng)
		return dp[len][b][con];
	
	if(H) p=num[len];
	else p=b-1;
	ans=0;
	for(i=0;i<=p;i++)
	{
		if(lng&&i==0)
			ans+=dfs(len-1,b,con,1,H&&i==num[len]);
		else
			ans+=dfs(len-1,b,con^(1 << i),0,H&&i==num[len]);
	}
	if(H==0&&lng==0)
		dp[len][b][con]=ans;
	return ans;
}

ll ys(ll n,ll b)
{
	ll len=0,i,k=n,ans=0;
	if(n==0) return 0;
	while(k)
	{
		len++;
		num[len]=k%b;
		k/=b;
	}
	ans=dfs(len,b,(ll)0,1,1);
	return ans;
}

int main()
{
	ll p,q,ans,jz;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while(T--)
	{
		scanf("%lld%lld%lld",&jz,&p,&q);
		p--;
		ans=ys(q,jz)-ys(p,jz);
		printf("%lld\n",ans);
	}
	return 0;
}