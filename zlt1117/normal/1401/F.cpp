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
const int maxn=(1<<20)+5;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
bool rev[maxn];
int a[maxn],n,q,x,k,l,r;
struct segmentree
{
	ll sum[maxn];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushup(int u){sum[u]=sum[ls]+sum[rs];}
	inline void build(int u,int l,int r)
	{
		if(l==r)sum[u]=a[l];
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pushup(u);
		}
	}
	inline void update(int u,int l,int r,int x,int v,int dep)
	{
		if(l==r)sum[u]=v;
		else
		{
			int mid=(l+r)>>1;
			if(rev[dep])
			{
				int len=r-x;
				x=l+len;
			}
			if(x<=mid)update(ls,l,mid,x,v,dep-1);
			else update(rs,mid+1,r,x,v,dep-1);
			pushup(u);
		}
	}
	inline ll query(int u,int l,int r,int x,int y,int dep)
	{
		if(x<=l&&y>=r)return sum[u];
		else
		{
			int mid=(l+r)>>1;
			ll ret=0;
			if(rev[dep])
			{
				int len=r-x;
				x=l+len;
				len=r-y;
				y=l+len;
				swap(x,y);
			}
			if(x<=mid)ret+=query(ls,l,mid,x,y,dep-1);
			if(y>mid)ret+=query(rs,mid+1,r,x,y,dep-1);
			return ret;
		}
	}
}tree;
int main()
{
	n=getint(),q=getint();
	FOR(i,1,(1<<n))a[i]=getint();
	tree.build(1,1,(1<<n));
	while(q--)
	{
		int opt=getint();
		if(opt==1)
		{
			x=getint(),k=getint();
			tree.update(1,1,(1<<n),x,k,n);
		}
		else if(opt==2)
		{
			k=getint();
			rev[k]^=1;
		}
		else if(opt==3)
		{
			k=getint();
			rev[k]^=1;
			rev[k+1]^=1;
		}
		else
		{
			l=getint(),r=getint();
			printf("%lld\n",tree.query(1,1,(1<<n),l,r,n));
		}
	}
	return 0;
}///