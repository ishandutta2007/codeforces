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
typedef std::pair<int, int> pii;
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int nr, ng, nb;
ll r[kN], g[kN], b[kN];
ll Sq(ll x) { return x * x; }
ll Cal(int i, int j, int k) {
	if(i > nr || i < 0 || j > ng || j < 0 || k > nb || k < 0) return Cal(1, 1, 1);
	return Sq(r[i] - g[j]) + Sq(r[i] - b[k]) + Sq(g[j] - b[k]);
}
int main() { int T = 1; rd(T);
	while(T--) {
		rd(nr, ng, nb);
		for(int i = 1; i <= nr; ++i) rd(r[i]);
		for(int i = 1; i <= ng; ++i) rd(g[i]);
		for(int i = 1; i <= nb; ++i) rd(b[i]);
		std::sort(r + 1, r + nr + 1); std::sort(g + 1, g + ng + 1); std::sort(b + 1, b + nb + 1);
		nr = std::unique(r + 1, r + nr + 1) - r - 1;
		ng = std::unique(g + 1, g + ng + 1) - g - 1;
		nb = std::unique(b + 1, b + nb + 1) - b - 1;
		r[0] = g[0] = b[0] = 1e9 + 5;
		ll ans = Cal(1, 1, 1);
		for(int i = 1; i <= nr; ++i) {
			int i1 = std::lower_bound(g + 1, g + ng + 1, r[i]) - g,
				i2 = std::lower_bound(b + 1, b + nb + 1, r[i]) - b;
			ans = std::min({ans, Cal(i, i1, i2), Cal(i, i1 - 1, i2 - 1), Cal(i, i1, i2 - 1), Cal(i, i1 - 1, i2)});
		}
		for(int i = 1; i <= ng; ++i) {
			int i1 = std::lower_bound(r + 1, r + nr + 1, g[i]) - r,
				i2 = std::lower_bound(b + 1, b + nb + 1, g[i]) - b;
			ans = std::min({ans, Cal(i1, i, i2), Cal(i1 - 1, i, i2 - 1), Cal(i1, i, i2 - 1), Cal(i1 - 1, i, i2)});
		}
		for(int i = 1; i <= nb; ++i) {
			int i1 = std::lower_bound(r + 1, r + nr + 1, b[i]) - r,
				i2 = std::lower_bound(g + 1, g + ng + 1, b[i]) - g;
			ans = std::min({ans, Cal(i1, i2, i), Cal(i1 - 1, i2 - 1, i), Cal(i1, i2 - 1, i), Cal(i1 - 1, i2, i)});
		}
		printf("%lld\n", ans);
	} return 0;
}