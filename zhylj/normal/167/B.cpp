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
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 200 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, l, K; ff p[N], f[N][N], g[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, l, K);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			p[i] = x / 100.0;
		}
		f[0][0] = 1; g[0] = 1;
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			if(x >= 0) {
				for(int j = n; ~j; --j) {
					for(int k = n; ~k; --k) {
						ff tmp = f[j][k]; f[j][k] = 0;
						f[j + 1][std::min(k + x, n)] += p[i] * tmp;
						f[j][k] += (1 - p[i]) * tmp;
					}
				}
			} else {
				for(int j = n; ~j; --j) {
					if(j) g[j] = p[i] * g[j - 1] + (1 - p[i]) * g[j];
					else g[j] = (1 - p[i]) * g[j];
				}
			}
		}
		ff ans = 0;
		for(int i = 0; i <= n; ++i)
			for(int j = std::max(l - i, 0); j <= n; ++j)
				for(int k = std::max(i - K, 0); k <= n; ++k) {
					ans += f[j][k] * g[i];
				}
		printf("%.12lf\n", ans);
	} return 0;
}