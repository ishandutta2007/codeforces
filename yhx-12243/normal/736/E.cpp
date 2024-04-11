#include <bits/stdc++.h>

typedef unsigned int u32;
const int N = 3054;

int n, K;
int a[N], v[N];
char r[N][N];

inline int fail() {return puts("no"), 0;}
inline bool cmp (const int x, const int y) {return a[x] < a[y];};

int main() {
	int i, j, x, y, s = 0;
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; ++i) r[i][i] = 88, v[i] = n - i - 1;
	for (i = 0; i < K; ++i) scanf("%d", a + i), s += a[i];
	if (K == n) {
		if (s != n * (n - 1)) return fail();
	} else {
		if (s > n * (n - 1)) return fail();
		div_t t = div(n * (n - 1) - s, n - K);
		std::fill(a + K, a + (K + t.rem), t.quot + 1);
		std::fill(a + (K + t.rem), a + n, t.quot);
	}
	if (!std::is_sorted(a, a + n, std::greater <int> ())) return fail();
	for (s = i = 0; i < n; ++i)
		if (x = v[i], (u32)a[x] > 2u * (n - 1u) || (s += a[x]) < i * (i + 1)) return fail();
	for (i = 0; i < n; ++i) {
		std::sort(v + i, v + n, cmp), x = v[i], s = a[x];
		for (j = i + 1; j < n; ++j)
			switch (y = v[j], s) {
				case 0: ----a[y], r[x][y] = 76, r[y][x] = 87; break;
				case 1: --s, --a[y], r[x][y] = r[y][x] = 68; break;
				default: ----s, r[x][y] = 87, r[y][x] = 76; break;
			}
	}
	puts("yes");
	for (i = 0; i < n; ++i) puts(r[i]);
	return 0;
}