#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+5,maxm=21*maxn;
int n,pos[maxn],a[maxn],b[maxn],rt[maxn],m,l,r,x,y,ans;
struct segmentree
{
	int tot,ls[maxm],rs[maxm],sum[maxm];
	inline void pushup(int u)
	{
		sum[u]=sum[ls[u]]+sum[rs[u]];
	}
	inline void update(int &u,int pre,int l,int r,int x)
	{
		u=++tot;
		if(l==r)
		{
			sum[u]++;
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			ls[u]=ls[pre],rs[u]=rs[pre];
			if(x<=mid)update(ls[u],ls[pre],l,mid,x);
			else update(rs[u],rs[pre],mid+1,r,x);
			pushup(u);
		}
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		else
		{
			int val=0;
			int mid=(l+r)>>1;
			if(x<=mid)val+=query(ls[u],l,mid,x,y);
			if(y>mid)val+=query(rs[u],mid+1,r,x,y);
			return val;
		}
	}
}tree;
inline int read()
{
	int x;
	scanf("%d",&x);
	return (x-1+ans)%n+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int temp;
		scanf("%d",&temp);
		a[temp]=i;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		pos[i]=a[b[i]];
	}
	for(int i=1;i<=n;++i)
	{
		tree.update(rt[i],rt[i-1],1,n,pos[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		l=read(),r=read(),x=read(),y=read();
		if(l>r)swap(l,r);
		if(x>y)swap(x,y);
		ans=tree.query(rt[y],1,n,l,r);
		ans-=tree.query(rt[x-1],1,n,l,r);
		printf("%d\n",ans);
		ans++;
	}
	return 0;
}