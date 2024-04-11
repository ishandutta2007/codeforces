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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3005;
int n,k1,k2,a[maxn],b[maxn];
struct MCMF
{
	static const int maxm=2e5+5;
	int p[maxn],s,t,tot,sz=-1;
	struct edge
	{
		int v,nxt,cost,flow;
		edge(int vv=0,int nn=0,int cc=0,int ff=0){v=vv,nxt=nn,cost=cc,flow=ff;}
	}e[maxm<<1];
	inline void add(int u,int v,int flow,int cost)
	{
		e[++sz]=edge(v,p[u],cost,flow);
		p[u]=sz;
	}
	inline void init()
	{
		memset(p,-1,sizeof(p));
	}
	inline void ins(int u,int v,int flow,int cost)
	{
		add(u,v,flow,cost);
		add(v,u,0,-cost);
	}
	int pre[maxn],lst[maxn],dis[maxn],flow[maxn];
	bool in[maxn];
	inline bool spfa()
	{
		queue<int>q; 
		q.push(s);
		memset(in,0,sizeof(bool)*(tot+1));
		memset(dis,0xcf,sizeof(int)*(tot+1));
		pre[t]=-1;
		q.push(s);in[s]=1,dis[s]=0;
		flow[s]=1e9;
		while(!q.empty())
		{
			int u=q.front();q.pop();in[u]=0;
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(dis[v]<dis[u]+e[i].cost&&e[i].flow)
				{
					dis[v]=dis[u]+e[i].cost;
					if(!in[v])q.push(v);
					pre[v]=u,lst[v]=i;
					flow[v]=min(e[i].flow,flow[u]);
				} 
			}
		}
		return pre[t]!=-1;
	}
	inline int EK()
	{
		int ans=0,flowf=0;
		while(spfa())
		{
			ans+=dis[t]*flow[t];flowf+=flow[t];
			int now=t;
			while(now!=s)
			{
				e[lst[now]].flow-=flow[t];
				e[lst[now]^1].flow+=flow[t];
				now=pre[now];
			}
		}
		return ans;
	}
}G;
inline void input()
{
	n=gi(),k1=gi(),k2=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)b[i]=gi();
}
inline void solve()
{
	G.init();
	G.s=0,G.tot=G.t=n+3;
	FOR(i,1,n)G.ins(G.s,i,1,0);
	FOR(i,1,n)G.ins(i,n+1,1,a[i]);
	FOR(i,1,n)G.ins(i,n+2,1,b[i]);
	G.ins(n+1,G.t,k1,0),G.ins(n+2,G.t,k2,0);
	printf("%d\n",G.EK());
	vector<int>v1,v2;
	FOR(i,1,n)
	{
		for(int j=G.p[i];j!=-1;j=G.e[j].nxt)
		{
			int v=G.e[j].v;
			if(v==n+1&&G.e[j].flow==0)v1.pb(i);
			if(v==n+2&&G.e[j].flow==0)v2.pb(i);
		 } 
	}
	for(int x:v1)printf("%d ",x);puts("");
	for(int x:v2)printf("%d ",x);puts("");
}
int main()
{
	input();
	solve();
	return 0;
}