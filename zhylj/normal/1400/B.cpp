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

ll p, f, cnts, cntw, s, w;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(p, f, cnts, cntw, s, w);
		if(s > w) std::swap(s, w), std::swap(cnts, cntw);
		ll ans = 0;
		for(int i = 0; i <= cnts && i * s <= p; ++i) {
			ll np = p - i * s, nf = f, cnt = 0;
			cnt += std::min(f / s, cnts - i);
			nf -= cnt * s;
			cnt += i + std::min(np / w + nf / w, cntw);
			ans = std::max(ans, cnt);
		}
		printf("%lld\n", ans);
	} return 0;
}