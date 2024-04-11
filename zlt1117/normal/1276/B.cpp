//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=4e5+5;
int T,n,m,a,b;
vector<int>vec[maxn];
vector<int>e[maxn];
int dfn[maxn],tot,dep,low[maxn],cnt,sta[maxn],fa[maxn],siz[maxn];
inline void init()
{
	FOR(i,1,n)vec[i].clear(),e[i].clear();
	FOR(i,1,n)dfn[i]=low[i]=siz[i]=fa[i]=0;
	tot=0,dep=0,cnt=0;
}
inline void input()
{
	n=gi(),m=gi(),a=gi(),b=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		vec[u].pb(v),vec[v].pb(u);
	}
}
inline void dfs(int u,int fa)
{
	sta[++dep]=u;
	dfn[u]=low[u]=++tot;
	for(auto v:vec[u])
	{
		if(v==fa)continue;
		if(dfn[v])low[u]=min(low[u],dfn[v]);
		else
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				++n;
				e[n].pb(u);
				e[u].pb(n);
				while(1)
				{
					int x=sta[dep--];
					e[x].pb(n),e[n].pb(x);
					if(x==v)break;
				}
			}
		}
	}
}
inline void dfs2(int u)
{
	if(u<=cnt)siz[u]=1;
	for(auto v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs2(v);
		siz[u]+=siz[v];
	}
}
inline void solve()
{
	cnt=n;
	dfs(1,0);
	ll ans=0;
	dfs2(a);
	int now=b;
	while(fa[now]!=a&&now!=0)now=fa[now];
	ans=siz[b]-1;
	ans*=(siz[a]-siz[now]-1);
	printf("%lld\n",ans);
}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}