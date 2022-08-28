#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#define SIZE 500005
#define BT 1024*512*2
#define INF 100000000000000005LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
struct segtree
{
	ll seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=INF,add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		//assert(l<r);
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=v,add[k]+=v;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=min(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	void reset(int v)
	{
		update(v,v+1,-INF);
	}
	ll get(int a,int b,int k,int l,int r)
	{
		//assert(l<r);
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr)+add[k];
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <edge> vec[SIZE];
vector <PP> query[SIZE];
ll ans[SIZE];
int sz;
int n,q;

void dfs1(int v=0,int bef=0)
{
	//printf("%d %d\n",v,bef);
	int f=sz;
	sz++;
	if(vec[v].size()==0) seg.reset(v);
	for(int i=0;i<query[v].size();i++)
	{
		P p=query[v][i].first;
		int l=p.first,r=p.second;
		r=min(r,v);
		if(l<=r) ans[query[v][i].second]=min(ans[query[v][i].second],seg.get(l,r+1));
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		int x=sz;
		seg.update(0,x,e.cost);
		dfs1(e.to,e.cost);
		seg.update(0,x,-e.cost);
	}
	seg.update(f,sz,bef);
}
void dfs2(int v=0,int bef=0)
{
	int f=sz;
	for(int i=((int) vec[v].size())-1;i>=0;i--)
	{
		edge e=vec[v][i];
		int x=sz;
		if(x<n) seg.update(x,n,e.cost);
		dfs2(e.to,e.cost);
		if(x<n) seg.update(x,n,-e.cost);
	}
	sz--;
	if(vec[v].size()==0) seg.reset(v);
	for(int i=0;i<query[v].size();i++)
	{
		P p=query[v][i].first;
		int l=p.first,r=p.second;
		l=max(l,v);
		if(l<=r) ans[query[v][i].second]=min(ans[query[v][i].second],seg.get(l,r+1));
	}
	seg.update(sz,f,bef);
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<n;i++)
	{
		int p,w;
		scanf("%d %d",&p,&w);p--;
		vec[p].push_back(edge(i,w));
	}
	for(int i=0;i<q;i++)
	{
		int v,l,r;
		scanf("%d %d %d",&v,&l,&r);v--,l--,r--;
		query[v].push_back(PP(P(l,r),i));
		ans[i]=INF;
	}
	sz=0;
	seg.init(n+2);
	dfs1();
	sz=n;
	seg.init(n+2);
	dfs2();
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}