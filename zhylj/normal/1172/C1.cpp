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
const int N = 50 + 5, MOD = 998244353;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int n, m; ll a[N], w[N], f[N][N][N];
void Plus(ll &x, ll y) { x = ((ll)x % MOD + y % MOD + MOD) % MOD; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]), a[i] = a[i] * 2 - 1;
		for(int i = 1; i <= n; ++i) rd(w[i]);
		for(int i = 1; i <= n; ++i) {
			memset(f, 0, sizeof(f));
			ll w_n = 0, w_p = 0, res = 0;
			for(int j = 1; j <= n; ++j) {
				if(i != j) {
					w_n += a[j] < 0 ? w[j] : 0;
					w_p += a[j] > 0 ? w[j] : 0;
				}
			}
			f[0][0][0] = 1;
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < m; ++k)
					for(int l = 0; l < m; ++l) {
						int d = QPow(w_n + w_p + w[i] - j + k + a[i] * l, MOD - 2);
						Plus(f[j + 1][k][l], 1LL * (w_n - j) * d % MOD * f[j][k][l] % MOD);
						Plus(f[j][k + 1][l], 1LL * (w_p + k) * d % MOD * f[j][k][l] % MOD);
						Plus(f[j][k][l + 1], 1LL * (w[i] + a[i] * l) * d % MOD * f[j][k][l] % MOD);
					}
			for(int j = 0; j <= m; ++j)
				for(int k = 0; j + k <= m; ++k) {
					int l = m - j - k;
					Plus(res, 1LL * f[j][k][l] * (w[i] + a[i] * l) % MOD);
				}
			printf("%lld\n", res);
		}
	} return 0;
}