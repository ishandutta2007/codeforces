#pragma GCC optimize(4)
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
vector<pair<int,int> >e[maxn];
int n,m;
ll dis[maxn][2][2];
struct node
{
	int u,t1,t2;ll dis;
	inline bool operator<(const node &b)const
	{
		return dis>b.dis;
	}
};
priority_queue<node>pq;
bool vis[maxn][2][2];
inline void dijkstra()
{
	dis[1][0][0]=0;
	pq.push({1,0,0,0});
	while(!pq.empty())
	{
		int u=pq.top().u,i=pq.top().t1,j=pq.top().t2;
		pq.pop();
		if(vis[u][i][j])continue;
		vis[u][i][j]=1;
		for(auto x:e[u])
		{
			int v=x.first,w=x.second;
			if(dis[v][i][j]>dis[u][i][j]+w)dis[v][i][j]=dis[u][i][j]+w,pq.push({v,i,j,dis[v][i][j]});
			if(i==0)
			{
				if(dis[v][1][j]>dis[u][i][j])dis[v][1][j]=dis[u][i][j],pq.push({v,1,j,dis[v][1][j]});
			}
			if(j==0)
			{
				if(dis[v][i][1]>dis[u][i][j]+w+w)dis[v][i][1]=dis[u][i][j]+w+w,pq.push({v,i,1,dis[v][i][1]});
			}
			if(i==0&&j==0)
			{
				if(dis[v][1][1]>dis[u][i][j]+w)dis[v][1][1]=dis[u][i][j]+w,pq.push({v,1,1,dis[v][1][1]});
			}
		}
	}
}
inline void init()
{
	memset(dis,0x3f,sizeof(dis));
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
}
inline void solve()
{
	dijkstra();
	FOR(i,2,n)
	{
		ll ans=dis[i][1][1];
		printf("%lld ",ans);
	}
}
int main()
{
	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}