#include <bits/stdc++.h>
#define lg2 std::__lg
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int *> pip;
typedef std::vector <pip> vector;
const int N = 100054, M = N * 2, W = 10000054, WQ = 666666, mod = 1000000007;

int n, q, E = 0;
int to[M], first[N], next[M];
int a[N], num[N], deno[N];
int *piq[WQ];
vector qs[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

namespace NT {
	int pn = 0, c[W], p[WQ], ip[WQ], buf[WQ];

	void sieve(int n) {
		int i, j, v;
		memset(c, -1, sizeof c);
		for (i = 2; i <= n; ++i) {
			if (!~c[i]) p[pn] = i, ip[pn] = PowerMod(i, mod - 2), c[i] = pn++;
			for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
		}
	}

	void init() {
		int i, j, *alloc = buf; sieve(W - 1);
		for (i = 0; i < pn; ++i)
			for (piq[i] = alloc, j = W - 1; j /= p[i]; ++alloc);
		std::fill(buf, alloc, 1);
	}
}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

namespace Tree {
	int p[N], dep[N];
	int cnt = 0, id[N], st[19][M], *o = *st;

	inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
	
	void dfs(int x) {
		int i, y; o[cnt] = x, id[x] = cnt++;
		for (i = first[x]; i; i = next[i])
			if ((y = to[i]) != p[x])
				p[y] = x, dep[y] = dep[x] + 1, dfs(y), o[cnt++] = x;
	}
	
	void build_sparse_table() {
		int *f, *g = o, i, j, k = cnt;
		for (j = 0; 1 << (j + 1) <= cnt; ++j) {
			f = g, g = st[j + 1], k -= 1 << j;
			for (i = 0; i < k; ++i)
				g[i] = dmin(f[i], f[i + (1 << j)]);
		}
	}

	inline void init() {dfs(1), build_sparse_table();}

	inline int LCA(int x, int y) {
		int L, R, c; std::tie(L, R) = std::minmax(id[x], id[y]), c = lg2(++R - L);
		return dmin(st[c][L], st[c][R - (1 << c)]);
	}
}

void solve(int x) {
	int i, j, y, n, *out;
	for (n = a[x]; n != 1; )
		for (i = NT::c[n], j = 0; !(n % NT::p[i]); n /= NT::p[i], ++j)
			piq[i][j] = (ll)piq[i][j] * NT::p[i] % mod;
	for (const pip &el : qs[x])
		for (std::tie(n, out) = el; n != 1; )
			for (i = NT::c[n], j = 0; !(n % NT::p[i]); n /= NT::p[i], ++j)
				*out = (ll)*out * piq[i][j] % mod;
	for (i = first[x]; i; i = next[i]) if (Tree::p[y = to[i]] == x) solve(y);
	for (n = a[x]; n != 1; )
		for (i = NT::c[n], j = 0; !(n % NT::p[i]); n /= NT::p[i], ++j)
			piq[i][j] = (ll)piq[i][j] * NT::ip[i] % mod;
}

int main() {
	int i, u, v, w, lca; NT::init();
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	Tree::init();
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	scanf("%d", &q);
	for (i = 0; i < q; ++i) {
		scanf("%d%d%d", &u, &v, &w), num[i] = deno[i] = 1;
		if (Tree::dep[u] > Tree::dep[v]) std::swap(u, v);
		if (u == (lca = Tree::LCA(u, v))) {
			qs[v].EB(w, num + i);
			if (Tree::p[u]) qs[ Tree::p[u] ].EB(w, deno + i);
		} else {
			qs[u].EB(w, num + i), qs[v].EB(w, num + i);
			qs[lca].EB(w, deno + i);
			if (Tree::p[lca]) qs[ Tree::p[lca] ].EB(w, deno + i);
		}
	}
	solve(1);
	for (i = 0; i < q; ++i) printf("%d\n", (int)PowerMod(deno[i], mod - 2, num[i]));
	return 0;
}