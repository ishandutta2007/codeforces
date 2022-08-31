#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <complex>
#define SIZE 300005
#define PI 3.1415926535897932384626
#define BT 512*1024*2

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex <ld> P;

struct segtree
{
	P seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=P(1,0);
			add[i]=P(0,0);
		}
	}
	void pass(int k)
	{
		seg[k*2+1]*=seg[k];
		add[k*2+1]*=seg[k];
		seg[k*2+2]*=seg[k];
		add[k*2+2]*=seg[k];
		add[k*2+1]+=add[k];
		add[k*2+2]+=add[k];
		seg[k]=P(1,0);
		add[k]=P(0,0);
	}
	void pl(int a,int b,int k,int l,int r,P v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) add[k]+=v;
		else
		{
			pass(k);
			pl(a,b,k*2+1,l,(l+r)/2,v);
			pl(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void pl(int a,int b,P v)
	{
		pl(a,b,0,0,mum,v);
	}
	void mul(int a,int b,int k,int l,int r,P v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]*=v;
			add[k]*=v;
		}
		else
		{
			pass(k);
			mul(a,b,k*2+1,l,(l+r)/2,v);
			mul(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void mul(int a,int b,P v)
	{
		mul(a,b,0,0,mum,v);
	}
	P get(int k)
	{
		k+=mum-1;
		P ret=add[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret*=seg[k];
			ret+=add[k];
		}
		return ret;
	}
};
segtree seg;
int n,m;

void print(int k)
{
	P g=seg.get(k);
	printf("%.10f %.10f\n",(double) g.real(),(double) g.imag());
}
int main()
{
	scanf("%d %d",&n,&m);
	seg.init(n+5);//i_W
	for(int i=0;i<=n;i++) seg.pl(i,i+1,P(i,0));
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);y--;
		P p=seg.get(y),q=seg.get(y+1);
		if(x==1)
		{
			double Z=(double) z/abs(q-p);
			seg.pl(y+1,n+1,(q-p)*P(Z,0));
		}
		else
		{
			ld Z=(ld) (-z)*PI/180.00;
			P rt=P(cos(Z),sin(Z));
			seg.mul(y+1,n+1,rt);
			seg.pl(y+1,n+1,(P(1,0)-rt)*p);
		}
		print(n);
	}
	return 0;
}