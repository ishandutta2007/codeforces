#include <bits/stdc++.h>
#define ctz __builtin_ctz
#define ad(x) ((((x) - 1) ^ 1) + 1)
#define tr(x) (2 * (x) - 1)
#define fa(x) (2 * (x))

const int N = 500054, M = N * 2, LN = 20;

int n, m, E = 0;
int to[M], first[N], next[M];
int P[LN][N], *p = *P, dep[N];
int cnt = 0, o[N], id[N], eid[N];
int cong[N], bel[M];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; o[++cnt] = x, id[x] = cnt;
	for (i = 0; P[i][x]; ++i) P[i + 1][x] = P[i][ P[i][x] ];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) p[y] = x, dep[y] = dep[x] + 1, dfs(y);
	eid[x] = cnt;
}

int jump_until(int x, int d) {
	int S = dep[x] - d;
	for (assert(S >= 0); S; S &= S - 1) x = P[ctz(S)][x];
	return x;
}

namespace dsu {
	int p[M];
	
	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}
	inline bool test(int x, int y, bool un = false) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return true;
		return un && (p[x] = y, false);
	}
	inline void equiv(int x, int y) {test(x, y, true), test(ad(x), ad(y), true);}
	inline void init(int n) {std::iota(p, p + ++n, 0);}
}

namespace dp {
	int f[N], stamp[N], li[N];
	int l[N], r[N];
	bool contain[N], rev[N];

	bool main(int R) {
		int i, x, y, cl, cr, cc, B, at, bt, top, _; bool Lr, Rr;
		memset(stamp, 0, (n + 1) << 2);
		for (_ = n; _; --_) {
			x = o[_], top = 0, cl = 1, cr = R, cc = (R + 1) / 2;
			for (i = first[x]; i; i = next[i]) {
				y = to[i], B = bel[tr(y)], at = (B + 1) / 2;
				if (stamp[at] != _) stamp[at] = _, l[at] = 1, r[at] = R, li[top++] = at;
				B & 1 ? up(l[at], f[y] + 1) : down(r[at], R - f[y]);
			}
			B = bel[tr(x)], bt = (B + 1) / 2;
			for (i = 0; i < top; ++i) {
				if (y = li[i], l[y] > r[y]) return false;
				if (y == bt)
					B & 1 ? (up(cl, l[y]), down(cr, r[y])) : (up(cl, R + 1 - r[y]), down(cr, R + 1 - l[y]));
				else
					Lr = l[y] * 2 <= R + 2, Rr = r[y] * 2 >= R,
					assert(Lr || Rr), down(cc, min(r[y], R + 1 - l[y])),
					up(cl, min(l[y], R + 1 - r[y])), down(cr, max(r[y], R + 1 - l[y]));
			}
			if (cc < cl) up(cl, R + 1 - cc);
			if (cl > cr) return false;
			for (f[x] = cl, i = 0; i < top; ++i) y = li[i], contain[y] = (l[y] <= cl && cl <= r[y]);
			for (i = first[x]; i; i = next[i])
				y = to[i], B = bel[tr(y)], at = (B + 1) / 2, rev[y] = (B ^ (at == bt ? bel[tr(x)] : contain[at])) & 1;
		}
		return true;
	}

	void dump(int R) {
		int i, v; ++R;
		for (i = 1; i <= n; ++i) v = o[i], (rev[v] ^= rev[p[v]]) && (f[v] = R - f[v]);
		for (i = 1; i <= n; ++i) printf("%d%c", f[i], i == n ? 10 : 32);
	}
}

int main() {
	int i, u, v, w, x, y, L, R, M;
	scanf("%d%d", &n, &m), dsu::init(2 * n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (dfs(1); m; --m) {
		scanf("%d%d", &u, &v), assert(u != v);
		if (id[u] > id[v]) std::swap(u, v);
		if (id[v] <= eid[u])
			++cong[v], --cong[jump_until(v, dep[u] + 1)];
		else {
			w = min(dep[u], dep[v]), x = jump_until(u, w), y = jump_until(v, w);
			for (i = LN - 1; i >= 0; --i)
				if (P[i][x] != P[i][y]) x = P[i][x], y = P[i][y];
			++cong[u], ++cong[v], --cong[x], --cong[y];
			dsu::equiv(tr(x), fa(y));
		}
	}
	for (i = n; i; --i)
		if (v = o[i], cong[ p[v] ] += cong[v], cong[v]) dsu::equiv(tr(v), tr(p[v]));
	for (i = 2; i <= n; ++i) if (dsu::test(tr(i), fa(i))) return puts("-1"), 0;
	for (u = 1; u <= n; ++u) {
		if (to[ i = first[u] ] == p[u]) first[u] = next[i];
		else for (i = first[u]; next[i]; i = next[i])
			if (to[next[i]] == p[u]) next[i] = next[next[i]];
		if (!bel[ dsu::ancestor(tr(u)) ]) bel[ dsu::ancestor(tr(u)) ] = tr(u);
		if (!bel[ dsu::ancestor(fa(u)) ]) bel[ dsu::ancestor(fa(u)) ] = fa(u);
	}
	for (i = 1; i <= 2 * n; ++i) bel[i] = bel[ dsu::ancestor(i) ];
	for (L = 1, R = n; L < R; dp::main(M = (L + R) / 2) ? R = M : L = M + 1);
	return printf("%d\n", L), dp::main(L), dp::dump(L), 0;
}