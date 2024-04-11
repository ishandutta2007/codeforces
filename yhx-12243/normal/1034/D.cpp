#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::map <int, int> map;
typedef map::iterator mit;
typedef std::vector <pr> vector;
const int N = 600054;

int n, K, z, cur_root;
int cic[N];
vector O[N], *now;
pr a[N];

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int x[1050000];

	void add(int id, int L, int R, int h, int v) {
		if (x[id] += v, L == R) return;
		segc; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
	}

	int bisect(int id, int L, int R, int lim) {
		if (assert(lim), x[id] < lim) return 0;
		for (; L < R; ) {
			segc; id = (x[rc] >= lim ? (L = M + 1, rc) : (R = M, lim -= x[rc], lc));
		}
		return L;
	}
}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h; h &= h - 1) s += x[h]; return s;}
	void add(int h, int v) {for (; h <= n; h |= h - 1, ++h) x[h] += v;}
	int kth(int k) {
		int l = 0, r, i;
		for (i = lg2(n); ~i; --i) if ((r = l + (1 << i)) <= n && x[r] < k) k -= x[l = r];
		return ++l;
	}
}

namespace pb_ds {
	ll x[N], X[N];

	ll sum(int h, ll *x) {ll s = 0; for (; h; h &= h - 1) s += x[h]; return s;}
	void add(int h, ll v, ll *x) {for (; h <= n; h |= h - 1, ++h) x[h] += v;}

	inline void add(int h, int v) {add(1, v, x), add(h + 1, -v, x), add(h + 1, (ll)h * -v, X);}
	inline ll prefix(int h) {return sum(h, x) * h - sum(h, X);}
}

inline void add_op(int h, int v) {if (h) now->EB(h, v);}

namespace CTree {
	map C;

	mit split(int pos) {
		mit it = C.lower_bound(pos), jt = it;
		return it->first == pos ? it : C.emplace_hint(it, pos, (--jt)->second);
	}

	void modify(int l, int r, int v) {
		mit it = split(l), jt = split(r), i, j;
		for (j = it; (i = j++) != jt; add_op(i->second, DC::D[i->first].first - DC::D[j->first].first));
		C.erase(it, jt), C.emplace(l, v);
		add_op(v, DC::D[r].first - DC::D[l].first);
	}

	void init() {C.emplace(0, 0), C.emplace(z - 1, 0);}
}

ll count(int lim) {
	int r; ll ret = 0;
	memset(BIT::x, 0, sizeof BIT::x);
	for (r = 1; r <= n; ++r) {
		for (const pr &e : O[r]) BIT::add(n + 1 - e.first, e.second);
		ret += cic[r] = n + 1 - BIT::kth(lim);
	}
	return ret;
}

int main() {
	int i, l, r, L, R, M; ll K0, ans = 0;
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; ++i) scanf("%d%d", &l, &r), DC::D[i] = pr(l, i), DC::D[i + n] = pr(r, i + n);
	z = DC::Discretize(2 * n);
	for (i = 0; i < n; ++i) a[i + 1] = pr(DC::F[i], DC::F[i + n]);
	CTree::init();
	for (r = 1; r <= n; ++r) now = O + r, CTree::modify(a[r].first, a[r].second, r);
	for (L = 0, R = 1000000007; L < R; count(M = (L + R + 1) / 2) < K ? R = M - 1 : L = M);
	K0 = count(L);
	for (r = 1; r <= n; ++r) {
		for (const pr &e : O[r]) pb_ds::add(e.first, e.second);
		ans += pb_ds::prefix(cic[r]);
	}
	printf("%lld\n", ans - (K0 - K) * L);
	return 0;
}