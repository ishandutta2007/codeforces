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

const int kN = 3e5 + 5;
const ll kInf = 0x3f3f3f3f3f3f3f3fLL;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

ll a[kN], b[kN], bd[kN]; int n, m, k, q;
ll Cal() {
	ll ret = 0;
	bd[1] = std::min(a[1], b[n]);
	a[1] -= b[n];
	for(int i = 1; i <= n; ++i) {
		if(a[i] > 0) ret += a[i];
		bd[i + 1] = std::min(a[i + 1], b[i]);
		a[i + 1] -= b[i];
	}
	return ret;
}
int main() { int T = 1; rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i], b[i]);
		ll ret = Cal(), ans = kInf;
		for(int i = 1; i <= n; ++i) ans = std::min(ans, ret + bd[i]);
		printf("%lld\n", ans);
	} return 0;
}