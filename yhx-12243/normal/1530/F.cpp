#include <bits/stdc++.h>
#define popc __builtin_popcount
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 25, N2 = 2100000, mod = 31607;

int n;
int a[N][N], ai[N][N2], b[N][N];
int f[N];
int L[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int PowerMod(int a, int n, int c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline int work() {
	int i, j, k, P = 1, Q, ret = 0;
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) P = P * a[i][j] % mod, a[i][j] = PowerMod(a[i][j], mod - 2);
	memset(L, 0, sizeof L), *f = 1;
	for (j = 0; j < n; ++j) {
		ai[j][0] = 1;
		f[j + 1] = 0;
		for (k = j + 1; k; --k) f[k] = (f[k] + f[k - 1]) % mod;
	}
	for (k = 0; k <= n; ++k) add(L[0][k], f[k]);
	
	for (i = 1; i < 1 << n; ++i) {
		for (j = 0; j < n; ++j) {
			ai[j][i] = ai[j][i & (i - 1)] * a[j][ctz(i)] % mod;
			f[j + 1] = 0;
			for (k = j + 1; k; --k) f[k] = (f[k] + f[k - 1] * ai[j][i]) % mod;
		}
		for (k = 0; k <= n; ++k) add(L[popc(i)][k], f[k]);
	}
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= n; ++j)
			(i ^ j) & 1 ? ret -= L[i][j] : ret += L[i][j];
	return P * (ret % mod + mod) % mod;
}


int main() {
	int i, j, A, x;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) cin >> x, a[i][j] = b[i][j] = 3973 * x % mod;
	A = work();

	memcpy(a, b, sizeof a);
	for (x = 1, i = 0; i < n; ++i) x = x * a[i][i] % mod, a[i][i] = 1;
	A -= work() * x;

	memcpy(a, b, sizeof a);
	for (x = 1, i = 0; i < n; ++i) x = x * a[i][n - i - 1] % mod, a[i][n - i - 1] = 1;
	A -= work() * x;

	memcpy(a, b, sizeof a);
	for (x = 1, i = 0; i < n; ++i) {
		x = x * a[i][i] % mod;
		if (i != n - i - 1) x = x * a[i][n - i - 1] % mod;
		a[i][i] = a[i][n - i - 1] = 1;
	}
	A += work() * x;

	A = mod + 1 - A;
	cout << (A % mod + mod) % mod << '\n';
	return 0;
}