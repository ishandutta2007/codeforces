#include <bits/stdc++.h>
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1

typedef std::pair <double, int> pr;
const int N = 200054;

int n, q, C;
int w[N], c[N], d[N];

struct node {
	pr incr, decr; double v;
	node () {}
	node (int id) {
		int _w = w[id], _d = std::min(d[id], c[id]), _c = c[id];
		v = (double)(_w * _d) / (_d + _c);
		incr = pr(_d == _c ? 0. : (double)(_w * _c) / (double)((_d + _c) * (_d + _c + 1ll)), id);
		decr = pr(_d ? (d[id] > _c ? 0. : (double)(_w * _c) / (double)((_d + _c) * (_d + _c - 1ll))) : INFINITY, id);
	}
} x[N * 4];

inline void update(node &ret, const node &l, const node &r) {ret.incr = std::max(l.incr, r.incr), ret.decr = std::min(l.decr, r.decr), ret.v = l.v + r.v;}

void build(int id, int L, int R) {
	if (L == R) {x[id] = node(L); return;}
	segc; build(lc, L, M), build(rc, M + 1, R);
	update(x[id], x[lc], x[rc]);
}

void adj(int id, int L, int R, int h) {
	if (L == R) {x[id] = node(L); return;}
	segc; h <= M ? adj(lc, L, M, h) : adj(rc, M + 1, R, h);
	update(x[id], x[lc], x[rc]);
}

int main() {
	int i, j, delta;
	scanf("%d%d%d", &n, &C, &q);
	for (i = 1; i <= n; ++i) scanf("%d", w + i);
	for (i = 1; i <= n; ++i) scanf("%d", c + i);
	for (build(1, 1, n); C; --C) ++d[ i = x[1].incr.second ], adj(1, 1, n, i);
	for (; q; --q) {
		scanf("%d%d", &delta, &i), delta = (1 - delta) | 1;
		c[i] += delta, adj(1, 1, n, i);
		for (; x[1].incr.first > x[1].decr.first; )
			++d[ i = x[1].incr.second ], --d[ j = x[1].decr.second ],
			adj(1, 1, n, i), adj(1, 1, n, j);
		printf("%.12lg\n", x[1].v);
	}
	return 0;
}