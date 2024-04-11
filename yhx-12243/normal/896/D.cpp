#include <bits/stdc++.h>
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int mod;
int n, l, r;
int o = 0, pr[10], al[10], pral[10][32];
int maj[N], fact[N], finv[N], c[N][10];

inline int min(const int x, const int y) {return x < y ? x : y;}

int exgcd(int a, int b, int &x, int &y) {
	if (b) {int d = exgcd(b, a % b, y, x); return y -= a / b * x, d;}
	else return x = 1, y = 0, a;
}

void init(int n) {
	int i, j, x;
	for (*fact = i = 1; i <= n; ++i) {
		for (x = i, j = 0; j < o; ++j)
			for (c[i][j] = c[i - 1][j]; !(x % pr[j]); x /= pr[j], ++c[i][j]);
		maj[i] = x, fact[i] = (ll)fact[i - 1] * x % mod;
	}
	exgcd(fact[n], mod, finv[n], i), finv[n] += finv[n] >> 31 & mod;
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * maj[i] % mod;
}

inline ll C(int n, int r) {
	if (r < 0 || n < r) return 0;
	int i, ret = (ll)fact[n] * finv[r] % mod * finv[n - r] % mod;
	for (i = 0; i < o; ++i) ret = (ll)ret * pral[i][c[n][i] - c[r][i] - c[n - r][i]] % mod;
	return ret;
}

void factor(int n) {
	int i, j;
	if (!(n & 1)) pr[o] = 2, n >>= al[o++] = ctz(n);
	for (i = 3; i * i <= n; i += 2)
		if (!(n % i)) for (pr[o++] = i; !(n % i); n /= i, ++al[~-o]);
	if (n != 1) pr[o] = n, al[o++] = 1;
	for (i = 0; i < o; ++i)
		for (*pral[i] = j = 1; j < 32; ++j) pral[i][j] = (ll)pral[i][j - 1] * pr[i] % mod;
}

int main() {
	int i, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> mod >> l >> r, ++r, factor(mod), init(n);
	for (i = n; i >= l; --i) ans = (ans + (C(i, (i - l) >> 1) - C(i, (i - r) >> 1)) * C(n, i)) % mod;
	cout << ans + (ans >> 31 & mod) << '\n';
	return 0;
}