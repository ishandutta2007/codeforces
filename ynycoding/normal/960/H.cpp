#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=100005;

namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	ll tag[N<<2], s0[N<<2], s1[N<<2], s2[N<<2];
	inline void addp(int id, int v)
	{
		s2[id]=s2[id]+2ll*s1[id]*v+1ll*v*v*s0[id];
		s1[id]=s1[id]+1ll*v*s0[id];
		tag[id]+=v;
	}
	inline void pushdown(int id)
	{
		addp(lid, tag[id]);
		addp(rid, tag[id]);
		tag[id]=0;
	}
	inline void upt(int id)
	{
		s1[id]=s1[lid]+s1[rid];
		s2[id]=s2[lid]+s2[rid];
	}
	void build(int id, int l, int r)
	{
		s0[id]=r-l+1;
//		printf("%d %d %d\n", id, l, r);
		if(l==r) return;
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
	}
	void add(int id, int l, int r, int l1, int r1, int v)
	{
		if(l1<=l&&r<=r1) { addp(id, v); return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(l1<=mid) add(lid, l, mid, l1, r1, v);
		if(r1>mid) add(rid, mid+1, r, l1, r1, v);
		upt(id);
	}
}
using namespace SGT;
int n, m, q, a[N], v[N], C;
ll rans[N];
int is[N];
vector<int> e[N], sid[N], fid[N], qr[N];
int dep[N], sz[N], son[N], up[N], pa[N], in[N], cnt;
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1;
	sz[u]=1;
	pa[u]=fa;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs1(int u, int fa, int top)
{
//	printf("u %d\n", u);
	in[u]=++cnt;
	up[u]=top;
	if(son[u]) dfs1(son[u], u, top);
	for(int v:e[u]) if(v!=fa&&v!=son[u])
	{
		dfs1(v, u, v);
	}
}
void add(int u, int v)
{
	while(u)
	{
		int p=up[u];
//		printf("add %d %d\n", in[p], in[u]);
		add(1, 1, n, in[p], in[u], v);
		u=pa[p];
	}
}
void solve(int c)
{
	for(int x:sid[c]) add(x, v[c]);
	for(int x:qr[c])
	{
		if(x<0)
		{
			x=-x;
			rans[x]=1ll*C*C*n+s2[1]-2ll*s1[1]*C;
		}
		else
		{
			add(x>>1, ((x&1)?-v[c]:v[c]));
		}
	}
	for(int x:fid[c]) add(x, -v[c]);
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &q, &C);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), sid[a[i]].pb(i);
	for(int i=2, x; i<=n; ++i) scanf("%d", &x), e[x].pb(i), e[i].pb(x);
	for(int i=1; i<=m; ++i) scanf("%d", v+i);
	build(1, 1, n);
	dfs(1, 0);
	dfs1(1, 0, 1);
	for(int i=1, op, x, y; i<=q; ++i)
	{
		scanf("%d%d", &op, &x);
		if(op==1)
		{
			scanf("%d", &y);
			qr[a[x]].pb(x<<1|1);
			qr[y].pb(x<<1);
			a[x]=y;
		}
		else
		{
			qr[x].pb(-i);
			is[i]=1;
		}
	}
	for(int i=1; i<=n; ++i) fid[a[i]].pb(i);
	for(int i=1; i<=m; ++i) solve(i);
	for(int i=1; i<=q; ++i) if(is[i]) printf("%.10Lf\n", (long double)rans[i]/n);
	return 0;
}