#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3e5+5;
int rt[maxn],n,q,a[maxn];
struct segmentree
{
	static const int maxn=6e6+5;
	int ls[maxn],rs[maxn],tot,sum[maxn];
	inline void pushup(int u){sum[u]=sum[ls[u]]+sum[rs[u]];}
	inline void update(int &u,int pre,int l,int r,int x,int v)
	{
		u=++tot;
		if(l==r)return sum[u]+=v,void();
		int mid=(l+r)>>1;
		ls[u]=ls[pre],rs[u]=rs[pre];
		if(x<=mid)update(ls[u],ls[pre],l,mid,x,v);
		else update(rs[u],rs[pre],mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1;
		int ret=0;
		if(x<=mid)ret+=query(ls[u],l,mid,x,y);
		if(y>mid)ret+=query(rs[u],mid+1,r,x,y);
		return ret;
	}
}tree;
struct segmentree2
{
	#define ls u<<1
	#define rs u<<1|1
	int minv[maxn<<2],tag[maxn<<2];
	inline void pushdown(int u)
	{
		if(tag[u]!=0)
		{
			tag[ls]+=tag[u];
			tag[rs]+=tag[u];
			minv[ls]+=tag[u];
			minv[rs]+=tag[u];
			tag[u]=0;
		}
	}
	inline void pushup(int u)
	{
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			minv[u]+=v;
			tag[u]+=v;
		}
		else
		{
			pushdown(u);
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,y,v);
			if(y>mid)update(rs,mid+1,r,x,y,v);
			pushup(u);
		}
	}
	inline int query()
	{
		int u=1,l=1,r=n;
		while(l!=r)
		{
			pushdown(u);
			int mid=(l+r)>>1;
			if(minv[rs]==0)u=rs,l=mid+1;
			else u=ls,r=mid;	
		}	
		return l;
	}	
	inline void bianli(int u,int l,int r)
	{
		if(l==r)cerr<<minv[u]<<' ';
		else 
		{
			pushdown(u);
			int mid=(l+r)>>1;
			bianli(ls,l,mid);
			bianli(rs,mid+1,r);
		}
	}
}tree2;
int main()
{
	n=getint(),q=getint();
	FOR(i,1,n)
	{
		a[i]=getint();
		if(a[i]>i)tree2.update(1,1,n,i,i,n+1);
		else tree2.update(1,1,n,i,i,i-a[i]);
	//	tree2.bianli(1,1,n);cerr<<endl;
	}
	for(int i=n;i>=1;--i)
	{
		int temp=0;
		rt[i]=rt[i+1];
		while(tree2.minv[1]==0)
		{
			temp++;
			int x=tree2.query();
			if(x<i)break;
			else tree.update(rt[i],rt[i],1,n,x,1);
			tree2.update(1,1,n,x,x,n+1);
			if(x!=n)tree2.update(1,1,n,x+1,n,-1);
			//tree2.bianli(1,1,n);cerr<<endl;
		}
	}
	while(q--)
	{
		int a=getint(),b=getint();
		printf("%d\n",tree.query(rt[a+1],1,n,1,n-b));
	}
	return 0;
}
///