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

int n, a[N], f[N], nxt[N], mx[N], r[N];

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
			mx[a[i]] = std::max(mx[a[i]], i);
		}
		for(int i = 1; i <= n; ++i)
			nxt[i] = mx[a[i]];
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int tar = i, n_tar = nxt[i];
			while(n_tar > tar) {
				int bg = tar;
				tar = n_tar;
				for(int j = bg + 1; j < tar; ++j) {
					r[j] = 1;
					n_tar = std::max(n_tar, nxt[j]);
				}
			}
			i = tar;
		}
		for(int i = 1; i <= n; ++i)
			ans += r[i];
		printf("%d\n", ans);
	} return 0;
}