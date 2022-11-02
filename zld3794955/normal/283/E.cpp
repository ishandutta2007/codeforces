#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010;
struct modify
{
	int pos,l,r;
}c[M<<1]={};
bool cmp(const modify &m1,const modify &m2)
{
	return m1.pos<m2.pos;
}
struct node
{
	int l,r,s0,s1,rev;
}t[N<<2]={};
void update(int k)
{
	t[k].s0=t[k<<1].s0+t[(k<<1)|1].s0;
	t[k].s1=t[k<<1].s1+t[(k<<1)|1].s1;
}
void set_rev(int k)
{
	t[k].rev=!t[k].rev;
	swap(t[k].s0,t[k].s1);
}
void push(int k)
{
	if(t[k].rev)
		set_rev(k<<1),set_rev((k<<1)|1);
	t[k].rev=0;
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
		update(k);
	}
	else
		t[k].s1=1,t[k].s0=0;
	t[k].l=l;
	t[k].r=r;
}
int query0(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].s0;
	push(k);
	int v=0;
	if(t[k<<1].r>=l)
		v+=query0(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		v+=query0(l,r,(k<<1)|1);
	return v;
}
void reverse01(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return set_rev(k);
	push(k);
	if(t[k<<1].r>=l)
		reverse01(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		reverse01(l,r,(k<<1)|1);
	update(k);
}
int n,m,q,a[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,l=0,r=0;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		l=lower_bound(a+1,a+n+1,l)-a;
		r=upper_bound(a+1,a+n+1,r)-a-1;
		if(l<=r)
		{
			c[++q]=(modify){l,l,r};
			c[++q]=(modify){r+1,l,r};
		}
	}
	sort(c+1,c+q+1,cmp);
	make_tree(1,n,1);
}
void work()
{
	long long ans=n;
	int p=1;
	ans=ans*(ans-1)*(ans-2)/3;
	for(int i=1;i<=n;++i)
	{
		reverse01(i,i,1);
		while(p<=q && c[p].pos<=i)
		{
			reverse01(c[p].l,c[p].r,1);
			++p;
		}
		long long t1=query0(1,n,1)-query0(i,i,1),t2=n-1-t1;
		ans-=t1*(t1-1)/2+t2*(t2-1)/2;
	}
	cout<<ans/2<<endl;
}
int main()
{
	init();
	work();
	return 0;
}