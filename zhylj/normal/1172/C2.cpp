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
const int N = 2e5 + 5, M = 3000 + 5, MOD = 998244353;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int n, m, a[N], w[N], f[M][M];
void Plus(int &x, int y) { x += y; x -= x >= MOD ? MOD : 0; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		int w_n = 0, w_p = 0;
		for(int i = 1; i <= n; ++i) {
			rd(w[i]);
			if(a[i]) Plus(w_p, w[i]);
			else Plus(w_n, w[i]);
		}
		f[0][0] = 1;
		for(int i = 0; i < m && i <= w_n; ++i)
			for(int j = 0; i + j < m; ++j) {
				int d = QPow((w_n + w_p - i + j) % MOD, MOD - 2);
				Plus(f[i + 1][j], 1LL * (w_n - i) * d % MOD * f[i][j] % MOD);
				Plus(f[i][j + 1], 1LL * (w_p + j) * d % MOD * f[i][j] % MOD);
			}
		int s_1 = 0, s_2 = 0;
		for(int i = 0; i <= m && i <= w_n; ++i) {
			int j = m - i;
			Plus(s_1, 1LL * f[i][j] * (w_n - i) % MOD);
			Plus(s_2, 1LL * f[i][j] * (w_p + j) % MOD);
		}
		for(int i = 1; i <= n; ++i) {
			int ans = 0;
			if(a[i]) ans = 1LL * s_2 * w[i] % MOD * QPow(w_p, MOD - 2) % MOD;
			else ans = 1LL * s_1 * w[i] % MOD * QPow(w_n, MOD - 2) % MOD;
			printf("%d\n", ans);
		}
	} return 0;
}