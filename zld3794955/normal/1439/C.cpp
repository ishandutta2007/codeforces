#include<bits/stdc++.h>
using namespace std;
const int N=200020;
struct seg_tree
{
	int l,r;
	long long minv,maxv,sum;
	long long tag;
}t[N<<2]={};
int n,q,a[N]={};
void settag(int k,int tag)
{
	if(tag>t[k].tag)
	{
		t[k].tag=tag;
		t[k].minv=t[k].maxv=tag;
		t[k].sum=(t[k].r-t[k].l+1)*1ll*tag;
	}
}
void push(int k)
{
	if(t[k].tag)
	{
		settag(k<<1,t[k].tag);
		settag((k<<1)|1,t[k].tag);
		t[k].tag=0;
	}
}
void update(int k)
{
	t[k].minv=min(t[k<<1].minv,t[(k<<1)|1].minv);
	t[k].maxv=max(t[k<<1].maxv,t[(k<<1)|1].maxv);
	t[k].sum=t[k<<1].sum+t[(k<<1)|1].sum;
}
void build_tree(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	if(l==r)
	{
		t[k].minv=t[k].maxv=t[k].sum=a[l];
		t[k].tag=0;
		return;
	}
	int mid=(l+r)>>1;
	build_tree(l,mid,k<<1);
	build_tree(mid+1,r,(k<<1)|1);
	update(k);
}
void modify(int l,int r,int v,int k)
{
	if(t[k].minv>=v)
		return;
	if(l<=t[k].l && t[k].r<=r && t[k].maxv<=v)
		return settag(k,v);
	push(k);
	if(l<=t[k<<1].r)
		modify(l,r,v,k<<1);
	if(r>=t[(k<<1)|1].l)
		modify(l,r,v,(k<<1)|1);
	update(k);
}
int find1(int l,int &v,int k)
{
	if(l<=t[k].l && t[k].sum<=v)
	{
		v-=t[k].sum;
		return t[k].r+1;
	}
	if(t[k].l==t[k].r && t[k].sum>v)
		return t[k].l;
	push(k);
	if(l<=t[k<<1].r)
	{
		int pos=find1(l,v,k<<1);
		if(pos==t[(k<<1)|1].l)
			return find1(l,v,(k<<1)|1);
		else
			return pos;
	}
	else
		return find1(l,v,(k<<1)|1);
}
int find2(int l,int v,int k)
{
	if(t[k].minv>v)
		return t[k].r+1;
	if(l<=t[k].l && t[k].maxv<=v)
		return t[k].l;
	push(k);
	if(l<=t[k<<1].r)
	{
		int pos=find2(l,v,k<<1);
		if(pos==t[(k<<1)|1].l)
			return find2(l,v,(k<<1)|1);
		else
			return pos;
	}
	else
		return find2(l,v,(k<<1)|1);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	build_tree(1,n,1);
	for(int i=1,t,x,y;i<=q;++i)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			modify(1,x,y,1);
		else if(t==2)
		{
			int ans=0;
			while(x<=n)
			{
				int tmp=find1(x,y,1);
				ans+=tmp-x;
				x=tmp<=n ? find2(tmp,y,1) : tmp;
			}
			printf("%d\n",ans);
		}
	}
}