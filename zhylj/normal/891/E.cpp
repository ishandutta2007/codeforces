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
const int N = 5e5 + 5, MOD = 1e9 + 7;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
void Plus(int &x, int y) { x += y; x -= x >= MOD ? MOD : 0; }
void Minus(int &x, int y) { x -= y; x += x < 0 ? MOD : 0; }

int n, k, a[N], g[N], h[N];

int A(int x, int y) {
	int ret = 1;
	for(int i = 1; i <= y; ++i)
		ret = 1LL * ret * (x - i + 1) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		int bg = 1;
		for(int i = 1; i <= n; ++i)
			rd(a[i]), bg = 1LL * bg * a[i] % MOD;
		g[0] = 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < i; ++j) {
				Plus(h[j], 1LL * g[j] * a[i] % MOD);
				Minus(h[j + 1], g[j]);
			}
			memcpy(g, h, sizeof(g));
			memset(h, 0, sizeof(h));
		}
		int rmv = 0, n_inv = QPow(n, MOD - 2);
		for(int i = 0; i <= n; ++i)
			Plus(rmv, 1LL * A(k, i) * g[i] % MOD * QPow(n_inv, i) % MOD);
		bg = (bg - rmv + MOD) % MOD;
		printf("%d\n", bg);
	} return 0;
}