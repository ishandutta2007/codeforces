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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, k; ll s[kN][kN], C[kN], fac[kN], fac_inv[kN];

void Init() {
	s[0][0] = C[0] = fac[0] = 1;
	for(int i = 1; i <= k; ++i) {
		fac[i] = fac[i - 1] * i % kMod;
		C[i] = C[i - 1] * (n - i - 1) % kMod * QPow(i + 1, kMod - 2) % kMod;
		for(int j = 1; j <= k; ++j) {
			s[i][j] = (j * s[i - 1][j] + s[i - 1][j - 1]) % kMod;
		}
	}
	fac_inv[k] = QPow(fac[k], kMod - 2);
	for(int i = k - 1; ~i; --i)
		fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
}

ll F(int r) {
	ll ret = QPow(2, n - r);
	for(int i = n - r + 1; i <= n; ++i)
		ret = ret * i % kMod;
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		ll ans = 0;
		rd(n, k); Init();
		if(n > k) {
			for(int i = 0; i <= k; ++i)
				ans = (ans + s[k][i] * F(i)) % kMod;
			printf("%lld\n", ans);
		} else {
			for(int i = 0; i <= n; ++i)
				ans = (ans + fac[n] * fac_inv[i] % kMod * fac_inv[n - i] % kMod * QPow(i, k)) % kMod;
			printf("%lld\n", ans);
		}
	} return 0;
}