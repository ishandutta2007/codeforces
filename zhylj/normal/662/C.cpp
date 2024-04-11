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
const int N = 20 + 5, M = 1e5 + 5, K = 2e6 + 5;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m; ll s[K], b[K];
char g[N][M];

void FWT(ll f[], bool flag) {
	for(int i = 1; i < 1 << n; i <<= 1)
		for(int j = 0; j < 1 << n; j += i << 1)
			for(int k = 0; k < i; ++k) {
				ll fl = f[j + k], fr = f[i + j + k];
				f[j + k] = fl + fr;
				f[i + j + k] = fl - fr;
			}
	if(!flag) {
		for(int i = 0; i < 1 << n; ++i)
			f[i] /= 1 << n;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i)
			scanf("%s", g[i] + 1);
		for(int i = 1; i <= m; ++i) {
			int x = 0;
			for(int j = 1; j <= n; ++j)
				x |= (g[j][i] - '0') << (j - 1);
			++s[x];
		}
		for(int i = 1; i < 1 << n; ++i) {
			int cnt = __builtin_popcount(i);
			b[i] = std::min(cnt, n - cnt);
		}
		FWT(s, true); FWT(b, true);
		for(int i = 0; i < 1 << n; ++i)
			s[i] *= b[i];
		FWT(s, false);
		ll ans = InfLL;
		for(int i = 0; i < 1 << n; ++i)
			ans = std::min(ans, s[i]);
		printf("%lld\n", ans);
	} return 0;
}