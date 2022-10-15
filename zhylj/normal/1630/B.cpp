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

int n, k, a[N], b[N], s[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) rd(a[i]), ++b[a[i]];
		for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + b[i];
		int ans_x = 1, ans_y = n;
		for(int i = 1, j = 0; i <= n; ++i) {
			for(; j < n && 2 * (s[j] - s[i - 1]) - n < k; ++j);
			if(2 * (s[j] - s[i - 1]) - n >= k && j - i <= ans_y - ans_x) {
				ans_y = j; ans_x = i;
			}
		}
		int ned_mx = (n + k) / 2;
		printf("%d %d\n", ans_x, ans_y);
		for(int i = 1; i <= n; ++i) {
			if(ans_x <= a[i] && a[i] <= ans_y) {
				if(ned_mx) c[i] = 1, --ned_mx;
				else c[i] = -1;
			} else c[i] = -1;
		}
		int cur_s = 0, lst = 1;
		for(int i = 1; i <= n; ++i) {
			cur_s += c[i];
			if((cur_s == 1 && k > 1) || (k == 1 && i == n)) {
				printf("%d %d\n", lst, i);
				--k;
				lst = i + 1; cur_s = 0;
			}
		}
		for(int i = 1; i <= n; ++i) b[i] = s[i] = c[i] = 0;
	} return 0;
}