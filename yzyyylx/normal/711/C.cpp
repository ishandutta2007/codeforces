#include<bits/stdc++.h>
#define ll long long
#define N 110
#define M 10000000000000000
using namespace std;

ll dp[N][N][N],n,m,k,cst[N][N],ans=M,col[N];

inline ll dfs(ll now,ll bea,ll last)
{
	if(now>n)
	{
		if(bea==k) return 0;
		else return M;
	}
	if(bea>k) return M;
	if(dp[now][bea][last]!=M) return dp[now][bea][last];
	ll i,j,res=M+1;
	if(col[now]!=0)
	{
		if(col[now]==last) res=dfs(now+1,bea,last);
		else res=dfs(now+1,bea+1,col[now]);
	}
	else
	{
		for(i=1;i<=m;i++)
		{
			if(i==last) res=min(res,dfs(now+1,bea,last)+cst[now][last]);
			else res=min(res,dfs(now+1,bea+1,i)+cst[now][i]);
		}
	}
	dp[now][bea][last]=res;
	return res;
}

int main()
{
	ll i,j,l;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&col[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&cst[i][j]);
		}
	}
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			for(l=0;l<=100;l++)
			{
				dp[i][j][l]=M;
			}
		}
	}
	ans=dfs(1,0,0);
	if(ans<M) printf("%lld",ans);
	else printf("-1");
}