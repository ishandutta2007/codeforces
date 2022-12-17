#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#define PII pair<int,int>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define gc getchar()
using namespace std;
const int maxn=1e5+5,maxm=2e6+5;
inline int getint()
{
	char ch=gc;int x=0,f=1;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
int sz,p[maxn*10];///!!!
struct edge
{
	int v,w,nxt;
	edge(int vv=0,int ww=0,int nn=0){v=vv,nxt=nn,w=ww;}
}e[maxm<<1];
inline void add(int u,int v,int w)
{
	e[++sz]=edge(v,w,p[u]);
	p[u]=sz;
}
struct node
{
	int u;ll dis;
	inline bool operator<(const node &b)const{return dis>b.dis;}
};
ll dis[maxn*10];///!!!
bool vis[maxn*10];
int tot,n,q,s;
struct segmentree
{
	static const int maxn=4e5+5;
	#define ls u<<1
	#define rs u<<1|1
	int ind[maxn],oud[maxn];
	inline void build(int u,int l,int r)
	{
		ind[u]=++tot,oud[u]=++tot;///ind oud 
		if(l==r){add(ind[u],l,0),add(l,oud[u],0);return ;}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		add(ind[u],ind[ls],0);
		add(ind[u],ind[rs],0);
		add(oud[ls],oud[u],0);
		add(oud[rs],oud[u],0);
	}
	inline void query1(int u,int l,int r,int x,int y,vector<int>&v)
	{
		if(x<=l&&y>=r)return v.push_back(ind[u]),void();
		int mid=(l+r)>>1;
		if(x<=mid)query1(ls,l,mid,x,y,v);
		if(y>mid)query1(rs,mid+1,r,x,y,v);
	}
	inline void query2(int u,int l,int r,int x,int y,vector<int>&v)
	{
		if(x<=l&&y>=r)return v.push_back(oud[u]),void();
		int mid=(l+r)>>1;
		if(x<=mid)query2(ls,l,mid,x,y,v);
		if(y>mid)query2(rs,mid+1,r,x,y,v);
	}
}tree;
inline void dijkstra()
{
	priority_queue<node>pq;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	node x;x.u=s,x.dis=0;
	pq.push(x);
	while(!pq.empty())
	{
		x=pq.top();
		pq.pop();
		if(vis[x.u])continue;
		vis[x.u]=1;
		REP(x.u)
		{
			int v=e[i].v;
			if(dis[v]>dis[x.u]+e[i].w)
			{
				dis[v]=dis[x.u]+e[i].w;
				node xx;
				xx.u=v,xx.dis=dis[v];
				pq.push(xx);
			}
		}
	}
}
int main()
{
//	freopen("running.in","r",stdin);
//	freopen("running.out","w",stdout);
	memset(p,-1,sizeof(p));
	n=getint(),q=getint(),s=getint();
	tot=n;
	tree.build(1,1,n);
	FOR(i,1,q)
	{
		int typ=getint(),v=getint();
		if(typ==1)
		{
			int u=getint(),w=getint();
			add(v,u,w);
		}
		else if(typ==2)
		{
			int l=getint(),r=getint(),w=getint();
			vector<int>vv;
			vv.clear();
			tree.query1(1,1,n,l,r,vv);
			FOR(i,0,(int)(vv.size())-1)
			{
				int bh=vv[i];
				add(v,bh,w);
			}
		}
		else
		{
			int l=getint(),r=getint(),w=getint();
			vector<int>vv;
			vv.clear();
			tree.query2(1,1,n,l,r,vv);
			FOR(i,0,(int)(vv.size())-1)
			{
				int bh=vv[i];
				add(bh,v,w);
			}
		}
	}
	dijkstra();
	FOR(i,1,n)printf("%lld ",dis[i]==inf?-1:dis[i]);
	return 0;	
}