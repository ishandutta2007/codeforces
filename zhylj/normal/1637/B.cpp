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
const int N = 200 + 5;

int n, a[N], buk[N], cost[N][N], f[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(cost, ~0x3f, sizeof(cost));
		memset(a, 0, sizeof(a));
		memset(f, ~0x3f, sizeof(f));
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			a[i] = std::min(a[i], n + 1);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			memset(buk, 0, sizeof(buk));
			int cur_mex = 0;
			for(int j = i; j <= n; ++j) {
				++buk[a[j]];
				while(buk[cur_mex]) ++cur_mex;
				cost[i][j] = cur_mex + 1;
			}
		}
		for(int len = 1; len <= n; ++len) {
			for(int i = 1; i + len - 1 <= n; ++i) {
				int j = i + len - 1;
				f[i][j] = cost[i][j];
				for(int k = i; k < j; ++k)
					f[i][j] = std::max(f[i][j], f[i][k] + cost[k + 1][j]);
			}
		}
		for(int i = 1; i <= n; ++i)
			for(int j = i; j <= n; ++j)
				ans += f[i][j];
		printf("%d\n", ans);
	} return 0;
}