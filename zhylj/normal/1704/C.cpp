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

int n, m, a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) rd(a[i]);
		std::sort(a + 1, a + m + 1);
		for(int i = 1; i < m; ++i) b[i] = a[i + 1] - a[i] - 1;
		b[m] = n + a[1] - a[m] - 1;
		std::sort(b + 1, b + m + 1, std::greater <int>());
		int ans = 0;
		for(int i = 1, j = 0; i <= m; ++i) {
			b[i] -= j * 2;
			b[i] = std::max(b[i], 0);
			if(b[i] > 0) {
				++j;
				--b[i]; ++ans;
			}
			if(b[i] > 0) {
				--b[i];
				if(b[i] > 0) {
					--b[i]; ++ans; ++j;
				}
			}
			ans += b[i];
		}
		printf("%d\n", n - ans);
	} return 0;
}