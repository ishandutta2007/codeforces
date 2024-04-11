#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100005;
int p[maxn],n,sz,k,w;
int siz[maxn],root,maxv[maxn];
bool vis[maxn];
int dis[maxn],val[maxn];
long long ans=0;
struct edge
{
	int v,w,nxt;
	edge() {}
	edge(int vv,int ww,int nn)
	{
		v=vv,w=ww,nxt=nn;
	}
} e[maxn<<1];
struct array
{
	const int maxk=100005;
	int c[maxn];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	inline void add(int x,int v)
	{
		while(x<=k+1)
		{
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	inline int query(int x)
	{
		int val=0;
		while(x>0)
		{
			val+=c[x];
			x-=lowbit(x);
		}
		return val;
	}
	inline void init()
	{
		memset(c,0,sizeof(c));
	}
}tree;
struct node
{
	int dis,val;
	inline bool operator<(const node&rhs)const
	{
		return dis<rhs.dis;
	}
} now[maxn];
inline void add(int u,int v,int w)
{
	e[++sz]=edge(v,w,p[u]);
	p[u]=sz;
}
inline int max(int a,int b)
{
	return a<b?b:a;
}
inline void getrt(int u,int sum,int fa)
{
	siz[u]=1,maxv[u]=0;
	for(int i=p[u]; i!=-1; i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v])continue;
		else
		{
			getrt(v,sum,u);
			siz[u]+=siz[v];
			maxv[u]=max(maxv[u],siz[v]);
		}
	}
	maxv[u]=max(maxv[u],sum-siz[u]);
	if(maxv[u]<maxv[root])
	{
		root=u;
	}
}
inline void getdis(int u,int fa)
{
	now[++now[0].dis].dis=dis[u];
	now[now[0].dis].val=val[u];
	for(int i=p[u]; i!=-1; i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v])continue;
		else
		{
			dis[v]=dis[u]+e[i].w;
			val[v]=val[u]+1;
			getdis(v,u);
		}
	}
}
inline long long count(int u,int dist,int dep)/// 
{
	long long ret=0;
	dis[u]=dist;
	val[u]=dep;
	now[0].dis=0;
	getdis(u,u);
	sort(now+1,now+now[0].dis+1);
	int l=1,r=now[0].dis;
	tree.init();
	for(int i=l;i<=r;++i)
	{
		tree.add(now[i].val+1,1);
	}
	while(l<r)
	{
		if(now[l].dis+now[r].dis>w)
		{
			tree.add(now[r].val+1,-1);
			r--;
		}
		else
		{
			tree.add(now[l].val+1,-1);/// 
			if(now[l].val<=k)ret+=tree.query(k-now[l].val+1);
			l++;
		}
	}
	return ret;
}
inline void solve(int u)
{
	vis[u]=true;
	ans+=count(u,0,0);
	for(int i=p[u]; i!=-1; i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			ans-=count(e[i].v,e[i].w,1);
			root=0;
			getrt(v,siz[v],u);
			solve(root);
		}
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d%d%d",&n,&k,&w);
	for(int i=1; i<=n-1; ++i)
	{
		int u,v,ww;
		scanf("%d%d",&v,&ww);
		add(i+1,v,ww);
		add(v,i+1,ww);
	}
	root=0;
	maxv[0]=1000000;
	getrt(1,n,0);
	solve(root);
	printf("%lld\n",ans);
	return 0;
}