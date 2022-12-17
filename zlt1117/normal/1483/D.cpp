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
const int maxn=605;
const ll inf=1e18;
int n,m,q;
ll dis[maxn][maxn];
int vis[maxn][maxn];
ll lim[maxn][maxn];///y from x's begin the most left
vector<pair<int,int> >vec[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)FOR(j,1,n)dis[i][j]=inf;
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		dis[v][u]=dis[u][v]=vis[u][v]=vis[v][u]=w;
	}
}
int ans;
inline void solve()
{
	FOR(i,1,n)dis[i][i]=0;
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	q=gi();
	FOR(i,1,q)
	{
		int x=gi(),y=gi(),l=gi();
		vec[x].pb({y,l});
	}
	FOR(i,1,n)
	{
		FOR(j,1,n)///from j
		{
			ll now=-inf;
			for(auto x:vec[j])now=max(now,x.second-dis[i][x.first]);
			lim[i][j]=now;
		}
	}
	FOR(i,1,n)
	{
		FOR(j,i+1,n)
		{///i->j
			if(!vis[i][j])continue;
			FOR(k,1,n)
			{
				if(dis[k][i]+vis[i][j]<=lim[j][k]||dis[k][j]+vis[j][i]<=lim[i][k])
				{
					ans++;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
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
}///