#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
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
const int maxn=5005,mod=998244353;
int dp[maxn][maxn];
vector<int>e[maxn];
int n,k,siz[maxn],dep[maxn],tmp[maxn],maxdep[maxn];
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
}
inline void dfs(int u,int fa)
{
	maxdep[u]=dep[u];
	dp[u][0]=1;
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		int kk=maxdep[u]-dep[u];
		FOR(i,0,max(maxdep[u],maxdep[v])-dep[u])tmp[i]=0;
		FOR(i,0,kk)
		{
			FOR(j,0,maxdep[v]-dep[u])
			{
				tmp[i]=(tmp[i]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
				if(i+j+1>k)continue;
				tmp[max(i,j+1)]=(tmp[max(i,j+1)]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
			}
		}
		maxdep[u]=max(maxdep[u],maxdep[v]);
		FOR(i,0,maxdep[u]-dep[u])dp[u][i]=tmp[i];
	}
}
inline void solve()
{
	dfs(1,0);
	int ans=0;
	FOR(i,0,k)ans=(ans+dp[1][i])%mod;
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}