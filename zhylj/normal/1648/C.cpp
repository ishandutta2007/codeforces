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
const int N = 2e5 + 5, MOD = 998244353;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int fac[N], fac_inv[N], inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = QPow(fac[N - 1], MOD - 2);
	for(int i = N - 2; ~i; --i) fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
	for(int i = 1; i < N; ++i) inv[i] = 1LL * fac_inv[i] * fac[i - 1] % MOD;
}

struct Bit {
	int tr[N];
	void Modify(int o, int v) {
		for(; o < N; o += o & -o) tr[o] = (tr[o] + v) % MOD;
	}
	int Query(int o) {
		int ret = 0;
		for(; o; o -= o & -o) ret = (ret + tr[o]) % MOD;
		return ret;
	}
} T;

int n, m, s[N], t[N], buk[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); Init();
		for(int i = 1; i <= n; ++i) rd(s[i]), ++buk[s[i]];
		for(int i = 1; i <= m; ++i) rd(t[i]);
		int ans = 0, cur_ans = 1;
		for(int i = 1; i < N; ++i)
			if(buk[i]) {
				T.Modify(i, buk[i]);
				cur_ans = 1LL * cur_ans * fac_inv[buk[i]] % MOD;
			}
		for(int i = 1; i <= std::min(m, n); ++i) {
			ans = (ans + 1LL * T.Query(t[i] - 1) * cur_ans % MOD * fac[n - i]) % MOD;
			if(!buk[t[i]])
				break;
			cur_ans = 1LL * cur_ans * buk[t[i]] % MOD;
			T.Modify(t[i], -1);
			--buk[t[i]];
			if(i == n && i != m) ans = (ans + 1) % MOD;
		}
		printf("%d\n", ans);
	} return 0;
}