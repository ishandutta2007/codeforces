#include<stdio.h>
using namespace std;
int a[400005];
struct node
{
	int val,xx;
}gt[400005];
int i,j,k,l,s,m,n,x,y,ss,aa;
inline int gcd(int o,int p)
{
	if (o%p==0)
	return p;
	return gcd(p,o%p);
}
inline void up(int o)
{
	gt[o].val=gcd(gt[o*2].val,gt[o*2+1].val);
	if (gt[o].val==gt[o*2].val)
	gt[o].xx+=gt[o*2].xx;
	if (gt[o].val==gt[o*2+1].val)
	gt[o].xx+=gt[o*2+1].xx;
}
inline void build(int o,int l,int r)
{
	if (l==r)
	{
		gt[o].val=a[l];
		gt[o].xx=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	up(o);
}
inline void ask(int o,int l,int r,int ll,int rr)
{
	if (l==ll&&r==rr)
	{
		int last=aa;
		if (aa==-1)
		aa=gt[o].val;
		else
		aa=gcd(aa,gt[o].val);
		if (aa!=last)
		ss=0;
		if (aa==gt[o].val)
		ss+=gt[o].xx;
		return ;
	}
	int mid=(l+r)>>1;
	if (mid>=rr)
	ask(o*2,l,mid,ll,rr);
	else
	if (mid<ll)
	ask(o*2+1,mid+1,r,ll,rr);
	else
	{
		ask(o*2,l,mid,ll,mid);
		ask(o*2+1,mid+1,r,mid+1,rr);
	}
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	build(1,1,n);
	for (i=1;i<=m;i++)
	{
		aa=-1;
		ss=0;
		scanf("%d%d",&x,&y);
		ask(1,1,n,x,y);
		printf("%d\n",y-x+1-ss);
	}
}