#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;

struct segtree
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
		seg[k]+=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			return get(a,b,k*2+1,l,(l+r)/2)+get(a,b,k*2+2,(l+r)/2,r);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
int cnt[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	seg.init(n+2);
	for(int i=0;i<n;i++)
	{
		cnt[i]=1;
		seg.add(i,1);
	}
	bool flip=false;
	int l=0,r=n;
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int g;
			scanf("%d",&g);
			if((!flip&&g*2<=r-l)||(flip&&g*2>r-l))
			{
				int zan=!flip?g:r-l-g;
				for(int j=0;j<zan;j++)
				{
					int p=l+j;
					int to=(l+zan)*2-1-p;
					cnt[to]+=cnt[p];
					seg.add(to,cnt[p]);
					cnt[p]=0;
				}
				l+=zan;
				flip=false;
			}
			else
			{
				int zan=!flip?r-l-g:g;
				for(int j=0;j<zan;j++)
				{
					int p=r-j-1;
					int to=(r-zan)*2-p-1;
					cnt[to]+=cnt[p];
					seg.add(to,cnt[p]);
					cnt[p]=0;
				}
				r-=zan;
				flip=true;
			}
		}
		else
		{
			int s,t;
			scanf("%d %d",&s,&t);
			if(!flip)
			{
				s+=l;
				t+=l;
			}
			else
			{
				s=r-s;
				t=r-t;
				swap(s,t);
			}
			printf("%d\n",seg.get(s,t));
		}
		//printf("%d %d %d\n",l,r,flip);
		//for(int i=0;i<n;i++) printf("%d ",cnt[i]);puts("");
	}
	return 0;
}