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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n; ll a[kN], fac[kN];

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

void Init() {
	fac[0] = 1;
	for(int i = 1; i <= n << 1; ++i) fac[i] = fac[i - 1] * i % kMod;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n); Init();
		for(int i = 1; i <= n << 1; ++i) {
			rd(a[i]);
		}
		std::sort(a + 1, a + 2 * n + 1);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) ans = (ans - a[i] + kMod) % kMod;
		for(int i = n + 1; i <= n << 1; ++i) ans = (ans + a[i]) % kMod;
		ll fac_inv_n = QPow(fac[n], kMod - 2);
		printf("%lld\n", ans * fac[n << 1] % kMod * fac_inv_n % kMod * fac_inv_n % kMod);
	} return 0;
}