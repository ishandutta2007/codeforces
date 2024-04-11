#include <bits/stdc++.h>
#define lg2 std::__lg
#define ctz __builtin_ctz
#define EB emplace_back
using std::pair;
using std::tuple;
using std::vector;

typedef long long ll;
const int N = 150054, M = N * 2, LN = 19;

int n, m, K;
int P[LN][N], *p = *P, dep[N];
int cnt = 0, o[N], id[N], eid[N];
pair <int, int> ch[N];
ll ans = 0;

inline ll C2(int x) {return x * (x - 1ll) / 2;}

namespace Tree {
	int E = 0;
	int to[M], first[N], next[M];

	inline void addedge(int u, int v) {
		to[++E] = v, next[E] = first[u], first[u] = E;
		to[++E] = u, next[E] = first[v], first[v] = E;
	}

	void dfs(int x) {
		int i, y; o[++cnt] = x, id[x] = cnt;
		for (i = 0; P[i][x]; ++i) P[i + 1][x] = P[i][ P[i][x] ];
		for (i = first[x]; i; i = next[i])
			if ((y = to[i]) != p[x])
				p[y] = x, dep[y] = dep[x] + 1, dfs(y);
		eid[x] = ::cnt;
	}

	int jump_until(int x, int d) {
		int S = dep[x] - d;
		for (assert(S >= 0); S; S &= S - 1) x = P[ctz(S)][x];
		return x;
	}

	int LCA(int x, int y) {
		if (dep[x] < dep[y]) std::swap(x, y);
		if (x = jump_until(x, dep[y]), x == y) return x;
		for (int i = LN - 1; i >= 0; --i)
			if (P[i][x] != P[i][y]) x = P[i][x], y = P[i][y];
		return p[x];
	}
}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h >= 0; h &= h + 1, --h) s += x[h]; return s;}
	void add(int h, int v) {for (; h < n; h |= h + 1) x[h] += v;}
}

namespace DIFF {
	int F1[N], F2[N];
	vector <int> cm[N];
	vector <tuple <int, int, int *>> cq[N];

	int main() {
		int i, u, v, w, *out;
		for (i = 0; i < m; ++i)
			std::tie(u, v) = ch[i], w = Tree::LCA(u, v),
			cm[ id[u] ].EB(dep[w]), cm[ id[v] ].EB(dep[w]);
		for (i = 1; i <= n; ++i)
			cq[ eid[i]  ].EB(dep[i] - K,      1, F1 + i),
			cq[ id[i]-1 ].EB(dep[i] - K,     -1, F1 + i),
			cq[ eid[i]  ].EB(dep[i] - K - 1,  1, F2 + i),
			cq[ id[i]-1 ].EB(dep[i] - K - 1, -1, F2 + i);
		for (i = 1; i <= n; ++i) {
			for (const int &v : cm[i]) BIT::add(v, 1);
			for (const auto &e : cq[i]) std::tie(u, v, out) = e, *out += v * BIT::sum(u);
		}
		for (i = 1; i <= n; ++i) ans += F2[i] * ll(F1[i] - F2[i]);
		return 0;
	}
}

namespace SAME {
	namespace ST {
		struct node {int v, lc, rc;} x[20030731];
		int cnt, Len;
		pair <int, int> Re[N];

		int merge(int id1, int id2, int L, int R) {
			if (!(id1 && id2)) return id1 | id2;
			if (L == R) return x[id1].v += x[id2].v, id1;
			int M = (L + R - 1) >> 1;
			x[id1].lc = merge(x[id1].lc, x[id2].lc, L, M);
			x[id1].rc = merge(x[id1].rc, x[id2].rc, M + 1, R);
			return x[id1].v = x[id1].lc[x].v + x[id1].rc[x].v, id1;
		}

		int add(int id, int L, int R, int h, int v) {
			id || (x[++cnt] = *x, id = cnt), x[id].v += v;
			if (L == R) return id;
			int M = (L + R - 1) >> 1;
			h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
			return id;
		}

		int range(int id, int L, int R, int ql, int qr) {
			if (!id || (ql <= L && R <= qr)) return x[id].v;
			int M = (L + R - 1) >> 1, s = 0;
			if (ql <= M) s += range(x[id].lc, L, M, ql, qr);
			if (qr > M) s += range(x[id].rc, M + 1, R, ql, qr);
			return s;
		}

		void __builtin_expand(int id, int L, int R) {
			if (!id) return;
			if (L == R) {Re[Len++] = pair <int, int> (L, x[id].v); return;}
			int M = (L + R - 1) >> 1;
			__builtin_expand(x[id].lc, L, M), __builtin_expand(x[id].rc, M + 1, R);
		}

