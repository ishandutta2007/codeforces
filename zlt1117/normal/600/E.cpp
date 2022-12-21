#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=1e5+5;
int cnt[maxn],col[maxn],n,p[maxn],sz;
int maxcnt,son[maxn],siz[maxn];
ll sum,ans[maxn];
struct edge
{
	int v,nxt;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs1(int u,int fa)
{
	siz[u]=1;
	REP(u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void update(int u,int fa,int val,int hvy)
{
	cnt[col[u]]+=val;
	if(val>0&&cnt[col[u]]>=maxcnt)
	{
		if(cnt[col[u]]>maxcnt)maxcnt=cnt[col[u]],sum=col[u];///is the color_u
		else sum+=col[u];
	}
	REP(u)
	{
		if(e[i].v==fa||e[i].v==hvy)continue;
		update(e[i].v,u,val,hvy);
	}
}
inline void dfs(int u,int fa,int typ)
{
	REP(u)
	{
		int v=e[i].v;
		if(v==fa||v==son[u])continue;
		dfs(v,u,0);
	}
	if(son[u])dfs(son[u],u,1);
	update(u,fa,1,son[u]);
	ans[u]=sum;
	if(typ==0)update(u,fa,-1,0),sum=maxcnt=0;///please attention
}
int main()
{
	memset(p,-1,sizeof(p));
	cin>>n;
	FOR(i,1,n)cin>>col[i];
	FOR(i,1,n-1)	
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs(1,0,1);
	FOR(i,1,n)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}