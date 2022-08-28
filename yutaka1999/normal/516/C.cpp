#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define BT 256*1024*2
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

struct P
{
	int to,id;
	P(int to=0,int id=0):to(to),id(id){}
};
struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,ll x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
struct getmax
{
	ll que[SIZE],val[SIZE];
	int id[SIZE],to[SIZE];
	segtree S;
	int s,e,last;
	
	void init(int n)
	{
		s=e=0;
		last=n;
		S.init(last+1);
	}
	void add(ll x,int p)
	{
		while(s<e&&que[e-1]<=x) e--;
		if(s==e) to[e]=last;
		else to[e]=id[e-1]+1;
		val[e]=p+1==to[e]?-INF:seg.get(p+1,to[e]);
		id[e]=p;
		que[e]=x;
		S.add(e,val[e]+que[e]);
		e++;
	}
	ll get(int T)//T not
	{
		if(s==e) return -1;
		int l=s,r=e;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(to[m]>=T) l=m;
			else r=m;
		}
		ll ret=que[l]+(id[l]+1==T?-INF:seg.get(id[l]+1,T));
		if(l+1<e) ret=max(ret,S.get(l+1,e));
		return ret;
	}
};
getmax gt;
vector <P> query[SIZE];
ll dist[SIZE],sum[SIZE];
ll height[SIZE],ans[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&dist[i]);
		dist[i+n]=dist[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&height[i]);
		height[i+n]=height[i];
	}
	sum[0]=0;
	for(int i=1;i<2*n;i++) sum[i]=sum[i-1]+dist[i-1];
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if(a<=b) query[b+1].push_back(P(a+n-1,i));
		else query[b+1].push_back(P(a-1,i));
	}
	seg.init(2*n+2);
	gt.init(2*n+1);
	for(int i=2*n-1;i>=0;i--)
	{
		seg.add(i,sum[i]+2*height[i]);
		gt.add(-sum[i]+2*height[i],i);
		for(int j=0;j<query[i].size();j++)
		{
			P p=query[i][j];
			ans[p.id]=gt.get(p.to+1);
		}
	}
	for(int i=0;i<m;i++) printf("%I64d\n",ans[i]);
	return 0;
}