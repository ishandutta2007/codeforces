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
const int N = 100 + 5, MOD = 998244353, INF = 0x3f3f3f3f;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int Inv(int a) { return QPow(a, MOD - 2); }

int fac[N], fac_inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = Inv(fac[N - 1]);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
}

int C(int x, int y) {
	if(x < y || y < 0) return 0;
	y = std::min(y, x - y);
	int ret = fac_inv[y];
	for(int i = 0; i < y; ++i)
		ret = 1LL * ret * (x - i) % MOD;
	return ret;
}

int n, c, L[N], R[N], d[N], w[N][N], f[N][N][N];

void Upd(int &x, int y, int c = 1) { x = (x + 1LL * y * c) % MOD; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); Init();
		int tot = 1, ans = 0;
		for(int i = 1; i <= n; ++i) {
			rd(L[i], R[i]); ++R[i];
			d[++c] = L[i];
			d[++c] = R[i];
			tot = 1LL * tot * (R[i] - L[i]) % MOD;
		}
		std::reverse(L + 1, L + n + 1);
		std::reverse(R + 1, R + n + 1);
		L[n + 1] = INF; R[n + 1] = INF + 1; ++n;
		d[++c] = INF; d[++c] = INF + 1;
		std::sort(d + 1, d + c + 1);
		c = std::unique(d + 1, d + c + 1) - d - 1;
		for(int i = 1; i <= n; ++i) {
			L[i] = std::lower_bound(d + 1, d + c + 1, L[i]) - d;
			R[i] = std::lower_bound(d + 1, d + c + 1, R[i]) - d;
		}
		for(int i = 1; i < c; ++i)
			for(int j = 1; j <= n; ++j)
				w[i][j] = C(d[i + 1] - d[i] + j - 1, j);
		for(int i = L[1]; i < R[1]; ++i) f[1][i][1] = 1;
		for(int i = 2; i <= n; ++i)
			for(int j = L[i - 1]; j < R[i - 1]; ++j)
				for(int k = 1; k <= i; ++k)
					for(int p = std::max(j, L[i]); p < R[i]; ++p) {
						Upd(f[i][p][p == j ? k + 1 : 1],
							f[i - 1][j][k],
							p == j ? 1 : w[j][k]
						);
					}
		ans = 1LL * f[n][c - 1][1] * Inv(tot) % MOD;
		printf("%d\n", ans);
	} return 0;
}