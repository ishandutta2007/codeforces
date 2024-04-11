#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e6 + 5, INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

int Gcd(int a, int b) { return b ? Gcd(b, a % b) : a; }

int n, m, a[N], b[N], gs[N], col[N];
ll v[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int g = 0; rd(n, m);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) rd(b[i]), g = Gcd(g, b[i]);
		for(int i = 1; i <= n; ++i) col[i] = (i - 1) % g;
		for(int i = 0; i < g; ++i) gs[i] = 0, v[i] = INFLL;
		for(int i = 1; i <= n; ++i) {
			if(a[i] < 0) {
				a[i] = -a[i];
				gs[col[i]] ^= 1;
				gs[(col[i] + 1) % g] ^= 1;
			}
			ans += a[i];
			v[col[i]] = std::min(v[col[i]], 2LL * a[i]);
		}
		ll rmv_0 = 0, rmv_1 = v[g - 1];
		for(int i = 0, d = 0; i < g - 1; ++i) {
			if(gs[i] ^ d) {
				rmv_0 += v[i];
				d = 1;
			} else d = 0;
		}
		for(int i = 0, d = 1; i < g - 1; ++i) {
			if(gs[i] ^ d) {
				rmv_1 += v[i];
				d = 1;
			} else d = 0;
		}
		printf("%lld\n", ans - std::min(rmv_0, rmv_1));
	} return 0;
}