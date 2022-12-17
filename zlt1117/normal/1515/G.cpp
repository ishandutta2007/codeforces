//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5;
int n,m;
vector<pair<int,int>>e[maxn];
int Q;
int scc[maxn];
stack<int>stk;
ll dep[maxn];
ll g[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w});//e[v].pb({u,w});
	}
}
int dfn[maxn],low[maxn],tot,scc_cnt;
inline void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	stk.push(u);
	for(auto x:e[u])
	{
		int v=x.first;
		if(scc[v])continue;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		++scc_cnt;
		while(1)
		{
			int x=stk.top();stk.pop();
			scc[x]=scc_cnt;
			if(x==u)break;
		}
	}
}
bool vis[maxn];
inline void dfs(int u)
{
	vis[u]=1;
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(scc[v]!=scc[u])continue;
		if(!vis[v])
		{
			dep[v]=dep[u]+w;
			dfs(v);
		}
		else
		{
			ll now=dep[u]+w-dep[v];
			//cerr<<u<<' '<<v<<' '<<w<<' '<<now<<endl;
			g[scc[u]]=__gcd(g[scc[u]],now);
		}
	}
}
inline void solve()
{
	FOR(i,1,n)if(!dfn[i])tarjan(i);
	FOR(i,1,n)if(!vis[i])dfs(i);
	Q=gi();
	FOR(i,1,Q)
	{
		ll v=gi(),s=gi(),t=gi();
		//cerr<<g[scc[v]]<<endl;
		if(g[scc[v]]==0)///only one point
		{
			if(s==0)puts("YES");
			else puts("NO");
		}
		else __gcd(s,t)%__gcd(t,g[scc[v]])?puts("NO"):puts("YES");
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