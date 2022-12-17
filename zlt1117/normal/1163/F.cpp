#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
//#define gc getchar()
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
const int maxn=2e5+5;
int n,m,q;
vector<pair<int,pair<int,int>>>e[maxn];
int pre[maxn],lst[maxn],id[maxn];
ll dis[2][maxn];
struct segmentree
{
	static const int maxn=8e5+5;
	#define ls u<<1
	#define rs u<<1|1
	ll minv[maxn];
	inline void init(){memset(minv,0x3f,sizeof(minv));}
	inline void update(int u,int l,int r,int x,int y,ll v)
	{
		if(x<=l&&y>=r)return minv[u]=min(minv[u],v),void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
	}
	inline ll query(int u,int l,int r,int x)
	{
		if(l==r)return minv[u];
		ll ret=minv[u];
		int mid=(l+r)>>1;
		if(x<=mid)ret=min(ret,query(ls,l,mid,x));
		else ret=min(ret,query(rs,mid+1,r,x));
		return ret;
	}
}tree;
int w[maxn],u[maxn],v[maxn];
inline void input()
{
	n=gi(),m=gi(),q=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({i,{v,w}}),e[v].pb({i,{u,w}});
		::w[i]=w;::u[i]=u,::v[i]=v;
	}
}
struct node{int u;ll dis;inline bool operator < (const node &b)const{return dis>b.dis;}};
bool vis[maxn];
inline void dijkstra(int u,ll *dis,int *now,int typ)
{
	FOR(i,1,n)dis[i]=1e18,now[i]=typ==0?0:1e9,lst[i]=pre[i]=0;
	memset(vis,0,sizeof(vis));
	dis[u]=0;priority_queue<node>pq;
	pq.push({u,0});
	while(!pq.empty())
	{
		int u=pq.top().u;pq.pop();
		if(id[u])now[u]=id[u];
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:e[u])
		{
			int id=x.first,v=x.second.first,w=x.second.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				lst[v]=id;pre[v]=u;
				pq.push({v,dis[v]});
				if(typ==0)now[v]=now[u];
				else now[v]=now[u];
			} 
		}
	}
}
int L[maxn],R[maxn];
int vist[maxn];
inline void solve()
{
	tree.init();
	dijkstra(n,dis[1],R,0);
	dijkstra(1,dis[0],L,1);
	memset(vis,0,sizeof(vis));
	int now=n;
	vector<int>v;v.pb(now);
	vector<int>edges;
	while(now!=1)
	{
		edges.pb(lst[now]);
		now=pre[now];
		v.pb(now);
	}
	reverse(v.begin(),v.end());
	reverse(edges.begin(),edges.end());
	FOR(i,0,sz(v)-1)id[v[i]]=i+1;
	FOR(i,0,sz(edges)-1)vist[edges[i]]=i+1;
	dijkstra(n,dis[1],R,1);
	dijkstra(1,dis[0],L,0);
	FOR(i,1,n)
	{
		for(auto x:e[i])
		{
			int u=i,v=x.second.first,w=x.second.second;
			if(vist[x.first])continue;
		//	printf("%d %d %d %d\n",L[u],R[v],L[v],R[u]);
			if(L[u]<R[v])tree.update(1,1,m+1,L[u],R[v]-1,dis[0][u]+dis[1][v]+w);
			if(L[v]<R[u])tree.update(1,1,m+1,L[v],R[u]-1,dis[0][v]+dis[1][u]+w);
		}
	}
	while(q--)
	{
		int i=gi(),x=gi();
		int u=::u[i],v=::v[i];
		if(!vist[i])
		{
			ll ans=min(dis[0][u]+dis[1][v]+x,dis[0][v]+dis[1][u]+x);
			ans=min(ans,dis[0][n]); 
			printf("%lld\n",ans);
		}
		if(vist[i])
		{
			if(x<w[i])printf("%lld\n",dis[0][n]-w[i]+x);
			else 
			{
				ll ans=dis[0][n]-w[i]+x;
				ans=min(ans,tree.query(1,1,m+1,vist[i]));
				printf("%lld\n",ans);
			}
		}
	}
}
int main()
{
	input();
	solve();
	return 0;
}