#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
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
const ll inf=1e12,INF=1e18;
struct edge
{
	int v,nxt;ll w;
	edge(int vv=0,ll ww=0,int nn=0){v=vv,w=ww,nxt=nn;}
};
struct Dinic
{
	static const int maxn=20005,maxm=2e6+5;
	edge e[maxm<<1];
	int p[maxn],tot,sz;
	int dis[maxn],q[maxn],hd,tl,cur[maxn];
	Dinic(){memset(p,-1,sizeof(p));sz=-1;} 
	inline void clear()
	{
		FOR(i,0,tot)p[i]=-1;
		sz=-1;tot=0;
	}
	inline void ins(int u,int v,ll w)
	{
		e[++sz]=edge(v,w,p[u]);
		p[u]=sz;
	}
	inline void add(int u,int v,ll w)
	{
		ins(u,v,w);
		ins(v,u,0);
	}
	inline bool bfs(int s,int t)
	{
		FOR(i,0,tot)dis[i]=-1,cur[i]=p[i];
		q[hd=tl=0]=s;dis[s]=0;
		while(hd<=tl)
		{
			int u=q[hd++];
			for(int i=p[u];i!=-1;i=e[i].nxt)
			{
				int v=e[i].v;
				if(e[i].w&&dis[v]==-1)
				{
					dis[v]=dis[u]+1;
					q[++tl]=v;
					if(v==t)return true;
				}
			}
		}
		return false;
	}
	inline ll dfs(int u,int t,ll flow)
	{
		if(u==t)return flow;
		ll ret=0;
		for(int &i=cur[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w&&dis[v]==dis[u]+1)
			{
				int val=dfs(v,t,min(flow,e[i].w));
				if(val==0)dis[v]=-1;
				else
				{
					ret+=val,e[i].w-=val,e[i^1].w+=val;
					flow-=val;
					if(flow==0)break;
				}
			}
		}
		return ret;
	}
	inline ll dinic(int s,int t)
	{
		ll ans=0;
		while(bfs(s,t))ans+=dfs(s,t,inf);
		return ans;
	}
}G;
const int maxn=1005;
int n,m;
ull c[maxn];
int v[maxn],a[maxn],b[maxn],M;
int s,t;
bool can[maxn][maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)v[i]=gi();
	M=1e9+1;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		can[u][v]=1;
	}
}
bool vis[maxn];
int ele[maxn],id[maxn],ans[maxn],bian[maxn];
int templ[maxn],tempr[maxn],lct,rct;
inline void Divide(int l,int r,int L,int R)
{
	if(l>r||L>R)return ;
	int mid=(L+R)>>1;
	G.clear();
	FOR(i,l,r)id[i]=i-l+2;
	s=0,t=1,G.tot=id[r];
	FOR(i,l,r)
	{
		ll val=abs(mid+1-v[ele[i]])-abs(mid-v[ele[i]]);
		val=-val;
		if(val>0)G.add(s,id[i],val);
		else G.add(id[i],t,-val);
	}
	FOR(i,l,r)FOR(j,l,r)if(can[ele[i]][ele[j]])G.add(id[i],id[j],INF);
	G.dinic(s,t);
	lct=rct=0;
	FOR(i,l,r)
	{
		if(G.dis[id[i]]!=-1)tempr[++rct]=ele[i];
		else templ[++lct]=ele[i],ans[ele[i]]=mid;
	}
	int cnt=l-1,t=lct;
	FOR(i,1,lct)ele[++cnt]=templ[i];
	FOR(i,1,rct)ele[++cnt]=tempr[i];
	Divide(l,l+t-1,L,mid-1);
	Divide(l+t,r,mid+1,R);
}
inline void solve()
{
	iota(ele+1,ele+n+1,1);
	FOR(i,1,n)M=max(M,v[i]);
	FOR(i,1,n)ans[i]=0;
	Divide(1,n,0,M);
	FOR(i,1,n)printf("%d ",ans[i]);
	puts("");
}
int main()
{
//	freopen("shop.in","r",stdin);
//	freopen("shop.out","w",stdout);
	input();
	solve();
	return 0;
}