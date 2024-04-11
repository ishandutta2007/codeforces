#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 800005
#define BT 1024*1024*2

using namespace std;
typedef pair <int,int> P;

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
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
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
	int right(int pos)
	{
		int gt=get(pos,mum);
		int l=0,r=mum,k=0;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(m<=pos||seg[k*2+2]==gt)
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
};
segtree seg;
vector <int> vx;
vector <P> query[SIZE];
int L[SIZE],R[SIZE];
int imos[SIZE];
P pos[SIZE];
int A[SIZE];
int ans[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		vx.push_back(A[i]);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;
		vx.push_back(b);
		query[a].push_back(P(b,i));
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			p.first=lower_bound(vx.begin(),vx.end(),p.first)-vx.begin();
			ans[p.second]=1;
			query[i][j]=p;
		}
	}
	seg.init(vx.size()+2);
	int lis=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			if(p.first>0) ans[p.second]+=seg.get(0,p.first);
		}
		int gt=0;
		if(A[i]>0) gt=seg.get(0,A[i]);
		L[i]=gt+1;
		lis=max(lis,gt+1);
		seg.add(A[i],gt+1);
	}
	seg.init(vx.size()+2);
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			if(p.first+1<vx.size()) ans[p.second]+=seg.get(p.first+1,vx.size());
		}
		int gt=0;
		if(A[i]+1<vx.size()) gt=seg.get(A[i]+1,vx.size());
		R[i]=gt+1;
		lis=max(lis,gt+1);
		seg.add(A[i],gt+1);
	}
	seg.init(n+2);
	for(int i=0;i<n;i++) pos[i]=P(A[i],-i);
	sort(pos,pos+n);
	for(int i=n-1;i>=0;i--)
	{
		int v=-pos[i].second;
		int gt=seg.get(v,n);
		if(L[v]+gt==lis)
		{
			int p=seg.right(v);
			if(gt==0) p=n;
			imos[v+1]++;
			imos[p]--;
		}
		seg.add(v,R[v]);
		if(R[v]==lis)
		{
			imos[0]++;
			imos[v]--;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i>0) imos[i]+=imos[i-1];
		int vl=imos[i]==0?lis-1:lis;
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			ans[p.second]=max(ans[p.second],vl);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}