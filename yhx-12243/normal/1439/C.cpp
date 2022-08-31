#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054;

int n, q;
int a[N];

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag) push_down(x[id], x[lc], x[rc], M - L + 1, R - M)
	struct node {int l, r; ll v; int tag;} x[530000*2];

	void build(int id, int L, int R) {
		if (L == R) {x[id].l = x[id].r = x[id].v = a[L]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id].l = x[lc].l, x[id].r = x[rc].r,
		x[id].v = x[lc].v + x[rc].v;
	}

	inline void cover(node &ret, int v, int w) {
		ret.l = ret.r = ret.tag = v, ret.v = (ll)v * w;
	}

	inline void push_down(node &ret, node &l, node &r, int lw, int rw) {
		cover(l, ret.tag, lw), cover(r, ret.tag, rw), ret.tag = 0;
	}

	void gmax(int id, int L, int R, int h, int v) {
		if (x[id].r >= v) return;
		segc; exist_pd;
		if (h <= M) gmax(lc, L, M, h, v);
		else if (h >= R && x[id].l <= v) return cover(x[id], v, R - L + 1);
		else gmax(lc, L, M, h, v), gmax(rc, M + 1, R, h, v);
		x[id].l = x[lc].l, x[id].r = x[rc].r,
		x[id].v = x[lc].v + x[rc].v;
	}

	ll range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		segc; exist_pd;
		ll s = 0;
		if (ql <= M) s += range(lc, L, M, ql, qr);
		if (qr > M) s += range(rc, M + 1, R, ql, qr);
		return s;
	}

	int bisect(int v) {
		int id = 1, L = 1, R = n;
		if (v < x[id].r) return n + 1;
		for (; L < R; ) {
			segc; exist_pd;
			if (v < x[lc].r) id = rc, L = M + 1;
			else id = lc, R = M;
		}
		return L;
	}

	int bisect_sum(ll v) {
		int id = 1, L = 1, R = n;
		if (x[id].v <= v) return n;
		for (; L < R; ) {
			segc; exist_pd;
			if (v < x[lc].v) id = lc, R = M;
			else v -= x[lc].v, id = rc, L = M + 1;
		}
		return L - 1;
		
	}
}

int solve(int s, int V) {
	int t, ans = 0; ll pre;
	for (; ; ) {
		s = std::max(s, ST::bisect(V));
		if (s == n + 1) return ans;
		pre = (s ? ST::range(1, 1, n, 1, s - 1) : 0);
//		fprintf(stderr, "pre[%d] = %lld\n", s - 1, pre);
		t = ST::bisect_sum(V + pre);
		V -= ST::range(1, 1, n, 1, t) - pre;
//		fprintf(stderr, "pre[%d] = %lld\n", t, ST::range(1,1,n,1,t));
//		fprintf(stderr, "[%d, %d] (s = %lld)\n", s, t, ST::range(1, 1, n, 1, t) - pre);
		ans += t - s + 1;
		s = t + 1;
	}
}

int main() {
	int i, op, x, y;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 1; i <= n; ++i) cin >> a[i];
	ST::build(1, 1, n);
	for (; q; --q)
		if (cin >> op >> x >> y, op == 1) {
			ST::gmax(1, 1, n, x, y);
		} else cout << solve(x, y) << '\n';
	return 0;
}