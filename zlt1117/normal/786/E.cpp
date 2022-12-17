#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc ((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++)
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=20005,inf=1e9;
int n,fa[maxn][20],m,id[maxn][20],Log[maxn],tot,dep[maxn];
vector<pair<int,int>>e[maxn];
///Dinic
namespace Dinic
{
	const int maxn=1e6+5;
	struct edge
	{
		int v,flow,nxt;
		edge(int vv=0,int ff=0,int nn=0){v=vv,flow=ff,nxt=nn;}
	}e[maxn<<1];
	int p[maxn],s,t,sz=-1,cur[maxn],dis[maxn],tot;
	inline void init(){memset(p,-1,sizeof(p));}
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
		FOR(i,0,tot)cur[i]=p[i],dis[i]=0;
		queue<int>q;q.push(s),dis[s]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(dis[v]==0&&e[i].flow)
				{
					dis[v]=dis[u]+1;
					q.push(v);
					if(v==t)return true;
				}
			}
		}
		return false;
	}
	inline int dfs(int u,int flow)
	{
		if(u==t)return flow;
		int ret=0;
		for(int &i=cur[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].flow&&dis[v]==dis[u]+1)
			{
				int now=dfs(v,min(flow,e[i].flow));
				if(now)
				{
					ret+=now;
					flow-=now;
					e[i].flow-=now;
					e[i^1].flow+=now;
					if(flow==0)break;
				}
				else dis[v]=-1;
			}
		}
		return ret;
	}
	inline int dinic()
	{
		int ans=0;
		while(bfs())
		ans+=dfs(s,inf);
		return ans;
	}
}
///Dinic
using Dinic::p;
using Dinic::ins;
inline void dfs(int u)
{
	dep[u]=dep[fa[u][0]]+1;
	FOR(i,1,Log[dep[u]-1])fa[u][i]=fa[fa[u][i-1]][i-1],id[u][i]=++tot;
	FOR(i,1,Log[dep[u]-1])ins(id[u][i],id[u][i-1],inf),ins(id[u][i],id[fa[u][i-1]][i-1],inf); 
	for(auto x:e[u])
	{
		int v=x.first,i=x.second;
		if(v==fa[u][0])continue;
		fa[v][0]=u,id[v][0]=++tot,dfs(v);
		ins(id[v][0],i+m,inf);
	}
}
inline void calc(int u,int v,int x)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=Log[dep[u]];i>=0;--i)
	{
		if(dep[fa[u][i]]>=dep[v])
		{
			ins(x,id[u][i],inf);
			u=fa[u][i];
		}
	}
	if(u==v)return ;
	for(int i=Log[dep[u]];i>=0;--i)
	{
		if(fa[u][i]!=fa[v][i])
		{
			ins(x,id[u][i],inf);
			ins(x,id[v][i],inf);
			u=fa[u][i],v=fa[v][i];
		}
	}
	ins(x,id[u][0],inf);
	ins(x,id[v][0],inf);
}
inline void input()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
	Dinic::init();
	n=gi(),m=gi();
	Dinic::s=0,Dinic::t=n+m,tot=n+m;
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb({v,i}),e[v].pb({u,i});
	}
	dfs(1);
}
inline void solve()
{
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		calc(u,v,i); 
	}
	Dinic::tot=tot;
	FOR(i,1,m)ins(Dinic::s,i,1);
	FOR(i,m+1,m+n-1)ins(i,Dinic::t,1);
	int ans=Dinic::dinic();
	vector<int>ansl,ansr;
	for(int i=p[Dinic::s];i!=-1;i=Dinic::e[i].nxt)if(!Dinic::dis[Dinic::e[i].v])ansl.pb(Dinic::e[i].v);
	for(int i=p[Dinic::t];i!=-1;i=Dinic::e[i].nxt)if(Dinic::dis[Dinic::e[i].v])ansr.pb(Dinic::e[i].v-m);
	printf("%d\n",ans);sort(ansl.begin(),ansl.end()),sort(ansr.begin(),ansr.end());
	printf("%d ",sz(ansl));for(int x:ansl)printf("%d ",x);puts(" ");
	printf("%d ",sz(ansr));for(int x:ansr)printf("%d ",x);puts(" ");
}
int main()
{
	input();
	solve();
	return 0;
}