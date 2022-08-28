#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define BT 256*1024*2
#define INF 100000000000LL

using namespace std;
typedef long long int ll;

struct segtree
{
	ll seg[BT];
	ll add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=min(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr)+add[k];
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
	ll val(int k)
	{
		return get(k,k+1);
	}
};
segtree seg[2];

int main()
{
	int n;
	scanf("%d",&n);
	seg[0].init(n+2);
	seg[1].init(n+2);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);a--;
		sum=a-sum;
		seg[i%2].update(i/2,i/2+1,sum);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int a,b,k;
			scanf("%d %d %d",&a,&b,&k);
			//[a,n]+k,[b+1,n]-kl
			seg[a%2].update(a/2,n,k);
			seg[(b+1)%2].update((b+1)/2,n,-k);
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			//for(int j=0;j<n;j++) printf("%lld ",seg[j%2].val(j/2));puts("");
			ll gn=a==0?0LL:seg[(a-1)%2].val((a-1)/2);
			ll L,R;
			int s,t;
			s=a+1;
			if(b%2==s%2) t=b;
			else t=b-1;
			if(s<=t) L=seg[s%2].get(s/2,t/2+1);
			else L=INF;
			L=max(gn-L,0LL);
			s=a;
			if(s%2==b%2) t=b;
			else t=b-1;
			if(s<=t) R=seg[s%2].get(s/2,t/2+1);
			else R=INF;
			R+=gn;
			ll last=seg[b%2].val(b/2);
			//printf("%lld %lld : %lld %lld\n",L,R,gn,last);
			if(b%2!=(a+1)%2) last*=-1;
			if(gn==last&&L<=0LL&&0LL<=R) puts("1");
			else puts("0");
		}
	}
	return 0;
}