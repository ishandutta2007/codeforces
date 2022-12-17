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
const int maxn=205,mod=1e9+7;
int n,dep[maxn],dfn[maxn],low[maxn],counter;
vector<int>e[maxn];
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
	inline void prepare(int x)
	{
		tot=0;
		FOR(i,2,maxn*2-1)Log[i]=Log[i>>1]+1;
		dfs(x,0);
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
int f[maxn][maxn];
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
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	//Tree::prepare();
}
inline void solve()
{
	FOR(i,1,n)f[0][i]=1;
	FOR(i,1,n)FOR(j,1,n)f[i][j]=1ll*(mod+1)/2*(f[i-1][j]+f[i][j-1])%mod;
	int ans=0;
	FOR(i,1,n)
	{
		Tree::prepare(i);
		FOR(j,1,n)
		{
			FOR(k,j+1,n)
			{
				int lca=LCA(j,k);
				ans=(ans+f[dep[k]-dep[lca]][dep[j]-dep[lca]])%mod;				
			}
		}
	}
	ans=1ll*ans*qpow(n,mod-2)%mod;
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}