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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 60 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}
ll Abs(ll x) { return x < 0 ? -x : x; }

ll D, pf[kN], upf1[kN], upf2[kN], fac[kN], fac_inv[kN]; int q, cnt = 0;
int main() { int T = 1; //rd(T);
	while(T--) {
		rd(D, q);
		for(ll i = 2; i * i <= D; ++i) {
			if(D % i == 0) pf[++cnt] = i;
			while(D % i == 0) D /= i;
		}
		fac[0] = 1;
		for(int i = 1; i <= 60; ++i) fac[i] = fac[i - 1] * i % kMod;
		fac_inv[60] = QPow(fac[60], kMod - 2);
		for(int i = 59; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
		if(D != 1) pf[++cnt] = D;
		while(q--) {
			memset(upf1, 0, sizeof(upf1));
			memset(upf2, 0, sizeof(upf2));
			ll u, v, ans1 = 1, ans2 = 1, x1 = 0, x2 = 0; rd(u, v);
			for(int i = 1; i <= cnt; ++i) {
				while(u % pf[i] == 0) u /= pf[i], upf1[i]++;
				while(v % pf[i] == 0) v /= pf[i], upf2[i]++;
			}
			for(int i = 1; i <= cnt; ++i) {
				int dt = std::min(upf1[i], upf2[i]);
				ans1 = ans1 * fac_inv[upf1[i] - dt] % kMod;
				ans2 = ans2 * fac_inv[upf2[i] - dt] % kMod;
				x1 += upf1[i] - dt; x2 += upf2[i] - dt;
			}
			printf("%lld\n", ans1 * ans2 % kMod * fac[x1] % kMod * fac[x2] % kMod);
		}
	} return 0;
}