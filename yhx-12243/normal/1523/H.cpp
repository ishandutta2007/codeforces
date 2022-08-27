#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

const int N = 20054, LN = 15, K = 31;

int n, lgn, q;
int a[N], e[N];
int F[LN][K][N];
int cur[K], nxt[K];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int argmax(const int x, const int y) {return e[x] <= e[y] ? y : x;}

namespace rmq {
	int st[LN][N];

	void build() {
		int *f, *g = *st, i, j, k = n;
		std::iota(g, g + (n + 1), 0);
		for (j = 0; j < lgn; ++j) {
			f = g, g = st[j + 1], k -= 1 << j;
			for (i = 1; i <= k; ++i) g[i] = argmax(f[i], f[i + (1 << j)]);
		}
	}

	inline int range(int L, int R) {
		int c = lg2(R - L);
		return argmax(st[c][L], st[c][R - (1 << c)]);
	}
}

inline int query(int l, int r, int k) {
	if (l == r) return 0;
	int i, d, e, w, ret = 1;
	std::fill(cur, cur + (k + 1), l), std::fill(nxt, nxt + (k + 1), l);
	for (i = lg2(r - l); i >= 0; --i) {
		for (d = 0; d <= k; ++d) {
			w = rmq::range(l, cur[d] + 1);
			for (e = 0; d + e <= k; ++e) up(nxt[d + e], F[i][e][w]);
		}
		if (nxt[k] >= r) memcpy(nxt, cur, (k + 1) << 2);
		else memcpy(cur, nxt, (k + 1) << 2), ret += 1 << i;
	}
	return ret;
}

int main() {
	typedef int (*pt)[N];
	int i, j, k, d, e, l, r, w; pt f, g = *F;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q, lgn = lg2(n);
	for (i = 1; i <= n; ++i) cin >> a[i], ::e[i] = i + a[i];
	rmq::build();
	for (d = 0; d <= 30; ++d) for (i = 1; i <= n; ++i) g[d][i] = min(i + a[i] + d, n);
	for (k = n, j = 0; j < lgn; ++j) {
		f = g, g = F[j + 1];
		for (d = 0; d <= 30; ++d)
			for (i = 1; i <= n; ++i) {
				w = rmq::range(i, f[d][i] + 1);
				for (e = 0; d + e <= 30; ++e) up(g[d + e][i], f[e][w]);
			}
	}
	for (; q; --q) cin >> l >> r >> k, cout << query(l, r, k) << '\n';
	return 0;
}