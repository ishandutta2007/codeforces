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
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,M=100010;
struct node
{
	int l,r,andv,orlazy;
}t[N<<2]={};
int n,m,a[N]={},l[M]={},r[M]={},q[M]={};
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)+1);
	}
	t[k].l=l;
	t[k].r=r;
	t[k].andv=t[k].orlazy=0;
}
inline void set_or(int k,int v)
{
	t[k].andv|=v;
	t[k].orlazy|=v;
}
inline void push(int k)
{
	set_or(k<<1,t[k].orlazy);
	set_or((k<<1)+1,t[k].orlazy);
	t[k].orlazy=0;
}
inline void update(int k)
{
	t[k].andv=t[k<<1].andv & t[(k<<1)+1].andv;
}
int get_and(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].andv;
	push(k);
	int s=0x7fffffff;
	if(t[k<<1].r>=l)
		s=s&get_and(l,r,k<<1);
	if(t[(k<<1)+1].l<=r)
		s=s&get_and(l,r,(k<<1)+1);
	return s;
}
void set_or(int l,int r,int v,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		set_or(k,v);
		return;
	}
	push(k);
	if(t[k<<1].r>=l)
		set_or(l,r,v,k<<1);
	if(t[(k<<1)+1].l<=r)
		set_or(l,r,v,(k<<1)+1);
	update(k);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&l[i],&r[i],&q[i]);
	make_tree(1,n,1);
}
void print(int k)
{
	//cout<<"k="<<k<<' '<<t[k].l<<' '<<t[k].r<<' '<<t[k].andv<<' '<<t[k].orlazy<<endl;
	if(t[k].l==t[k].r)
		printf("%d ",t[k].andv);
	else
	{
		push(k);
		print(k<<1);
		print((k<<1)+1);
	}
}
void work()
{
	for(int i=1;i<=m;++i)
	{
		set_or(l[i],r[i],q[i],1);
		//print(1);
	}
	for(int i=1;i<=m;++i)
		if(q[i]!=get_and(l[i],r[i],1))
		{
			puts("NO");
			return;
		}
	puts("YES");
	print(1);
	//for(int i=1;i<=n;++i)
	//	for(int j=i;j<=n;++j)
	//		cout<<i<<' '<<j<<' '<<get_and(i,j,1)<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}