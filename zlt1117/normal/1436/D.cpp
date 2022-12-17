#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
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
const int maxn=2e5+5;
int n,p[maxn],sz,a[maxn];
ll dp[maxn],maxv;
struct edge
{
	int v,nxt;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void init()
{
	memset(p,-1,sizeof(p));
}
inline void input()
{
	n=gi();
	FOR(i,2,n)
	{
		int x=gi();
		add(i,x);add(x,i);
	}
	FOR(i,1,n)a[i]=gi(),maxv+=a[i];
}
inline bool dfs(int u,int fa,ll x)
{
	dp[u]=0;
	bool ok=0;
	dp[u]-=a[u];
	REP(u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		ok=1;
		if(!dfs(v,u,x))return false;
		dp[u]+=dp[v];
		if(dp[u]>=maxv)dp[u]=maxv;
	}
	if(!ok)dp[u]+=x;
	if(dp[u]<0)return false;
	return true;
}
inline bool check(ll x)
{
	return dfs(1,0,x);
}
inline void solve()
{
	ll l=0,r=maxv,ans=0;///2e5*1e9
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}