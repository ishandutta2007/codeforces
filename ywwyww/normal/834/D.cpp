#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct p
{
	int l,r;
	int ls,rs;
	int t,s;
};
p a[1000010];
int cnt;
int rt;
void build(int &p,int l,int r)
{
	p=++cnt;
	a[p].l=l;
	a[p].r=r;
	a[p].ls=a[p].rs=a[p].t=a[p].s=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(a[p].ls,l,mid);
	build(a[p].rs,mid+1,r);
}
void addt(int p,int v)
{
	a[p].t+=v;
	a[p].s+=v;
}
void push(int p)
{
	if(a[p].t&&a[p].l!=a[p].r)
	{
		addt(a[p].ls,a[p].t);
		addt(a[p].rs,a[p].t);
		a[p].t=0;
	}
}
void update(int p,int l,int r,int v)
{
	if(l>r)
		return;
	if(l<=a[p].l&&r>=a[p].r)
	{
		addt(p,v);
		return;
	}
	push(p);
	int mid=(a[p].l+a[p].r)>>1;
	if(l<=mid)
		update(a[p].ls,l,r,v);
	if(r>mid)
		update(a[p].rs,l,r,v);
	a[p].s=max(a[a[p].ls].s,a[a[p].rs].s);
}
int query(int p,int l,int r)
{
	if(l<=a[p].l&&r>=a[p].r)
		return a[p].s;
	push(p);
	int s=0x80000000;
	int mid=(a[p].l+a[p].r)>>1;
	if(l<=mid)
		s=max(s,query(a[p].ls,l,r));
	if(r>mid)
		s=max(s,query(a[p].rs,l,r));
	return s;
}
int last[50010];
int pre[50010];
int c[50010];
int f[50010][60];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	memset(last,0,sizeof last);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		pre[i]=last[c[i]];
		last[c[i]]=i;
	}
	memset(f,0x80,sizeof f);
	f[0][0]=0;
	int j;
	for(j=1;j<=k;j++)
	{
		cnt=0;
		build(rt,1,n);
		for(i=1;i<=n;i++)
		{
			update(rt,pre[i]+1,i,1);
			update(rt,i,i,f[i-1][j-1]);
			f[i][j]=query(rt,1,i);
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}