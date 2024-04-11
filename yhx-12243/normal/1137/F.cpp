#include <bits/stdc++.h>

const int N = 400054;

int n, q, E = 0, C;
int to[N], first[N], next[N];
int cnt = 0, o[N], p[N], max[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

namespace BIT {
	#define lowbit(x) (x & -x)
	int n, x[N];
	void init(int _n) {n = _n; for (int i = 1; i <= n; ++i) if (i + lowbit(i) <= n) x[i + lowbit(i)] += x[i];}
	void add(int h, int v) {for (; h <= n; h += lowbit(h)) x[h] += v;}
	int sum(int h) {int s = 0; for (; h; h -= lowbit(h)) s += x[h]; return s;}
}

namespace LCT {
	#define pa p[nd]
	struct node {bool rev; int v, cov, p, c[2];} nd[N];
	inline int dir(int x) {return !nd[x].p ? -1 : x == nd[x].pa.c[0] ? 0 : x == nd[x].pa.c[1] ? 1 : -1;}
	inline void reverse(int x) {x && (std::swap(nd[x].c[0], nd[x].c[1]), nd[x].rev = !nd[x].rev);}
	void push_down(int x) {nd[x].rev && (reverse(nd[x].c[0]), reverse(nd[x].c[1]), nd[x].rev = false);}
	int pull_down(int x) {int ret = (~dir(x) ? pull_down(nd[x].p) : x); return push_down(x), ret;}
	inline void update(int x) {const int l = nd[x].c[0], r = nd[x].c[1]; nd[x].v = (l ? nd[l].v : 0) + (r ? nd[r].v : 0) + 1;}
	void rotate(int x) {
		int y = nd[x].p, d = !dir(x);
		nd[nd[y].c[!d] = nd[x].c[d]].p = y;
		nd[x].p = nd[y].p;
		if (~dir(y)) nd[y].pa.c[dir(y)] = x;
		nd[nd[x].c[d] = y].p = x;
		update(y);
	}
	void splay(int x) {for (std::swap(nd[x].cov, nd[pull_down(x)].cov); ~dir(x); rotate(x))
		if (~dir(nd[x].p)) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p); update(x);}
	void access(int x) {
		for (int y = 0; x; y = x, x = nd[x].p) {
			splay(x);
			nd[x].c[1] ? BIT::add(nd[x].c[1][nd].cov = nd[x].cov, nd[x].c[1][nd].v - nd[x].v) : BIT::add(nd[x].cov, -nd[x].v);
			(nd[x].c[1] = y) && (nd[y].cov = 0), update(x);
		}
	}
	void make_root(int x) {access(x), splay(x), reverse(x);}
}

inline void addedge(int u, int v) {
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void dfs(int x) {
	int i, y; o[++cnt] = max[x] = x;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dfs(y), up(max[x], max[y]);
}

inline int rank(int x) {return LCT::splay(x), BIT::sum(LCT::nd[x].cov) - LCT::nd[x].c[0][LCT::nd].v;}

int main() {
	char op[9]; int i, u, v;
	scanf("%d%d", &n, &q);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(C = n);
	for (i = 1; i <= n; ++i) LCT::nd[i].v = 1, LCT::nd[i].cov = max[i], ++BIT::x[max[i]];
	for (i = 1; i < n; ++i) if (LCT::nd[i].p = v = p[i], max[i] == max[v]) LCT::nd[v].c[1] = i, LCT::nd[i].cov = 0;
	for (i = cnt; i; --i) LCT::update(o[i]);
	for (BIT::init(n + q); q; --q)
		switch (scanf("%s%d", op, &v), *op) {
			case 117: // up
				LCT::make_root(v), LCT::nd[v].cov = ++C, BIT::add(C, LCT::nd[v].v); break;
			case 119: // when
				printf("%d\n", rank(v)); break;
			case 99: // compare
				scanf("%d", &u), printf("%d\n", rank(u) < rank(v) ? u : v); break;
		}
	return 0;
}