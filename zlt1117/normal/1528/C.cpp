#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
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
const int maxn=3e5+5;
int sum,ans,n;
struct BIT
{
	int c[maxn];
	inline void update(int x,int v)
	{
		while(x<=n)c[x]+=v,x+=x&-x;
	}
	inline void clear()
	{
		FOR(i,1,n)c[i]=0;
	}
	inline int query(int x)
	{
		int ret=0;
		while(x)ret+=c[x],x-=x&-x;
		return ret;
	}
}tree,tree2;
vector<int>e[maxn],e2[maxn];
int dep[maxn],dfn[maxn],low[maxn],tot,fa[maxn][20],siz[maxn],tp[maxn],son[maxn],Log[maxn];
inline void dfs(int u)
{
	siz[u]=1;dep[u]=dep[fa[u][0]]+1;
	FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:e[u])
	{
		if(v==fa[u][0])continue;
		fa[v][0]=u,dfs(v),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	tp[u]=topf,dfn[u]=++tot;
	if(son[u])dfs2(son[u],topf);
	for(int v:e[u])
	{
		if(v==fa[u][0]||v==son[u])continue;
		dfs2(v,v);
	}
	low[u]=tot;
}
inline void init()
{
	sum=ans=0;
	FOR(i,1,n)e[i].clear(),e2[i].clear();
	FOR(i,1,n)dep[i]=dfn[i]=low[i]=fa[i][0]=siz[i]=tp[i]=son[i]=0;
	FOR(i,1,n)FOR(j,0,19)fa[i][j]=0;
	tree.clear(),tree2.clear();
	tot=0;
}
inline void input()
{
	n=gi();
	FOR(i,2,n)
	{
		int u=gi();
		e2[i].pb(u),e2[u].pb(i);
	}
	FOR(i,2,n)
	{
		int u=gi();
		e[i].pb(u),e[u].pb(i);
	}
	dfs(1);
	dfs2(1,1);
}
inline int get(int u)
{
	for(int i=Log[dep[u]];i>=0;--i)
	{
		if(fa[u][i]!=0&&tree.query(dfn[fa[u][i]]))u=fa[u][i];
	}
	return u;
}
inline void dfs3(int u,int fa)
{
	vector<pair<int,int>>now;
	bool ok=0;
	int t=sum;
	if(tree2.query(low[u])-tree2.query(dfn[u]-1)==0)
	{
		tree2.update(dfn[u],1);ok=1;
		if(tree.query(dfn[u]))
		{
			int x=get(u);
			now.pb({x,1});
			tree.update(dfn[x],-1);
			tree.update(low[x]+1,1);
		}
		else sum++;
		tree.update(dfn[u],1);
		tree.update(low[u]+1,-1);
		now.pb({u,-1});
	}
	ans=max(ans,sum);
	for(int v:e2[u])
	{
		if(v==fa)continue;
		dfs3(v,u);
	}
	if(ok)tree2.update(dfn[u],-1);
	for(auto x:now)
	{
		int y=x.first,v=x.second;
		tree.update(dfn[y],v);
		tree.update(low[y]+1,-v);
	}
	sum=t;
}
inline void solve()
{
	dfs3(1,0);
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	T=gi();
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}