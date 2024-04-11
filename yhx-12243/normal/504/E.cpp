#include <bits/stdc++.h>
#define lg2 std::__lg

typedef std::pair <int, int> pr;
const int N = 300054, M = N * 2, LN = 54;

inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

struct LCP {
	int n, *sa, *rnk, *st[LN];
	LCP () : n(0), sa(NULL), rnk(NULL) {memset(st, 0, sizeof st);}
	~LCP () {
		if (sa) delete [] sa;
		if (rnk) delete [] rnk;
		for (int i = 0; i < LN; ++i) if (st[i]) delete [] st[i];
	}
	void construct(const char *s) {
		int i, j, k, m = 256, p, limit; n = strlen(s);
		int *x = new int[n + 1], *y = new int[n + 1], *buf = new int[max(n, m)], *f, *g = new int[n + 1];
		auto cmp = [this] (const int *a, const int u, const int v, const int l) {return a[u] == a[v] && (u + l >= n ? 0 : a[u + l]) == (v + l >= n ? 0 : a[v + l]);};
		if (sa) delete [] sa; sa = new int[n];
		if (rnk) delete [] rnk;
		for (i = 0; i < LN; ++i) if (st[i]) delete [] st[i], st[i] = 0;
		for (i = 0; i < n; ++i) sa[i] = i, x[i] = (unsigned char)s[i];
		std::sort(sa, sa + n, [s] (const int u, const int v) {return (unsigned char)s[u] < (unsigned char)s[v];});
		for (j = 1; j < n; j <<= 1, m = ++p) {
			std::iota(y, y + j, n - j), p = j;
			for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
			memset(buf, 0, m << 2);
			for (i = 0; i < n; ++i) ++buf[ x[y[i]] ];
			for (i = 1; i < m; ++i) buf[i] += buf[i - 1];
			for (i = n - 1; i >= 0; --i) sa[ --buf[ x[y[i]] ] ] = y[i];
			std::swap(x, y);
			x[*sa] = p = 1, x[n] = 0;
			for (i = 1; i < n; ++i) x[sa[i]] = (cmp(y, sa[i - 1], sa[i], j) ? p : ++p);
			if (p >= n) break;
		}
		if (rnk = x, n == 1) *x = 0;
		else for (i = 0; i < n; ++i) --x[i];
		delete [] buf, delete [] y;
		for (p = i = 0; i < n; g[ x[i++] - 1 ] = p) {
			if (p && --p, !x[i]) continue;
			for (j = sa[x[i] - 1], limit = n - max(i, j); p < limit && s[i + p] == s[j + p]; ++p);
		}
		*st = g, k = n - 1;
		for (j = 0; 1 << (j + 1) < n; ++j) {
			k -= 1 << j, f = g, g = st[j + 1] = new int[k + 1];
			for (i = 0; i < k; ++i)
				g[i] = min(f[i], f[i + (1 << j)]);
		}
	}
	inline int operator () (const int u, const int v) {
		assert((unsigned)u < (unsigned)n && (unsigned)v < (unsigned)n);
		if (u == v) return n - u;
		int L, R, c; std::tie(L, R) = std::minmax(rnk[u], rnk[v]), c = lg2(R - L);
		return min(st[c][L], st[c][R - (1 << c)]);
	}
} lcp;

char s[N], str[M];
int n, q, E = 0;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int cnt = 0, o[N], id[N], prf[N], top[N];
pr L[LN], R[LN];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs_wt(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dep[y] = dep[x] + 1;
			dfs_wt(y), size[x] += size[y];
			size[y] > size[z] ? z = y : 0;
		}	
}

void dfs_hld(int x, int r) {
	int i, y; o[++cnt] = x, id[x] = cnt, top[x] = r;
	if (!prf[x]) return;
	dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
}

int decomposition(int u, int v, pr *ret) {
	static pr rev[54];
	int x = top[u], y = top[v], c = 0, d = 0;
	for (; x != y; dep[x] > dep[y] ? (ret[c++] = pr(id[u], id[x]), u = p[x], x = top[u]) : (rev[d++] = pr(id[y], id[v]), v = p[y], y = top[v]));
	ret[c++] = pr(id[u], id[v]);
	return std::reverse_copy(rev, rev + d, ret + c) - ret;
}

int main() {
	int i, j, u, v, U, V, Lc, Rc, g, pos;
	scanf("%d%s", &n, s + 1);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs_wt(1), dfs_hld(1, 1);
	for (str[n] = 1, i = 0; i < n; ++i) str[i] = str[2 * n - i] = s[ o[i + 1] ];
	lcp.construct(str);
	for (scanf("%d", &q); q; --q) {
		scanf("%d%d%d%d", &u, &v, &U, &V);
		Lc = decomposition(u, v, L), Rc = decomposition(U, V, R);
		for (pos = i = j = 0; i < Lc && j < Rc; ) {
			u = (L[i].first <= L[i].second ? L[i].first - 1 : 2 * n - L[i].first + 1), U = abs(L[i].first - L[i].second) + 1;
			v = (R[j].first <= R[j].second ? R[j].first - 1 : 2 * n - R[j].first + 1), V = abs(R[j].first - R[j].second) + 1;
			pos += g = std::min({lcp(u, v), U, V});
			if (g < U && g < V) break;
			g == U ? ++i : (L[i].first += L[i].first <= L[i].second ? g : -g);
			g == V ? ++j : (R[j].first += R[j].first <= R[j].second ? g : -g);
		}
		printf("%d\n", pos);
	}	
	return 0;
}