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
const int kN = 2e5 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

ll fac[kN], fac_inv[kN]; int n; ll k;
ll Bino(int x, int y) { return fac[x] * fac_inv[y] % kMod * fac_inv[x - y] % kMod; }
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		fac[0] = 1; rd(n, k);
		if(k > n) {
			printf("0"); return 0;
		}
		for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % kMod;
		fac_inv[n] = QPow(fac[n], kMod - 2);
		for(int i = n - 1; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
		k = n - k;
		ll ans = 0, tmp = 1;
		for(int i = 0; i <= k; ++i, tmp *= -1) {
			ans = (ans + tmp * QPow(k - i, n) % kMod * Bino(k, i) % kMod) % kMod;
		}
		ans = (ans * Bino(n, k) % kMod + kMod) % kMod;
		if(k != n) ans = ans * 2 % kMod;
		printf("%lld", ans);
	} return 0;
}