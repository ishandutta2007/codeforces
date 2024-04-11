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

int n, siz[N];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

void Dfs(int u, int p, int &rt, int &rt_mx) {
	int mx = 0;
	siz[u] = 1;
	for(int v : E[u]) if(v != p) {
		Dfs(v, u, rt, rt_mx);
		siz[u] += siz[v];
		mx = std::max(mx, siz[v]);
	}
	mx = std::max(mx, n - siz[u]);
	if(mx < rt_mx) {
		rt_mx = mx;
		rt = u;
	}
}

void Dfs2(int u, int p) {
	siz[u] = 1;
	for(int v : E[u]) if(v != p) {
		Dfs2(v, u);
		siz[u] += siz[v];
	}
}

int typ[N], dfv;
void Dfs3(int u, int p, int d, int t) {
	int u_dfv = ++dfv;
	printf("%d %d %d\n", p, u, (dfv - d) * t);
	for(int v : E[u]) if(v != p) {
		Dfs3(v, u, u_dfv, t);
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
		int rt = 0, rt_mx = 1e9;
		Dfs(1, 0, rt, rt_mx);
		std::sort(E[rt].begin(), E[rt].end(),
			[&](const int &u, const int &v) { return siz[u] > siz[v]; }
		);
		int A = 0, B = 0;
		for(int v : E[rt]) {
			Dfs2(v, rt);
			if(A < B) {
				typ[v] = 1, A += siz[v];
				Dfs3(v, rt, 0, 1);
			} else B += siz[v];
		}
		dfv = 0;
		for(int v : E[rt]) {
			if(!typ[v])
				Dfs3(v, rt, 0, A + 1);
		}
	} return 0;
}