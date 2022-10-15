#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e5 + 5, M = 40, Mpw = 2e3 + 5, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, m, k, ans[M]; bool m_var[M]; ll b[M];

void Dfs(int cur, ll S) {
	if(cur == k) {
		++ans[__builtin_popcount(S & ((1 << 31) - 1)) + __builtin_popcount(S >> 31)];
		return;
	}
	Dfs(cur + 1, S ^ b[cur]); Dfs(cur + 1, S);
}
void Solve1() {
	std::sort(b, b + m);
	std::reverse(b, b + m);
	Dfs(0, 0);
}
int f[M][M][Mpw];
void Update(int &x, int y) { x = (x + y) % Mod; }
void Output(int x) {
	for(int i = m - 1; ~i; --i)
		printf("%d", (x >> i) & 1);
	printf("\n");
}
void Solve2() {
	for(int i = m - 1; ~i; --i) if(b[i]) {
		m_var[i] = true;
		for(int j = i + 1; j < m; ++j)
			if((b[j] >> i) & 1)
				b[j] ^= b[i];
	}
	std::sort(b, b + m);
	std::reverse(b, b + m);
	for(int i = 0; i < k; ++i) {
		ll x = 0; int p = 0;
		for(int j = 0; j < m; ++j)
			if(!m_var[j]) {
				x |= ((b[i] >> j) & 1) << (p++);
			}
		b[i] = x;
	}
	f[0][0][0] = 1;
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j <= k; ++j) {
			for(int S = 0; S < 1 << (m - k); ++S) {
				Update(f[i + 1][j + 1][S ^ b[i]], f[i][j][S]);
				Update(f[i + 1][j][S], f[i][j][S]);
			}
		}
	}
	for(int i = 0; i <= k; ++i)
		for(int S = 0; S < 1 << (m - k); ++S)
			Update(ans[i + __builtin_popcount(S)], f[k][i][S]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) {
			ll x; rd(x);
			for(int j = m - 1; ~j; --j) {
				if((~x >> j) & 1) continue;
				if(!b[j]) {
					b[j] = x;
					++k;
					break;
				}
				x ^= b[j];
			}
		}
		if(k <= 25) Solve1();
		else Solve2();
		for(int i = 0; i <= m; ++i)
			printf("%lld ", 1LL * ans[i] * QPow(2, n - k) % Mod);
		printf("\n");
	} return 0;
}