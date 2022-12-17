#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e5+5;
int n,m;
int val[maxn],dep[maxn],dfn[maxn],tot,fa[maxn],tp[maxn],p[maxn],son[maxn],sz,siz[maxn];
vector<pair<int,int> >v;
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
struct seg
{
	#define ls u<<1
	#define rs u<<1|1
	int sum[maxn<<2];
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)
		{
			sum[u]=v;
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,v);
			else update(rs,mid+1,r,x,v);
			pushup(u);
		}
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		else
		{
			int mid=(l+r)>>1,val=0;
			if(x<=mid)val+=query(ls,l,mid,x,y);
			if(y>mid)val+=query(rs,mid+1,r,x,y);
			return val;
		}
	}
}tree;
inline void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u]=f;
	siz[u]=1;
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f)continue;
		else
		{
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
}
inline void dfs2(int u,int topf)
{
	dfn[u]=++tot;
	tp[u]=topf;
	if(son[u])dfs2(son[u],topf);
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa[u]||v==son[u])continue;
		else
		{
			dfs2(v,v);
		}
	}
}
inline int query(int u,int v)
{
	int sumd=dep[u]+dep[v],value=0;
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		value+=tree.query(1,1,n,dfn[tp[u]],dfn[u]);
		u=fa[tp[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	value+=tree.query(1,1,n,dfn[u],dfn[v]);
	value-=val[u];
	if(value==0)return sumd-2*dep[u];
	else return -1;
}
inline void update(int id,int va)
{
	int u=v[id-1].first;
	if(dep[v[id-1].second]>dep[u])u=v[id-1].second;
	val[u]=va;
	tree.update(1,1,n,dfn[u],va);
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
	{
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		add(uu,vv);
		add(vv,uu);
		v.push_back(make_pair(uu,vv));
	}
	dfs1(1,0);
	dfs2(1,1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1)update(x,0);
		else if(opt==2)update(x,1);
		else
		{
			scanf("%d",&y);
			printf("%d\n",query(x,y));
		}
	}
	return 0;
}