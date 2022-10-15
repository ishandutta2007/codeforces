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
const int N = 2e6 + 5, MOD = 1e9 + 7, M = 20;

void FMT(ll f[], int n, bool flag) {
	int si = flag ? 1 : -1;
	for(int i = 1; i < 1 << n; i <<= 1)
		for(int j = 0; j < 1 << n; j += i << 1)
			for(int k = 0; k < i; ++k) {
				f[j + k] += si * f[i + j + k];
			}
}

int n; ll f[N], pw[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		int U = (1 << M) - 1;
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			++f[U]; ++f[x];
		}
		pw[0] = 1;
		for(int i = 1; i <= n; ++i)
			pw[i] = 1LL * pw[i - 1] * 2 % MOD;
		FMT(f, M, true);
		for(int i = 0; i < 1 << M; ++i) {
			// A + B = n
			// A + 2 * B = f[i]
			int B = f[i] - n, A = n - B;
			f[i] = pw[B];
		}
		FMT(f, M, false);
		f[0] = (f[0] % MOD + MOD) % MOD;
		printf("%lld\n", f[0] % MOD);
	} return 0;
}