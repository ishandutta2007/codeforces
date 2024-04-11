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

int n; ll a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(i % 2 == 0) a[i] = -a[i];
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(a[i] < 0) continue;
			ll cur_top = a[i], mn = a[i] - 1;
			for(int j = i + 1; j <= n; ++j) {
				cur_top += a[j];
				if(a[j] < 0 && cur_top <= mn)
					ans += mn - std::max(cur_top, 0LL) + 1;
				if(cur_top < 0) break;
				mn = std::min(mn, cur_top);
			}
		}
		printf("%lld\n", ans);
	} return 0;
}