#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int ind[maxn],T;
int siz[maxn],p[maxn],sz,maxv[maxn],now,n,ans;
vector<int>rt,vec;
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
inline void dfs(int u,int fa)
{
	siz[u]=1;
	REP(u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		maxv[u]=max(siz[v],maxv[u]);
	}
	if(max(n-siz[u],maxv[u])<=n/2)rt.push_back(u);
}
inline void dfs2(int u,int fa)
{
	bool ok=false;
	REP(u)
	{
		int v=e[i].v;
		if(v==rt[1])ok=true;
		if(v==fa||v==rt[1])continue;
		dfs2(v,u);
	}
	if(!ok&&ind[u]==1)ans=u;
}
int main()
{
	T=getint();
	memset(p,-1,sizeof(p));
	while(T--)
	{
		n=getint();
		FOR(i,1,n-1)
		{
			int u=getint(),v=getint();
			add(u,v),add(v,u);
			ind[u]++,ind[v]++;
		}
		sz=0;
		rt.clear();
		vec.clear();
		dfs(1,0);
		if(rt.size()==1)
		{
			printf("%d %d\n",1,e[p[1]].v);
			printf("%d %d\n",1,e[p[1]].v);
		}
		else
		{
			ans=0;
			dfs2(rt[0],0);
			printf("%d %d\n",ans,e[p[ans]].v);
			printf("%d %d\n",ans,rt[1]);
		}
		FOR(i,1,n)p[i]=-1,ind[i]=0,siz[i]=0,maxv[i]=0;
	}
	return 0;
}