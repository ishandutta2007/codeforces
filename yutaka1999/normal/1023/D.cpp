#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree2
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=max(ret,seg[k]);
		}
		return ret;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=max(seg[k],v);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
}seg2;
int left[SIZE],right[SIZE];
int A[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<q;i++) left[i]=n,right[i]=-1;
	int pos=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);A[i]--;
		if(A[i]>=0)
		{
			left[A[i]]=min(left[A[i]],i);
			right[A[i]]=max(right[A[i]],i);
		}
		else pos=i;
	}
	seg2.init(n+2);
	for(int i=0;i<q;i++)
	{
		if(left[i]<=right[i])
		{
			seg2.update(left[i],right[i]+1,i);
		}
	}
	for(int i=0;i<n;i++)
	{
		int v=seg2.get(i);
		if(A[i]!=-1&&v>A[i])
		{
			puts("NO");
			return 0;
		}
		v=max(v,0);
		A[i]=v;
	}
	bool X=false;
	for(int i=0;i<n;i++) if(A[i]==q-1) X=true;
	if(!X)
	{
		if(pos==-1)
		{
			puts("NO");
			return 0;
		}
		A[pos]=q-1;
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[i]+1);
	}puts("");
	return 0;
}