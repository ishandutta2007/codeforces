#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054;

int n, q;
int l[N], r[N];
char s[N], t[N];

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (~x[id].cov) push_down(x[id], x[lc], x[rc], M - L + 1, R - M)

	struct node {int v, cov;} x[530000];

	inline void push_down(node &ret, node &l, node &r, int lw, int rw) {
		l.cov = r.cov = ret.cov, l.v = ret.cov * lw, r.v = ret.cov * rw, ret.cov = -1;
	}

	void build(int id, int L, int R, char *s) {
		x[id].cov = -1;
		if (L == R) {x[id].v = s[L - 1] & 1; return;}
		segc; build(lc, L, M, s), build(rc, M + 1, R, s);
		x[id].v = x[lc].v + x[rc].v;
	}

	void adj(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v = (R - L + 1) * v, x[id].cov = v; return;}
		segc; exist_pd;
		if (ql <= M) adj(lc, L, M, ql, qr, v);
		if (qr > M) adj(rc, M + 1, R, ql, qr, v);
		x[id].v = x[lc].v + x[rc].v;
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		segc, s = 0; exist_pd;
		if (ql <= M) s += range(lc, L, M, ql, qr);
		if (qr > M) s += range(rc, M + 1, R, ql, qr);
		return s;
	}
}

void work() {
	int i, v, w;
	cin >> n >> q >> s >> t;
	for (i = 0; i < q; ++i) cin >> l[i] >> r[i];
	ST::build(1, 1, n, t);
	for (i = q - 1; i >= 0; --i) {
		v = ST::range(1, 1, n, l[i], r[i]), w = r[i] - l[i] + 1;
		if (2 * v == w) {cout << "NO\n"; return;}
		ST::adj(1, 1, n, l[i], r[i], 2 * v > w);
	}
	for (i = 1; i <= n; ++i)
		if ((s[i - 1] & 1) != ST::range(1, 1, n, i, i)) {cout << "NO\n"; return;}
	cout << "YES\n"; 
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}