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

int n;
std::vector <int> E[N], f[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
	f[u].push_back(1);
	f[v].push_back(1);
}

void Inc(int &x, int y) { x = (x + y) % MOD; }
void Mul(int &x, int y) { x = 1LL * x * y % MOD; }

int s[N][3];
void Dfs(int u, int p) {
	for(int v : E[u])
		if(v != p) Dfs(v, u);
	std::vector <int> pre(f[u].size(), 1), suf(f[u].size(), 1);
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(v != p) {
			Mul(suf[i + 1], s[v][1] + s[v][0]);
			if(i) Mul(pre[i - 1], s[v][2] + s[v][0]);
			Mul(f[u][i], s[v][2]);
		}
	}
	for(int i = 0; i < E[u].size(); ++i)
		Mul(suf[i + 1], suf[i]);
	for(int i = E[u].size(); i; --i)
		Mul(pre[i - 1], pre[i]);
	for(int i = 0; i < f[u].size(); ++i) {
		Mul(f[u][i], pre[i]);
		Mul(f[u][i], suf[i]);
	}
	s[u][2] = f[u].back();
	for(int i = 0, j = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(v != p) Inc(s[u][j], f[u][i]);
		else s[u][1] = f[u][i], j = 2;
	}
}

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
			Add(u, v);
		}
		for(int i = 1; i <= n; ++i) f[i].push_back(1);
		Dfs(1, 0);
		int ans = 0;
		for(int v : f[1])
			Inc(ans, v);
		printf("%d\n", ans);
	} return 0;
}