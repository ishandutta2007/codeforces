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

int n, q; ll s[N], sd[N], d[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(s[i]);
		std::sort(s + 1, s + n + 1);
		for(int i = 1; i < n; ++i) d[i] = s[i + 1] - s[i];
		std::sort(d + 1, d + n);
		for(int i = n - 1; i; --i) sd[i] = sd[i + 1] + d[i];
		rd(q);
		while(q--) {
			int idx;
			ll l, r, len, ans; rd(l, r);
			len = r - l + 1;
			ans = s[n] - s[1] + len;
			idx = std::lower_bound(d + 1, d + n, len) - d;
			ans -= sd[idx] - (n - idx) * len;
			printf("%lld ", ans);
		}
		printf("\n");
	} return 0;
}