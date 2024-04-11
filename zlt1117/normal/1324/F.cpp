#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e5+5;
int dp[maxn],f[maxn];
int p[maxn],sta[maxn],n,sz,ans[maxn];
///fstate 
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u,int fa)
{
	dp[u]=sta[u];
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		dp[u]+=max(dp[v],0);
	}
}
inline void dfs2(int u,int fa)
{
	ans[u]=dp[u]+max(f[u],0);
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		f[v]=max(0,f[u]+dp[u]-max(dp[v],0));
		dfs2(v,u);
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&sta[i]),sta[i]=(sta[i]==1)?1:-1;
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}