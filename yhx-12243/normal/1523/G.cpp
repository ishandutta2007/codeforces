#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 50054, M = 100054;

int n, m;
int ans[N];
pr a[M];
vector rs[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

namespace ST2d {
	struct node {int v, lc, rc;} x[20030731];

	int root[N], cnt = 0;

	int adj(int id, int L, int R, int h, int v) {
		if (!id) id = ++cnt;
		up(x[id].v, v);
		if (L == R) return id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = adj(x[id].lc, L, M, h, v) : x[id].rc = adj(x[id].rc, M + 1, R, h, v);
		return id;
	}

	int prefix(int id, int L, int R, int h) {
		if (h > R) return x[id].v;
		int M, s = 0;
		for (; id && L != R; )
			M = (L + R - 1) >> 1,
			id = (h <= M ? (R = M, x[id].lc) : (up(s, x[id].lc[x].v), L = M + 1, x[id].rc));
		return s;
	}

	void insert(int x, int y, int v) {for (; x > 0; x &= x - 1) root[x] = adj(root[x], 1, n, y, v);}

	int query(int l, int r) {
		int s = 0;
		for (; l <= n; l |= l - 1, ++l) up(s, prefix(root[l], 1, n, r + 1));
		return s;
	}
}

int solve(int L, int R) {
	if (L > R) return 0;
	int id = ST2d::query(L, R), l, r;
	if (!id) return 0;
	return std::tie(l, r) = a[m - id], r - l + 1 + solve(L, l - 1) + solve(r + 1, R);
}

int main() {
	int i, l, r, d;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (i = 0; i < m; ++i) cin >> l >> r, a[i] = pr(l, r), rs[r - l + 1].EB(i);
	for (d = n; d; --d) {
		for (int id : rs[d]) ST2d::insert(a[id].first, a[id].second, m - id);
		ans[d] = solve(1, n);
	}
	for (i = 1; i <= n; ++i) cout << ans[i] << '\n';
	return 0;
}