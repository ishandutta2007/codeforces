#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 510
#define M 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll n,m,dp[N][N],num[N],nxt[N][N],pos[N];
char str[N];

ll dfs(ll u,ll v)
{
	if(u>v) return 0;
	if(u==v) return 1;
	if(dp[u][v]!=-1) return dp[u][v];
	ll i,res=dfs(u+1,v)+1;
	for(i=nxt[u][num[u]];i<=v;i=nxt[i][num[u]]) res=min(res,dfs(u+1,i-1)+dfs(i,v));
	return dp[u][v]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,p,q;
	cin>>n;
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(i==1 || str[i]!=str[i-1])
		{
			num[++m]=str[i];
		}
	}
	for(i=1;i<=300;i++) pos[i]=m+1;
	for(i=m;i>=1;i--)
	{
		nxt[i][num[i]]=pos[num[i]];
		pos[num[i]]=i;
	}
	n=m;
	cout<<dfs(1,n);
}