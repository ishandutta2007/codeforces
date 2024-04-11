//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5,mod=1e9+7;
int dep[maxn],a[maxn],b[maxn],dfn[maxn],counter,low[maxn],n;
vector<int>e[maxn];
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
namespace Tree
{
	int tot,Log[maxn<<1],st[maxn<<1][20],fir[maxn];
	inline void dfs(int u,int fa)
	{
		st[++tot][0]=u,fir[u]=tot;
		dep[u]=dep[fa]+1;dfn[u]=++counter;
		for(int v:e[u])
		{
			if(v==fa)continue;
			dfs(v,u);
			st[++tot][0]=u;
		}
		low[u]=counter;
	}
	inline int compare(int x,int y){return dep[x]<dep[y]?x:y;}
	inline void prepare()
	{
		FOR(i,2,maxn*2-1)Log[i]=Log[i>>1]+1;
		dfs(1,0);
		FOR(j,1,Log[tot])FOR(i,1,tot-(1<<j)+1)st[i][j]=compare(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	inline int LCA(int x,int y)
	{
		x=fir[x],y=fir[y];
		if(x>y)swap(x,y);
		int l=Log[y-x+1];
		return compare(st[x][l],st[y-(1<<l)+1][l]);
	}
	inline int dist(int x,int y)
	{
		return dep[x]+dep[y]-2*dep[LCA(x,y)];
	}
}
using Tree::dist;
using Tree::LCA;
int ans[maxn],g[maxn],mu[maxn],pri[maxn],cnt,phi[maxn];
bool vis[maxn];
namespace Virtual_Tree
{
	const int maxn=4e5+5;
	int Q[maxn],p[maxn],cnt,stk[maxn],tp,sz,dp[maxn];
	bool vis[maxn];
	struct edge
	{
		int v,nxt;
		edge(int vv=0,int nn=0){v=vv,nxt=nn;}
	}e[maxn<<1];
	inline void init()
	{
		memset(p,-1,sizeof(p));
		sz=-1;
	}
	inline void add(int u,int v)
	{
		e[++sz]=edge(v,p[u]);
		p[u]=sz;
	}
	inline void clear()
	{
		FOR(i,1,cnt)p[Q[i]]=-1,dp[Q[i]]=0,vis[Q[i]]=0;
		sz=-1,tp=0;cnt=0;
	}
	inline void build()
	{
		sort(Q+1,Q+cnt+1,[&](int x,int y){return dfn[x]<dfn[y];});
		for(int i=cnt-1;i>=1;--i)Q[++cnt]=LCA(Q[i],Q[i+1]);
		Q[++cnt]=1;
		sort(Q+1,Q+cnt+1,[&](int x,int y){return dfn[x]<dfn[y];});
		cnt=unique(Q+1,Q+cnt+1)-Q-1;
		FOR(i,1,cnt)
		{
			while(tp&&dfn[Q[i]]>low[stk[tp]])tp--;
			if(tp)add(stk[tp],Q[i]),add(Q[i],stk[tp]);
			stk[++tp]=Q[i];
		}
	}
	inline void DP(int u,int fa,int &ans)
	{
		if(vis[u])dp[u]=phi[a[u]];
		ans=(ans-1ll*dp[u]*dp[u]%mod*dep[u]%mod+mod)%mod;
		for(int i=p[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v==fa)continue;
			DP(v,u,ans);
			ans=(ans-2ll*dp[u]*dp[v]%mod*dep[u]%mod+mod)%mod;
			dp[u]=(dp[u]+dp[v])%mod;
		}
	}
	inline void work(int x)
	{
		int sum=0;
		for(int i=x;i<=n;i+=x)Q[++cnt]=b[i],sum=(sum+phi[i])%mod,vis[b[i]]=1;
		for(int i=x;i<=n;i+=x)g[x]=(g[x]+1ll*phi[i]*dep[b[i]]%mod*sum%mod)%mod;
		build();
		DP(1,0,g[x]);
		g[x]=2ll*g[x]%mod;
		clear();
	}
}
using Virtual_Tree::work;
inline void init()
{
	vis[0]=vis[1]=1;mu[1]=1,phi[1]=1;
	FOR(i,2,maxn-1)
	{
		if(!vis[i])pri[++cnt]=i,phi[i]=i-1,mu[i]=-1;
		FOR(j,1,cnt)
		{
			int x=pri[j];
			if(1ll*x*i>=maxn)break;
			if(i%x)vis[x*i]=1,mu[x*i]=mu[x]*mu[i],phi[i*x]=phi[i]*phi[x];
			else {vis[x*i]=1,mu[x*i]=0;phi[i*x]=phi[i]*x;break;}
		}
	}
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[a[i]]=i;
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	Tree::prepare();
	Virtual_Tree::init();
}
inline void solve()
{
	FOR(i,1,n)work(i);
	FOR(i,1,n)for(int j=i;j<=n;j+=i)ans[i]=(ans[i]+1ll*mu[j/i]*g[j]%mod+mod)%mod;
	int sum=0;
	FOR(i,1,n)sum=(sum+1ll*ans[i]*i%mod*qpow(phi[i],mod-2)%mod)%mod;
	sum=1ll*sum*qpow(n,mod-2)%mod*qpow(n-1,mod-2)%mod;
	printf("%d\n",sum);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
8
1 2 3 4 5 6 7 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
*/