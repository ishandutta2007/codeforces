#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=100005, B=120;
namespace SGT{
	#define ls ch[u][0]
	#define rs ch[u][1]
	int ch[N*B][2], cnt[N*B], tot;
	void ins(int &u, int l, int r, int p, int v)
	{
		if(!u) u=++tot;
		cnt[u]+=v;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(p<=mid) ins(ls, l, mid, p, v);
		else ins(rs, mid+1, r, p, v);
	}
	int merge(int x, int y, int l, int r)
	{
		if(!x||!y) return x|y;
		int u=++tot;
		cnt[u]=cnt[x]+cnt[y];
		if(l==r) return u;
		int mid=(l+r)>>1;
		ls=merge(ch[x][0], ch[y][0], l, mid);
		rs=merge(ch[x][1], ch[y][1], mid+1, r);
		return u;
	}
	int findpr(int u, int u1, int l, int r, int p)
	{
		if(!u) return 0;
		if(r<=p&&!(cnt[u]-cnt[u1])) return 0;
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(p>mid)
		{
			int v=findpr(rs, ch[u1][1], mid+1, r, p);
			if(v) return v;
		}
		int v=findpr(ls, ch[u1][0], l, mid, p);
		return v;
	}
	int findnx(int u, int u1, int l, int r, int p)
	{
		if(!u) return 0;
		if(l>=p&&!(cnt[u]-cnt[u1])) return 0;
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(p<=mid)
		{
			int v=findnx(ls, ch[u1][0], l, mid, p);
			if(v) return v;
		}
		int v=findnx(rs, ch[u1][1], mid+1, r, p);
		return v;
	}
}
using namespace SGT;
int n, r0, rt[N], sz[N], rans[N];
int stk[N], top;
vector<int> e[N];
void pdfs(int u, int fa)
{
	sz[u]=1;
	for(int v:e[u]) if(v!=fa)
	{
		pdfs(v, u);
		sz[u]+=sz[v];
	}
	ins(rt[u], 1, n, sz[u], 1);
	for(int v:e[u]) if(v!=fa) rt[u]=merge(rt[u], rt[v], 1, n);
}
void dfs(int u, int fa)
{
	int mx=n-sz[u], mx1=0, id=0, mn=(u==r0?0x3f3f3f3f:mx);
	for(int v:e[u]) if(v!=fa)
	{
		if(sz[v]>mx) mx1=mx, mx=sz[v], id=v;
		else if(sz[v]>mx1) mx1=sz[v];
		mn=std::min(mn, sz[v]);
	}
	int a, b, lim=(mx-mn)/2;
	if(!id) a=rt[r0], b=rt[u];
	else a=rt[id], b=0;
	rans[u]=mx;
	if(mn<=n)
	{
		int v=findpr(a, b, 1, n, lim);
		int p=std::lower_bound(stk+1, stk+top+1, lim+sz[u], std::greater<int>())-stk;
		if(!id&&p<=top) v=std::max(v, stk[p]-sz[u]);
		if(v) rans[u]=std::min(rans[u], std::max(mx-v, mn+v));
		v=findnx(a, b, 1, n, lim);
		if(!id&&p>1) v=std::min((v?v:0x3f3f3f3f), stk[p-1]-sz[u]);
		if(v) rans[u]=std::min(rans[u], std::max(mx-v, mn+v));
		rans[u]=std::max(rans[u], mx1);
	}
	ins(rt[r0], 1, n, sz[u], -1);
	stk[++top]=sz[u];
	for(int v:e[u]) if(v!=fa)
		dfs(v, u);
	--top;
	ins(rt[r0], 1, n, sz[u], 1);
}
int main()
{
	scanf("%d", &n);
	if(n==1) return puts("0"), 0;
	for(int i=1, x, y; i<=n; ++i)
	{
		scanf("%d%d", &x, &y);
		if(x>y) std::swap(x, y);
		if(!x) r0=y;
		else e[x].pb(y), e[y].pb(x);
	}
	pdfs(r0, 0);
	dfs(r0, 0);
	for(int i=1; i<=n; ++i) printf("%d\n", rans[i]);
	return 0;
}