#include<bits/stdc++.h>
using namespace std;
const int N=200200,B=33;
const int Push=1,Change=2,Normal=0;
struct node
{
	int l,r,tot,a[B],lazy;
}t[N<<2]={};
int base[N]={},m;
void guass(int n)
{
	m=1;
	for(int d=30;d>=0 && m<=n;--d)
	{
		for(int i=m;i<=n;++i)
			if(base[i]&(1<<d))
			{
				swap(base[m],base[i]);
				break;
			}
		if((base[m]&(1<<d))==0)
			continue;
		for(int i=m+1;i<=n;++i)
			if(base[i]&(1<<d))
				base[i]^=base[m];
		++m;
	}
	--m;
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
	}
	t[k].l=l;
	t[k].r=r;
	t[k].tot=0;
	fill(t[k].a,t[k].a+B,0);
	t[k].lazy=0;
}
void set_lazy(int k,int v)
{
	if(k>(N<<2))
		cerr<<"k="<<k<<endl;
	t[k].lazy^=v;
	if(t[k].tot==0 && v)
	{
		++t[k].tot;
		t[k].a[1]=v;
	}
	else
	{
		for(int i=1;i<=t[k].tot;++i)
			if(t[k].a[i]&(1<<30))
				t[k].a[i]^=v;
		copy(t[k].a+1,t[k].a+t[k].tot+1,base+1);
		guass(t[k].tot);
		t[k].tot=m;
		copy(base+1,base+m+1,t[k].a+1);
	}
}
void push(int k,int)
{
	if(t[k].lazy)
	{
		set_lazy(k<<1,t[k].lazy);
		set_lazy((k<<1)|1,t[k].lazy);
		t[k].lazy=0;
	}
}
void update(int k)
{
	int t1=t[k<<1].tot, t2=t[(k<<1)|1].tot;
	copy(t[k<<1].a+1,t[k<<1].a+t1+1,base+1);
	copy(t[(k<<1)|1].a+1,t[(k<<1)|1].a+t2+1,base+t1+1);
	guass(t1+t2);
	t[k].tot=m;
	copy(base+1,base+m+1,t[k].a+1);
}
void change(int l,int r,int v,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return set_lazy(k,v);
	push(k,Change);
	if(t[k<<1].r>=l)
		change(l,r,v,k<<1);
	if(t[(k<<1)|1].l<=r)
		change(l,r,v,(k<<1)|1);
	update(k);
}
void push(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return;
	push(k,Push);
	if(t[k<<1].r>=l)
		push(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		push(l,r,(k<<1)|1);
}
void query(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		for(int i=1;i<=t[k].tot;++i)
			base[++m]=t[k].a[i]&(~(1<<30));
		guass(m);
		return;
	}
	if(t[k<<1].r>=l)
		query(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		query(l,r,(k<<1)|1);
}
int n,q;
void init()
{
	scanf("%d%d",&n,&q);
	make_tree(1,n,1);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		change(i,i,x|(1<<30),1);
	}
}
void work()
{
	int type,l,r,k;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d%d",&l,&r,&k);
			change(l,r,k,1);
		}
		if(type==2)
		{
			scanf("%d%d",&l,&r);
			m=0;
			push(l,r,1);
			m=0;
			query(l,r,1);
			printf("%d\n",1<<m);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}