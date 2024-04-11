#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 128*1024

using namespace std;
typedef long long int ll;

struct segtree
{
	int seg[SIZE*2],all[SIZE*2],add[SIZE*2];
	int n,mum;
	
	void init()
	{
		mum=1;
		while(mum<n) mum*=2;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=0;
			add[i]=0;
		}
		for(int i=mum-1;i<mum*2;i++) all[i]=1;
		for(int i=mum-2;i>=0;i--) all[i]=all[i*2+1]+all[i*2+2];
	}
	void make(int k)
	{
		seg[k]=0;
		if(add[k*2+1]==0) seg[k]+=seg[k*2+1];
		else seg[k]+=all[k*2+1]-seg[k*2+1];
		if(add[k*2+2]==0) seg[k]+=seg[k*2+2];
		else seg[k]+=all[k*2+2]-seg[k*2+2];
	}
	void updata(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) add[k]=1-add[k];
		else
		{
			updata(a,b,k*2+1,l,(l+r)/2);
			updata(a,b,k*2+2,(l+r)/2,r);
			make(k);
		}
	}
	int sum(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return add[k]==0?seg[k]:all[k]-seg[k];
		int v1=sum(a,b,k*2+1,l,(l+r)/2);
		int v2=sum(a,b,k*2+2,(l+r)/2,r);
		int len=min(b,r)-max(a,l);
		return add[k]==0?v1+v2:len-(v1+v2);
	}
	void updata(int a,int b)
	{
		updata(a,b,0,0,mum);
	}
	int sum(int a,int b)
	{
		return sum(a,b,0,0,mum);
	}
};
segtree seg[20];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<20;i++) seg[i].n=n,seg[i].init();
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<20;j++)
		{
			if(a>>j&1)
			{
				seg[j].updata(i,i+1);
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;b--;
			ll sum=0;
			for(int j=0;j<20;j++)
			{
				int s=seg[j].sum(a,b+1);
				sum+=(1LL<<j)*s;
			}
			printf("%I64d\n",sum);
		}
		else
		{
			int a,b,x;
			scanf("%d %d %d",&a,&b,&x);a--;b--;
			for(int j=0;j<20;j++)
			{
				if(x>>j&1)
				{
					seg[j].updata(a,b+1);
				}
			}
		}
	}
	return 0;
}