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
const int N = 15, M = (1 << 14) + 5, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, a[N], g[N][N], w[N][M], f[M][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 0; i < n; ++i) rd(a[i]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				g[i][j] = 1LL * a[i] * QPow(a[i] + a[j], Mod - 2) % Mod;
		for(int i = 0; i < n; ++i)
			for(int S = 0; S < 1 << n; ++S) {
				w[i][S] = 1;
				for(int j = 0; j < n; ++j)
					if((S >> j) & 1) w[i][S] = 1LL * w[i][S] * g[i][j] % Mod;
			}
		int ans = 0;
		for(int S = 1; S < 1 << n; ++S) {
			if(S & -S == S) { f[S][1] = 1; continue; }
			for(int T = (S - 1) & S; T; T = (T - 1) & S) {
				int p = 1;
				for(int i = 0; i < n; ++i)
					if((T >> i) & 1) p = 1LL * p * w[i][S ^ T] % Mod;
				for(int i = 2; i <= n; ++i) {
					f[S][i] = (f[S][i] + 1LL * f[T][1] * f[S ^ T][i - 1] % Mod * p) % Mod;
					if(S == (1 << n) - 1) {
						int siz = __builtin_popcount(T);
						ans = (ans + 1LL * f[T][1] * f[S ^ T][i - 1] % Mod * p % Mod * siz) % Mod;
					}
				}
			}
			int tot = 0;
			for(int i = 2; i <= n; ++i)
				tot = (tot + f[S][i]) % Mod;
			f[S][1] = (1 - tot + Mod) % Mod;
		}
		ans = (ans + 1LL * n * f[(1 << n) - 1][1]) % Mod;
		printf("%d\n", ans);
	} return 0;
}