#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc ((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++)
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
const int maxn=1e6+5;
int n,dep[maxn],len[maxn],son[maxn],fa[maxn];
vector<int>e[maxn];
int *f[maxn],tmp[maxn],*id=tmp,ans[maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u,dfs(v);
		if(len[v]>len[son[u]])son[u]=v;
	}
	len[u]=len[son[u]]+1;
}
inline void dfs2(int u)
{
	f[u][0]=1;
	if(son[u])
	{
		f[son[u]]=f[u]+1;
		dfs2(son[u]);
		ans[u]=ans[son[u]]+1;
	}
	for(int v:e[u])
	{
		if(v==fa[u]||v==son[u])continue;
		f[v]=id,id+=len[v];dfs2(v);
		FOR(j,1,len[v])
		{
			f[u][j]+=f[v][j-1];
			if((f[u][j]>f[u][ans[u]])||(f[u][j]==f[u][ans[u]]&&j<ans[u]))ans[u]=j;
		}
	}
	if(f[u][ans[u]]==1)ans[u]=0;
}
inline void solve()
{
	dfs(1);
	f[1]=id,id+=len[1],dfs2(1);///get the memory
	FOR(i,1,n)printf("%d\n",ans[i]);
}
int main()
{
	input();
	solve();
	return 0;
}