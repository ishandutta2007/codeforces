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

int n, nxt[N]; ll a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		a[n + 1] = -1;
		for(int i = n; i; --i) {
			if(a[i + 1] != a[i]) nxt[i] = i + 1;
			else nxt[i] = nxt[i + 1];
		}
		int ans = n;
		for(int i = 1; i <= n; ++i) {
			int cur_ans = nxt[i] - i;
			for(int j = nxt[i] - 1; j <= n; ++cur_ans) {
				j = std::lower_bound(a + j + 1, a + n + 1, a[j] + (a[j] - a[i])) - a;
			}
			ans = std::min(ans, n - (cur_ans - 1));
		}
		printf("%d\n", ans);
	} return 0;
}