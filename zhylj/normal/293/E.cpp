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
#define seg(o) T[o].seg
#define tag(o) T[o].tag
#define lc(o) T[o].lc
#define rc(o) T[o].rc
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, l_mx, w_mx; ll ans;
std::vector <pii> E[N];

int T[N];
void Modify(int o, int v) {
	for(; o <= n; o += o & -o) T[o] += v;
}
int Query(int o) {
	int ret = 0;
	for(; o; o -= o & -o) ret += T[o];
	return ret;
}

int siz[N]; bool vis[N];
void FindRoot(int u, int p, int tot, int &rt, int &rt_mx) {
	siz[u] = 1;
	int cur_mx = 0;
	for(auto i : E[u]) {
		int v = i.fi;
		if(v != p && !vis[v]) {
			FindRoot(v, u, tot, rt, rt_mx);
			siz[u] += siz[v];
			cur_mx = std::max(cur_mx, siz[v]);
		}
	}
	cur_mx = std::max(cur_mx, tot - siz[u]);
	if(cur_mx < rt_mx) {
		rt_mx = cur_mx;
		rt = u;
	}
}
struct Opt {
	int typ, d; ll s;
}; std::vector <Opt> tmp;
void Dfs(int u, int p, int d, ll s, int t) {
	if(d > l_mx || s > w_mx) return;
	tmp.push_back((Opt) { 1, d, s });
	tmp.push_back((Opt) { 2, l_mx - d, w_mx - s });
	ans += t;
	siz[u] = 1;
	for(auto i : E[u]) {
		int v = i.fi, w = i.se;
		if(v != p && !vis[v]) {
			Dfs(v, u, d + 1, s + w, t);
			siz[u] += siz[v];
		}
	}
}
ll Calc() {
	ll ret = 0;
	std::sort(tmp.begin(), tmp.end(), [&](const Opt &x, const Opt &y) {
		return x.s != y.s ? x.s < y.s : x.typ < y.typ;
	});
	for(auto i : tmp) {
		int typ = i.typ, d = i.d;
		if(typ == 1) {
			Modify(d, 1);
		} else ret += Query(d);
	}
	for(auto i : tmp) {
		int typ = i.typ, d = i.d;
		if(typ == 1) Modify(d, -1);
	}
	return ret;
}
void Div(int u, int tot) {
	int rt, rt_mx = Inf;
	FindRoot(u, 0, tot, rt, rt_mx);
	vis[rt] = true;
	for(auto i : E[rt]) {
		int v = i.fi, w = i.se;
		if(!vis[v]) Dfs(v, rt, 1, w, 2);
	}
	ans += Calc();
	tmp.clear();
	for(auto i : E[rt]) {
		int v = i.fi, w = i.se;
		if(!vis[v]) {
			Dfs(v, rt, 1, w, 0);
			ans -= Calc();
			tmp.clear();
		}
	}
	for(auto i : E[rt]) {
		int v = i.fi;
		if(!vis[v]) Div(v, siz[v]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, l_mx, w_mx);
		for(int i = 2; i <= n; ++i) {
			int p, w; rd(p, w);
			E[p].push_back(mkp(i, w));
			E[i].push_back(mkp(p, w));
		}
		Div(1, n); ans /= 2;
		printf("%lld\n", ans);
	} return 0;
}