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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod)
		if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, m, a[kN]; ll fac[kN], fac_inv[kN], inv[kN], f[kN];

void Init() {
	fac[0] = 1;
	for(int i = 1; i <= m; ++i) fac[i] = fac[i - 1] * i % kMod;
	fac_inv[m] = QPow(fac[m], kMod - 2);
	for(int i = m - 1; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
	for(int i = 1; i <= m; ++i) inv[i] = fac[i - 1] * fac_inv[i] % kMod;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		ll n1_inv;
		rd(n); n1_inv = QPow(n - 1, kMod - 2);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			m += a[i];
		}
		Init();
		f[0] = f[1] = 0;
		for(int i = 1; i < m; ++i) {
			ll d = inv[m - i] * (1 - n + kMod) % kMod,
				c = (1LL * i * (n - 2) + m) % kMod * n1_inv % kMod;
			c = (kMod - c) % kMod;
			f[i + 1] = (i * (f[i - 1] + 1) + c * f[i]) % kMod * d % kMod;
		}
		ll bg_tot = 0;
		for(int i = 1; i <= n; ++i) {
			bg_tot = (bg_tot + f[a[i]]) % kMod;
		}
		printf("%lld\n", (bg_tot - f[m] + kMod) % kMod);
	} return 0;
}