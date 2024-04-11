#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;
typedef long long int ll;

struct segtree
{
	int seg[BT];
	ll cost[BT],diff[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<n;i++)
		{
			int k=i+mum-1;
			seg[k]=i;
			cost[i]=0;
		}
		for(int i=0;i<mum-1;i++)
		{
			seg[i]=-1;
			cost[i]=0;
		}
	}
	void pass(int k,int l,int r)
	{
		if(seg[k]!=-1)
		{
			for(int i=k*2+1;i<=k*2+2;i++)
			{
				ll d=diff[k];
				seg[i]=seg[k];
				diff[i]+=d;
				cost[i]+=d*(ll) (r-l)/2;
			}
			diff[k]=0;
		}
	}
	void make(int k)
	{
		seg[k]=seg[k*2+1]==seg[k*2+2]?seg[k*2+1]:-1;
		cost[k]=cost[k*2+1]+cost[k*2+2];
		diff[k]=0;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b&&seg[k]!=-1)
		{
			ll d=abs(seg[k]-v);
			seg[k]=v;
			diff[k]+=d;
			cost[k]+=d*(ll) (r-l);
		}
		else
		{
			pass(k,l,r);
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			make(k);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	ll calc(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return cost[k];
		else
		{
			pass(k,l,r);
			ll vl=calc(a,b,k*2+1,l,(l+r)/2);
			ll vr=calc(a,b,k*2+2,(l+r)/2,r);
			make(k);
			return vl+vr;
		}
	}
	ll calc(int a,int b)
	{
		return calc(a,b,0,0,mum);
	}
};
segtree seg;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	seg.init(n);
	for(int i=0;i<m;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int l,r,v;
			scanf("%d %d %d",&l,&r,&v);l--;r--;v--;
			seg.update(l,r+1,v);
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);l--;r--;
			printf("%llld\n",seg.calc(l,r+1));
		}
	}
	return 0;
}