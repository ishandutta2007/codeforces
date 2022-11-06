#include<stdio.h>
#include<queue>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
struct node
{
	int l,r,lson,rson,cnt;
	long long cost;
}a[3000002];
int tot=1,n,m,b;
long long A,B;
void add_node(int l,int r,int p,int t)
{
	a[t].l=l;a[t].r=r;
	if(l==r&&r==p)
	{a[t].cnt+=1;a[t].cost=(long long)a[t].cnt*B;return;}
	if(l<=p&&p<=((l+r)>>1))
	{
		if(!a[t].lson)a[t].lson=++tot;
		add_node(l,(l+r)>>1,p,a[t].lson);
	}
	if(((l+r)>>1)+1<=p&&p<=r)
	{
		if(!a[t].rson)a[t].rson=++tot;
		add_node(((l+r)>>1)+1,r,p,a[t].rson);
	}
	a[t].cnt=a[a[t].lson].cnt+a[a[t].rson].cnt;
	a[t].cost=Min(((a[t].lson?a[a[t].lson].cost:A)+(a[t].rson?a[a[t].rson].cost:A)),(a[t].cnt?(long long)a[t].cnt*(long long)(a[t].r-a[t].l+1)*B:A));
}
int main()
{
	scanf("%d%d%lld%lld",&n,&m,&A,&B);
	a[1]=node{1,(1<<n),0,0,0,A};
	while(m--)
	{
		scanf("%d",&b);
		add_node(1,(1<<n),b,1);
	}printf("%lld",a[1].cost);
}