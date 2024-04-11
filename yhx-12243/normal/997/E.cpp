#include <bits/stdc++.h>
#define lg2 std::__lg
#define ctz __builtin_ctz
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 254000;

int n, q;
int p[N], dep[N], idx[N];
int P[19][N], *pa = *P;
vector G[N];
ll w[N], sum[N], lsum[N], rsum[N], lcj[N], rcj[N];
ll depL[N], depR[N];

namespace DCTree {
	enum type {leaf, disjunct, conjunct} I[N];

	pr st[20][N];
	int stack1[N], stack2[N], stack[N];
	int cnt, root, left[N], mid[N], right[N];

	inline void up(pr &x, const pr &y) {x.first > y.first ? x.first = y.first : 0, x.second < y.second ? x.second = y.second : 0;}

	void build_sparse_table() {
		int i, j, k = n; pr *f, *g = *st;
		for (j = 0; 1 << (j + 1) <= n; ++j) {
			f = g, g = st[j + 1], k -= 1 << j;
			for (i = 1; i <= k; ++i)
				up(g[i] = f[i], f[i + (1 << j)]);
		}
	}

	inline bool is_consecutive(int L, int R) {
		int c = lg2(R - L); pr ans = st[c][L]; up(ans, st[c][R - (1 << c)]);
		return ans.second - ans.first == R - L - 1;
	}

	namespace ST {
		#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
		struct node {int v, tag;} x[N * 4];

		void build(int id, int L, int R) {
			x[id].v = L, x[id].tag = 0;
			if (L == R) return;
			segc; build(lc, L, M), build(rc, M + 1, R);
		}

		void add(int id, int L, int R, int ql, int qr, int v) {
			if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
			segc;
			if (ql <= M) add(lc, L, M, ql, qr, v);
			if (qr > M) add(rc, M + 1, R, ql, qr, v);
			x[id].v = std::min(x[lc].v, x[rc].v) + x[id].tag;
		}

		int find_suf(int id, int L, int R, int v, int cv = 0) {
			if (cv + x[id].v > v) return -1;
			if (L == R) return L;
			segc, p = find_suf(lc, L, M, v, cv += x[id].tag);
			return ~p ? p : find_suf(rc, M + 1, R, v, cv);
		}
	}

	inline void link(int x, int px) {pa[x] = px, G[px].EB(x);}

	void build() {
		int i, l, top1 = 0, top2 = 0, top = 0, &v = root, u; cnt = n;
		for (i = 1; i <= n; ++i) st[0][i] = pr(p[i], p[i]), left[i] = right[i] = i, I[i] = leaf;
		build_sparse_table(), ST::build(1, 1, n);
		for (i = 1; i <= n; ++i) {
			for (; top1 && p[i] > p[ stack1[top1] ]; --top1)
				ST::add(1, 1, n, stack1[top1 - 1] + 1, stack1[top1], p[i] - p[ stack1[top1] ]);
			for (; top2 && p[i] < p[ stack2[top2] ]; --top2)
				ST::add(1, 1, n, stack2[top2 - 1] + 1, stack2[top2], p[ stack2[top2] ] - p[i]);
			stack1[++top1] = stack2[++top2] = i;
			l = ST::find_suf(1, 1, n, i);
			for (v = i; top && left[ u = stack[top] ] >= l; --top)
				if (I[u] == conjunct && is_consecutive(mid[u], i + 1))
					right[u] = i, link(v, u), v = u;
				else if (is_consecutive(left[u], i + 1)) {
					I[++cnt] = conjunct, link(u, cnt), link(v, cnt);
					left[cnt] = left[u], right[cnt] = i, mid[cnt] = left[v], v = cnt;
				} else {
					I[++cnt] = disjunct, link(v, cnt);
					for (; top && !is_consecutive(left[ u = stack[top] ], i + 1); --top)
						link(u, cnt); link(u, cnt);
					left[cnt] = left[u], right[cnt] = i, v = cnt;
				}
			stack[++top] = v;
		}
	}
}

inline ll C2(int x) {return x * (x - 1ll) / 2;}
inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}

void dfs(int x) {
	int i, y, deg = G[x].size(); ll s = 0; bool conj = DCTree::I[x] == DCTree::conjunct;
	std::sort(G[x].begin(), G[x].end(), [] (const int x, const int y) {return DCTree::left[x] < DCTree::left[y];});
	w[x] = (conj ? C2(deg) : 1);
	for (i = 0; P[i][x]; ++i) P[i + 1][x] = P[i][ P[i][x] ];
	for (i = 0; i < deg; ++i) {
		y = G[x][i], dep[y] = dep[x] + 1, idx[y] = i;
		lsum[y] = s, dfs(y), s += sum[y];
		if (conj) lcj[y] = C2(i), rcj[y] = C2(deg - i - 1);
	}
	sum[x] = s + w[x], s = 0;
	for (i = deg - 1; i >= 0; --i) y = G[x][i], rsum[y] = s, s += sum[y];
}

void dfs2(int x) {
	for (int y : G[x])
		depL[y] = depL[x] + lsum[y] + lcj[y], depR[y] = depR[x] + rsum[y] + rcj[y], dfs2(y);
}

int jump_until(int x, int d) {
	for (int S = dep[x] - d; S; S &= S - 1) x = P[ctz(S)][x];
	return x;
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	if (x = jump_until(x, dep[y]), x == y) return x;
	for (int i = 18; i >= 0; --i)
		if (P[i][x] != P[i][y])
			x = P[i][x], y = P[i][y];
	return pa[x];
}

int main() {
	int i, j, l, r, c, d; ll ans; using DCTree::root;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", p + i);
	DCTree::build(), dfs(root), dfs2(root);
	for (scanf("%d", &q); q; --q) {
		scanf("%d%d", &l, &r), --l, ++r;
		if (!l && r == n + 1) ans = sum[root];
		else if (!l) ans = depL[r];
		else if (r == n + 1) ans = depR[l];
		else {
			c = LCA(l, r), ans = (depR[l] - depR[c]) + (depL[r] - depL[c]) - (sum[c] - w[c]);
			if (DCTree::I[c] == DCTree::conjunct)
				d = G[c].size(), i = idx[jump_until(l, dep[c] + 1)], j = idx[jump_until(r, dep[c] + 1)],
				ans += C2(j - i - 1) - C2(d - i - 1) - C2(j);
		}
		printf("%lld\n", ans);
	}
	return 0;
}