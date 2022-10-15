#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e6 + 5, MOD = 1e9 + 7, INV2 = (MOD + 1) / 2;

int QPow(int a, int b) {
	int res = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) res = 1LL * res * bas % MOD;
	return res;
}

int fac[N], fac_inv[N], pw[N];
int C(int x, int y) {
	if(y < 0 || x < y) return 0;
	return 1LL * fac[x] * fac_inv[y] % MOD * fac_inv[x - y] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	fac[0] = 1;
	for(int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = QPow(fac[N - 1], MOD - 2);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
	pw[0] = 1;
	for(int i = 1; i < N; ++i)
		pw[i] = 1LL * pw[i - 1] * INV2 % MOD;
	while(test_case_cnt--) {
		int n, m, k; rd(n, m, k);
		int ans = 0;
		if(n == m) {
			ans = 1LL * m * k % MOD;
			printf("%d\n", ans);
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			if(n < i + 1 || m < i) continue;
			ans = (ans + 1LL * (C(n - (i + 1), m - i) + MOD) % MOD
									* i % MOD * k % MOD * pw[n - i]) % MOD;
			ans = (ans + MOD) % MOD;
		}
		printf("%d\n", ans);
	} return 0;
}