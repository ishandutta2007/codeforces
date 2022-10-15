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
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 100 + 5, ST = 1e5 + 5, Inf = 0x3f3f3f3f;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b, int p) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % p)
		if(b & 1) ret = 1LL * ret * bas % p;
	return ret;
}

ll n; int m, tot, pw[N], cnt[10], bas[10];
ll f[N][ST]; bool vis[N][ST];
ll Dfs(int u, int res, int S) {
	if(vis[res][S]) return f[res][S];
	if(u == tot) return res == 0;
	ll ret = 0;
	for(int i = 0; i < 10; ++i)
		if(S / bas[i] % (cnt[i] + 1))
			ret += Dfs(u + 1, (res + i * pw[u]) % m, S - bas[i]);
	return vis[res][S] = true, f[res][S] = ret;
}
ll Solve() {
	memset(f, 0, sizeof(f));
	memset(bas, 0, sizeof(bas));
	memset(vis, false, sizeof(vis));
	int S = 0;
	bas[0] = 1;
	for(int i = 1; i < 10; ++i)
		bas[i] = bas[i - 1] * (cnt[i - 1] + 1);
	for(int i = 0; i < 10; ++i)
		S += bas[i] * cnt[i];
	return Dfs(0, 0, S);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 0; i < 18; ++i)
			pw[i] = QPow(10, i, m);
		while(n) {
			++cnt[n % 10];
			++tot;
			n /= 10;
		}
		ll ans = Solve();
		if(cnt[0]) {
			--cnt[0]; --tot;
			ans -= Solve();
		}
		printf("%lld\n", ans);
	} return 0;
}