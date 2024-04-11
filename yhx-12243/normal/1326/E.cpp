#include <bits/stdc++.h>

const int N = 300054;

int n;
int p[N], ip[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int v, b, tag;} x[N * 4];

	void build(int id, int L, int R) {
		if (L == R) {x[id].v = p[L]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id].v = max(x[lc].v, x[rc].v);
	}

	void del(int id, int L, int R, int h) {
		if (L == R) {x[id].v = 0; return;}
		segc; h <= M ? del(lc, L, M, h) : del(rc, M + 1, R, h);
		x[id].v = max(x[lc].v, x[rc].v);
	}

	int gmax(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		segc, s = 0;
		if (ql <= M) up(s, gmax(lc, L, M, ql, qr));
		if (qr > M) up(s, gmax(rc, M + 1, R, ql, qr));
		return s;
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].b += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		x[id].b = min(x[lc].b, x[rc].b) + x[id].tag;
	}

	int find(int id, int L, int R, int h, int cv = 0) {
		if (cv + x[id].b > 0) return n;
		if (L == R) return L;
		segc; cv += x[id].tag;
		if (h > M) return find(rc, M + 1, R, h, cv);
		int p = find(lc, L, M, h, cv);
		return p == n ? find(rc, M + 1, R, M + 1, cv) : p;
	}
}

int main() {
	int i, x, y, ri;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", p + i), ip[p[i]] = i;
	ST::build(1, 1, n), printf("%d", ST::x[1].v);
	for (i = 1; i < n; ++i) {
		scanf("%d", &x),
		ri = ST::find(1, 1, n, x),
		y = ST::gmax(1, 1, n, 1, ri),
		assert(y), y = ip[y],
//		fprintf(stderr, "%d affect %d\n", x, y);
		ST::del(1, 1, n, y),
		ST::add(1, 1, n, x, n, -1),
		ST::add(1, 1, n, y, n, 1),
		printf(" %d", ST::x[1].v);
	}
	return putchar(10), 0;
}