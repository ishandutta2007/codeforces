#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define x first
#define y second
#define mp std::make_pair
#define pb push_back
#define N 300005
using std::pair;
using std::set;
using std::vector;
int n, k, a[N], b[N], mx, tag[N];
set<pair<pair<int, int>, int> > st;
vector<pair<pair<int, int>, int> > del, ins;
vector<pair<int, int> > op[N];
inline void insert(int l, int r, int col)
{
	auto it=st.lower_bound(mp(mp(l, r), 0));
	int tot=r-l;
	if(it!=st.begin()&&prev(it)->x.y>l)
	{
		auto pr=prev(it);
		if(pr->x.y>=r)
		{
			auto t=*pr;
			op[col].pb(mp(t.y+1, tot));
			st.insert(mp(mp(l, r), col));
			if(t.x.x<l) st.insert(mp(mp(t.x.x, l), t.y));
			if(t.x.y>r) st.insert(mp(mp(r, t.x.y), t.y));
			st.erase(t);
			return;
		}
		del.pb(*pr);
		if(pr->x.x<l) ins.pb(mp(mp(pr->x.x, l), pr->y));
		op[col].pb(mp(pr->y+1, pr->x.y - l));
		tot-=pr->x.y - l;
	}
	for(; it!=st.end()&&it->x.x <= r; ++it)
	{
		del.pb(*it);
		if(it->x.y<=r)
		{
			op[col].pb(mp(it->y+1, it->x.y - it->x.x));
			tot-=it->x.y - it->x.x;
		}
		else
		{
			op[col].pb(mp(it->y+1, r - it->x.x));
			tot-=r - it->x.x;
			ins.pb(mp(mp(r, it->x.y), it->y));
		}
	}
	op[col].pb(mp(1, tot));
	for(auto t:del) st.erase(t);
	for(auto t:ins) st.insert(t);
	del.clear();
	ins.clear();
	st.insert(mp(mp(l, r), col));
}
ll calc(int len)
{
	ll ret=0;
	std::fill(tag, tag+n+1, 0);
	for(int l=1, r=1, cur=0; r<=n; ++r)
	{
		for(auto t:op[r])
		{
			if(t.x<=l) cur+=t.y;
			else tag[t.x]+=t.y;
			tag[r+1]-=t.y;
		}
		while(l<r&&cur+tag[l+1]>=len) ++l, cur+=tag[l];
		if(cur>=len) ret+=l;
	}
	return ret;
}
ll sum[N], sum1[N];
ll _ask(int p) { ll ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
ll _ask1(int p) { ll ret=0; while(p) ret+=sum1[p], p-=p&(-p); return ret; }
inline void _add(int p, ll v) { while(p<=n) sum[p]+=v, p+=p&(-p); }
inline void _add1(int p, ll v) { while(p<=n) sum1[p]+=v, p+=p&(-p); }
inline ll askpr(int r) { return (r+1)*_ask(r)-_ask1(r); }
inline void addsuf(int p, int v) { _add(p, v), _add1(p, 1ll*p*v); }
inline ll ask(int l, int r) { return askpr(r)-askpr(l-1); }
inline void add(int l, int r, int v) { addsuf(l, v), addsuf(r+1, -v); }
ll calcans(int len)
{
	ll ret=0;
	std::fill(tag, tag+n+1, 0);
	for(int l=1, r=1, cur=0; r<=n; ++r)
	{
		for(auto t:op[r])
		{
			if(t.x<=l) cur+=t.y;
			else tag[t.x]+=t.y;
			tag[r+1]-=t.y;
			add(t.x, r, t.y);
		}
		while(l<r&&cur+tag[l+1]>=len) ++l, cur+=tag[l];
		if(cur>=len) ret+=ask(1, l);
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d%d", a+i, b+i), mx=std::max(b[i], mx);
	for(int i=1; i<=n; ++i) insert(a[i], b[i], i);
	
	int l=1, r=mx;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(calc(mid)>=k) l=mid;
		else r=mid-1;
	}
	ll ans=0;
	ans=calcans(l+1)+1ll*l*(k-calc(l+1));
	printf("%lld\n", ans);
	return 0;
}