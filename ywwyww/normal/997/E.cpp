#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>

const int N=120010;
typedef std::pair<int,int> pii;
typedef long long ll;
int n,q;
namespace seg
{
	pii s1[300010];
	ll s2[300010];
	int t1[300010];
	int t2[300010];
#define ls (p<<1)
#define rs ((p<<1)|1)
#define mid ((L+R)>>1)
	void mt(int p)
	{
		if(s1[ls].first==s1[rs].first)
			s1[p]=pii(s1[ls].first,s1[ls].second+s1[rs].second);
		else if(s1[ls].first<s1[rs].first)
			s1[p]=s1[ls];
		else
			s1[p]=s1[rs];
		s2[p]=s2[ls]+s2[rs];
	}
	void build(int p,int L,int R)
	{
		s1[p].first=0;
		s1[p].second=R-L+1;
		if(L==R)
			return;
		build(ls,L,mid);
		build(rs,mid+1,R);
		mt(p);
	}
	void add1(int p,int v)
	{
		t1[p]+=v;
		s1[p].first+=v;
	}
	void add2(int p,int v)
	{
		t2[p]+=v;
		s2[p]+=(ll)v*s1[p].second;
	}
	void push(int p)
	{
		if(t1[p])
		{
			add1(ls,t1[p]);
			add1(rs,t1[p]);
			t1[p]=0;
		}
		if(t2[p])
		{
			if(s1[ls].first<=s1[rs].first)
				add2(ls,t2[p]);
			if(s1[rs].first<=s1[ls].first)
				add2(rs,t2[p]);
			t2[p]=0;
		}
	}
	void add(int p,int l,int r,int v,int L,int R)
	{
		if(l<=L&&r>=R)
		{
			add1(p,v);
			return;
		}
		push(p);
		if(l<=mid)
			add(ls,l,r,v,L,mid);
		if(r>mid)
			add(rs,l,r,v,mid+1,R);
		mt(p);
	}
	ll query(int p,int l,int r,int L,int R)
	{
		if(l<=L&&r>=R)
			return s2[p];
		push(p);
		ll res=0;
		if(l<=mid)
			res+=query(ls,l,r,L,mid);
		if(r>mid)
			res+=query(rs,l,r,mid+1,R);
		return res;
	}
}
struct zjtakioi2019
{
	int f[N];
	int a[N];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
	int find(int x)
	{
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void insert(int x,int v)
	{
		seg::add(1,x,x,v,1,n);
		a[x]=v;
		while(f[x]>1&&a[x]>a[f[x]-1])
		{
			seg::add(1,f[f[x]-1],f[x]-1,a[x]-a[f[x]-1],1,n);
			f[x]=f[f[x]-1];
		}
	}
}
f1,f2;
int a[N];
ll ans[N];
std::vector<pii> g[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("cf997e.in","r",stdin);
	freopen("cf997e.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	int x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		g[y].push_back(pii(x,i));
	}
	f1.init(n);
	f2.init(n);
	seg::build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		f1.insert(i,a[i]);
		f2.insert(i,-a[i]);
		seg::add(1,1,i,-1,1,n);
		seg::add2(1,1);
		for(auto v:g[i])
			ans[v.second]=seg::query(1,v.first,i,1,n);
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}