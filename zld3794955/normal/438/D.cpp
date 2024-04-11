#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const int N=100010;
struct node
{
	int l,r,maxp;
	long long sum;
}t[N<<2]={};
int n,m,a[N]={};
inline void update(int k)
{
	if(a[t[k<<1].maxp]>a[t[(k<<1)+1].maxp])
		t[k].maxp=t[k<<1].maxp;
	else
		t[k].maxp=t[(k<<1)+1].maxp;
	t[k].sum=t[k<<1].sum+t[(k<<1)+1].sum;
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)+1);
		update(k);
	}
	else
	{
		t[k].maxp=l;
		t[k].sum=a[l];
	}
	t[k].l=l;
	t[k].r=r;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	make_tree(1,n,1);
}
long long sum(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].sum;
	long long s=0;
	if(t[k<<1].r>=l)
		s+=sum(l,r,k<<1);
	if(t[(k<<1)+1].l<=r)
		s+=sum(l,r,(k<<1)+1);
	return s;
}
int max_pos(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].maxp;
	int maxp=0,v=0,tmp=0;
	if(t[k<<1].r>=l && a[tmp=max_pos(l,r,k<<1)]>v)
		v=a[tmp],maxp=tmp;
	if(t[(k<<1)+1].l<=r && a[tmp=max_pos(l,r,(k<<1)+1)]>v)
		v=a[tmp],maxp=tmp;
	return maxp;
}
void up(int pos,int v,int k)
{
	if(t[k].l==t[k].r)
	{
		t[k].sum=v;
		a[pos]=v;
		return;
	}
	if(t[k<<1].r>=pos)
		up(pos,v,k<<1);
	else
		up(pos,v,(k<<1)+1);
	update(k);
}
void mod(int pos,int m,int k)
{
	if(t[k].l==t[k].r)
	{
		t[k].sum%=m;
		a[pos]%=m;
		return;
	}
	if(t[k<<1].r>=pos)
		mod(pos,m,k<<1);
	else
		mod(pos,m,(k<<1)+1);
	update(k);
}
void work()
{
	int type,l,r,k,x;
	for(int i=1;i<=m;++i)
	{
		//cout<<"i="<<i<<endl;
		scanf("%d",&type);
		//cout<<type<<endl;
		if(type==1)
		{
			scanf("%d%d",&l,&r);
			printf("%I64d\n",sum(l,r,1));
		}
		if(type==2)
		{
			scanf("%d%d%d",&l,&r,&x);
			int tmp(0);
			while(a[tmp=max_pos(l,r,1)]>=x)
				mod(tmp,x,1);
		}
		if(type==3)
		{
			scanf("%d%d",&k,&x);
			up(k,x,1);
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}