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
const int N = 1e5 + 5, MOD = 1e9 + 7;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
int Inv(int a) { return QPow(a, MOD - 2); }

inline void Inc(int &x, int y) { x += y; x -= x >= MOD ? MOD : 0; }
inline void Dec(int &x, int y) { x -= y; x += x < 0 ? MOD : 0; }
struct Seg {
	struct Bit {
		int tr[N];
		void Modify(int o, int v) {
			if(v < 0) v += MOD;
			for(; o < N; o += o & -o)
				Inc(tr[o], v);
		}
		int Query(int o) {
			int ret = 0;
			for(; o; o -= o & -o)
				Inc(ret, tr[o]);
			return ret;
		}
	} A, B;
	void Modify(int x, int v) {
		A.Modify(x, v);
		B.Modify(x, 1LL * x * v % MOD);
	}
	int Query(int x) {
		return (1LL * (x + 1) * A.Query(x) - B.Query(x) + MOD) % MOD;
	}
	void Modify(int x, int y, int v) { Modify(x, v); Modify(y + 1, -v); }
	int Query(int x, int y) { return (Query(y) - Query(x - 1) + MOD) % MOD; }
} T;

int n, p[N], vis[N];
std::vector <int> opt[N], E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}
int fa[N], siz[N], hvy[N], dep[N];
void Dfs(int u, int p) {
	fa[u] = p;
	siz[u] = 1;
	dep[u] = dep[p] + 1;
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[hvy[u]])
			hvy[u] = v;
	}
}
int dfn[N], top[N], dfv;
void Dfs2(int u, int p, int t) {
	dfn[u] = ++dfv; top[u] = t;
	if(hvy[u]) Dfs2(hvy[u], u, t);
	for(int v : E[u]) if(v != p && v != hvy[u]) {
		Dfs2(v, u, v);
	}
}
void Modify(int u, int v) {
	while(u) {
		T.Modify(dfn[top[u]], dfn[u], v);
		u = fa[top[u]];
	}
}
int Query(int u) {
	int ret = 0;
	while(u) {
		Inc(ret, T.Query(dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	return ret;
}
int tot, tot_dep;
void Insert(int u, int v) {
	tot = (tot + v * p[u]) % MOD;
	tot = (tot + MOD) % MOD;
	tot_dep = (tot_dep + 1LL * v * p[u] * dep[u]) % MOD;
	tot_dep = (tot_dep + MOD) % MOD;
	Modify(u, v * p[u]);
	vis[u] ^= 1;
}
int GetAns(int u) {
	int ret = (
		-2LL * Query(u) * p[u] +
		1LL * tot_dep * p[u] +
		1LL * tot * dep[u] % MOD * p[u]
	) % MOD;
	ret = (ret + MOD) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		int ans = 0, cur_ans = 0, d = 1;
		for(int i = 1; i <= n; ++i) {
			int l, r; rd(l, r);
			p[i] = Inv(r - l + 1);
			d = 1LL * d * (r - l + 1) % MOD;
			opt[l].push_back(i);
			opt[r + 1].push_back(i);
		}
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		Dfs(1, 0);
		Dfs2(1, 0, 1);
		for(int c = 1; c < N; ++c) {
			for(int u : opt[c]) {
				if(vis[u]) {
					Insert(u, -1);
					Dec(cur_ans, GetAns(u));
				} else {
					Inc(cur_ans, GetAns(u));
					Insert(u, 1);
				}
			}
			Inc(ans, cur_ans);
		}
		ans = 1LL * ans * d % MOD;
		printf("%d\n", ans);
	} return 0;
}