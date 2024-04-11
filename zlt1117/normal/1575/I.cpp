#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int c[maxn],n,q;
vector<int>e[maxn];
int dfn[maxn],tot;
struct BIT
{
	ll c[maxn];
	inline void update(int x,int v)
	{
		while(x<=n)c[x]+=v,x+=x&-x;
	}
	inline ll query(int x)
	{
		ll ret=0;
		while(x)ret+=c[x],x-=x&-x;
		return ret;
	}
}tree;
inline void init()
{

}
inline void input()
{
	n=gi();q=gi();
	FOR(i,1,n)c[i]=gi(),c[i]=abs(c[i]);
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
int fa[maxn][20],Log[maxn],dep[maxn],low[maxn];
inline void dfs(int u)
{
	dfn[u]=++tot;
	dep[u]=dep[fa[u][0]]+1;
	FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:e[u])
	{
		if(v==fa[u][0])continue;
		fa[v][0]=u;
		dfs(v);
	}
	low[u]=tot;
}
inline int LCA(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int i=Log[dep[v]];i>=0;--i)if(dep[fa[v][i]]>=dep[u])v=fa[v][i];
	if(u==v)return u;
	for(int i=Log[dep[v]];i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline void solve()
{
	FOR(i,2,n)Log[i]=Log[i>>1]+1;
	dfs(1);
	FOR(i,1,n)tree.update(dfn[i],c[i]),tree.update(low[i]+1,-c[i]);
	FOR(i,1,q)
	{
		int opt=gi();
		int u=gi(),v=gi();
		if(opt==1)
		{
			v=abs(v);
			tree.update(dfn[u],v-c[u]);
			tree.update(low[u]+1,c[u]-v);
			c[u]=v;
		}
		else 
		{
			ll ans=0;
			int lca=LCA(u,v);
			ans+=2*tree.query(dfn[u])+2*tree.query(dfn[v])-2*tree.query(dfn[lca])-2*tree.query(dfn[fa[lca][0]]);
			ans-=c[u]+c[v];
			printf("%lld\n",ans);
		}
	}
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}