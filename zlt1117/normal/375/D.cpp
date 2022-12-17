#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=1e5+5;
int d[maxn],c[maxn],cnt[maxn];
int son[maxn],siz[maxn],n,m;
vector<int>e[maxn];
inline void dfs(int u,int fa)
{
	siz[u]=1;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
vector<pair<int,int>>q[maxn];
int ans[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)c[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	FOR(i,1,m)
	{
		int x=gi(),k=gi();
		q[x].pb({i,k});
	}
}
inline void update(int u,int fa,int typ)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		update(v,u,typ);
	}
	if(typ==1)d[++cnt[c[u]]]++;
	else d[cnt[c[u]]--]--;
}
inline void dfs2(int u,int fa,int typ)
{
	for(int v:e[u])
	{
		if(v==fa||v==son[u])continue;
		dfs2(v,u,0);
	}
	if(son[u])dfs2(son[u],u,1);
	for(int v:e[u])if(v!=fa&&v!=son[u])update(v,u,1);
	d[++cnt[c[u]]]++;
	for(auto x:q[u])ans[x.first]=d[x.second];
	if(!typ)update(u,fa,-1); 
}
inline void solve()
{
	dfs(1,0);
	dfs2(1,0,1);
	FOR(i,1,m)printf("%d\n",ans[i]);
}
int main()
{
	input();
	solve();
	return 0;
}