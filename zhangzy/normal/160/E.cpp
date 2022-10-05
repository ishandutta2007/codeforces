%:pragma GCC optimize(3)
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define zzy 5200000
using namespace std;
struct XY{
	int st,en,t,p,seat;
}a[zzy];
struct linetree{
	int val,name;
}tr[zzy];
int n,m,tot,tsor[zzy],ans[zzy];

bool compareXY(XY smallxy,XY bigxy)
{
	return smallxy.st!=bigxy.st ? smallxy.st < bigxy.st : smallxy.p<bigxy.p;
}

void inse(int k,int x,int l,int r)
{
	if (l==r)
	{
		if (a[k].en>tr[x].val)
		{
			tr[x].val=a[k].en;
			tr[x].name=a[k].p;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (a[k].seat<=mid)
		inse(k,x<<1,l,mid);
	else
		inse(k,x<<1|1,mid+1,r);
	tr[x].val= max(tr[x<<1].val,tr[x<<1|1].val);
}

int que(int k,int x,int l,int r)
{
	if (tr[x].val<a[k].en) return -1;
	if (l==r)
		return tr[x].name;
	int mid=(l+r)>>1;
	int tem=a[k].seat>mid?-1:que(k,x<<1,l,mid);
	return tem>0?tem:que(k,x<<1|1,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	tot=n+m;
	for (int i=1;i<=tot;i++)
	{
		scanf("%d%d%d",&a[i].st,&a[i].en,&a[i].t);
		a[i].p=i;
		tsor[i]=a[i].t;
	}
	sort(tsor+1,tsor+tot+1);
	sort(a+1,a+tot+1,compareXY);
	for (int i=1;i<=tot;i++)
		a[i].seat=lower_bound(tsor+1,tsor+tot+1,a[i].t)-tsor;
		//stl 
	//for (int i=1;i<=tot;i++)printf("%d ",a[i].seat);
	for (int i=1;i<=tot;i++)
		if (a[i].p<=n)
			inse(i,1,1,tot);
		else
			ans[a[i].p]=que(i,1,1,tot);
	for (int i=n+1;i<=tot;i++)
		printf("%d ",ans[i]);
}