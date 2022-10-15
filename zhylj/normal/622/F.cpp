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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

ll fac[kN], fac_inv[kN], y[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		ll n, k;
		rd(n, k);
		ll p = 1, ans = 0;
		fac[0] = 1;
		for(int i = 1; i <= k + 2; ++i) {
			y[i] = (y[i - 1] + QPow(i, k)) % kMod;
		}
		if(n <= k + 2) {
			printf("%lld\n", y[n]);
			return 0;
		}
		k += 2;
		for(int i = 1; i <= k; ++i) {
			p = p * (n - i) % kMod;
			fac[i] = fac[i - 1] * i % kMod;
		}
		fac_inv[k] = QPow(fac[k], kMod - 2);
		for(int i = k - 1; ~i; --i)
			fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
		for(int i = 1; i <= k; ++i) {
			ll t = p * QPow(n - i, kMod - 2) % kMod, d = fac_inv[i - 1] * fac_inv[k - i] % kMod;
			if((k - i) & 1) d = kMod - d;
			ans = (ans + t * d % kMod * y[i]) % kMod;
		}
		printf("%lld\n", ans);
	} return 0;
}