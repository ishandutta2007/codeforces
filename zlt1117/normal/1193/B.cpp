#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=1e5+5;
int n,m,k;
vector<int>e[maxn];
int w[maxn],d[maxn];
struct segmentree
{
	static const int maxn=2e6+5;
	ll maxv[maxn],tag[maxn];
	int tot,ls[maxn],rs[maxn];
	inline void pushup(int u)
	{
		maxv[u]=max(maxv[ls[u]],maxv[rs[u]]);
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			if(ls[u])maxv[ls[u]]+=tag[u];
			if(rs[u])maxv[rs[u]]+=tag[u];
			if(ls[u])tag[ls[u]]+=tag[u];
			if(rs[u])tag[rs[u]]+=tag[u];
			tag[u]=0;
		}
	}
	inline int merge(int u,int v,int l,int r,ll &pre1,ll &pre2)
	{
		if(u==0&&v==0)return 0;
		if(u==0)
		{
			pre2=max(pre2,maxv[v]);
			maxv[v]+=pre1;tag[v]+=pre1;
			return v;
		}
		if(v==0)
		{
			pre1=max(pre1,maxv[u]);
			maxv[u]+=pre2;tag[u]+=pre2;
			return u;
		}
		if(l==r)
		{
			pre1=max(maxv[u],pre1);
			pre2=max(maxv[v],pre2);
			maxv[u]=max(maxv[u]+pre2,maxv[v]+pre1);
			return u;
		}
		int mid=(l+r)>>1;
		pushdown(u),pushdown(v);
		ls[u]=merge(ls[u],ls[v],l,mid,pre1,pre2);
		rs[u]=merge(rs[u],rs[v],mid+1,r,pre1,pre2);
		pushup(u);
		return u;
	}
	inline void update(int &u,int l,int r,int x,ll v)
	{
		if(!u)u=++tot;
		if(l==r)return maxv[u]=v,void();
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls[u],l,mid,x,v);
		else update(rs[u],mid+1,r,x,v);
		pushup(u);
	}
	inline ll query(int u,int l,int r,int x,int y)
	{
		if(!u)return 0;
		if(x<=l&&y>=r)return maxv[u];
		ll ret=0;int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)ret=query(ls[u],l,mid,x,y);
		if(y>mid)ret=max(ret,query(rs[u],mid+1,r,x,y));
		return ret;
	}
}tree;
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,2,n)
	{
		int x=gi();
		e[x].pb(i),e[i].pb(x);
	}
	FOR(i,1,m)
	{
		int x=gi();
		d[x]=gi(),w[x]=gi();
	}
}
int rt[maxn];
inline void dfs(int u,int fa)
{
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		ll pre1=0,pre2=0;
		rt[u]=tree.merge(rt[u],rt[v],1,k,pre1,pre2);
	}
	ll now=tree.query(rt[u],1,k,1,d[u]);
	if(w[u])tree.update(rt[u],1,k,d[u],now+w[u]);
}
inline void solve()
{
	dfs(1,0);
	printf("%lld\n",tree.maxv[rt[1]]);
}
int main()
{
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout); 
	init();
	input();
	solve();
	return 0;
}