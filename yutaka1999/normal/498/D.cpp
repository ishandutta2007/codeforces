#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define MX 60
#define BT 1024*128*2

using namespace std;

struct segtree
{
	int seg[BT][MX];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			for(int j=0;j<MX;j++)
			{
				seg[i][j]=0;
			}
		}
	}
	void add(int k,int x)
	{
		k+=mum-1;
		for(int j=0;j<MX;j++)
		{
			if(j%x==0) seg[k][j]=2;
			else seg[k][j]=1;
		}
		while(k>0)
		{
			k=(k-1)/2;
			for(int j=0;j<MX;j++)
			{
				seg[k][j]=seg[k*2+1][j]+seg[k*2+2][(j+seg[k*2+1][j])%MX];
			}
		}
	}
	int get(int a,int b,int k,int l,int r,int t)
	{
		if(b<=l||r<=a) return t;
		if(a<=l&&r<=b) return t+seg[k][t%MX];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2,t);
			return get(a,b,k*2+2,(l+r)/2,r,vl);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum,0);
	}
};
segtree seg;
char str[5];

int main()
{
	int n;
	scanf("%d",&n);
	seg.init(n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		seg.add(i,a);
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",&str);
		if(str[0]=='C')
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;
			seg.add(a,b);
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;b--;
			printf("%d\n",seg.get(a,b));
		}
	}
	return 0;
}