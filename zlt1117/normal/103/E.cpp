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
const int inf=1e9;
struct edge
{
	int v,w,nxt;
	edge(int vv=0,int ww=0,int nn=0){v=vv,w=ww,nxt=nn;}
};
struct Dinic
{
	static const int maxn=100005,maxm=400000+5;
	edge e[maxm<<1];
	int p[maxn],tot,s,t,sz;
	int dis[maxn],q[maxn],hd,tl,cur[maxn];
	Dinic(){memset(p,-1,sizeof(p));sz=-1;} 
	inline void clear()
	{
		FOR(i,0,tot)p[i]=-1;
		sz=-1;
	}
	inline void ins(int u,int v,int w)
	{
		e[++sz]=edge(v,w,p[u]);
		p[u]=sz;
	}
	inline void add(int u,int v,int w)
	{
		ins(u,v,w);
		ins(v,u,0);
	}
	inline bool bfs()
	{
		q[hd=tl=0]=s;
		FOR(i,0,tot)cur[i]=p[i],dis[i]=-1;
		dis[s]=0;
		while(hd<=tl)
		{
			int u=q[hd++];
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(dis[v]==-1&&e[i].w)
				{
					dis[v]=dis[u]+1;
					if(v==t)return true;
					q[++tl]=v;
				}
			}
		}
		return dis[t]!=-1;
	}
	inline int dfs(int u,int flow)
	{
		if(u==t)return flow;
		int ret=0;
		for(int &i=cur[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]==dis[u]+1&&e[i].w)
			{
				ll val=dfs(v,min(flow,e[i].w));
				if(val==0)dis[v]=-1;
				else
				{
					ret+=val,e[i].w-=val,e[i^1].w+=val,flow-=val;
					if(flow==0)break;
				}
			}
		}
		return ret;
	}
	inline ll dinic()
	{
		ll sum=0;
		while(bfs())
		sum+=dfs(s,inf);
		return sum;
	}
}G;
const int maxn=305;
int n,a[maxn];
inline void init()
{

}
int s,t;
ll ans;
inline void input()
{
	n=gi();
	G.s=s=0,G.t=t=G.tot=n+n+1;
	FOR(i,1,n)
	{
		int x=gi();
		FOR(j,1,x)
		{
			int v=gi();
			G.add(i,v+n,inf);
		}
	}
	FOR(i,1,n)G.add(i+n,t,inf);
	FOR(i,1,n)
	{
		a[i]=gi();a[i]=-a[i];
		ans+=a[i]+inf;
		G.add(s,i,inf+a[i]);
	}
}
inline void solve()
{
	ans-=G.dinic();
	printf("%lld\n",-ans);
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