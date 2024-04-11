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

ll C(int n, int m) {
	if(n < m) return 0;
	ll ret = 1;
	for(int i = n - m + 1; i <= n; ++i) ret *= i;
	for(int i = 1; i <= m; ++i) ret /= i;
	return ret;
}

ll Calc(ll r1, ll r2, ll r3, ll sum) {
	if(r1 < 1 || r2 < 1 || r3 < 1 || sum > r1 + r2 + r3 || sum < 3) return 0;
	ll ret = 0;
	ret += C(sum - 1, 2);
	ret -= C(sum - r1 - 1, 2) + C(sum - r2 - 1, 2) + C(sum - r3 - 1, 2);
	ret += C(sum - r1 - r2 - 1, 2) + C(sum - r2 - r3 - 1, 2) + C(sum - r3 - r1 - 1, 2);
	ret -= C(sum - r1 - r2 - r3 - 1, 2);
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		ll a, b, c, l; rd(a, b, c, l);
		ll ans = 0;
		for(ll i = a + b + c; i <= a + b + c + l; ++i) {
			int p = (i - 1) / 2;
			ans += Calc(p - a + 1, p - b + 1, p - c + 1, i - a - b - c + 3);
		}
		printf("%lld\n", ans);
	} return 0;
}