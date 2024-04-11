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
const int N = 5e5 + 5;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m; ll t_a, t_b, k, a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, t_a, t_b, k);
		memset(a, 0x3f, sizeof(a));
		memset(b, 0x3f, sizeof(b));
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) rd(b[i]);
		if(k >= n) { printf("-1\n"); return 0; }
		ll ans = -INFLL;
		for(int i = 0; i <= k; ++i) {
			int j = std::lower_bound(b + 1, b + m + 1, a[i + 1] + t_a) - b + k - i;
			ans = std::max(ans, b[j] + t_b);
		}
		printf("%lld\n", ans >= INFLL ? -1 : ans);
	} return 0;
}