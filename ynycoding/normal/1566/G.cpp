#include <cstdio>
#include <random>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f
#define ll long long
#define mp std::make_pair
using std::pair;
using std::set;
using std::map;
using std::multiset;
const int N=200005;
int n, m, q, x[N], y[N], w[N], top;
struct cmp{
	bool operator ()(int x, int y) { return w[x]==w[y]?x<y:w[x]<w[y]; }
};
ll rv[N];
set<int, cmp> st[N], rs;
multiset<ll> ts;
map<pair<int, int>, int> id;
int ok[N];
inline void ins(int x)
{
//	if(ok[x]==1) printf("ins %d\n", x);
	if((++ok[x])==2) rs.insert(x);
}
inline void del(int x)
{
//	if(ok[x]==2) printf("del %d\n", x);
	if((ok[x]--)==2) rs.erase(x);
}
inline void unfix(int x)
{
	auto it=st[x].begin();
	if(st[x].size()) del(*it), ++it;
	if(st[x].size()>1) del(*it), ++it;
	if(st[x].size()>2) del(*it), ++it;
	ts.erase(rv[x]);
}
inline void fix(int x)
{
	auto it=st[x].begin();
	if(st[x].size()) ins(*it), ++it;
	if(st[x].size()>1) ins(*it), ++it;
	if(st[x].size()>2) ins(*it), ++it;
	rv[x]=st[x].size()>2?1ll*w[*st[x].begin()]+w[*next(st[x].begin())]+w[*next(next(st[x].begin()))]:INF;
//	if(st[x].size()>2) printf("fa %d %d %d\n", *st[x].begin(), *next(st[x].begin()), *next(next(st[x].begin())));
//	printf("fix %d %d %lld\n", x, st[x].size(), rv[x]);
	ts.insert(rv[x]);
}
inline void solve(void)
{
	static int id[10], top;
	top=0;
	ll ans=ts.empty()?INF:*ts.begin();
//	for(ll x:ts) printf("%lld\n", x);
//	for(int x:rs)
//		printf("have %d %d %d\n", ::x[x], y[x], w[x]);
	for(int x:rs)
	{
		id[++top]=x;
		if(top==4) break;
	}
	for(int i=1; i<=top; ++i)
	{
		for(int j=i+1; j<=top; ++j)
		{
			int a=x[id[i]], b=y[id[i]], c=x[id[j]], d=y[id[j]];
			if(a!=c&&a!=d&&b!=c&&b!=d) ans=std::min(ans, 1ll*w[id[i]]+w[id[j]]);
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i)
	{
		++top;
		scanf("%d%d%d", x+top, y+top, w+top);
		if(x[top]>y[top]) std::swap(x[top], y[top]);
		id[mp(x[top], y[top])]=top;
		st[x[top]].insert(top);
		st[y[top]].insert(top);
	}
	for(int i=1; i<=n; ++i) fix(i);
	scanf("%d", &q);
	solve();
	for(int i=1, t, a, b; i<=q; ++i)
	{
		scanf("%d%d%d", &t, &a, &b);
		if(a>b) std::swap(a, b);
		if(!t)
		{
			int u=id[mp(a, b)];
			unfix(a), unfix(b);
			st[a].erase(u);
			st[b].erase(u);
			fix(a), fix(b);
		}
		else
		{
			++top;
			scanf("%d", w+top);
			x[top]=a, y[top]=b;
			id[mp(a, b)]=top;
			unfix(a), unfix(b);
			st[a].insert(top), st[b].insert(top);
			fix(a), fix(b);
		}
		solve();
	}
	return 0;
}