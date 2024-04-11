#include <bits/stdc++.h>
#define EB emplace_back
#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 540000, K = 51;

struct edge {
	int u, v, col;
	edge * read() {return scanf("%d%d", &u, &v), col = 0, this;}
} e[N];

struct UFSex {
	int n, *p, *size, *w;
	vector hist;

	UFSex () : n(0), p(NULL), size(NULL), w(NULL) {}
	~UFSex () {if (p) delete [] (p), delete [] (size), delete [] (w);}

	void resize(int _n) {
		if (p) delete [] (p), delete [] (size), delete [] (w), hist.clear();
		n = _n, p = new int[n + 1], size = new int[n + 1], w = new int[n + 1];
		std::iota(p, p + (n + 1), 0), std::fill(size + 1, size + (n + 1), 1), memset(w, 0, (n + 1) << 2);
	}

	int ancestor(int x, int *d = NULL) {return p[x] == x ? x : (d && (*d ^= w[x]), ancestor(p[x], d));}

	void Union(int x, int y, int weight) {
		if (size[x] > size[y]) std::swap(x, y);
		p[x] = y, size[y] += size[x], w[x] = weight, hist.EB(x);
	}

	inline int time() {return hist.size();}

	inline void undo(int t) {int x; for (t = hist.size() - t; t > 0; --t) x = hist.back(), size[p[x]] -= size[x], p[x] = x, w[x] = 0, hist.pop_back();}
} ufs[K];

int V, E, C, n;
int la[N];
bool ans[N];
pr modifies[N];
vector x[N * 4];

inline void get_time(int *res) {for (int i = 1; i <= C; ++i) res[i] = ufs[i].time();}
inline void backtrack(int *res) {for (int i = 1; i <= C; ++i) ufs[i].undo(res[i]);}

void add(int id, int L, int R, int ql, int qr, int v) {
	if (ql <= L && R <= qr) return x[id].EB(v);
	segc;
	if (ql <= M) add(lc, L, M, ql, qr, v);
	if (qr > M) add(rc, M + 1, R, ql, qr, v);
}

void scan(int id, int L, int R) {
	int i, u, v, d1, d2, d, col, time[K + 1];
	get_time(time);
	for (int i : x[id]) {
		if (!(col = e[i].col)) continue;
		d1 = d2 = 0;
		if ((u = ufs[col].ancestor(e[i].u, &d1)) != (v = ufs[col].ancestor(e[i].v, &d2)))
			ufs[col].Union(u, v, d1 ^ d2 ^ 1);
	}
	if (L == R) {
		std::tie(i, col) = modifies[L];
		d1 = d2 = 0;
		u = ufs[col].ancestor(e[i].u, &d1);
		v = ufs[col].ancestor(e[i].v, &d2);
		d = d1 ^ d2 ^ 1;
		(ans[L] = !(u == v && d)) && (e[i].col = col);
		return backtrack(time);
	}
	segc; scan(lc, L, M), scan(rc, M + 1, R), backtrack(time);
}

int main() {
	int i, u, v;
	scanf("%d%d%d%d", &V, &E, &C, &n);
	for (i = 1; i <= C; ++i) ufs[i].resize(V);
	for (i = 1; i <= E; ++i) e[i].read(), la[i] = INT_MAX;
	for (i = 1; i <= n; la[u] = i, ++i) {
		scanf("%d%d", &u, &v), modifies[i] = pr(u, v);
		if (la[u] < i - 1) add(1, 1, n, la[u] + 1, i - 1, u);
	}
	for (i = 1; i <= E; ++i) if (la[i] < n) add(1, 1, n, la[i] + 1, n, i);
	scan(1, 1, n);
	for (i = 1; i <= n; ++i) puts(ans[i] ? "YES" : "NO");
	return 0;
}