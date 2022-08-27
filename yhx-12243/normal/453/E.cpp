#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef std::tuple <int, int, int> tuple;
typedef std::map <int, int> map;
typedef map::iterator mit;
const int N = 100054;

struct pony {
	int I, v, max;
	friend std::istream & operator >> (std::istream &in, pony &B) {return in >> B.I >> B.max >> B.v;}
} a[N];

int n, q, m = 0, max_time;
ll ans[N];
vector <tuple> at[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace CTree {
	map C;

	inline void init() {C.emplace(0, -1), C.emplace(n, 0);}

	mit split(int pos) {
		mit it = C.lower_bound(pos), jt = it;
		return it->first == pos ? it : C.emplace_hint(it, pos, (--jt)->second);
	}

	void modify(int l, int r, int t, int id) {
		mit it = split(l), jt = split(r), i, j;
		for (j = it; (i = j++) != jt; )
			if (~i->second) at[j->first].EB(t - i->second, 1, id), at[i->first].EB(t - i->second, -1, id);
			else at[j->first].EB(~t, 1, id), at[i->first].EB(~t, -1, id);
		C.erase(it, jt), C.emplace(l, t);
	}
}

namespace BIT {
	ll x0[N], x1[N];

	inline void reset() {memset(x0, 0, sizeof x0), memset(x1, 0, sizeof x1);}
	inline void add(int h, ll v, ll *x) {for (; h <= max_time; h |= h + 1) x[h] += v;}
	inline ll sum(int h, ll *x) {ll s = 0; for (; h >= 0; h &= h + 1, --h) s += x[h]; return s;}
	inline ll query(int t) {return down(t, max_time), sum(t, x0) + sum(t, x1) * t;}
}

int main() {
	int i, t, l, r, coef, id;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	cin >> q, CTree::init();
	for (i = 0; i < q; ++i) cin >> t >> l >> r, CTree::modify(--l, r, t, i);
	max_time = 1;
	for (i = 0; i < n; ++i) if (a[i].v) up(max_time, (a[i].max + a[i].v - 1) / a[i].v);
	for (i = 0; ; ++i) {
		for (const tuple &e : at[i])
			if (std::tie(t, coef, id) = e, ~t >> 31) ans[id] += coef * BIT::query(t);
		if (i == n) break;
		if (a[i].v)
			BIT::add(0, a[i].v, BIT::x1),
			t = (a[i].max + a[i].v - 1) / a[i].v,
			BIT::add(t, a[i].max - a[i].v * t, BIT::x1),
			BIT::add(t + 1, a[i].v * (t - 1) - a[i].max, BIT::x1),
			BIT::add(t, (t - 1ll) * (a[i].v * t - a[i].max), BIT::x0),
			BIT::add(t + 1, (ll)t * (a[i].max - a[i].v * (t - 1)), BIT::x0);
	}
	max_time = 1, BIT::reset();
	for (i = 0; i < n; ++i) if (a[i].v) up(max_time, (a[i].max - a[i].I + a[i].v - 1) / a[i].v);
	for (i = 0; ; ++i) {
		for (const tuple &e : at[i])
			if (std::tie(t, coef, id) = e, t >> 31) ans[id] += coef * BIT::query(~t);
		if (i == n) break;
		BIT::add(0, a[i].I, BIT::x0);
		if (a[i].v)
			a[i].max -= a[i].I,
			BIT::add(0, a[i].v, BIT::x1),
			t = (a[i].max + a[i].v - 1) / a[i].v,
			BIT::add(t, a[i].max - a[i].v * t, BIT::x1),
			BIT::add(t + 1, a[i].v * (t - 1) - a[i].max, BIT::x1),
			BIT::add(t, (t - 1ll) * (a[i].v * t - a[i].max), BIT::x0),
			BIT::add(t + 1, (ll)t * (a[i].max - a[i].v * (t - 1)), BIT::x0);
	}
	for (i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}