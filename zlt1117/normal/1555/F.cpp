#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=5e5+5;
int n,Q;
int u[maxn],v[maxn],w[maxn];
vector<pair<int,int>>e[maxn];
int d[maxn];
int dfn[maxn],dis[maxn],low[maxn],tot,son[maxn],siz[maxn],tp[maxn],fa[maxn],dep[maxn];
bool vis[maxn];
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void input()
{
	n=gi(),Q=gi();
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,Q)
	{
		u[i]=gi(),v[i]=gi(),w[i]=gi();
		if(get(u[i])==get(v[i]))continue;
		else fa[get(u[i])]=get(v[i]);
		e[u[i]].pb({v[i],w[i]});
		e[v[i]].pb({u[i],w[i]});
		vis[i]=1;
	}
}
inline void dfs(int u)
{
	siz[u]=1;dep[u]=dep[fa[u]]+1;
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa[u])continue;
		fa[v]=u,dis[v]=dis[u]^w;
		dfs(v),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	tp[u]=topf;dfn[u]=++tot;
	if(son[u])dfs2(son[u],topf);
	for(auto x:e[u])
	{
		int v=x.first;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
	low[u]=tot;
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=1.2e6+5;
	int sum[maxn],tag[maxn];
	inline void pushdown(int u,int l,int r)
	{
		if(tag[u])
		{
			int mid=(l+r)>>1;
			sum[ls]+=tag[u]*(mid-l+1);
			sum[rs]+=tag[u]*(r-mid);
			tag[ls]+=tag[u],tag[rs]+=tag[u];
			tag[u]=0;
		}
	}
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return sum[u]+=(r-l+1)*v,tag[u]+=v,void();
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u]>0;
		int mid=(l+r)>>1,ret=0;
		pushdown(u,l,r);
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret+=query(rs,mid+1,r,x,y);
		return ret>0;
	}
}tree;
inline int LCA(int u,int v)
{
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		u=fa[tp[u]];
	}
	return dep[u]>dep[v]?v:u;
}
inline void update_cover(int u,int v)
{
//	tree.update(dfn[u],-1),tree.update(dfn[u]+1,1);
//	tree.update(dfn[v],-1),tree.update(dfn[v]+1,1);
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		tree.update(1,1,n,dfn[tp[u]],dfn[u],1);
		u=fa[tp[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	tree.update(1,1,n,dfn[u],dfn[v],1);
	int lca=LCA(u,v);
	tree.update(1,1,n,dfn[lca],dfn[lca],-1);
}
inline bool query(int u,int v)
{
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		if(tree.query(1,1,n,dfn[tp[u]],dfn[u]))return 1;
		u=fa[tp[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	if(u!=v)return tree.query(1,1,n,dfn[u]+1,dfn[v]);
	return 0;
}
inline void solve()
{
	FOR(i,1,n)fa[i]=0;
	FOR(i,1,n)
	{
		if(!dfn[i])
		{
			dfs(i);
			dfs2(i,i);
		}
	}
	FOR(i,1,Q)
	{
		if(vis[i])
		{
			puts("Yes");
			continue;
		}
		if((dis[u[i]]^dis[v[i]])==w[i])puts("No");
		else if(query(u[i],v[i]))puts("No");
		else puts("Yes"),update_cover(u[i],v[i]);
	}
}
int main()
{
	input();
	solve();
	return 0;
}