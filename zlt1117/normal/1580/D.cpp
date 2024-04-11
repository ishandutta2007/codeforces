#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
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
const int maxn=4005;
int n,m,a[maxn],siz[maxn];
ll dp[maxn][maxn];
vector<int>e[maxn];
int rt;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi();rt=1;
	FOR(i,1,n)if(a[i]<a[rt])rt=i;
}
inline void build(int l,int r,int x)
{
	if(l>r)return ;
	int rt=l;
	FOR(i,l,r)if(a[i]<a[rt])rt=i;
	e[x].pb(rt),e[rt].pb(x);
	build(l,rt-1,rt);
	build(rt+1,r,rt);
}
inline void dfs(int u,int fa)
{
	dp[u][0]=0;dp[u][1]=1ll*(m-1)*a[u],siz[u]=1;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		for(int i=siz[u];i>=0;--i)
		{
			for(int j=siz[v];j>=0;--j)
			{
				dp[u][i+j]=max(dp[u][i+j],dp[u][i]+dp[v][j]-1ll*a[u]*i*j*2);
			}
		}
		siz[u]+=siz[v];
	}
}
inline void solve()
{
	memset(dp,0xcf,sizeof(dp));
	build(1,n,0);
	dfs(rt,0);
	printf("%lld\n",dp[rt][m]);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}