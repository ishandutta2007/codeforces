#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e5+5;
double dp[maxn];
int p[maxn],siz[maxn],sz,n;
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
	int sum=0;
	siz[u]=1;
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		else 
		{
			dfs(v,u);
			siz[u]+=siz[v];
		}
	}
}
inline void dfs2(int u,int fa)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		else 
		{
			dp[v]=dp[u]+(siz[u]-siz[v]-1)/2.0+1;
			dfs2(v,u);
		}
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		int fa;
		scanf("%d",&fa);
		add(i,fa);
		add(fa,i);
	}
	dp[1]=1;
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
	{
		printf("%.6lf ",dp[i]);
	}
	printf("\n");
	return 0;
}