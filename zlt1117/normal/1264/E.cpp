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
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e4+5,maxm=1e5+5,inf=1e9;
int p[maxn],sz=-1,n,m;
int dis[maxn],flow[maxn],pre[maxn],lst[maxn],s,t,tot,ans,cans;
struct edge
{
	int v,flow,cost,nxt;
	edge(int vv=0,int ff=0,int cc=0,int nn=0){v=vv,nxt=nn,flow=ff,cost=cc;}
}e[maxm<<1];
inline void add(int u,int v,int flow,int cost)
{
	e[++sz]=edge(v,flow,cost,p[u]);
	p[u]=sz;
}
inline void ins(int u,int v,int flow,int cost)
{
	add(u,v,flow,cost);
	add(v,u,0,-cost);
}
bool in[maxn];
inline bool spfa()
{
	FOR(i,0,tot)dis[i]=inf,flow[i]=0;
	queue<int>q;q.push(s),dis[s]=0,in[s]=1;flow[s]=inf;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		in[u]=0;
		REP(u)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].cost&&e[i].flow)
			{
				dis[v]=dis[u]+e[i].cost;
				pre[v]=u,lst[v]=i;flow[v]=min(e[i].flow,flow[u]);
				if(!in[v])q.push(v);
			}
		}
	}
	return flow[t]!=0;
}
inline void EK()
{
	while(spfa())
	{
		int now=t,d=flow[t];
		ans+=d,cans+=d*dis[t];
		while(now!=s)
		{
			e[lst[now]].flow-=d;
			e[lst[now]^1].flow+=d;
			now=pre[now];
		}
	}
}
inline void init()
{
	memset(p,-1,sizeof(p));
}
inline int get(int i,int j){return (i-1)*n+j+n;}
int vis[105][105];
inline void input()
{
	n=gi();m=gi();
	s=0,t=n*(n+1)+1;tot=t;
	FOR(i,1,n)FOR(j,1,n)vis[i][j]=2;
	FOR(i,1,m)
	{
		int x=gi(),y=gi();
		vis[x][y]=1;
		vis[y][x]=0;
	}
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			int x=vis[i][j];
			if(i>=j)continue;
			ins(s,get(i,j),1,0);
			if(x==0||x==2)ins(get(i,j),j,1,0);
			if(x==1||x==2)ins(get(i,j),i,1,0);
		}
	}
	FOR(i,1,n)FOR(j,0,n)ins(i,t,1,j);
}
int a[105][105];
inline void solve()
{
	EK();
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			if(i<j)
			{
				for(int k=p[get(i,j)];k!=-1;k=e[k].nxt)
				{
					int v=e[k].v;
					if(e[k].flow==0)
					{
						if(v==j)a[i][j]=0,a[j][i]=1;
						else a[i][j]=1,a[j][i]=0;
					}
				}
			}
		}
	}
	FOR(i,1,n)
	{
		FOR(j,1,n)printf("%d",a[i][j]);
		puts("");
	}
}
int main()
{
//	int T=gi();
//	while(T--)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}