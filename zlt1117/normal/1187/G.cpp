#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const ll INF=1e18;
const int inf=1e9;
struct edge
{
	int v,w,cost,nxt;
	edge(int vv=0,int ww=0,int cc=0,int nn=0)
	{
		v=vv,w=ww,cost=cc,nxt=nn;
	}
};
struct MCMF
{
	static const int maxn=4e5+5,maxm=4e6+5;
	edge e[maxm];
	int s,t,p[maxn],sz,tot;
	int pre[maxn],lst[maxn],flow[maxn];
	bool in[maxn];
	ll dis[maxn];
	MCMF(){memset(p,-1,sizeof(p));sz=-1;}
	inline void ins(int u,int v,int w,int cost)
	{
		e[++sz]=edge(v,w,cost,p[u]);
		p[u]=sz;
	}
	inline void add(int u,int v,int w,int cost)
	{
		ins(u,v,w,cost);
		ins(v,u,0,-cost);
	}
	inline bool spfa(int s,int t)
	{
		FOR(i,0,tot)dis[i]=INF,in[i]=0;
		queue<int>q;q.push(s);in[s]=1;dis[s]=0;flow[s]=1e9,pre[t]=-1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();in[u]=0;
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(dis[v]>dis[u]+e[i].cost&&e[i].w)
				{
					dis[v]=dis[u]+e[i].cost;
					flow[v]=min(flow[u],e[i].w);
					pre[v]=u,lst[v]=i;
					if(!in[v])q.push(v),in[v]=1;
				}
			}
		}
		return pre[t]!=-1;
	}
	inline pair<int,ll> EK(int s,int t)
	{
		int maxflow=0;ll mincost=0;
		while(spfa(s,t))
		{
			maxflow+=flow[t];
			mincost+=flow[t]*dis[t];
			for(int u=t;u!=s;u=pre[u])
			{
				e[lst[u]].w-=flow[t];
				e[lst[u]^1].w+=flow[t];
			} 
		}
		return {maxflow,mincost};
	}
}G;
const int maxn=55;
vector<pair<int,int>>ed[maxn];
int n,m,s,t,k,c,d,cnt;
inline void input()
{
	n=gi(),m=gi(),k=gi(),c=gi(),d=gi();
	s=0,t=1,cnt=1;
	FOR(i,1,k)
	{
		int x=gi();
		G.add(s,x+1,1,0);
	}
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		ed[u].pb({v,i});
		ed[v].pb({u,i+m});
	}
	m*=2;
}
inline void solve()
{
	FOR(i,0,n+k)
	{
		FOR(j,1,n)
		{
			G.add(j+cnt,cnt+j+n+m+m,inf,0);
			for(auto x:ed[j])
			{
				int v=x.first,id=x.second;
				G.add(j+cnt,id+cnt+n,inf,0);
				G.add(id+cnt+n+m,v+cnt+n+m+m,inf,0);
			}
		}
		FOR(j,1,m)
		{
			FOR(p,1,k)
			{
				G.add(cnt+j+n,cnt+j+n+m,1,d*(2*p-1));
			}
		}
		G.add(cnt+1,t,inf,c*i);
		cnt+=n+m+m;
	}
	G.add(cnt+1,t,inf,c*(n+k+1));
	G.tot=cnt+n+m+m;
	printf("%lld\n",G.EK(s,t).second);
}
int main()
{
	input();
	solve();
	return 0;
}