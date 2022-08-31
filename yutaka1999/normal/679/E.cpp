#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 1024*128*2
#define INF 100000000000000000LL
#define B 42LL

using namespace std;
typedef long long int ll;

struct segtree
{
	ll add[BT],seg[BT];//seg : distl
	ll now[BT];
	bool use[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			add[i]=0;
			now[i]=seg[i]=1;
			use[i]=i>=mum-1;
		}
	}
	void pass(int k)
	{
		for(int i=k*2+1;i<=k*2+2;i++)
		{
			if(use[k])
			{
				add[i]=add[k];
				seg[i]=seg[k];
				now[i]=now[k];
				use[i]=true;
			}
			else
			{
				add[i]+=add[k];
				seg[i]-=add[k];
			}
		}
		use[k]=false;
		add[k]=0;
	}
	void make(int k)
	{
		seg[k]=min(seg[k*2+1],seg[k*2+2]);
	}
	void ins(int a,int b,int k,int l,int r,ll nw,ll dt)//x
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			add[k]=0;
			now[k]=nw;
			seg[k]=dt;
			use[k]=true;
		}
		else
		{
			pass(k);
			ins(a,b,k*2+1,l,(l+r)/2,nw,dt);
			ins(a,b,k*2+2,(l+r)/2,r,nw,dt);
			make(k);
		}
	}
	void ins(int a,int b,ll nw,ll dt)
	{
		ins(a,b,0,0,mum,nw,dt);
	}
	void up(int a,int b,int k,int l,int r,ll x)//distxA
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			if(seg[k]>x)
			{
				add[k]+=x;
				seg[k]-=x;
				//printf("%d %d %d : %d\n",l,r,k,add[k]);
			}
			else if(use[k])
			{
				ll y=now[k]-seg[k]+x;
				while(now[k]<y) now[k]*=42LL;
				seg[k]=now[k]-y;
				add[k]=0;
				//printf("%d %d %d : %d\n",l,r,k,add[k]);
			}
			else
			{
				pass(k);
				up(a,b,k*2+1,l,(l+r)/2,x);
				up(a,b,k*2+2,(l+r)/2,r,x);
				make(k);
			}
		}
		else
		{
			pass(k);
			up(a,b,k*2+1,l,(l+r)/2,x);
			up(a,b,k*2+2,(l+r)/2,r,x);
			make(k);
		}
	}
	void up(int a,int b,ll x)
	{
		up(a,b,0,0,mum,x);
	}
	ll get(int p)
	{
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			pass(k);
			int m=(l+r)/2;
			if(p<m)
			{
				r=m;
				k=k*2+1;
			}
			else
			{
				l=m;
				k=k*2+2;
			}
		}
		return now[k]-seg[k];
	}
	ll all()
	{
		return seg[0];
	}
};
segtree seg;

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		ll nw=1;
		while(nw<t) nw*=42LL;
		seg.ins(i,i+1,nw,nw-t);
	}
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int x;
			scanf("%d",&x);x--;
			printf("%lld\n",seg.get(x));
		}
		else if(tp==2)
		{
			int a,b,x;
			scanf("%d %d %d",&a,&b,&x);a--;b--;
			ll nw=1;
			while(nw<x) nw*=42LL;
			seg.ins(a,b+1,nw,nw-x);
		}
		else
		{
			int a,b,x;
			scanf("%d %d %d",&a,&b,&x);a--;b--;
			while(1)
			{
				seg.up(a,b+1,x);
				//printf("* %d %d %d : %lld\n",a,b,x,seg.all());
				if(seg.all()>0) break;
			}
		}
	}
	return 0;
}