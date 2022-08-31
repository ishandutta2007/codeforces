#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <stack>
#define SIZE 100005
#define BB 1024*128*2
#define BT 20

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree_max
{
	int seg[BB];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=max(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
}smx[BT];
struct segtree_min
{
	int seg[BB];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=BB*100;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=min(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return BB*100;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
}smn[BT];
int A[SIZE];
int L[SIZE][BT];
int R[SIZE][BT];
int ans[SIZE];
P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		R[i][0]=i+A[i];
		L[i][0]=i-A[i];
	}
	for(int i=0;i+1<BT;i++)
	{
		smx[i].init(n+2);
		smn[i].init(n+2);
		for(int j=0;j<n;j++)
		{
			smx[i].add(j,R[j][i]);
			smn[i].add(j,L[j][i]);
		}
		for(int j=0;j<n;j++)
		{
			R[j][i+1]=smx[i].get(max(0,L[j][i]),min(n,R[j][i]+1));
			L[j][i+1]=smn[i].get(max(0,L[j][i]),min(n,R[j][i]+1));
			if(R[j][i]>=n)
			{
				R[j][i+1]=max(R[j][i+1],smx[i].get(0,R[j][i]-n+1)+n);
				L[j][i+1]=min(L[j][i+1],smn[i].get(0,R[j][i]-n+1)+n);
			}
			if(L[j][i]<0)
			{
				R[j][i+1]=max(R[j][i+1],smx[i].get(L[j][i]+n,n)-n);
				L[j][i+1]=min(L[j][i+1],smn[i].get(L[j][i]+n,n)-n);
			}
			R[j][i+1]=min(R[j][i+1],2*n-1);
			L[j][i+1]=max(L[j][i+1],-n+1);
		}
	}
	for(int i=0;i<n;i++)
	{
		int l=i,r=i;
		ans[i]=0;
		for(int j=BT-2;j>=0;j--)
		{
			int tr=smx[j].get(max(0,l),min(n,r+1));
			int tl=smn[j].get(max(0,l),min(n,r+1));
			if(r>=n)
			{
				tr=max(tr,smx[j].get(0,r-n+1)+n);
				tl=min(tl,smn[j].get(0,r-n+1)+n);
			}
			if(l<0)
			{
				tr=max(tr,smx[j].get(l+n,n)-n);
				tl=min(tl,smn[j].get(l+n,n)-n);
			}
			if(tr-tl<n-1)
			{
				ans[i]+=1<<j;
				r=tr,l=tl;
			}
		}
		if(n>1) ans[i]++;
		printf("%d ",ans[i]);
	}puts("");
	return 0;
}