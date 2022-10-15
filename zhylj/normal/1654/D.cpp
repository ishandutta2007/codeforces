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

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}

int n, buk[N], mx[N];

int p[N], s[N], p_cnt;
bool flag[N];
void Sieve() {
	s[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = i;
			s[i] = i;
		}
		for(int j = 1; p[j] * i < N && j <= p_cnt; ++j) {
			flag[i * p[j]] = true;
			s[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}

std::vector <int> GetDiv(int x) {
	std::vector <int> ret;
	while(x != 1) {
		ret.push_back(s[x]);
		x /= s[x];
	}
	return ret;
}

int X[N], Y[N];
std::vector <int> a[N], b[N];
std::vector <pii> E[N];

int f[N];
void Dfs(int u, int p) {
	for(pii i : E[u]) {
		int v = i.fi, idx = i.se;
		if(v != p) {
			f[v] = 1LL * f[u] * Y[idx] % MOD * QPow(X[idx], MOD - 2) % MOD;
			for(auto x : a[idx]) --buk[x];
			for(auto y : b[idx]) ++buk[y];
			for(auto x : a[idx]) mx[x] = std::max(mx[x], -buk[x]);
			for(auto y : b[idx]) mx[y] = std::max(mx[y], -buk[y]);
			Dfs(v, u);
			for(auto x : a[idx]) ++buk[x];
			for(auto y : b[idx]) --buk[y];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	Sieve();
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) E[i].clear();
		for(int i = 1; i <= n; ++i) mx[i] = buk[i] = f[i] = 0;
		for(int i = 1; i < n; ++i) {
			int u, v, x, y; rd(u, v, x, y);
			a[i * 2 - 1] = GetDiv(x); b[i * 2 - 1] = GetDiv(y);
			X[i * 2 - 1] = x; Y[i * 2 - 1] = y;
			a[i * 2] = b[i * 2 - 1]; b[i * 2] = a[i * 2 - 1];
			X[i * 2] = y; Y[i * 2] = x;
			E[u].push_back(mkp(v, i * 2 - 1));
			E[v].push_back(mkp(u, i * 2));
		}
		f[1] = 1; Dfs(1, 0);
		int ans = 0, lcm = 1;
		for(int i = 1; i <= n; ++i) {
			ans = (ans + f[i]) % MOD;
			lcm = 1LL * lcm * QPow(i, mx[i]) % MOD;
		}
		ans = 1LL * ans * lcm % MOD;
		printf("%d\n", ans);
	} return 0;
}