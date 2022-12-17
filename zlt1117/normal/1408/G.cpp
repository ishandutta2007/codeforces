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
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=3005,maxm=3e6+5,mod=998244353;
int n,a[maxn][maxn];
struct edge
{
	int u,v,w;
}ed[maxm];
int tot,m;
int siz[maxn],ec[maxn],dp[maxn][maxn];
int fa[maxn];
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)FOR(j,1,n)a[i][j]=gi();
	FOR(i,1,n)FOR(j,i+1,n)ed[++m]={i,j,a[i][j]};
	sort(ed+1,ed+m+1,[&](edge a,edge b){return a.w<b.w;});
}
int size1[maxn],tmp[maxn],ok[maxn];
vector<int>e[maxn];
inline void dfs(int u,int fa)
{
	size1[u]=1;dp[u][0]=1;
	for(int v:e[u])
	{
		dfs(v,u);
		memset(tmp,0,sizeof(int)*(size1[u]+size1[v]+1));
		FOR(j,0,size1[u])FOR(k,0,size1[v])tmp[j+k]=(tmp[j+k]+1ll*dp[u][j]*dp[v][k])%mod;
		FOR(j,1,size1[u]+size1[v])dp[u][j]=tmp[j];dp[u][0]=0;
		size1[u]+=size1[v];
	}
	if(ok[u])dp[u][1]=(dp[u][1]+1)%mod;dp[u][0]=0;
}
inline void solve()
{
	FOR(i,1,n)fa[i]=i,siz[i]=1;tot=n;
	FOR(i,1,2*n)fa[i]=i;
	FOR(i,1,m)
	{
		int u=get(ed[i].u),v=get(ed[i].v);
		if(u==v)
		{
			ec[u]++;
			if(ec[u]==siz[u]*(siz[u]-1)/2)ok[u]=1;
		}
		else
		{
			++tot;
			fa[u]=fa[v]=tot;e[tot].pb(u),e[tot].pb(v);
			ec[tot]=ec[u]+ec[v]+1;
			siz[tot]=siz[u]+siz[v];
			if(ec[tot]==siz[tot]*(siz[tot]-1)/2)ok[tot]=1;
		}
	}
	FOR(i,1,n)ok[i]=1;
	dfs(tot,0);
	FOR(i,1,n)printf("%d%c",dp[tot][i]," \n"[i==n]);
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