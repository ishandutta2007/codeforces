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
const int N = 5e5 + 5;

struct Dsu {
	int fa[N];
	void Init(int n) { for(int i = 1; i <= n; ++i) fa[i] = i; }
	int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
	bool Merge(int x, int y) {
		x = Find(x); y = Find(y);
		if(x != y) {
			fa[x] = y;
			return true;
		}
		return false;
	}
} A;

int n, m, t, U[N], V[N], d[N];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}
int dfn[N], siz[N], dfv;
std::vector <int> T[N];
void Dfs(int u, int p) {
	siz[u] = 1; dfn[u] = ++dfv;
	auto cmp = [&](const int &u, const int &v) {
		return dfn[u] < dfn[v];
	};
	for(int v : E[u]) if(v != p) {
		Dfs(v, u);
		siz[u] += siz[v];
		T[u].push_back(v);
	}
	std::sort(T[u].begin(), T[u].end(), cmp);
}
void Dfs2(int u, int p) {
	d[u] += d[p];
	for(int v : E[u]) if(v != p) {
		Dfs2(v, u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); A.Init(n);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			if(!A.Merge(u, v)) {
				++t;
				U[t] = u; V[t] = v;
			} else Add(u, v);
		}
		Dfs(1, 0);
		auto cmp = [&](const int &u, const int &v) {
			return dfn[u] < dfn[v];
		};
		for(int i = 1; i <= t; ++i) {
			int u = U[i], v = V[i];
			if(dfn[u] > dfn[v]) std::swap(u, v);
			if(dfn[u] <= dfn[v] && dfn[v] + siz[v] <= dfn[u] + siz[u]) {
				++d[1]; ++d[v];
				int w = *(std::upper_bound(T[u].begin(), T[u].end(), v, cmp) - 1);
				--d[w];
			} else {
				++d[u]; ++d[v];
			}
		}
		Dfs2(1, 0);
		for(int i = 1; i <= n; ++i)
			printf(d[i] == t ? "1" : "0");
		printf("\n");
	} return 0;
}