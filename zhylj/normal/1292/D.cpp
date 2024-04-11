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
const int N = 5e3 + 5, M = 700 + 5;

int p[M], f[N], pw[M][N], p_cnt;
bool flag[N];
void Init() {
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) p[++p_cnt] = i, f[i] = i;
		for(int j = 1; j <= p_cnt && i * p[j] < N; ++j) {
			flag[i * p[j]] = true; f[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 1; i <= p_cnt; ++i) {
		for(int q = p[i]; q < N; q = q * p[i])
			for(int j = q; j < N; j += q) ++pw[i][j];
		for(int j = 1; j < N; ++j) pw[i][j] += pw[i][j - 1];
	}
}

int n, m, g[N << 1];
std::vector <int> s[N << 1];

bool Cmp(const std::vector <int> &x, const std::vector <int> &y) {
	for(int i = p_cnt - 1; ~i; --i)
		if(x[i] != y[i]) return x[i] < y[i];
	return false;
}
std::vector <int> Lca(std::vector <int> &x, std::vector <int> &y) {
	std::vector <int> ret(p_cnt, 0);
	for(int i = p_cnt - 1; ~i; --i) {
		ret[i] = std::min(x[i], y[i]);
		if(x[i] != y[i]) break;
	}
	return ret;
}
int DistAnc(std::vector <int> &x, std::vector <int> &y) {
	int ret = 0;
	for(int i = 0; i < p_cnt; ++i) 
		ret += std::abs(x[i] - y[i]);
	return ret;
}

std::vector <pii> E[N << 1];
std::map <std::vector <int>, int> idx;
void Add(int u, int v, int w) {
	E[u].push_back(mkp(v, w));
	E[v].push_back(mkp(u, w));
}

int d[N << 1], siz[N << 1];
void Dfs(int u, int p, int tot, int &rt, int &rt_mx) {
	int mx = 0;
	siz[u] = d[u];
	for(pii e : E[u]) {
		int v = e.fi, w = e.se;
		if(v != p) {
			Dfs(v, u, tot, rt, rt_mx);
			siz[u] += siz[v];
			mx = std::max(mx, siz[v]);
		}
	}
	mx = std::max(mx, tot - siz[u]);
	if(mx < rt_mx) {
		rt_mx = mx;
		rt = u;
	}
}

void Dfs2(int u, int p, int dep, ll &ans) {
	ans += 1LL * dep * d[u];
	for(pii e : E[u]) {
		int v = e.fi, w = e.se;
		if(v != p) Dfs2(v, u, dep + w, ans);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		Init();
		rd(n);
		int a_mx = 0;
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			if(x == 0) x = 1;
			a_mx = std::max(a_mx, x);
			++g[x];
		}
		for(int i = 0; i <= a_mx; ++i) {
			s[++m].resize(p_cnt);
			for(int j = 1; j <= p_cnt; ++j)
				s[m][j - 1] = pw[j][i];
		}
		std::sort(s + 1, s + m + 1, Cmp);
		int _m = m;
		for(int i = 2; i <= _m; ++i)
			s[++m] = Lca(s[i - 1], s[i]);
		std::sort(s + 1, s + m + 1, Cmp);
		m = std::unique(s + 1, s + m + 1) - s - 1;
		int cnt = 0;
		for(int i = 1; i <= m; ++i)
			idx[s[i]] = ++cnt;
		for(int i = 2; i <= m; ++i) {
			std::vector <int> t = Lca(s[i - 1], s[i]);
			Add(idx[t], i, DistAnc(t, s[i]));
		}
		for(int i = 0; i <= a_mx; ++i)
			if(g[i]) {
				std::vector <int> t(p_cnt, 0);
				for(int j = 1; j <= p_cnt; ++j)
					t[j - 1] = pw[j][i];
				d[idx[t]] = g[i];
			}
		int rt, rt_mx = n + 1;
		Dfs(1, 0, n, rt, rt_mx);
		ll ans = 0;
		Dfs2(rt, 0, 0, ans);
		printf("%lld\n", ans);
	} return 0;
}