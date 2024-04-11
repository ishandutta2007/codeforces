#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define MX 35
#define BT 256*1024*2

using namespace std;

struct N
{
	int vl[MX];
	N(){}
	void clear()
	{
		memset(vl,0,sizeof(vl));
	}
	void ins(int p,int x)
	{
		vl[p]=x;
	}
};
N emp;
N merge(N l,N r)
{
	for(int i=0;i<MX;i++)
	{
		if(r.vl[i]>0)
		{
			int gt=r.vl[i];
			for(int j=i;j>=0;j--)
			{
				if(gt>>j&1)
				{
					if(l.vl[j]==0)
					{
						l.ins(j,gt);
						break;
					}
					gt^=l.vl[j];
				}
			}
		}
	}
	return l;
}
struct segtree1
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]^=v;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret^=seg[k];
		}
		return ret;
	}
};
struct segtree2
{
	N seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i].clear();
	}
	void ins(int k,int x)
	{
		k+=mum-1;
		int mx=0,X=x;
		while(X>1)
		{
			mx++;
			X/=2;
		}
		seg[k].ins(mx,x);
	}
	void build()
	{
		for(int i=mum-2;i>=0;i--)
		{
			seg[i]=merge(seg[i*2+1],seg[i*2+2]);
		}
	}
	void change(int k,int x)
	{
		seg[k+mum-1].clear();
		ins(k,x);
		k+=mum-1;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=merge(seg[k*2+1],seg[k*2+2]);
		}
	}
	N get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return emp;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			N vl=get(a,b,k*2+1,l,(l+r)/2);
			N vr=get(a,b,k*2+2,(l+r)/2,r);
			return merge(vl,vr);
		}
	}
	int get(int a,int b)
	{
		N V=get(a,b,0,0,mum);
		int cnt=0;
		for(int i=0;i<MX;i++) if(V.vl[i]!=0) cnt++;
		return cnt;
	}
};
segtree1 s1;
segtree2 s2;

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	s1.init(n+2);
	s2.init(n+2);
	int last=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		s1.add(i,a);
		s2.ins(i,last^a);
		last=a;
	}
	s2.build();
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int l,r,k;
			scanf("%d %d %d",&l,&r,&k);l--;r--;
			s1.update(l,r+1,k);
			int L=s1.get(l);
			if(l>0) L^=s1.get(l-1);
			s2.change(l,L);
			if(r+1<n)
			{
				int R=s1.get(r)^s1.get(r+1);
				s2.change(r+1,R);
			}
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);l--;r--;
			s2.change(l,s1.get(l));
			int c=s2.get(l,r+1);
			int ret=1;
			for(int j=0;j<c;j++) ret<<=1;
			printf("%d\n",ret);
			if(l>0) s2.change(l,s1.get(l)^s1.get(l-1));
		}
	}
	return 0;
}