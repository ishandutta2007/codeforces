//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
inline int query1(int u)
{
	printf("d %d\n",u);fflush(stdout);
	int x=gi();assert(x!=-1);return x;
}
inline int query2(int u)
{
	printf("s %d\n",u);fflush(stdout);
	int x=gi();assert(x!=-1);return x;
}
inline void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
const int maxn=2e5+5;
int n;
vector<int>e[maxn];
///HLD
int dfn[maxn],dep[maxn],tim,low[maxn],bot[maxn],tp[maxn],siz[maxn],son[maxn],fa[maxn];
inline void dfs(int u)
{
	siz[u]=1;dep[u]=dep[fa[u]]+1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	dfn[u]=++tim;tp[u]=topf;
	if(son[u])dfs2(son[u],topf),bot[u]=bot[son[u]];
	else bot[u]=u;
	for(int v:e[u])
	{
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
///HLD
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1);dfs2(1,1);
}
inline void solve()
{
	int u=1,last=query1(1);
	while(1)
	{
		int now=query1(bot[u]);
		if(last+now==dep[bot[u]]-dep[u])
		{
			u=bot[u];
			FOR(i,1,now)u=fa[u];
			return answer(u);
		}
		else
		{
			last=now+last-dep[bot[u]]+dep[u];last/=2;
			now-=last;u=bot[u];
			FOR(i,1,now)u=fa[u];
			u=query2(u);last--;
		}
	}
}
int main()
{
	input();
	solve();
	return 0;
}