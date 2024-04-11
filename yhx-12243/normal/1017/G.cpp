#include <bits/stdc++.h>

const int N = 100054;

int n, q;
int p[N], fc[N], nc[N];
int dep[N], size[N];
int cnt = 0, o[N], id[N], eid[N], prf[N], top[N];

inline int max(const int x, const int y) {return x < y ? y : x;}
inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag) push_down(x[id], x[lc], x[rc])

	struct node {
		int v, max, origin_max; bool tag;
	} x[N * 3];

	inline void update(node &ret, const node &l, const node &r) {ret.max = max(l.max + r.v, r.max), ret.v = l.v + r.v;}

	inline void cover(node &ret) {ret.v = 0, ret.max = ret.origin_max, ret.tag = true;}

	inline void push_down(node &ret, node &l, node &r) {cover(l), cover(r), ret.tag = false;}

	void build(int id, int L, int R) {
		if (L == R) {x[id].v = 0, x[id].origin_max = x[id].max = dep[o[L]]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		update(x[id], x[lc], x[rc]);
	}

	void add(int id, int L, int R, int h, int v) {
		if (L == R) {x[id].v += v, x[id].max += v; return;}
		segc; exist_pd; h <= M ? add(lc, L, M, h, v) : add(rc, M + 1, R, h, v);
		update(x[id], x[lc], x[rc]);
	}

	void clear(int id, int L, int R, int ql, int qr)  {
		if (ql <= L && R <= qr) return cover(x[id]);
		segc; exist_pd;
		if (ql <= M) clear(lc, L, M, ql, qr);
		if (qr > M) clear(rc, M + 1, R, ql, qr);
		update(x[id], x[lc], x[rc]);
	}

	node range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id];
		segc; exist_pd;
		if (qr <= M) return range(lc, L, M, ql, qr);
		if (ql > M) return range(rc, M + 1, R, ql, qr);
		node ret, l(range(lc, L, M, ql, M)), r(range(rc, M + 1, R, M + 1, qr));
		return update(ret, l, r), ret;
	}
}

void dfs_wt(int x) {
	int y, &z = prf[x]; size[x] = !fc[x];
	for (y = fc[x]; y; y = nc[y])
		dep[y] = dep[x] + 1, dfs_wt(y),
		size[x] += size[y], size[y] > size[z] ? z = y : 0;
}

void dfs_hld(int x, int r) {
	int y; o[++cnt] = x, eid[x] = id[x] = cnt, top[x] = r;
	if (!prf[x]) return; dfs_hld(prf[x], r);
	for (y = fc[x]; y; y = nc[y]) if (!top[y]) dfs_hld(y, y);
	eid[x] = cnt;
}

int weight(int u) {
	int x = top[u]; ST::node r; r.v = 0, r.max = INT_MIN;
	for (; x; u = p[x], x = top[u])
		ST::update(r, ST::range(1, 1, n, id[x], id[u]), r);
	return r.max;
}

inline void reweight(int x) {
	int diff = weight(x) - dep[x];
	if (diff > 0) ST::add(1, 1, n, id[x], -diff);
}

int main() {
	int i, x, op;
	scanf("%d%d", &n, &q);
	for (i = 2; i <= n; ++i) scanf("%d", &x), link(i, x);
	dfs_wt(1), dfs_hld(1, 1);
	for (ST::build(1, 1, n); q; --q)
		switch (scanf("%d%d", &op, &x), op) {
			case 1: ST::add(1, 1, n, id[x], 1); break;
			case 2: ST::clear(1, 1, n, id[x], eid[x]), reweight(x); break;
			case 3: puts(weight(x) > dep[x] ? "black" : "white"); break;
		}
	return 0;
}