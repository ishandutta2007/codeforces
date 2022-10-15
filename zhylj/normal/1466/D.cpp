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

int n, dg[kN]; ll w[kN], a[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		ll ans = 0; int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			rd(w[i]); dg[i] = 0;
			ans += w[i];
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			++dg[u]; ++dg[v];
		}
		for(int i = 1; i <= n; ++i) {
			while(--dg[i]) a[++cnt] = w[i];
		}
		std::sort(a + 1, a + cnt + 1);
		std::reverse(a + 1, a + cnt + 1);
		for(int i = 1; i < n; ++i) {
			printf("%lld ", ans);
			ans += a[i]; 
		}
		printf("\n");
	} return 0;
}