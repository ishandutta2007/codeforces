#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e6 + 5, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, q, f[N], fac[N], fac_inv[N], inv_3;
int C(int x, int y) {
	if(x < y) return 0;
	return 1LL * fac[x] * fac_inv[y] % Mod * fac_inv[x - y] % Mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		fac[0] = 1;
		for(int i = 1; i <= 3 * n; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
		fac_inv[3 * n] = QPow(fac[3 * n], Mod - 2);
		for(int i = 3 * n - 1; ~i; --i)
			fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % Mod;
		inv_3 = QPow(3, Mod - 2);
		for(int i = 0; i <= n; ++i) {
			f[0] = (f[0] + 1) % Mod;
			f[1] = (f[1] + 3 * i) % Mod;
			f[2] = (f[2] + 3LL * i * (3 * i - 1)  / 2) % Mod;
		}
		for(int i = 2; i < 3 * n; ++i) {
			ll s1 = -C(3 * n, i + 1), s2 = -3LL * C(3 * n, i) % Mod,
				s3 = 3LL * (f[i - 1] - C(3 * n, i - 1)) % Mod,
				s4 = f[i - 2] - C(3 * n, i - 2);
			f[i] = -1LL * inv_3 * (s1 + s2 + s3 + s4) % Mod;
			f[i] = (f[i] + Mod) % Mod;
		}
		f[3 * n] = 1;
		while(q--) {
			int x; rd(x);
			printf("%d\n", f[x]);
		}
	} return 0;
}