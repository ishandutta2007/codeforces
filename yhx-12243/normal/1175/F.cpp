#include <bits/stdc++.h>

const int N = 300054;

int n, m = 0;
int a[N], last[N];
int one[N], max[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

int solve(int L, int M, int R) {
	int i, lim = L, len = 1, ret = max[M] = 1;
	for (i = M + 1; i <= R; ++i) up(max[i] = max[i - 1], a[i]);
	for (i = M - 1; i >= L; --i) up(max[i] = max[i + 1], a[i]);
	for (i = L; i <= R; ++i) {
		if (last[ a[i] ]) up(lim, last[ a[i] ] + 1);
		if (last[ a[i] ] = i, lim > M) break;
		if (i > M) up(len, a[i]), ret += lim <= i - len + 1 && max[i - len + 1] <= len;
	}
	for (i = L; i <= R; ++i) last[ a[i] ] = 0;
	lim = R, len = 1;
	for (i = R; i >= L; --i) {
		if (last[ a[i] ]) down(lim, last[ a[i] ] - 1);
		if (last[ a[i] ] = i, lim < M) break;
		if (i < M) up(len, a[i]), ret += lim >= i + len - 1 && max[i + len - 1] <= len;
	}
	for (i = L; i <= R; ++i) last[ a[i] ] = 0;
	return ret;
}

int main() {
	int i, ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) if (scanf("%d", a + i), a[i] == 1) one[++m] = i;
	one[++m] = n + 1;
	for (i = 1; i < m; ++i) ans += solve(one[i - 1] + 1, one[i], one[i + 1] - 1);
	printf("%d\n", ans);
	return 0;
}