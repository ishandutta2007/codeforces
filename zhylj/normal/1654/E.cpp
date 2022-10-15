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
const int N = 1e5 + 5, B = 300;

int n, a[N], buk[N * B * 2], buk_d[N * 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		int ans = 1;
		for(int i = -B + 1; i < B; ++i) {
			for(int j = 1; j <= n; ++j) {
				++buk[a[j] + i * (n - j) + N * B];
				ans = std::max(ans, buk[a[j] + i * (n - j) + N * B]);
			}
			for(int j = 1; j <= n; ++j)
				--buk[a[j] + i * (n - j) + N * B];
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= i + N / B && j <= n; ++j) {
				if((a[j] - a[i]) % (j - i) == 0) {
					++buk_d[(a[j] - a[i]) / (j - i) + N];
					ans = std::max(ans, buk_d[(a[j] - a[i]) / (j - i) + N] + 1);
				}
			}
			for(int j = i + 1; j <= i + N / B && j <= n; ++j) {
				if((a[j] - a[i]) % (j - i) == 0) {
					--buk_d[(a[j] - a[i]) / (j - i) + N];
				}
			}
		}
		printf("%d\n", n - ans);
	} return 0;
}