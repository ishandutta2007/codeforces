#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 2054, mod = 998244353;

int R, C, n;
int binom[2 * N][2 * N];
int u[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

inline int solve(int R, int C, bool strict) {
	int i, j, t, s = 0;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			u[i][j] = (ll)binom[i][j - 1] * binom[i - 1][C - j] % mod;
	for (i = 1; i < R; ++i)
		for (t = 0, j = 1; j < C; ++j) {
			if (!strict) add(t, u[i][j]);
			s = (s + (ll)t * u[R - i][C - j]) % mod;
			if (strict) add(t, u[i][j]);
		}
	return s;
}

int main() {
	int i, j, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> R >> C, n = std::max(R, C);
	for (i = 0; i <= 2 * n + 5; ++i) binom[i][0] = binom[0][i] = 1;
	for (i = 1; i <= 2 * n + 5; ++i) for (j = 1; j <= 2 * n + 5; ++j) add(binom[i][j] = binom[i - 1][j], binom[i][j - 1]);
	ans = solve(R, C, true);
	add(ans, solve(C, R, false));
	cout << ans * 2 % mod << '\n';
	return 0;
}
/*
---------
|----||||
|||--||||
|||-|||||
|||||--||
|||||---|
---------
*/