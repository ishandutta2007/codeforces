#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define SIZE 200005
#define BT 256*1024*2
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,ll x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
	int search(ll sum)
	{
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			if(seg[k*2+1]<sum)
			{
				sum-=seg[k*2+1];
				l=(l+r)/2;
				k=k*2+2;
			}
			else
			{
				r=(l+r)/2;
				k=k*2+1;
			}
		}
		return l;
	}
	int medium(int l,int r)//closed interval [l,r]
	{
		ll g=get(l,r+1);
		g=(g+1)/2;
		if(l>0) g+=get(0,l);
		return search(g);
	}
};
struct segtree2
{
	ll seg[BT];
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
		seg[k]=x%MOD;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2])%MOD;
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return (vl+vr)%MOD;
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree s1;
segtree2 s2;
ll A[SIZE];

ll get_right(int s,int t)
{
	ll ret=A[t]*(s1.get(s,t+1)%MOD)%MOD;
	ret-=s2.get(s,t+1);
	if(ret<0) ret+=MOD;
	return ret;
}
ll get_left(int s,int t)
{
	ll ret=s2.get(s,t+1);
	ret-=A[s]*(s1.get(s,t+1)%MOD)%MOD;
	if(ret<0) ret+=MOD;
	return ret;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		A[i]-=i;
	}
	s1.init(n+2);
	s2.init(n+2);
	for(int i=0;i<n;i++)
	{
		ll w;
		scanf("%lld",&w);
		s1.add(i,w);
		s2.add(i,A[i]*w%MOD);
	}
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x<0)
		{
			x=-x;
			x--;
			s1.add(x,y);
			s2.add(x,(ll) y*A[x]%MOD);
		}
		else
		{
			x--,y--;
			int d=s1.medium(x,y);
			printf("%lld\n",(get_right(x,d)+get_left(d,y))%MOD);
		}
	}
	return 0;
}