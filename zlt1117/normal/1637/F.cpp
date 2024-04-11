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
const int maxn=2e5+5;
int n,h[maxn];
vector<int>e[maxn];
int maxv[maxn];
inline void init()
{

}
int now=0;
inline void input()
{
	n=gi();
	FOR(i,1,n)h[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	FOR(i,1,n)if(h[i]>h[now])now=i;
}
ll ans;
int maxv2[maxn];
inline void dfs(int u,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		if(maxv[v]>=maxv[u])maxv2[u]=maxv[u],maxv[u]=maxv[v];
		else maxv2[u]=max(maxv2[u],maxv[v]);
	}
	if(maxv[u]<h[u])ans+=h[u]-maxv[u],maxv[u]=h[u];
}
inline void solve()
{
	dfs(now,0);
	ans+=h[now]-maxv2[now];
	printf("%lld\n",ans);
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