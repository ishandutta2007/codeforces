#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define SIZE 128*1024*2

using namespace std;
typedef long long int ll;

struct segtree
{
	ll seg[SIZE*2],add[SIZE*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum*=2;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=0;
			add[i]=0;
		}
	}
	void updata(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) add[k]+=v;
		else
		{
			seg[k]+=(ll) v*(min(b,r)-max(l,a));
			updata(a,b,k*2+1,l,(l+r)/2,v);
			updata(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void updata(int a,int b,int v)// [a,b) + v
	{
		updata(a,b,0,0,mum,v);
	}
	ll sum(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0LL;
		if(a<=l&&r<=b) return seg[k]+add[k]*(r-l);
		ll v1=sum(a,b,k*2+1,l,(l+r)/2);
		ll v2=sum(a,b,k*2+2,(l+r)/2,r);
		return v1+v2+add[k]*(min(b,r)-max(a,l));
	}
	ll sum(int a,int b)// sum of [a,b)
	{
		return sum(a,b,0,0,mum);
	}
	void check()
	{
		for(int i=0;i<mum*2;i++)
		{
			printf("%d %d\n",seg[i],add[i]);
		}
	}
};
segtree seg;
int size=0;
//[0,size)

void add(int x)
{
	seg.updata(0,size,x);
	if(size>1) seg.updata(0,size-1,-x);
}
ll last()
{
	return seg.sum(0,size)-(size>1?seg.sum(0,size-1):0);
}
void erase()
{
	ll num=last();
	add(-num);
	size--;
}
double average()
{
	return (double) seg.sum(0,size)/size;
}

int main()
{
	int n;
	scanf("%d",&n);
	seg.init(5+n);
	size++;
	add(0);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;
			seg.updata(0,a+1,b);
		}
		else if(t==2)
		{
			int a;
			scanf("%d",&a);
			size++;
			add(a);
		}
		else erase();
		printf("%.8f\n",average());
	}
	return 0;
}