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
const int maxn=605;
int vis[maxn][maxn];
ll dis[maxn];
bool now[maxn];
int minv[maxn]; 
ll ans[maxn][maxn];
bool cur[maxn];
int n,m,tmp[maxn][maxn];
inline void dijkstra(int u)
{
	memset(now,0,sizeof(now));
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	FOR(i,0,n-1)
	{
		int now1=n;
		FOR(j,0,n-1)if(!now[j]&&dis[j]<dis[now1])now1=j;
		int u=now1;now[u]=1;
		FOR(j,0,n-1)dis[(j+dis[u])%n]=min(dis[(j+dis[u])%n],dis[u]+tmp[u][j]);
	}
}
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		vis[u][v]=w;
	}
	memset(tmp,0x3f,sizeof(tmp));
	FOR(i,0,n-1)FOR(j,0,n-1)
	{
		if(!vis[i][j])continue;
		FOR(k,0,n-1)tmp[i][(j+k)%n]=min(tmp[i][(j+k)%n],vis[i][j]+k);
	}
}
inline void solve()
{
	FOR(i,0,n-1)
	{
		dijkstra(i);
		FOR(j,0,n-1)ans[i][j]=dis[j];
	}
	FOR(i,0,n-1)
	{
		FOR(j,0,n-1)printf("%lld ",ans[i][j]);
		printf("\n");
	}
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}