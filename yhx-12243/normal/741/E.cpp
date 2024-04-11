#include <bits/stdc++.h>
#define lg2 std::__lg
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 200054, LN = 19;

inline void down(int &x, const int y) {x > y ? x = y : 0;}
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
		for (p = i = 0; i < n; ++i) {
			if (p && --p, !x[i]) continue;
			for (j = sa[x[i] - 1], limit = n - max(i, j); p < limit && s[i + p] == s[j + p]; ++p);
			g[ x[i] - 1 ] = p;
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

struct request {
	int l, r, x, y, mod;
	request * read() {return scanf("%d%d%d%d%d", &l, &r, &mod, &x, &y), this;}
} qry[N];

int S, T, q;
int st[LN][N], at[N];
int ord[N], id[N], ans[N];
char s[N], *t;
vector small[N];

inline bool cmp(int x, int y) { 
	if (x >= y) return !(x == y || cmp(y, x));
	int L = lcp(S, x);
	if (x + T <= y) {
		if (L < T) return t[L] < s[x + L];
		L = lcp(x, x + T);
		if (L < y - x - T) return s[x + L] < s[x + T + L];
		L = lcp(y - T, S);
		if (L < T) return s[y - T + L] < t[L];
	} else {
		if (L < y - x) return t[L] < s[x + L];
		L = lcp(S + y - x, S);
		if (L < x + T - y) return t[y - x + L] < t[L];
		L = lcp(x, S + x + T - y);
		if (L < y - x) return s[x + L] < t[x + T - y + L];
	}
	return x < y;
}

void build_sparse_table() {
	int *f, *g = *st, i, j, k = S;
	for (j = 0; 1 << (j + 1) <= S + 1; ++j) {
		f = g, g = st[j + 1], k -= 1 << j;
		for (i = 0; i <= k; ++i)
			g[i] = min(f[i], f[i + (1 << j)]);
	}
}

inline int range(int L,int R) {int c = lg2(R - L); return min(st[c][L], st[c][R - (1 << c)]);}
inline bool contain(int x, int L, int R) {return L <= x && x <= R;}
inline int next(int x, int a, int m) {int t = (a - x) % m; return x + t + (t >> 31 & m);}

int main() {
	int i, j, l, r, x, y, mod, cnt;
	scanf("%s", s), S = strlen(s), t = s + S,
	scanf("%s%d", t, &q), T = strlen(t),
	lcp.construct(s), ord[N - 1] = -1,
	std::iota(ord, ord + (S + 1), 0), std::sort(ord, ord + (S + 1), cmp);
	for (i = 0; i <= S; ++i) id[ord[i]] = i;
	for (i = 0; i < q; ++i) qry[i].read(), ans[i] = N - 1;
	memcpy(*st, id, (S + 1) << 2), build_sparse_table();
	for (i = 0; i < q; ++i) if (qry[i].mod >= 135) {
		l = qry[i].l, r = qry[i].r, x = qry[i].x, y = qry[i].y, mod = qry[i].mod;
		if (!contain(l % mod, x, y)) l = next(l, x, mod);
		for (; ; ) {
			j = min(next(l, y, mod), r) + 1;
			if (l >= j) break;
			down(ans[i], range(l, j));
			l = next(j, x, mod);
		}
	} else small[ qry[i].mod ].EB(i);
	for (mod = 1; mod < 135; ++mod) {
		for (cnt = i = 0; i < mod; ++i)
			for (j = i; j <= S; j += mod) st[0][cnt] = id[j], at[j] = cnt++;
		assert(cnt == S + 1), build_sparse_table();
		for (int id : small[mod])
			for (i = qry[id].x; i <= qry[id].y; ++i) {
				l = next(qry[id].l, i, mod),
				r = next(qry[id].r + 1, i, mod) - mod;
				if (l <= r) down(ans[id], range(at[l], at[r] + 1));
			}
	}
	for (i = 0; i < q; ++i) printf("%d%c", ord[ans[i]], i == q - 1 ? 10 : 32);
	return 0;
}