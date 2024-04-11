#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 200005
#define BT 256*1024*2
#define INF 1000000000

using namespace std;
typedef long long int ll;

struct segtree
{
	int seg[BT],mn[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=-1;
			mn[i]=INF;
		}
	}
	void ins(int k,int x)
	{
		k+=mum-1;
		mn[k]=seg[k]=x;
	}
	void build()
	{
		for(int i=mum-2;i>=0;i--)
		{
			mn[i]=min(mn[i*2+1],mn[i*2+2]);
			seg[i]=-1;
		}
	}
	void pass(int k)
	{
		if(seg[k]!=-1)
		{
			seg[k*2+1]=seg[k*2+2]=seg[k];
			mn[k*2+1]=mn[k*2+2]=seg[k];
		}
	}
	ll get(int a,int b,int k,int l,int r,int x)//xx+1A
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b)
		{
			if(mn[k]>x) return 0;
			if(seg[k]!=-1)
			{
				//printf("%d %d %d\n",l,r,seg[k]);
				ll ret=(ll) (x+1-seg[k])*(ll) (r-l);
				mn[k]=seg[k]=x+1;
				return ret;
			}
			pass(k);
			ll vl=get(a,b,k*2+1,l,(l+r)/2,x);
			ll vr=get(a,b,k*2+2,(l+r)/2,r,x);
			if(seg[k*2+1]==seg[k*2+2]&&seg[k*2+1]!=-1) seg[k]=seg[k*2+1];
			else seg[k]=-1;
			mn[k]=min(mn[k*2+1],mn[k*2+2]);
			return vl+vr;
		}
		else
		{
			pass(k);
			ll vl=get(a,b,k*2+1,l,(l+r)/2,x);
			ll vr=get(a,b,k*2+2,(l+r)/2,r,x);
			if(seg[k*2+1]==seg[k*2+2]&&seg[k*2+1]!=-1) seg[k]=seg[k*2+1];
			else seg[k]=-1;
			mn[k]=min(mn[k*2+1],mn[k*2+2]);
			return vl+vr;
		}
	}
	ll get(int a,int b,int x)
	{
		return get(a,b,0,0,mum,x);
	}
};
segtree seg;
vector <int> dv[SIZE];
int left[SIZE],right[SIZE];
int l2[SIZE],r2[SIZE];
int n;

void make()
{
	for(int i=1;i<SIZE;i++)
	{
		for(int j=i;j<SIZE;j+=i)
		{
			dv[j].push_back(i);
		}
	}
	for(int i=0;i<SIZE;i++)
	{
		left[i]=l2[i]=SIZE;
		right[i]=r2[i]=-1;
	}
}
int main()
{
	make();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<dv[a].size();j++)
		{
			int v=dv[a][j];
			int gt=i;
			if(left[v]>=gt) swap(gt,left[v]);
			if(l2[v]>=gt) swap(gt,l2[v]);
			gt=i;
			if(right[v]<=gt) swap(gt,right[v]);
			if(r2[v]<=gt) swap(gt,r2[v]);
		}
	}
	seg.init(n+2);
	for(int i=0;i<n;i++) seg.ins(i,i);
	seg.build();
	ll ret=0;
	for(int i=SIZE-1;i>=1;i--)
	{
		if(right[i]==-1||left[i]==right[i]) continue;
		//printf("%d : %d %d : %d %d\n",i,left[i],right[i],l2[i],r2[i]);
		//[left+1,right-1],[0,r2-1],[l2+1,n-1] i
		ll sum=0;
		if(left[i]+1<=right[i]-1)
		{
			ll gt=seg.get(left[i]+1,right[i],right[i]-1);
			sum+=gt;
		}
		//puts("*");
		if(0<=r2[i]-1)
		{
			ll gt=seg.get(0,r2[i],r2[i]-1);
			sum+=gt;
		}
		if(l2[i]+1<=n-1)
		{
			ll gt=seg.get(l2[i]+1,n,n-1);
			sum+=gt;
		}
		ret+=sum*(ll) i;
	}
	printf("%lld\n",ret);
	return 0;
}