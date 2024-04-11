#include<bits/stdc++.h>
using namespace std;
const int N=200020,M=200020,mod=1000000000;
struct node
{
	int l,r;
	long long s1,s2,lazy;
}t[N<<2]={};
int n,m,a[N]={},f[N]={0,1};
void update(int k)
{
	int L=k<<1,R=(k<<1)|1;
	int d=t[L].r-t[L].l+1;
	t[k].s1=(t[L].s1+t[R].s1*f[d-1]+t[R].s2*f[d])%mod;
	t[k].s2=(t[L].s2+t[R].s1*f[d]+t[R].s2*f[d+1])%mod;
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
		t[k].s1=0,t[k].s2=a[l];
	t[k].l=l;
	t[k].r=r;
	t[k].lazy=0;
}
void add_lazy(int k,int c)
{
	(t[k].lazy+=c)%=mod;
	(t[k].s1+=c*(f[t[k].r-t[k].l+1]-1ll))%=mod;
	(t[k].s2+=c*(f[t[k].r-t[k].l+2]-1ll))%=mod;
}
void push(int k)
{
	add_lazy(k<<1,t[k].lazy);
	add_lazy((k<<1)|1,t[k].lazy);
	t[k].lazy=0;
}
void change(int pos,int c,int k)
{
	if(t[k].l==t[k].r)
	{
		t[k].s1=0,t[k].s2=c;
		return;
	}
	push(k);
	if(t[k<<1].r>=pos)
		change(pos,c,k<<1);
	else
		change(pos,c,(k<<1)|1);
	update(k);
}
long long get_sum(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return (t[k].s1*f[t[k].l-l]+t[k].s2*f[t[k].l-l+1])%mod;
	push(k);
	long long s=0;
	if(t[k<<1].r>=l)
		s+=get_sum(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		s+=get_sum(l,r,(k<<1)|1);
	return s%mod;
}
void add(int l,int r,int v,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return add_lazy(k,v);
	push(k);
	if(t[k<<1].r>=l)
		add(l,r,v,k<<1);
	if(t[(k<<1)|1].l<=r)
		add(l,r,v,(k<<1)|1);
	update(k);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=n+10;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	make_tree(1,n,1);
}
void work()
{
	int t,l,r,x,v;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&x,&v);
			change(x,v,1);
		}
		if(t==2)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",(int)get_sum(l,r,1));
		}
		if(t==3)
		{
			scanf("%d%d%d",&l,&r,&v);
			add(l,r,v,1);
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}