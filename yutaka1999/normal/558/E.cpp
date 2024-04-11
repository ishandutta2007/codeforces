#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define BT 1024*128*2
#define MX 26

using namespace std;

struct segtree
{
	int seg[BT],st[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			seg[i]=0;
			st[i]=-1;
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]=v*(r-l);
			st[k]=v;
		}
		else
		{
			if(st[k]!=-1)
			{
				st[k*2+1]=st[k*2+2]=st[k];
				seg[k*2+1]=seg[k*2+2]=st[k]*(r-l)/2;
				st[k]=-1;
			}
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			if(st[k]!=-1)
			{
				st[k*2+1]=st[k*2+2]=st[k];
				seg[k*2+1]=seg[k*2+2]=st[k]*(r-l)/2;
				st[k]=-1;
			}
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree alp[MX];
char str[SIZE];
int cnt[MX];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	scanf("%s",&str);
	for(int i=0;i<MX;i++) alp[i].init(n+2);
	for(int i=0;i<n;i++) alp[str[i]-'a'].update(i,i+1,1);
	for(int i=0;i<q;i++)
	{
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);l--;r--;
		for(int j=0;j<MX;j++)
		{
			cnt[j]=alp[j].get(l,r+1);
			alp[j].update(l,r+1,0);
		}
		if(k==1)
		{
			int now=l;
			for(int j=0;j<MX;j++)
			{
				if(cnt[j]>0)
				{
					alp[j].update(now,now+cnt[j],1);
					now+=cnt[j];
				}
			}
		}
		else
		{
			int now=l;
			for(int j=MX-1;j>=0;j--)
			{
				if(cnt[j]>0)
				{
					alp[j].update(now,now+cnt[j],1);
					now+=cnt[j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<MX;j++)
		{
			if(alp[j].get(i,i+1)==1)
			{
				printf("%c",'a'+j);
				break;
			}
		}
	}
	puts("");
	return 0;
}