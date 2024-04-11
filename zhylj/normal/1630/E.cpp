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
const int N = 1e6 + 5, MOD = 998244353;

int QPow(int a, int b) {
	int res = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) res = 1LL * res * bas % MOD;
	return res;
}
int Inv(int a) { return QPow(a, MOD - 2); }
int Gcd(int a, int b) { return b ? Gcd(b, a % b) : a; }

int n, a[N], f[N], g[N], b[N], fac[N], fac_inv[N], inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[n] = Inv(fac[n]);
	for(int i = n - 1; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
	for(int i = 1; i <= n; ++i)
		inv[i] = 1LL * fac_inv[i] * fac[i - 1] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		Init();
		int ans = 0, tot = 0, gcd = 0;
		for(int i = 1; i <= n; ++i) b[i] = f[i] = g[i] = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]), ++b[a[i]];
		for(int i = 1; i <= n; ++i) gcd = Gcd(gcd, b[i]);
		if(gcd == n) { printf("1\n"); continue; }
		std::sort(b + 1, b + n + 1);
		std::reverse(b + 1, b + n + 1);
		for(int d = 1; d <= n; ++d) if(gcd % d == 0) {
			int t = n / d, c = fac[t];
			for(int i = 1; i <= n && b[i]; ++i) {
				int x = b[i] / d, y = (n - b[i]) / d, h = 0;
				h = 1LL * y * inv[x + y - 1] % MOD;
				c = 1LL * c * fac_inv[x] % MOD;
				f[d] = (f[d] + 1LL * x * h) % MOD;
			}
			f[d] = 1LL * f[d] * d % MOD * c % MOD;
			g[d] = c;
		}
		for(int i = 0; i < n; ++i) {
			ans = (ans + f[n / Gcd(i, n)]) % MOD;
			tot = (tot + g[n / Gcd(i, n)]) % MOD;
		}
		ans = 1LL * ans * Inv(tot) % MOD;
		printf("%d\n", ans);
	} return 0;
}