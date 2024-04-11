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
const int maxn=1e5+5;
ll dp[maxn][2];
int n,l[maxn],r[maxn];
vector<int>e[maxn];
inline void init()
{
	FOR(i,1,n)l[i]=r[i]=0,e[i].clear();
	FOR(i,1,n)dp[i][0]=dp[i][1]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)l[i]=gi(),r[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void dfs(int u,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		dp[u][0]+=max(abs(l[u]-l[v])+dp[v][0],abs(l[u]-r[v])+dp[v][1]);
		dp[u][1]+=max(abs(r[u]-l[v])+dp[v][0],abs(r[u]-r[v])+dp[v][1]);
	}
}
inline void solve()
{
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}