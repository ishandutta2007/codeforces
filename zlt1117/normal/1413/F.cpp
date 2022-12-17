#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=5e5+5;
int n,p[maxn],sz,maxpos,maxdis,fa[maxn],Q;
struct node 
{
	int u,v,w;
};
vector<node>edg;
struct edge
{
	int v,w,nxt;
	edge(int vv=0,int ww=0,int nn=0){v=vv,w=ww,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v,int w)
{
	e[++sz]=edge(v,w,p[u]);
	p[u]=sz;
}
struct segmentree
{
	static const int maxn=2e6+5;
	int rt;///the starting node
	#define ls u<<1
	#define rs u<<1|1
	int dep[maxn],tot,dfn[maxn],siz[maxn],len[maxn],rk[maxn];
	bool tag[maxn];
	int maxv[maxn][2];///0 is the even,1 is the odd
	inline void pushup(int u)
	{
		FOR(i,0,1)
		{
			if(maxv[ls][i]>maxv[rs][i])maxv[u][i]=maxv[ls][i];
			else maxv[u][i]=maxv[rs][i];
		}
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			swap(maxv[ls][0],maxv[ls][1]);
			swap(maxv[rs][0],maxv[rs][1]);
			tag[ls]^=1,tag[rs]^=1,tag[u]=0;
		}
	}
	inline void dfs(int u,int fa)
	{
		dfn[u]=++tot;
		siz[u]=1;
		rk[tot]=u;
		REP(u)
		{
			int v=e[i].v;
			if(v==fa)continue;
			if(e[i].w==1)len[v]=len[u]^1;
			else len[v]=len[u];///!!!
			dep[v]=dep[u]+1;
			dfs(v,u);
			siz[u]+=siz[v];
		}
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)
		{
			maxv[u][len[rk[l]]]=dep[rk[l]];
			return ;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return maxv[u][0];
		int mid=(l+r)>>1,ret=0;
		pushdown(u);
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=max(ret,query(rs,mid+1,r,x,y));
	}
	inline void update(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)
		{
			tag[u]^=1;
			swap(maxv[u][0],maxv[u][1]);
			return ;
		}
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls,l,mid,x,y);
		if(y>mid)update(rs,mid+1,r,x,y);
		pushup(u);
	}
	inline void change(int u,int v)
	{
		if(dep[u]>dep[v])swap(u,v);
		update(1,1,n,dfn[v],dfn[v]+siz[v]-1);
	}
}tree1,tree2;
inline void dfs2(int u,int f,int dis)
{
	if(dis>maxdis){maxpos=u,maxdis=dis;}
	REP(u)
	{
		int v=e[i].v;
		if(v==f)continue;
		dfs2(v,u,dis+1);
	}
}
inline void init()
{
	dfs2(1,0,0);
	tree1.rt=maxpos;
	maxdis=0;
	dfs2(maxpos,0,0);
	tree2.rt=maxpos;
	tree1.dfs(tree1.rt,0);
	tree2.dfs(tree2.rt,0);
	tree1.build(1,1,n);
	tree2.build(1,1,n);
}
inline void input()
{
	memset(p,-1,sizeof(p));
	n=gi();
	node x;
	edg.push_back(x);
	FOR(i,1,n-1)
	{
		x.u=gi(),x.v=gi(),x.w=gi();
		edg.push_back(x);
		add(x.u,x.v,x.w);add(x.v,x.u,x.w);
	}
}
inline void solve()
{
	Q=gi();
	while(Q--)
	{
		int x=gi();
		int u=edg[x].u,v=edg[x].v;
		tree1.change(u,v);
		tree2.change(u,v);
		printf("%d\n",max(tree1.query(1,1,n,1,n),tree2.query(1,1,n,1,n)));
	}
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	input();
	init();
	solve();
	return 0;
}///