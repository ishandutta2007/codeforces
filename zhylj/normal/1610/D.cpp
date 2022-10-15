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

int n, a[N], b[N];
int RmvOdd() {
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] % 2 == 0) b[++cnt] = a[i];
	int rmv = n - cnt;
	for(int i = 1; i <= cnt; ++i)
		a[i] = b[i];
	n = cnt;
	return rmv;
}
int Log2(int x) {
	if(x % 2 == 0) return Log2(x / 2) + 1;
	else return 0;
}
int c[40];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i)
			rd(a[i]);
		int rmv = RmvOdd(), ans = 0, ans_2 = 1;
		ans = (ans + 1LL * QPow(2, n) * (QPow(2, rmv) - 1 + MOD)) % MOD;
		for(int i = 1; i <= n; ++i)
			++c[Log2(a[i])];
		for(int i = 32; i; --i) {
			if(c[i]) {
				ans = (ans + 1LL * ans_2 * (QPow(2, c[i] - 1) - 1 + MOD)) % MOD;
				ans_2 = 1LL * ans_2 * QPow(2, c[i]) % MOD;
			}
		}
		ans = ans % MOD;
		printf("%d\n", ans);
	} return 0;
}