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
const int N = 2000 + 5, MOD = 1e9 + 7, INV2 = (MOD + 1) / 2;

int f[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m, k; rd(n, m, k);
		for(int i = 1; i <= n; ++i) {
			f[i][0] = 0; f[i][i] = 1LL * i * k % MOD;
			for(int j = 1; j < i; ++j)
				f[i][j] = 1LL * (f[i - 1][j] + f[i - 1][j - 1]) % MOD * INV2 % MOD;
		}
		printf("%d\n", f[n][m]);
	} return 0;
}