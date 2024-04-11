#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz64 __builtin_ctzll
using std::cin;
using std::cout;
using std::string;
using std::vector;

typedef unsigned long long u64;
typedef std::pair <u64, u64> pr;
const int N = 50054, M = 5000054;

int n, m, q, V, lgV, aid;
u64 R, v[M];
pr a[N], b[N], o[N];
vector <pr> qs[N], o_[N], a_[N];
bool ans[N], alive[M];

struct BIT {
	int x[M];

	inline int sum(int h) {
		int s = 0; for (; h >= 0; h &= h + 1, --h) s += x[h]; return s;
	}
	inline void add(int h, int v) {
		for (; h < V; h |= h + 1) x[h] += v;
	}
	inline int kth(int k) {
		int i, l = -1, r;
		for (i = lgV; i >= 0; --i)
			if ((r = (1 << i) + l) < V && x[r] < k) k -= x[l = r];
		return l + 1;
	}
	inline int succ(int h) {return kth(sum(h - 1) + 1);}
} S, T;

namespace dsu {
	int p[M];

	inline void init() {std::iota(p, p + V, 0);}

	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

	inline bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (p[x] = y, false);
	}
}

vector <pr> divide(u64 L, u64 R) {
	static pr res[256];
	int cl, cr, l = 0, r = 256; vector <pr> ret;
	for (; L != R; ) {
		cl = ctz64(L), cr = ctz64(R);
		if (cl < cr)
			res[l++] = pr(L, (L | (L - 1)) + 1), L = (L | (L - 1)) + 1;
		else
			res[--r] = pr(R & (R - 1), R), R &= R - 1;
	}
	ret.assign(res, res + l), ret.insert(ret.end(), res + r, res + 256);
	return ret;
}

inline int bel(u64 x) {return std::upper_bound(v, v + V, x) - v - 1;}

namespace graph {
	vector <int> G[M];

	inline void addedge(int u, int v) {G[u].EB(v), G[v].EB(u);}
}

void init(int id) {
	u64 L = v[id], R = v[id + 1], Lx, Rx;
	int w = ctz64(R - L), i, l, r;
	for (i = w; i < n; ++i) {
		Lx = L ^ (1ull << i), Rx = Lx + (R - L);
		l = bel(Lx), r = bel(Rx - 1);
		if (l == r) graph::addedge(id, l);
	}
}

void insert(int id) {
	for (const int v : graph::G[id]) if (alive[v]) dsu::test(id, v, true);
	alive[id] = true;
}

void insert_bundle(const vector <pr> &set) {
	assert(!set.empty());
	int i, L = bel(set.front().first), R = bel(set.back().first);
	for (i = L; i <= R; ++i) insert(i);
}

void query(vector <pr> &set) {
	int u, v;
	std::reverse(set.begin(), set.end());
	for (const pr &e : set) u = bel(e.first), v = bel(e.second), ans[aid++] = dsu::test(u, v);
}

int main() {
	int i; u64 l, r; string op;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q, R = 1ull << n;
	for (i = 0; i < q; ++i)
		if (cin >> op >> l >> r, op == "block") a[m++] = pr(l, r);
		else qs[m].EB(l, r);
	for (i = 0; i < m; ++i) b[i] = a[i];
	std::sort(b, b + m);
	for (r = q = i = 0; i < m; ++i) {
		if (r < b[i].first) o[q++] = pr(r, b[i].first);
		r = b[i].second + 1;
	}
	if (r < R) o[q++] = pr(r, R);
	for (i = 0; i < q; ++i) o_[i] = divide(o[i].first, o[i].second);
	for (i = 0; i < m; ++i) a_[i] = divide(a[i].first, a[i].second + 1);
	for (i = 0; i < q; ++i) std::transform(o_[i].begin(), o_[i].end(), v + V, [] (const pr &e) {return e.first;}), V += o_[i].size();
	for (i = 0; i < m; ++i) std::transform(a_[i].begin(), a_[i].end(), v + V, [] (const pr &e) {return e.first;}), V += a_[i].size();
	std::sort(v, v + V), v[V] = R;
//	for (i = 0; i <= V; ++i) fprintf(stderr, "v[%d] = [%llu, %llu)\n", i, v[i], v[i + 1]);
	dsu::init(), lgV = lg2(V);

	for (i = 0; i < V; ++i) init(i);

	for (i = 0; i < q; ++i) insert_bundle(o_[i]);
	query(qs[m]);
	for (i = m - 1; i >= 0; --i) insert_bundle(a_[i]), query(qs[i]);
	for (i = aid - 1; i >= 0; --i) cout << int(ans[i]) << '\n';
	return 0;
}