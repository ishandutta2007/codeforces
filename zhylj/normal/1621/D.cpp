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
const int N = 500 + 5, M = 5e5 + 5;

int n, c[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		ll ans = 0;
		for(int i = 1; i <= n << 1; ++i)
			for(int j = 1; j <= n << 1; ++j) {
				rd(c[i][j]);
				if(i > n && j > n) ans += c[i][j], c[i][j] = 0;
			}
		printf("%lld\n", ans + std::min({ c[n][n << 1], c[n][n + 1], c[n << 1][n], c[n + 1][n],
			c[n + 1][1], c[1][n + 1], c[1][n << 1], c[n << 1][1] }));
	} return 0;
}