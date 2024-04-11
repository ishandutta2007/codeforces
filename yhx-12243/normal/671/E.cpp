#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;
const ll INF = 0x0f3f3f3f3f3f3f3fll;

int n, K;
int top = 0, stack[N];
int p[N], fc[N], nc[N];
int ans[N];
ll g[N], pos[N], a[N], b[N];

inline ll min(const ll x, const ll y) {return x < y ? x : y;}
inline ll max(const ll x, const ll y) {return x < y ? y : x;}
inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag) push_down(x[id], x[lc], x[rc])

	struct node {
		ll sta, v, ans, tag;
	} x[N * 4];
/*
	sta : static max b[]
	v   : dynamic max b[]
*/
	inline void cover(node &ret, ll v) {ret.v += v, ret.ans += v, ret.tag += v;}

	inline void push_down(node &ret, node &l, node &r) {cover(l, ret.tag), cover(r, ret.tag), ret.tag = 0;}

	ll left__;
	inline ll recursive(int id, int L, int R) {
		if (L == R) return left__ - x[id].sta;
		segc; exist_pd;
		return x[lc].v >= left__  ? min(x[id].ans, recursive(lc, L, M)) : min(left__ - x[lc].sta, recursive(rc, M + 1, R));
	}

	inline void update(int id, int L, int R) {
		segc; x[id].v = max(x[lc].v, x[rc].v), left__ = x[lc].v, x[id].ans = recursive(rc, M + 1, R);
	}

	void build(int id, int L, int R) {
		if (L == R) {x[id].sta = x[id].v = b[L]; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		x[id].sta = max(x[lc].sta, x[rc].sta);
		update(id, L, R);
	}

	void add(int id, int L, int R, int ql, int qr, ll v) {
		if (ql <= L && R <= qr) return cover(x[id], v);
		segc; exist_pd;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		update(id, L, R);
	}

	// max i where b[i] >= v
	int locate(int id, int L, int R, ll v) {
		if (L == R) return x[id].sta >= v ? L : -1;
		segc; exist_pd;
		return x[rc].sta >= v ? locate(rc, M + 1, R, v) : locate(lc, L, M, v);
	}

	int find(int id, int L, int R, ll left) {
		if (L == R) return left - x[id].sta <= K ? L : -1;
		segc, r; exist_pd;
		if (x[lc].v >= left) return x[id].ans <= K ? find(rc, M + 1, R, x[lc].v) : find(lc, L, M, left);
		return ~(r = find(rc, M + 1, R, left)) ? r : locate(id, L, R, left - K);
	}

	// extract range [l, r]
	void extract(int l, int r) {
		if (l > 0) ST::add(1, 0, n - 1, 0, l - 1, -INF);
		if (r < n) ST::add(1, 0, n - 1, r, n - 1, INF);
	}

	// unextract range [l, r]
	void recover(int l, int r) {
		if (l > 0) ST::add(1, 0, n - 1, 0, l - 1, INF);
		if (r < n) ST::add(1, 0, n - 1, r, n - 1, -INF);
	}

	inline int query(int l, int r) {
		int ret;
		return ST::extract(l, r), ret = ST::find(1, 0, n - 1, -INF), ST::recover(l, r), ret;
	}
}

void solve(int x) {
	int y, limit, *_ptr;
	stack[top++] = x, a[N - 1] = a[x] - K;
	if (p[x] != n) ST::add(1, 0, n - 1, p[x] - 1, n - 1, a[x] - a[p[x]]);

	_ptr = std::lower_bound(stack, stack + top, N - 1, [] (const int x, const int y) {return a[x] < a[y];});
	limit = (_ptr == stack ? n : _ptr[-1]);
	ans[x] = ST::query(x, limit - 1) - x + 1;

	for (y = fc[x]; ~y; y = nc[y]) solve(y);
	if (--top, p[x] != n) ST::add(1, 0, n - 1, p[x] - 1, n - 1, a[p[x]] - a[x]);
}

int main() {
	int i, v;
	scanf("%d%d", &n, &K);
	for (i = 1; i < n; ++i) scanf("%lld", pos + i), pos[i] += pos[i - 1];
	for (i = 1; i <= n; ++i) scanf("%lld", g + i), g[i] += g[i - 1];
	for (i = 0; i < n; ++i) a[i] = g[i] - pos[i];
	for (i = 0; i < n; ++i) b[i] = g[i + 1] - pos[i];
	memset(fc, -1, (n + 1) << 2);
	for (i = 0; i < n; stack[++top] = i++)
		for (; top && a[ v = stack[top] ] > a[i]; --top) link(v, i);
	for (; top; --top) link(stack[top], n);
	ST::build(1, 0, n - 1);
	for (v = fc[n]; ~v; v = nc[v]) solve(v);
	printf("%d\n", *std::max_element(ans, ans + n));
	return 0;
}