#include<bits/stdc++.h>
using namespace std;
const int mod=95542721,N=100010,D=48;
struct node
{
	int l,r,s[D],lazy;
}t[N<<2]={};
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
		for(int i=0;i<D;++i)
			t[k].s[i]=(t[k<<1].s[i]+t[(k<<1)|1].s[i])%mod;
	}
	else
	{
		scanf("%d",t[k].s);
		for(int i=1;i<D;++i)
			t[k].s[i]=t[k].s[i-1]*1ll*t[k].s[i-1]%mod*t[k].s[i-1]%mod;
	}
	t[k].l=l;
	t[k].r=r;
}
void add_lazy(int k,int c)
{
	t[k].lazy=(t[k].lazy+c);
    if(t[k].lazy>=D) t[k].lazy-=D;
	rotate(t[k].s,t[k].s+c,t[k].s+D);
}
void push(int k)
{
	add_lazy(k<<1,t[k].lazy);
	add_lazy((k<<1)|1,t[k].lazy);
	t[k].lazy=0;
}
void cube(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return add_lazy(k,1);
	push(k);
	if(t[k<<1].r>=l)
		cube(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		cube(l,r,(k<<1)|1);
	for(int i=0;i<D;++i)
		t[k].s[i]=(t[k<<1].s[i]+t[(k<<1)|1].s[i])%mod;
}
int sum(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].s[0];
	push(k);
	int s=0;
	if(t[k<<1].r>=l)
		s+=sum(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		s+=sum(l,r,(k<<1)|1);
	return s%mod;
}
int main()
{
	int n,q,type,l,r;
	scanf("%d",&n);
	make_tree(1,n,1);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&type,&l,&r);
		if(type==1)
			printf("%d\n",sum(l,r,1));
		else
			cube(l,r,1);
	}
	return 0;
}