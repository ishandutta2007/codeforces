//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
#define db long double
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
int n,m,u,v;
vector<int>e[maxn];
int st[maxn],ed[maxn],sumx,sumy,siz[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	FOR(i,1,n)st[i]=gi(),sumx+=st[i],ed[i]=gi(),sumy+=ed[i];
}
db ans;
db dp[maxn],sum[maxn],p[maxn];
inline void dfs(int u,int fa)
{
	siz[u]=1;
	for(auto v:e[u])if(v!=fa)dfs(v,u),siz[u]+=siz[v];
}
inline void dfs2(int u,int fa)
{
	int sum1=siz[u]-1;
	sum[u]=(db)dp[u]*ed[u]/sumy;
	p[u]=(db)ed[u]/sumy;
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dp[v]=dp[u]+sum1-siz[v]+1;
		dfs2(v,u);
		sum[u]+=sum[v];
		p[u]+=p[v];
	}
}
inline void dfs3(int u,int fa)
{
	ans+=1.0*st[u]/sumx*sum[u];
	for(auto v:e[u])
	{
		if(v==fa)continue;
		sum[v]=sum[u];
		sum[v]-=(1-p[v]-(db)ed[u]/sumy)*siz[v];
		sum[v]+=1-p[v];
		sum[v]-=p[v];
		sum[v]-=(n-siz[v]-1)*p[v];
		sum[v]+=(siz[v]-1)*(1-p[v]);
		sum[v]+=(p[v]-(db)ed[v]/sumy)*(n-siz[v]);
		dfs3(v,u);
	}
}
inline void solve()
{
	dfs(1,0);dfs2(1,0);
	dfs3(1,0);
	printf("%.10Lf",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}