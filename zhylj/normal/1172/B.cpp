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
const int N = 5e5 + 5, MOD = 998244353;

int n, dg[N], fac[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			++dg[u]; ++dg[v];
		}
		fac[0] = 1;
		for(int i = 1; i <= n; ++i) 
			fac[i] = 1LL * fac[i - 1] * i % MOD;
		int ans = n;
		for(int i = 1; i <= n; ++i)
			ans = 1LL * ans * fac[dg[i]] % MOD;
		printf("%d\n", ans);
	} return 0;
}