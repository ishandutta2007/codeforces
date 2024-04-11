#include <bits/stdc++.h>
#define N 100010

typedef long long ll;

int n, q;
int fc[N], nc[N];
int p[N], w[N], size[N];
ll coe[N];
ll ans = 0;

namespace LCT {
	#define pa p[nd]
/*
	v: size
	dv: not preferred child
	w: weight
	coe: coefficient (sum w.coe = ans)
	dvw: sum dv.w
*/
	struct node {int c[2], p; ll v, dv, w, coe, dvw, tag;} nd[N];

	inline int dir(int x) {return !x[nd].p ? -1 : x == x[nd].pa.c[0] ? 0 : x == x[nd].pa.c[1] ? 1 : -1;}

	void fy(int x, ll v) {nd[x].coe += nd[x].dv * v; nd[x].tag += v;}

	void push_down(int x) {if (nd[x].tag) fy(nd[x].c[0], nd[x].tag), fy(nd[x].c[1], nd[x].tag), nd[x].tag = 0;}

	void pull_down(int x) {if (~dir(x)) pull_down(nd[x].p); push_down(x);}

	void update(int x) {
		int l = nd[x].c[0], r = nd[x].c[1];
		nd[x].v = nd[l].v + nd[r].v + nd[x].dv;
		nd[x].dvw = nd[l].dvw + nd[r].dvw + nd[x].dv * nd[x].w;
	}

	void rotate(int x) {
		int y = x[nd].p, d = !dir(x);
		nd[y[nd].c[!d] = x[nd].c[d]].p = y;
		x[nd].p = y[nd].p;
		if (~dir(y)) y[nd].pa.c[dir(y)] = x;
		nd[x[nd].c[d] = y].p = x;
		update(y);
	}

	void splay(int x) {for (pull_down(x); ~dir(x); rotate(x))
		if (~dir(nd[x].p)) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p); update(x);}

	int access(int x) {
		int y = 0;
		for (; x; y = x, x = nd[x].p) {
			splay(x); nd[x].dv += nd[x].c[1][nd].v;
			nd[x].c[1] = y; nd[x].dv -= nd[y].v; update(x);
		}
		return y;
	}

	void link(int x, int y) {splay(x); nd[x].p = y;}
}

void Do(int x, int lca, int y) {
	int &u = p[x], size_x;
	if (u == y) return;

	LCT::access(u); if (p[lca]) LCT::access(p[lca]);
	LCT::splay(x); size_x = LCT::nd[x].v;
	LCT::splay(u);
	LCT::nd[u].dv -= size_x; LCT::update(u);
	LCT::fy(u, -size_x * 2); ans -= LCT::nd[u].dvw * size_x * 2;

	LCT::access(y); if (p[lca]) LCT::access(p[lca]);
	LCT::splay(y);
	LCT::fy(y, size_x * 2); ans += LCT::nd[y].dvw * size_x * 2;
	LCT::nd[y].dv += size_x; LCT::update(y);

	u = y; LCT::link(x, y);
}

inline void link(int x, int px) {nc[x] = fc[px]; fc[px] = x;}

void dfs(int x) {
	int y; size[x] = 1;
	for (y = fc[x]; y; y = nc[y]) dfs(y), size[x] += size[y];
	coe[p[x]] -= (ll)size[x] * size[x];
	coe[x] += (ll)size[x] * size[x];
}

int main() {
	int i, x, y, lca, delta; char op[6]; double iv;
	scanf("%d", &n), iv = 1. / ((double)n * n);
	for (i = 2; i <= n; ++i) scanf("%d", p + i), link(i, p[i]);
	for (i = 1; i <= n; ++i) scanf("%d", w + i);
	dfs(1);
	for (i = 1; i <= n; ++i) ans += (ll)coe[i] * w[i];
	printf("%.12lg\n", ans * iv);
	for (i = 1; i <= n; ++i)
		LCT::nd[i].dv = size[i], LCT::nd[i].w = w[i], LCT::nd[i].coe = coe[i];
	for (i = 2; i <= n; ++i) LCT::link(i, p[i]);
	LCT::access(1);
	for (scanf("%d", &q); q; --q)
		if (scanf("%s%d%d", op, &x, &y), *op == 80) {
			assert(x != y);
			LCT::access(x); LCT::splay(x);
			lca = LCT::access(y); LCT::splay(y);
			if (lca == x) std::swap(x, y);
			Do(x, lca, y);
			printf("%.12lg\n", ans * iv);
		} else {
			LCT::access(x); LCT::splay(x);
			delta = y - w[x];
			LCT::nd[x].w = w[x] = y;
			printf("%.12lg\n", (ans += delta * LCT::nd[x].coe) * iv);
		}
	return 0;
}