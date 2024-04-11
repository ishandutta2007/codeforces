#include<bits/stdc++.h>
using namespace std;
const int N=200200;
struct node
{
	int l,r;
	int s1,s2;
}t[N<<2]={};
int n,k,a,b,q,v[N]={};
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
	}
	else
		v[l]=0;
	t[k].l=l;
	t[k].r=r;
	t[k].s1=t[k].s2=0;
}
void add(int pos,int c,int k)
{
	if(t[k].l==t[k].r)
	{
		v[pos]+=c;
		t[k].s1=min(v[pos],b);
		t[k].s2=min(v[pos],a);
		return;
	}
	if(t[k<<1].r>=pos)
		add(pos,c,k<<1);
	else
		add(pos,c,(k<<1)|1);
	t[k].s1=t[k<<1].s1+t[(k<<1)|1].s1;
	t[k].s2=t[k<<1].s2+t[(k<<1)|1].s2;
}
int gets1(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].s1;
	int v=0;
	if(t[k<<1].r>=l)
		v+=gets1(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		v+=gets1(l,r,(k<<1)|1);
	return v;
}
int gets2(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].s2;
	int v=0;
	if(t[k<<1].r>=l)
		v+=gets2(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		v+=gets2(l,r,(k<<1)|1);
	return v;
}
int main()
{	
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	make_tree(1,n,1);
	int type,d,p;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&d,&p);
			add(d,p,1);
		}
		else
		{
			scanf("%d",&d);
			int ans=0;
			if(d>1)
				ans+=gets1(1,d-1,1);
			if(d+k<=n)
				ans+=gets2(d+k,n,1);
			printf("%d\n",ans);
		}
	}
	return 0;
}