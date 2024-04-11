#include <cstdio>
#include <set>
#include <algorithm>
using std::set;
const int N=200005;
int n, q, p[N], c0, c1, cs[N], rp[N];
namespace SGT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	int tag[N<<2], mn[N<<2];
	inline void upt(int u)
	{
		mn[u]=std::min(mn[ls], mn[rs]);
	}
	inline void addp(int u, int v)
	{
		tag[u]+=v, mn[u]+=v;
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			addp(ls, tag[u]);
			addp(rs, tag[u]);
			tag[u]=0;
		}
	}
	void build(int u, int l, int r)
	{
		if(l==r)
		{
			mn[u]=cs[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r);
		upt(u);
	}
	void add(int u, int l, int r, int l1, int r1, int v)
	{
		if(l1<=l&&r<=r1)
		{
			addp(u, v);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(u);
		if(l1<=mid) add(ls, l, mid, l1, r1, v);
		if(r1>mid) add(rs, mid+1, r, l1, r1, v);
		upt(u);
	}
	int ask(int u, int l, int r, int p)
	{
		if(l==r) return mn[u];
		int mid=(l+r)>>1;
		pushdown(u);
		if(p<=mid) return ask(ls, l, mid, p);
		return ask(rs, mid+1, r, p);
	}
	int find(int u, int l, int r)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		pushdown(u);
		if(mn[ls]==mn[u]) return find(ls, l, mid);
		return find(rs, mid+1, r);
	}
}
using namespace SGT;
set<int> st0, st1;
inline int calc(int x) { return x>n+1?1:x<=n?-1:0; }
inline void rins(set<int> &s, int x, int &c)
{
	s.insert(x);
	if(s.size()>1)
	{
		auto it=s.find(x);
		int nx=next(it)==s.end()?*s.begin():*next(it);
		int pr=it==s.begin()?*prev(s.end()):*prev(it);
		if(p[nx]==p[pr]+1) --c;
		if(p[x]==p[pr]+1) ++c;
		if(p[nx]==p[x]+1) ++c;
	}
}
inline void rdel(set<int> &s, int x, int &c)
{
	if(s.size()>1)
	{
		auto it=s.find(x);
		int nx=next(it)==s.end()?*s.begin():*next(it);
		int pr=it==s.begin()?*prev(s.end()):*prev(it);
		if(p[nx]==p[pr]+1) ++c;
		if(p[x]==p[pr]+1) --c;
		if(p[nx]==p[x]+1) --c;
	}
	s.erase(x);
}
inline void del(int x)
{
	if(p[x]<=n+1) rdel(st0, x, c0);
	if(p[x]>=n+1) rdel(st1, x, c1);
}
inline void ins(int x)
{
	rp[p[x]]=x;
	if(p[x]<=n+1) rins(st0, x, c0);
	if(p[x]>=n+1) rins(st1, x, c1);
}
// inline int dis(int x, int y) { return x>y?y-x+2*n+1:y-x; }
inline void solve(void)
{
	if(ask(1, 1, 2*n+1, rp[n+1])!=mn[1])
	{
		int p=find(1, 1, 2*n+1);
		printf("%d\n", p==2*n+1?0:p);
	}
	else
	{
		if(n==1||(c0==n&&c1==n)) puts("-1");
		else if(c0<n) printf("%d\n", rp[n+1]==2*n+1?0:rp[n+1]);
		else printf("%d\n", rp[n+1]-1);
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=2*n+1; ++i) scanf("%d", p+i), ins(i), cs[i]=cs[i-1]+calc(p[i]);
	build(1, 1, 2*n+1);
	for(int i=1, x, y; i<=q; ++i)
	{
		scanf("%d%d", &x, &y);
		if(x>y) std::swap(x, y);
		del(x), del(y);
		if(calc(p[y])!=calc(p[x])) add(1, 1, 2*n+1, x, y-1, calc(p[y])-calc(p[x]));
		std::swap(p[x], p[y]);
		ins(x), ins(y);
		solve();
	}
	return 0;
}