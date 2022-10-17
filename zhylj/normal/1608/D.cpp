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
const int N = 2e6 + 5, MOD = 998244353;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int n, fac[N], fac_inv[N], ans[N], cnt_1, cnt_2, cnt_3;
char opt[5];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = QPow(fac[N - 1], MOD - 2);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % MOD * fac_inv[x - y] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		Init();
		int add_1 = 1, add_2 = 1, rmv = 1, ans = 0, y = n;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", opt);
			int case_cnt = 0;
			if(opt[0] == '?' && opt[1] == '?') ++cnt_1;
			else if(((opt[0] == 'W' && opt[1] == '?') || (opt[0] == '?' && opt[1] == 'W')))
				++cnt_2;
			else if(((opt[0] == '?' && opt[1] == 'B') || (opt[0] == 'B' && opt[1] == '?')))
				++cnt_3, --y;
			else if(opt[0] == 'B' && opt[1] == 'B') y -= 2;
			else if((opt[0] == 'W' && opt[1] == 'B') || (opt[0] == 'B' && opt[1] == 'W'))
				--y;

			if((opt[0] == '?' || opt[0] == 'W') && (opt[1] == '?' || opt[1] == 'B'))
				++case_cnt;
			else add_1 = 0;

			if((opt[0] == '?' || opt[0] == 'B') && (opt[1] == '?' || opt[1] == 'W'))
				++case_cnt;
			else add_2 = 0;

			rmv = 1LL * case_cnt * rmv % MOD;
		}
		int x = cnt_1 * 2 + cnt_2 + cnt_3;
		ans = (ans - rmv + C(x, y) + add_1 + add_2) % MOD;
		ans = (ans + MOD) % MOD;
		printf("%d\n", ans);
	} return 0;
}