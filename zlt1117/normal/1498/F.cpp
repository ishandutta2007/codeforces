#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e5+5;
int n,k;
vector<int>e[maxn];
int sum[maxn][42];
int ans[maxn],val[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	FOR(i,1,n)val[i]=gi();
}
inline void dfs(int u,int fa)
{
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		FOR(j,1,2*k-1)sum[u][j]^=sum[v][j-1];
		sum[u][0]^=sum[v][2*k-1];
	}
	sum[u][0]^=val[u];
}
int temp[maxn][42];
inline void dfs2(int u,int fa)
{
	FOR(i,0,2*k-1)if((i/k)&1)ans[u]^=sum[u][i];
	FOR(i,0,2*k-1)temp[u][i]=sum[u][i];
	for(auto v:e[u])
	{
		if(v==fa)continue;
		FOR(j,1,2*k-1)sum[u][j]^=sum[v][j-1];
		sum[u][0]^=sum[v][2*k-1];
		FOR(j,1,2*k-1)sum[v][j]^=sum[u][j-1];
		sum[v][0]^=sum[u][2*k-1];
		dfs2(v,u);
		FOR(j,0,2*k-1)sum[u][j]=temp[u][j];
	}
}
inline void solve()
{
	dfs(1,0);
	dfs2(1,0); 
	FOR(i,1,n)printf("%d ",ans[i]!=0);
}
signed main()
{
	init();
	input();
	solve();
	return 0;
}