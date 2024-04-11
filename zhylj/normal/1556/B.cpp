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

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		int cnt_0 = 0, cnt_1 = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); a[i] %= 2;
			if(a[i]) ++cnt_1;
			else ++cnt_0;
		}
		if(abs(cnt_1 - cnt_0) > 1) printf("-1\n");
		else {
			ll ans = InfLL;
			if(cnt_0 >= cnt_1) {
				int cur_0 = 1; ll cur_ans = 0;
				for(int i = 1; i <= n; ++i)
					if(a[i] == 0) cur_ans += abs(i - cur_0), cur_0 += 2;
				ans = std::min(ans, cur_ans);
			}
			if(cnt_1 >= cnt_0) {
				int cur_0 = 2; ll cur_ans = 0;
				for(int i = 1; i <= n; ++i)
					if(a[i] == 0) cur_ans += abs(i - cur_0), cur_0 += 2;
				ans = std::min(ans, cur_ans);
			}
			printf("%lld\n", ans);
		}
	} return 0;
}