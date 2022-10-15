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

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		ll a[4], b[4], ans =0;
		for(int i = 0; i < 3; ++i) rd(a[i]);
		for(int i = 0; i < 3; ++i) rd(b[i]);
		ll x = std::min(a[2], b[1]);
		ans += x * 2; a[2] -= x; b[1] -= x;
		x = std::min(a[2], b[2]);
		a[2] -= x; b[2] -= x;
		x = std::min(a[2], b[0]);
		a[2] -= x; b[0] -= x;

		x = std::min(a[1], b[0]);
		a[1] -= x; b[0] -= x;
		x = std::min(a[1], b[1]);
		a[1] -= x; b[1] -= x;
		x = std::min(a[1], b[2]);
		ans -= 2 * x; a[1] -= x; b[2] -= x;

		printf("%lld\n", ans);
	} return 0;
}