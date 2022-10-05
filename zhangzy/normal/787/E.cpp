#include<cstdio>
#include<iostream>
#include<vector>
#define xxx 100100
#define yyy 5202333
using namespace std;
int root[xxx],cnt=0,n,a[xxx],hea[xxx],nex[xxx];
struct T{
	int lc,rc,siz;
}tr[yyy];

void C(int p1,int p2,int l,int r,int v,int cg)
{
	if (l==r)
	{
		tr[p2].siz+=cg;
		return;
	}
	int mid=(l+r)>>1;
	if (v<=mid)
	{
		if (!tr[p2].lc||tr[p2].lc==tr[p1].lc) 
		{
			tr[p2].lc=++cnt;
			tr[tr[p2].lc].siz=tr[tr[p1].lc].siz;
		}
		if (!tr[p2].rc) tr[p2].rc=tr[p1].rc;
		C(tr[p1].lc,tr[p2].lc,l,mid,v,cg);
	}
	else
	{
		if (!tr[p2].lc) tr[p2].lc=tr[p1].lc;
		if (!tr[p2].rc||tr[p2].rc==tr[p1].rc) 
		{
			tr[p2].rc=++cnt;
			tr[tr[p2].rc].siz=tr[tr[p1].rc].siz;
		}
		C(tr[p1].rc,tr[p2].rc,mid+1,r,v,cg);
	}
	tr[p2].siz = tr[tr[p2].lc].siz + tr[tr[p2].rc].siz;
	return;
}

int F(int p,int l,int r,int v)
{
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (v<=tr[tr[p].lc].siz) return F(tr[p].lc,l,mid,v);
	else return F(tr[p].rc,mid+1,r,v-tr[tr[p].lc].siz);
}

void P(int p,int l,int r)
{
	printf(" %d (%d,%d) %d-%d %d\n",p,tr[p].lc,tr[p].rc,l,r,tr[p].siz);
	if (l==r) return;
	int mid=(l+r)>>1;
	P(tr[p].lc,l,mid);P(tr[p].rc,mid+1,r);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		nex[i]=hea[i]=n+1;
	int x,y;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=n;i>0;i--)
	{
		nex[i]=hea[a[i]];
		hea[a[i]]=i;
	}
	root[0]=0;root[1]=++cnt;
	C(root[0],root[1],1,n+1,n+1,1);
	for (int i=1;i<=n;i++)
		if (hea[i]<=n)
			C(root[0],root[1],1,n+1,hea[i],1);
	//printf("\n%d:\n",1);P(root[1],1,n+1);scanf("%d",&root[1001]);
	for (int i=2;i<=n;i++)
	{
		root[i]=++cnt;
		C(root[i-1],root[i],1,n+1,i-1,-1);
		if (nex[i-1]<=n) C(root[i-1],root[i],1,n+1,nex[i-1],1);
			//printf("\n%d:\n",i);P(root[i],1,n+1);
	}
	if (0)
	{
		for (int i=1;i<=n;i++)
		{
			printf("\n%d:\n",i);
			P(root[i],1,n+1);
		}	
	}
	
	
	int ans,p;
	for (int i=1;i<=n;i++)
	{
		ans=0;
		p=1;
		while (p<=n)
		{
			p=F(root[p],1,n+1,i+1);
			ans++;
		}
		printf("%d ",ans);
	}
	return 0;
}