		inline void expand(int id) {Len = 0, __builtin_expand(id, 1, n);}
	}

	vector <int> cs[N], infos[N];
	int vtc, vt[M];
	int BASE, fK, stack[N], root[N];

	inline bool idcmp(const int A, const int B) {return id[A] < id[B];}

	void merge(int u, int v) {
		int i, g, c, di, ru = root[u], rv = root[v];
		di = 2 * BASE + fK - dep[u];
		if (ST::x[ru].v < ST::x[rv].v) std::swap(ru, rv);
		ST::expand(rv);
		for (i = 0; i < ST::Len; ++i)
			if (std::tie(g, c) = ST::Re[i], dep[o[g]] >= di)
				g = Tree::jump_until(o[g], di), ans += (ll)c * ST::range(ru, 1, n, id[g], eid[g]);
		root[u] = ST::merge(root[u], root[v], 1, n);
	}

	void DSA(int n, int *v) {
		int i, x, y, la, di, conn, top = ST::cnt = 0;
		for (i = 0; i < n; ++i) {
			if (x = v[i], !top) stack[++top] = x;
			else {
				stack[top + 1] = 0;
				for (y = Tree::LCA(x, stack[top]); top && dep[stack[top]] >= dep[y]; --top)
					if (top > 1 && stack[top + 1]) merge(stack[top], stack[top + 1]);
				if (i == n - 1) return;
				if (stack[++top] != y) root[y] = root[stack[top]], stack[top] = y;
			}
			stack[++top] = x, root[x] = 0;
			la = -1, di = 2 * BASE + fK - dep[x], conn = 0;
			for (int v : infos[x]) {
				if (~la && Tree::LCA(o[la], o[v])[dep] >= di) ++conn;
				else ans += C2(conn), conn = 1;
				root[x] = ST::add(root[x], 1, ::n, la = v, 1);
			}
			ans += C2(conn);
		}
	}

	int main() {
		int i, u, v, w, la, conn;
		for (i = 0; i < m; ++i) std::tie(u, v) = ch[i], cs[Tree::LCA(u, v)].EB(i);
		fK = K + (K == 1);
		for (w = 1; w <= n; ++w) if (cs[w].size() > 1u) {
			vtc = 1, *vt = w, BASE = dep[w];
			for (int i : cs[w]) {
				std::tie(u, v) = ch[i];
				if (u == w || v == w) continue;
				if (dep[u] >= BASE + fK) u = Tree::jump_until(u, BASE + fK - 1);
				if (dep[v] >= BASE + fK) v = Tree::jump_until(v, BASE + fK - 1);
				if (id[u] > id[v]) std::swap(u, v);
				infos[u].EB(id[v]), vt[vtc++] = u;
			}
			if (vtc > 1) {
				std::sort(vt, vt + vtc, idcmp), vtc = std::unique(vt, vt + vtc) - vt, vt[vtc++] = *vt;
				for (i = 1; i < vtc; ++i) std::sort(infos[ vt[i] ].begin(), infos[ vt[i] ].end());
				DSA(vtc, vt);
				for (i = 1; i < vtc; ++i) infos[ vt[i] ].clear();
			}
			vtc = 0;
			for (int i : cs[w]) {
				std::tie(u, v) = ch[i];
				if (dep[u] > BASE + K) u = Tree::jump_until(u, BASE + K);
				if (dep[v] > BASE + K) v = Tree::jump_until(v, BASE + K);
				if (dep[u] == BASE + K) infos[u].EB(id[v]), vt[vtc++] = u;
				if (dep[v] == BASE + K) infos[v].EB(id[u]), vt[vtc++] = v;
			}
			if (vtc > 0) {
				std::sort(vt, vt + vtc, idcmp), vtc = std::unique(vt, vt + vtc) - vt;
				for (i = 0; i < vtc; ++i) {
					u = vt[i], std::sort(infos[u].begin(), infos[u].end());
					ans += C2(infos[u].size());
					la = -1, conn = 0;
					for (int v : infos[u]) {
						if (~la && Tree::LCA(o[la], o[v])[dep] > BASE) ++conn;
						else ans -= C2(conn), conn = 1;
						la = v;
					}
					ans -= C2(conn), infos[u].clear();
				}
			}
		}
		return 0;
	}
}

int main() {
	int i, u, v, w, m_ = 0;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), Tree::addedge(u, v);
	Tree::dfs(1);
	for (i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v), w = Tree::LCA(u, v);
		if (dep[u] + dep[v] - dep[w] * 2 >= K) ch[m_++] = pair <int, int> (u, v);
	}
	m = m_, DIFF::main(), SAME::main();
	printf("%lld\n", ans);
	return 0;
}