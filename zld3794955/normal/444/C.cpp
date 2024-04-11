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
#define int long long
const int N=100100;
int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
struct node
{
	int l,r;
	long long lazy,sum;
	int same_color,c;
}t[N<<2]={};
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)+1);
		t[k].same_color=false;
	}
	else
	{
		t[k].same_color=true;
		t[k].c=l;
	}
	t[k].l=l;
	t[k].r=r;
	t[k].lazy=t[k].sum=0;
}
void set_lazy(int k,long long lazy)
{
	t[k].lazy+=lazy;
	t[k].sum+=(t[k].r-t[k].l+1)*lazy;
}
void push(int k)
{
	if(t[k].l!=t[k].r)
	{
		set_lazy(k<<1,t[k].lazy);
		set_lazy((k<<1)+1,t[k].lazy);
		if(t[k].same_color)
		{
			t[k<<1].same_color=true;
			t[k<<1].c=t[k].c;
			t[(k<<1)+1].same_color=true;
			t[(k<<1)+1].c=t[k].c;
		}
	}
	t[k].lazy=0;
}
long long sum(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].sum;
	push(k);
	long long s=0;
	if(t[k<<1].r>=l)
		s+=sum(l,r,k<<1);
	if(t[(k<<1)+1].l<=r)
		s+=sum(l,r,(k<<1)+1);
	return s;
}
void change(int l,int r,int c,int k)
{
	if(t[k].l>=l && t[k].r<=r && t[k].same_color)
	{
		set_lazy(k,max(c,t[k].c)-min(c,t[k].c));
		t[k].c=c;
		return;
	}
	push(k);
	if(t[k<<1].r>=l)
		change(l,r,c,k<<1);
	if(t[(k<<1)+1].l<=r)
		change(l,r,c,(k<<1)+1);
	t[k].sum=t[k<<1].sum+t[(k<<1)+1].sum;
	if(t[k].l>=l && t[k].r<=r)
		t[k].same_color=true,t[k].c=c;
	else
		t[k].same_color=false;
	//else
	//{
	//	t[k].same_color=t[k<<1].c==t[(k<<1)+1].c;
	//	t[k].same_color&=t[k<<1].same_color && t[(k<<1)+1].same_color;
	//	if(t[k].same_color)
	//		t[k].c=t[k<<1].c;
	//}
}
int n,m;
void init()
{
	n=getint(),m=getint();
	make_tree(1,n,1);
}
void print(int k)
{
	if(t[k].l!=t[k].r)
		push(k);
	if(t[k].l!=t[k].r)
		print(k<<1);
	
	cout<<t[k].l<<' '<<t[k].r<<' '<<t[k].same_color<<' '<<t[k].c<<' '<<t[k].sum<<endl;
	if(t[k].l!=t[k].r)
		print((k<<1)+1);
}
void work()
{
	int type,l,r,x;
	for(int i=1;i<=m;++i)
	{
		type=getint();
		if(type==1)
		{
			l=getint(),r=getint(),x=getint();
			change(l,r,x,1);
		}
		if(type==2)
		{
			l=getint(),r=getint();
			printf("%I64d\n",sum(l,r,1));
		}
		//print(1);
		//cout<<"--------------------------"<<endl;
	}
}
#undef int
int main()
{	
	init();
	work();
	return 0;
}