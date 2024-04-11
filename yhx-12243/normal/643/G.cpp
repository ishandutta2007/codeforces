#include <bits/stdc++.h>

const int N = 150054, G = 100;

int n, p, B;
int a[N], rdd[N];
int arr[G], ans[G];

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int x[N * 4];
	int ori[N * 4], cnt;

	void build(int id, int L, int R) {
		if (L == R) {x[id] = a[L]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id] = (x[lc] == x[rc] ? x[lc] : 0);
	}

	void cover(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr && x[id]) {ori[cnt++] = x[id], x[id] = v; return;}
		segc; x[id] && (x[lc] = x[rc] = x[id]);
		if (ql <= M) cover(lc, L, M, ql, qr, v);
		if (qr > M) cover(rc, M + 1, R, ql, qr, v);
		x[id] = (x[lc] == x[rc] ? x[lc] : 0);
	}

	int get_value(int id, int L, int R, int h) {
		if (x[id]) return x[id];
		segc; x[id] && (x[lc] = x[rc] = x[id]);
		return h <= M ? get_value(lc, L, M, h) : get_value(rc, M + 1, R, h);
	}
}

namespace pb_ds {
	struct node {int v, lc, rc;} x[20030731];

	int cnt = 0, root[N];

	inline void up(node &ret, int lw, int rw) {ret.v = (~ret.lc ? x[ret.lc].v : lw) + (~ret.rc ? x[ret.rc].v : rw);}

	int add(int id, int L, int R, int h, int v) {
		if (!id) id = ++cnt; else if (!~id) id = ++cnt, x[id].lc = x[id].rc = -1, x[id].v = R - L + 1;
		if (L == R) return x[id].v += v, id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
		return up(x[id], M - L + 1, R - M), id;
	}

	int del(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return v;
		if (!id) id = ++cnt; else if (!~id) id = ++cnt, x[id].lc = x[id].rc = -1, x[id].v = R - L + 1;
		int M = (L + R - 1) >> 1;
		if (ql <= M) x[id].lc = del(x[id].lc, L, M, ql, qr, v);
		if (qr > M) x[id].rc = del(x[id].rc, M + 1, R, ql, qr, v);
		up(x[id], M - L + 1, R - M);
		return id;
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (!id) return 0; if (!~id) return std::min(R, qr) - std::max(L, ql) + 1;
		if (ql <= L && R <= qr) return x[id].v;
		int M = (L + R - 1) >> 1, s = 0;
		if (ql <= M) s += range(x[id].lc, L, M, ql, qr);
		if (qr > M) s += range(x[id].rc, M + 1, R, ql, qr);
		return s;
	}

	void init() {for (int i = 1; i <= n; ++i) root[a[i]] = add(root[a[i]], 1, n, i, 1);}
	inline void clear(int x, int l, int r) {root[x] = del(root[x], 1, n, l, r, 0);}
	inline void cover(int x, int l, int r) {root[x] = del(root[x], 1, n, l, r, -1);}
	inline int get_times(int x, int l, int r) {return range(root[x], 1, n, l, r);}
}

int main() {
	int i, j, op, l, r, x, lim, rem, q0, q, t, tot;
	std::mt19937 gen(20030731);
	scanf("%d%d%d", &n, &q, &p);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	ST::build(1, 1, n), pb_ds::init();
	for (q0 = 1; q0 <= q; ++q0) {
		if (scanf("%d%d%d", &op, &l, &r), l > r) {op == 1 && scanf("%*d"); continue;}
		if (op == 1) {
			scanf("%d", &x), ST::cnt = 0, ST::cover(1, 1, n, l, r, x);
			std::sort(ST::ori, ST::ori + ST::cnt);
			ST::cnt = std::unique(ST::ori, ST::ori + ST::cnt) - ST::ori;
			for (i = 0; i < ST::cnt; ++i) pb_ds::clear(ST::ori[i], l, r);
			pb_ds::cover(x, l, r);
		} else {
			rem = r - l + 1, lim = (rem * p + 99) / 100, tot = 0;
			if (rem < 75) {
				for (i = l; i <= r; ++i)
					arr[i - l] = ST::get_value(1, 1, n, i);
				std::sort(arr, arr + rem), arr[rem] = -1;
				for (j = 0, i = 1; i <= rem; ++i)
					if (arr[i] != arr[j]) i - j >= lim && (ans[tot++] = arr[j]), j = i;
			} else
				for (t = 75; t > 0 && rem > 0; --t) {
					i = gen() % (r - l + 1) + l;
					x = ST::get_value(1, 1, n, i);
					if (rdd[x] == q0) continue; rdd[x] = q0;
					j = pb_ds::get_times(x, l, r);
					if (j >= lim) ans[tot++] = x;
					rem -= j;
				}
			std::sort(ans, ans + tot), printf("%d", tot);
			for (i = 0; i < tot; ++i) printf(" %d", ans[i]);
			putchar(10);
		}
	}
	return 0;
}