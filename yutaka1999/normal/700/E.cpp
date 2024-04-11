#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <cassert>
#include <functional>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=BT;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return BT;
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
	int left(int pos,int mn)//min[i,pos]<mnmax iT
	{
		int L,R,K=-1;
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(pos<m)
			{
				r=m;
				k=k*2+1;
			}
			else
			{
				if(seg[k*2+1]<mn)
				{
					L=l;
					R=m;
					K=k*2+1;
				}
				l=m;
				k=k*2+2;
			}
		}
		if(seg[k]<mn) return l;
		if(K==-1) return -1;
		l=L,r=R,k=K;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(seg[k*2+2]<mn)
			{
				l=m;
				k=k*2+2;
			}
			else
			{
				r=m;
				k=k*2+1;
			}
		}
		return l;
	}
	int right(int pos,int mn)//min[pos,i]<mnmin iT
	{
		int L,R,K=-1;
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(m<=pos)
			{
				l=m;
				k=k*2+2;
			}
			else
			{
				if(seg[k*2+2]<mn)
				{
					L=m;
					R=r;
					K=k*2+2;
				}
				r=m;
				k=k*2+1;
			}
		}
		if(seg[k]<mn) return l;
		if(K==-1) return mum-1;
		l=L,r=R,k=K;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(seg[k*2+1]<mn)
			{
				r=m;
				k=k*2+1;
			}
			else
			{
				l=m;
				k=k*2+2;
			}
		}
		return l;
	}
};
segtree s1,s2;
char str[SIZE];
int rnk[SIZE],sa[SIZE];
int lcp[SIZE];
int n;
PP tmp[SIZE];

void init()
{
	for(int i=0;i<n;i++) rnk[i]=str[i]-'a';
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=0;i<n;i++)
		{
			tmp[i]=PP(P(rnk[i],i+k<n?rnk[i+k]:-1),i);
		}
		sort(tmp,tmp+n);
		for(int i=0;i<n;)
		{
			int f=i;
			for(;i<n&&tmp[i].first==tmp[f].first;i++)
			{
				rnk[tmp[i].second]=f;
			}
		}
	}
	for(int i=0;i<n;i++) sa[rnk[i]]=i;
	int H=0;
	for(int i=0;i<n;i++)
	{
		if(H>0) H--;
		if(rnk[i]==n-1) continue;
		int to=sa[rnk[i]+1];
		while(i+H<n&&to+H<n&&str[i+H]==str[to+H]) H++;
		lcp[rnk[i]]=H;
	}
	s1.init(n+2);
	s2.init(n+2);
	//s1 : sa min
	//s2 : lcpmin
	for(int i=0;i<n;i++) s1.add(i,sa[i]);
	for(int i=0;i<n-1;i++) s2.add(i,lcp[i]);
	//for(int i=0;i<n;i++) printf("%d ",sa[i]);puts("");
	//for(int i=0;i<n-1;i++) printf("%d ",lcp[i]);puts("");
}
int ans;
int solve(int start)
{
	int ret=0;
	int to=start;
	while(to!=n-1)
	{
		int L=to-start+1;
		//LoT
		int A=s2.left(rnk[start]-1,L)+1;
		int B=s2.right(rnk[start],L);
		int mn=s1.get(A,B+1);
		if(mn>=n) break;
		int d=mn-start;
		int s=rnk[start],t=rnk[mn];
		if(s>t) swap(s,t);
		int mxl=s2.get(s,t);
		mxl=L+((mxl-L)/d)*d;
		ret+=(mxl-L)/d+1;
		to=start+mxl+d-1;
	}
	//printf(":");
	return ret;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",&str);
	init();
	ans=0;
	for(int i=0;i<n;i++)
	{
		s1.add(rnk[i],BT);
		ans=max(ans,solve(i));
	}
	printf("%d\n",ans+1);
	return 0;
}