#include <bits/stdc++.h>
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::vector <pr> vector;
const int N = 100054;

int n, q, LB;
int a[N];

struct node {
	vector pre, suf;
	ll v;
	node () {}
	node (int c) : v(c >= LB) {pre.EB(c, 1), suf.EB(c, 1);}
	inline ll operator ^ (const node &B) const {
		int m = suf.size(), i = m - 1, s = 0; ll ret = 0;
		for (const pr &e : B.pre) {
			for (; i >= 0 && (suf[i].first | e.first) >= LB; --i) s += suf[i].second;
			ret += (ll)s * e.second;
		}
		return ret;
	}
} x[N * 3];

inline void merge_seq(vector &ret, const vector &l, const vector &r) {
	int v; ret = l;
	for (const pr &e : r)
		if ((v = ret.back().first | e.first) == ret.back().first) ret.back().second += e.second;
		else ret.EB(v, e.second);
}

inline void update(node &ret, const node &l, const node &r) {
	ret.v = l.v + r.v + (l ^ r), merge_seq(ret.pre, l.pre, r.pre), merge_seq(ret.suf, r.suf, l.suf);
}

void build(int id, int L, int R) {
	if (L == R) {x[id] = node(a[L]); return;}
	segc; build(lc, L, M), build(rc, M + 1, R);
	update(x[id], x[lc], x[rc]);
}

void adj(int id, int L, int R, int h) {
	if (L == R) {x[id] = node(a[L]); return;}
	segc; h <= M ? adj(lc, L, M, h) : adj(rc, M + 1, R, h);
	update(x[id], x[lc], x[rc]);
}

node range(int id, int L, int R, int ql, int qr) {
	if (ql <= L && R <= qr) return x[id];
	segc;
	if (qr <= M) return range(lc, L, M, ql, qr);
	if (ql > M) return range(rc, M + 1, R, ql, qr);
	node ret, l(range(lc, L, M, ql, M)), r(range(rc, M + 1, R, M + 1, qr));
	return update(ret, l, r), ret;
}

int main() {
	int i, u, v, op;
	scanf("%d%d%d", &n, &q, &LB);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (build(1, 1, n); q; --q)
		if (scanf("%d%d%d", &op, &u, &v), op == 1)
			a[u] == v || (a[u] = v, adj(1, 1, n, u), 0);
		else
			printf("%lld\n", range(1, 1, n, u, v).v);
	return 0;
}