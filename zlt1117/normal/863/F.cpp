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
const ll inf=1e18;
const int INF=1e9;
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
		FOR(i,0,tot)dis[i]=inf,in[i]=0;
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
int n,q;
bool vis[maxn][maxn];
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,q)
	{
		int t=gi(),l=gi(),r=gi(),v=gi();
		if(t==1)FOR(j,l,r)FOR(k,1,v-1)vis[j][k]=1;
		else FOR(j,l,r)FOR(k,v+1,n)vis[j][k]=1;
	}
}
int s,t;
inline void solve()
{
	s=0,G.tot=t=2*n+1;
	FOR(i,1,n)G.add(s,i,1,0);
	FOR(i,1,n)
	{
		int cnt=0;
		FOR(j,1,n)
		{
			if(vis[i][j])continue;
			cnt++;
			G.add(i,j+n,1,0);
		}
		FOR(j,1,n)G.add(i+n,t,1,2*j-1);
		if(!cnt)return puts("-1"),void();
	}
	printf("%lld\n",G.EK(s,t).second);
}
int main()
{
	input();
	solve();
	return 0;
}