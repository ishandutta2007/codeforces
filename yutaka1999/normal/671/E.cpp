#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define BT 1024*128*2
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=INF;
	}
	void ins(int k,ll x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
	int right(int a,int b,int k,int l,int r,ll lim)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b)
		{
			if(seg[k]>lim) return -1;
			if(l+1==r) return l;
			if(seg[k*2+2]<=lim) return right(a,b,k*2+2,(l+r)/2,r,lim);
			return right(a,b,k*2+1,l,(l+r)/2,lim);
		}
		else
		{
			int vr=right(a,b,k*2+2,(l+r)/2,r,lim);
			if(vr!=-1) return vr;
			return right(a,b,k*2+1,l,(l+r)/2,lim);
		}
	}
	int right(ll lim,int p)//limAp
	{
		if(p==0) return -1;
		return right(0,p,0,0,mum,lim);
	}
};
segtree seg,seg2;
vector <int> vec[SIZE];
int W[SIZE],G[SIZE];
ll sum[SIZE],sum2[SIZE];
ll pl[SIZE],mn[SIZE];
ll score2[SIZE];
ll dep[SIZE];
int nxt[SIZE],to[SIZE];
int vertex[SIZE];
P pos[SIZE];
ll memo[SIZE];
int n;
ll k;
int ans;
int sz;

void dfs(int v)
{
	seg2.ins(sz,min(mn[v],score2[v])+dep[v]);
	vertex[sz]=v;
	memo[sz++]=dep[v];
	int p=lower_bound(memo,memo+sz,dep[v]-k)-memo;
	//p O
	seg2.ins(p,mn[vertex[p]]+dep[vertex[p]]);
	int last=p==0?n+1:vertex[p-1];
	ll q=seg2.get(p,sz);
	to[v]=seg.right(q+k-dep[v],last);
	seg2.ins(p,min(mn[vertex[p]],score2[vertex[p]])+dep[vertex[p]]);
	ans=max(ans,to[v]-v+1);
	for(int i=0;i<vec[v].size();i++) dfs(vec[v][i]);
	sz--;
	seg2.ins(sz,INF);
	//printf("%d : %d %d %d : %d %lld\n",v,nxt[v],to[v],pq,p,q);
}
int main()
{
	scanf("%d %lld",&n,&k);n--;
	for(int i=0;i<n;i++) scanf("%d",&W[i]);
	for(int i=0;i<=n;i++) scanf("%d",&G[i]);
	seg.init(n+2);
	for(int i=0;i<=n;i++)
	{
		if(i==0) sum[i]=-G[0];
		else sum[i]=sum[i-1]+W[i-1]-G[i];
		seg.ins(i,sum[i]);
	}
	for(int i=n;i>=0;i--)
	{
		if(i==n) sum2[i]=-G[n];
		else sum2[i]=sum2[i+1]+W[i]-G[i];
	}
	//to[i] : inKv
	//Ai<j Asum2[i]-sum2[j]>0 <=> sum2[i]>sum2[j] j
	int sz=0;
	for(int i=n;i>=0;i--)
	{
		while(sz>0&&pos[sz-1].first>=sum2[i]) sz--;
		if(sz==0)
		{
			nxt[i]=n+1;
			pl[i]=dep[i]=0;
		}
		else
		{
			nxt[i]=pos[sz-1].second;
			pl[i]=sum2[i]-pos[sz-1].first;
			dep[i]=pl[i]+dep[nxt[i]];
			vec[nxt[i]].push_back(i);
		}
		mn[i]=seg.get(i,nxt[i]);
		score2[i]=sum[nxt[i]-1]-pl[i];
		pos[sz++]=P(sum2[i],i);
	}
	//seg.init(n+3);//g
	//for(int i=0;i<=n;i++) seg.ins(i,sum[i]);
	seg2.init(n+3);
	ans=0;
	for(int i=0;i<=n;i++)
	{
		if(nxt[i]==n+1)
		{
			sz=0;
			dfs(i);
		}
	}
	//for(int i=0;i<=n;i++) printf("%d : %d %d\n",i,nxt[i],to[i]);
	printf("%d\n",ans);
	return 0;
}