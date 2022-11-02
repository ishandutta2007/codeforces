//by daifucong
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 500001
struct segment_tree
{
	#define lson(x) (x<<1)
	#define rson(x) (x<<1|1)
	int sumv[maxn<<2],lazy[maxn<<2],minv[maxn<<2],maxv[maxn<<2];
	inline void pushup(int p)
	{
		sumv[p]=sumv[lson(p)]+sumv[rson(p)];
		minv[p]=min(minv[lson(p)],minv[rson(p)]);
		maxv[p]=max(maxv[lson(p)],maxv[rson(p)]);
	}
	inline void setit(int p,int l,int r,int to)
	{
		minv[p]=maxv[p]=to;
		sumv[p]=(r-l+1)*to;
		lazy[p]=to;
	}
	inline void pushdown(int p,int l,int r)
	{
		if(lazy[p]==0) return;
		int mid=(l+r)>>1;
		setit(lson(p),l,mid,lazy[p]);
		setit(rson(p),mid+1,r,lazy[p]);
		lazy[p]=0;
	}
	inline void change(int p,int l,int r,int ql,int qr,int to)
	{
		if(to<=minv[p]) return;if(l>r) return;
		if(ql<=l&&qr>=r&&to>maxv[p]) return (void)setit(p,l,r,to);
		int mid=(l+r)>>1;pushdown(p,l,r);
		if(ql<=mid) change(lson(p),l,mid,ql,qr,to);
		if(qr>mid) change(rson(p),mid+1,r,ql,qr,to);
		pushup(p);
	}
	inline int querysum(int p,int l,int r,int ql,int qr)
	{
		if(ql<=l&&qr>=r) return sumv[p];
		int mid=(l+r)>>1,res=0;pushdown(p,l,r);
		if(ql<=mid) res+=querysum(lson(p),l,mid,ql,qr);
		if(qr>mid) res+=querysum(rson(p),mid+1,r,ql,qr);
		pushup(p);return res;
	}
}seg;
vector<pair<pair<int,int>,int> > v[maxn];
int n,A,B,C;
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&A,&B,&C);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
		v[C].push_back(make_pair(make_pair(1,a),b));
		v[c].push_back(make_pair(make_pair(1,a),B));
		v[c].push_back(make_pair(make_pair(a+1,A),b));
	}
	int res=0;
	for(int i=C;i>=1;i--)
	{
		for(int j=0;j<(int)v[i].size();j++) seg.change(1,1,A,v[i][j].first.first,v[i][j].first.second,v[i][j].second);
		res+=seg.querysum(1,1,A,1,A);
	}
	res=A*B*C-res;
	cout<<res;
}