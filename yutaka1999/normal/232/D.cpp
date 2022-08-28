#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define INF 1000000005
#define BT 256*1024*2

using namespace std;
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
		for(int i=0;i<mum*2;i++) seg[i]=-1;
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
	int left(int s,int mn)
	{
		if(s<0) return s;
		int l=0,r=mum,k=0;
		int L=0,R=mum,K=-1;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(s<m)
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
		while(L+1<R)
		{
			int m=(L+R)/2;
			if(seg[K*2+2]<mn)
			{
				L=m;
				K=K*2+2;
			}
			else
			{
				R=m;
				K=K*2+1;
			}
		}
		return L;
	}
	int right(int s,int mn)
	{
		int l=0,r=mum,k=0;
		int L=0,R=mum,K=-1;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(m<=s)
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
		if(K==-1) return -1;
		while(L+1<R)
		{
			int m=(L+R)/2;
			if(seg[K*2+1]<mn)
			{
				R=m;
				K=K*2+1;
			}
			else
			{
				L=m;
				K=K*2+2;
			}
		}
		return L;
	}
};
struct BIT
{
	int bit[SIZE];
	int n;
	
	void init(int m)
	{
		n=m;
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit;
segtree seg;
int diff[SIZE],imos[SIZE];
int rank[SIZE],sa[SIZE];
int lcp[SIZE];
int fl[SIZE],fr[SIZE];
int ans[SIZE];
vector <int> QL[SIZE],QR[SIZE];
PP pos[SIZE];

int get(int s,int t)
{
	return imos[t]-(s==0?0:imos[s-1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	int now;
	scanf("%d",&now);
	n--;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		diff[i]=t-now;
		diff[i+n+1]=now-t;
		now=t;
	}
	diff[n]=INF;
	int sz=2*n+1;
	for(int i=0;i<sz;i++) rank[i]=diff[i];
	for(int k=1;k<=sz;k<<=1)
	{
		for(int i=0;i<sz;i++)
		{
			pos[i]=PP(P(rank[i],i+k<sz?rank[i+k]:-INF),i);
		}
		sort(pos,pos+sz);
		for(int i=0;i<sz;)
		{
			int s=i;
			for(;i<sz&&pos[i].first==pos[s].first;i++)
			{
				rank[pos[i].second]=s;
			}
		}
	}
	for(int i=0;i<sz;i++) sa[rank[i]]=i;
	for(int i=0;i<sz;i++) imos[i]=sa[i]<=n?0:1;
	for(int i=1;i<sz;i++) imos[i]+=imos[i-1];
	int H=0;
	for(int i=0;i<sz;i++)
	{
		if(H>0) H--;
		if(rank[i]==sz-1) continue;
		int tg=sa[rank[i]+1];
		while(i+H<sz&&tg+H<sz&&diff[i+H]==diff[tg+H]) H++;
		lcp[rank[i]]=H;
	}
	lcp[sz-1]=0;
	seg.init(sz+2);
	for(int i=0;i<sz;i++) seg.add(i,lcp[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--;r--;
		int len=r-l;
		int left=seg.left(rank[l]-1,len);
		int right=seg.right(rank[l],len);
		if(right==-1) right=sz-1;
		left++;
		fl[i]=left;
		fr[i]=right;
		if(l==r) ans[i]=n;
		else
		{
			if(l-len>0) QL[l-len-1].push_back(i);
			if(r+1<n) QR[r+1].push_back(i);
		}
	}
	bit.init(sz+2);
	for(int i=n-1;i>=0;i--)
	{
		bit.add(rank[i+n+1]+1,1);
		for(int j=0;j<QR[i].size();j++)
		{
			int id=QR[i][j];
			ans[id]+=bit.get(fl[id]+1,fr[id]+1);
		}
	}
	bit.init(sz+2);
	for(int i=0;i<n;i++)
	{
		bit.add(rank[i+n+1]+1,1);
		for(int j=0;j<QL[i].size();j++)
		{
			int id=QL[i][j];
			ans[id]+=bit.get(fl[id]+1,fr[id]+1);
		}
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}