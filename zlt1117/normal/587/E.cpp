#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
struct xxj
{
	static const int maxm=31;
	int a[32];
	inline void clear()
	{
		memset(a,0,sizeof(a));
	}
	inline void insert(int x)
	{
		for(int i=maxm;i>=0;--i)
		{
			if(x&(1<<i))
			{
				if(a[i])x^=a[i];
				else
				{
					a[i]=x;
					return ;
				}
			}
		}
	}
	inline void merge(xxj b)
	{
		for(int i=maxm;i>=0;--i)
		{
			if(b.a[i])insert(b.a[i]);
		}
	}
	inline int query()
	{
		int cnt=0;
		for(int i=maxm;i>=0;--i)if(a[i])cnt++;
		return (1<<cnt);
	}
};
int a[maxn];
int b[maxn],n,m,opt,x,y;
namespace A
{
	struct segmentree
	{
		#define ls u<<1
		#define rs u<<1|1
		int sum[maxn<<2],tag[maxn<<2];
		inline void pushdown(int u)
		{
			if(tag[u]==0)return ;
			tag[ls]^=tag[u];
			tag[rs]^=tag[u];
			sum[ls]^=tag[u];
			sum[rs]^=tag[u];
			tag[u]=0;
		}
		inline void build(int u,int l,int r)
		{
			if(l==r)
			{
				sum[u]=a[l];
			}
			else
			{
				int mid=(l+r)>>1;
				build(ls,l,mid);
				build(rs,mid+1,r);
			}
		}
		inline void update(int u,int l,int r,int x,int y,int v)
		{
			if(x<=l&&y>=r)
			{
				tag[u]^=v;
				sum[u]^=v;
			}
			else
			{
				int mid=(l+r)>>1;
				pushdown(u);
				if(x<=mid)update(ls,l,mid,x,y,v);
				if(y>mid)update(rs,mid+1,r,x,y,v);
			}
		}
		inline int query(int u,int l,int r,int x)
		{
			if(l==r)return sum[u];
			else
			{
				pushdown(u);
				int mid=(l+r)>>1;
				if(x<=mid)return query(ls,l,mid,x);
				else return query(rs,mid+1,r,x);
			}
		}
	}tree;
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	xxj a[maxn<<2];
	inline void pushup(int u)
	{
		a[u].clear();///!!!
		a[u].merge(a[ls]);
		a[u].merge(a[rs]);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)
		{
			a[u].insert(b[l]);
		}
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pushup(u);
		}
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)
		{
			a[u].clear();
			a[u].insert(v);
		}
		else
		{
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,v);
			else update(rs,mid+1,r,x,v);
			pushup(u);
		}
	}
	inline xxj query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)
		{
			return a[u];
		}
		else
		{
			xxj val;
			val.clear();
			int mid=(l+r)>>1;
			if(x<=mid)val.merge(query(ls,l,mid,x,y));
			if(y>mid)val.merge(query(rs,mid+1,r,x,y));
			return val;
		}
	}
}tree;
int main()
{
	n=getint(),m=getint();
	for(int i=1;i<=n;++i)a[i]=getint(),b[i]=a[i]^a[i-1];
	A::tree.build(1,1,n);
	tree.build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		opt=getint(),x=getint(),y=getint();
		if(opt==1)
		{
			int val=getint();
			A::tree.update(1,1,n,x,y,val);
			if(y!=n)tree.update(1,1,n,y+1,b[y+1]^=val);
			tree.update(1,1,n,x,b[x]^=val);
		}
		else
		{
			xxj now;
			now.clear();
			now.insert(A::tree.query(1,1,n,x));
			if(x!=y)now.merge(tree.query(1,1,n,x+1,y));///b[x+1]==b[y]
			printf("%d\n",now.query());
		}
	}
	return 0;
}