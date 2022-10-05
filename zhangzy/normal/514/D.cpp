#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define xxx 500000
#define yyy 1000000
using namespace std;
int tr[7][2000000];
int n,m,k,a[7][100010],ttt[7]={0};

void build(int w,int x,int l,int r)
{
	if (l==r)
	{
		tr[w][x]=a[w][l];
		return;
	}
	int mid=(l+r)>>1;
	build(w,x<<1,l,mid);
	build(w,(x<<1)+1,mid+1,r);
	tr[w][x]=max(tr[w][x<<1],tr[w][(x<<1)+1]);
}

int que(int w,int x,int l,int r,int st,int en)
{
	if (l==st&&r==en)
		return tr[w][x];
	int mid=(l+r)>>1;
	if (en<=mid)
		return que(w,x<<1,l,mid,st,en);
	if (st>mid)
		return que(w,(x<<1)+1,mid+1,r,st,en);
	return max( que(w,x<<1,l,mid,st,mid) , que(w,(x<<1)+1,mid+1,r,mid+1,en) );
}

int pd(int st,int en)
{
	int kk=k;
	for (int i=1;i<=m;i++)
	{
		ttt[i]=que(i,1,1,n,st,en);
		kk-=ttt[i];
		if (kk<0) return 0;
	}
	return 1;
}

int le,ri,mi,ans=0,kk,realans[6]={0};
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[j][i]);
	for (int i=1;i<=m;i++)
		build(i,1,1,n);
	for (int i=1;i<=n;i++)
	{
		le=i;ri=n;
		while (le<=ri)
		{
			mi=(le+ri)/2;
			memset(ttt,0,sizeof(ttt));
			if (pd(i,mi))
			{
				le=mi+1;
				if (mi-i+1>ans)
				{
					ans=mi-i+1;
					for (int i=1;i<=m;i++)
						realans[i]=ttt[i];	
				}
			}
			else
			{
				ri=mi-1;
			}
		}
	}
	for (int i=1;i<=m;i++)
		printf("%d ",realans[i]);
}