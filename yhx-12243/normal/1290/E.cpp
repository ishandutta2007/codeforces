#include <bits/stdc++.h>

typedef long long ll;
const int N = 150054, INF = 0x3f3f3f3f;

int n;
int a[N], b[N];
ll ans[N];

inline void down(int &x, const int y) {x < y ? x = y : 0;}
inline void up(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h > 0; h &= h - 1) s += x[h]; return s;}
	void add(int h, int v) {for (; h <= n; h |= h - 1, ++h) x[h] += v;}
	void init() {memset(x, 0, (n + 1) << 2);}
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].t) push_down(x[id], x[lc], x[rc])

	struct node {int v, c, s, t;} x[N * 4];

	ll global_sum;

	void update(node &ret, const node &l, const node &r) {
		if (l.v == r.v) ret.v = l.v, ret.c = l.c + r.c, ret.s = max(l.s, r.s);
		else if (l.v < r.v) ret.v = r.v, ret.c = r.c, ret.s = max(l.v, r.s);
		else ret.v = l.v, ret.c = l.c, ret.s = max(l.s, r.v);
	}

	void push_down(node &ret, node &l, node &r) {
		bool left_gt = l.v >= r.v, right_gt = l.v <= r.v;
		if (left_gt) l.v += ret.t, l.t += ret.t;
		if (right_gt) r.v += ret.t, r.t += ret.t;
		ret.t = 0;
	}

	void build(int id, int L, int R) {
		x[id].v = x[id].s = -INF, x[id].c = x[id].t = 0;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	inline void init() {global_sum = 0, build(1, 1, n);}

	void adj(int id, int L, int R, int h, int v) {
		if (L == R) {x[id].v = v, x[id].c = 1; return;}
		segc; exist_pd;
		h <= M ? adj(lc, L, M, h, v) : adj(rc, M + 1, R, h, v);
		update(x[id], x[lc], x[rc]);
	}

	void min(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr && x[id].s < v) {
			if (v < x[id].v)
				global_sum -= (ll)x[id].c * BIT::sum(x[id].v),
				x[id].t += v - x[id].v,
				global_sum += (ll)x[id].c * BIT::sum(x[id].v = v);
			return;
		}
		segc; exist_pd;
		if (ql <= M) min(lc, L, M, ql, qr, v);
		if (qr > M) min(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), b[a[i]] = i, ans[i] = -i;
	for (j = 0; j != 2; ++j)
		for (BIT::init(), ST::init(), i = 1; i <= n; ++i) {
			ST::adj(1, 1, n, b[i], n);
			if (b[i] != 1) ST::min(1, 1, n, 1, b[i] - 1, b[i] - 1);
			ans[i] += ST::global_sum += i - BIT::sum(b[i]);
			BIT::add(b[i], 1), b[i] = n - b[i] + 1;
		}
	for (i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
	return 0;
}