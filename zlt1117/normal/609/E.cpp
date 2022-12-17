#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=4e5+5;
int fa[maxn],n,m,f[maxn],val[maxn];
ll ans[maxn];
ll sum;
struct edge
{
	int u,v,w,bh;
	inline bool operator<(const edge&rhs)const
	{
		return w<rhs.w;
	}
}e[maxn];
namespace LCT
{
	struct lct
	{
		int son[maxn][2],maxv[maxn];
		bool rev[maxn];
		inline void pushdown(int u)
		{
			if(rev[u])
			{
				rev[son[u][1]]^=1;
				rev[son[u][0]]^=1;
				swap(son[u][0],son[u][1]);
				rev[u]=0;
			}
		}
		inline void pushup(int u)
		{
			maxv[u]=max(val[u],max(maxv[son[u][0]],maxv[son[u][1]]));
		}
		inline bool nroot(int x)
		{
			return son[fa[x]][0]==x||son[fa[x]][1]==x;
		}
		inline void rotate(int x)
		{
			int y=fa[x],z=fa[y],k=son[y][1]==x;
			if(nroot(y))son[z][son[z][1]==y]=x;
			fa[x]=z;
			son[y][k]=son[x][k^1];
			fa[son[x][k^1]]=y;
			son[x][k^1]=y;
			fa[y]=x;
			pushup(y);
			pushup(x);
		}
		inline void pushall(int x)
		{
			if(nroot(x))pushall(fa[x]);
			pushdown(x);
		}
		inline void splay(int x)
		{
			pushall(x);
			while(nroot(x))
			{
				int y=fa[x],z=fa[y];
				if(nroot(y))
				{
					if((son[z][1]==y)^(son[y][1]==x))rotate(x);
					else rotate(y);
				}
				rotate(x);
			}
		}
		inline void access(int x)
		{
			for(int y=0;x;y=x,x=fa[x])
			{
				splay(x);
				son[x][1]=y;
				pushup(x);
			}
		}
		inline void makeroot(int x)
		{
			access(x);
			splay(x);
			rev[x]^=1;
		}
		inline int findroot(int x)
		{
			access(x);
			splay(x);
			pushdown(x);
			while(son[x][0])
			{
				x=son[x][0];
				pushdown(x);
			}
			splay(x);
			return x;
		}
		inline void link(int x,int y)
		{
			makeroot(x);
			if(findroot(y)!=x)
			{
				fa[x]=y;
			}
		}
		inline void split(int x,int y)
		{
			makeroot(x);
			access(y);
			splay(y);
		}
		inline int query(int x,int y)
		{
			split(x,y);
			return maxv[y];
		}
	}lct;
	inline void work()
	{
		for(int i=1;i<=m;++i)
		{
			ans[e[i].bh]=sum+e[i].w-lct.query(e[i].u,e[i].v);
		}
		for(int i=1;i<=m;++i)
		{
			printf("%lld\n",ans[i]);
		}
	}
}
namespace MST
{
	inline int get(int x)
	{
		if(x==f[x])return x;
		else return f[x]=get(f[x]);
	}
	inline void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)f[i]=i;
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			e[i].bh=i;
			val[i+n]=e[i].w;
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=m;++i)
		{
			int fu=get(e[i].u),fv=get(e[i].v);
			if(fu==fv)continue;
			else
			{
				f[fu]=fv;
				LCT::lct.link(e[i].u,e[i].bh+n);
				LCT::lct.link(e[i].v,e[i].bh+n);
				sum+=e[i].w;
			}
		}
	}
}
int main()
{
	MST::work();
	LCT::work();
}