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
const int maxn=3005,inf=1e9;
int a[maxn],b[maxn],n;
int s,t;
struct Dinic
{
	static const int maxn=4e5+5,maxm=8e5+5,inf=1e9;
	int p[maxn],sz=-1,dis[maxn],cur[maxn],tot;
	struct edge
	{
		int v,flow,nxt;
		edge(int vv=0,int ff=0,int nn=0){v=vv,flow=ff,nxt=nn;}
	}e[maxm<<1];
	inline void add(int u,int v,int flow)
	{
		e[++sz]=edge(v,flow,p[u]);
		p[u]=sz;
	}
	inline void ins(int u,int v,int flow)
	{
		add(u,v,flow);
		add(v,u,0);
	}
	inline bool bfs()
	{
		FOR(i,0,tot)dis[i]=0,cur[i]=p[i];
		dis[s]=1;queue<int>q;q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(!dis[v]&&e[i].flow)
				{
					dis[v]=dis[u]+1;
					q.push(v);
					if(v==t)return 1;
				}
			}
		}
		return 0;
	}
	inline int dfs(int u,int flow)
	{
		if(u==t)return flow;
		int sum=0;
		for(int &i=cur[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].flow&&dis[v]==dis[u]+1)
			{
				int now=dfs(v,min(flow,e[i].flow));
				if(now)
				{
					sum+=now,e[i].flow-=now;
					flow-=now,e[i^1].flow+=now;
					if(flow==0)return sum;
				}
				else dis[v]=-1;
			}
		}
		return sum;
	}
	inline int dinic()
	{
		int ret=0;
		while(bfs())ret+=dfs(s,inf);
		return ret;
	}
	inline void clear()
	{
		memset(p,-1,sizeof(p));
		sz=-1;
	}
}G;
int now[maxn];
inline void init()
{
	G.clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)b[i]=gi();
	G.tot=n;
	FOR(i,1,100)now[i]=++G.tot;
}
inline void solve()
{
	FOR(i,1,n)
	{
		G.ins(i,now[a[i]],inf);
		FOR(j,1,100)
		{
			if(j%a[i]==0)
			{
				G.ins(++G.tot,now[j],inf);
				now[j]=G.tot;
				G.ins(now[j],i,inf);
			}
		}
	}
	t=++G.tot;
	int ans=0;
	FOR(i,1,n)
	{
		if(b[i]>0)ans+=b[i],G.ins(s,i,b[i]);
		else G.ins(i,t,-b[i]);
	}
	ans-=G.dinic();
	printf("%d\n",ans);
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