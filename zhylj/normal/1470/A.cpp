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

int n, m, k[kN], c[kN];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(k[i]);
		for(int i = 1; i <= m; ++i) rd(c[i]);
		for(int i = 1; i <= n; ++i) c[m + i] = k[i] = c[k[i]];
		m += n; std::sort(c + 1, c + m + 1);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += c[i];
		}
		printf("%lld\n", ans);
	} return 0;
}