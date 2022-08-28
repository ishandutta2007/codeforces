#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define BT 512*1024*2

using namespace std;
typedef long long int ll;

struct P
{
	int a,b,c,d;
	P(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
};
P unite(P l,P r)
{
	P ret;
	ret.a=min(l.a,r.a);
	ret.c=0;
	if(ret.a==l.a) ret.c+=l.c;
	if(ret.a==r.a) ret.c+=r.c;
	ret.b=min(l.b,r.b);
	if(l.a!=ret.a) ret.b=min(ret.b,l.a);
	if(r.a!=ret.a) ret.b=min(ret.b,r.a);
	ret.d=0;
	if(l.a==ret.b) ret.d+=l.c;
	else if(l.b==ret.b) ret.d+=l.d;
	if(r.a==ret.b) ret.d+=r.c;
	else if(r.b==ret.b) ret.d+=r.d;
	return ret;
}
struct segtree
{
	P seg[BT];
	int add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=P(BT,BT+1,0,0);
			add[i]=0;
		}
	}
	void ins(int k,int x)
	{
		k+=mum-1;
		seg[k].a=x;
		seg[k].c=1;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=unite(seg[k*2+1],seg[k*2+2]);
			seg[k].a+=add[k];
			seg[k].b+=add[k];
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k].a+=v;
			seg[k].b+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=unite(seg[k*2+1],seg[k*2+2]);
			seg[k].a+=add[k];
			seg[k].b+=add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get()
	{
		int ret=0;
		if(seg[0].a<=2) ret+=seg[0].c;
		if(seg[0].b<=2) ret+=seg[0].d;
		return ret;
	}
};
segtree seg;
int back[SIZE],perm[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		back[p]=i;
		perm[i]=p;
	}
	ll ret=0;
	seg.init(n+2);
	for(int i=n-1;i>=0;i--)
	{
		seg.ins(i,0);
		seg.update(i,n,1);
		if(back[i]+1<n)
		{
			int to=perm[back[i]+1];
			if(to>i) seg.update(to,n,-1);
		}
		if(back[i]-1>=0)
		{
			int to=perm[back[i]-1];
			if(to>i) seg.update(to,n,-1);
		}
		ret+=seg.get()-1;
	}
	printf("%I64d\n",ret);
	return 0;
}