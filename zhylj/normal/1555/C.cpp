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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int m; ll s[2][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(m);
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= m; ++j) {
				rd(s[i][j]);
				s[i][j] += s[i][j - 1];
			}
		ll ans = InfLL;
		for(int i = 1; i <= m; ++i)
			ans = std::min(ans, std::max(s[0][m] - s[0][i], s[1][i - 1]));
		printf("%lld\n", ans);
	} return 0;
}