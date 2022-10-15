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
const int kN = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, q;
std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); E[v].push_back(u); }

int fa[kN][20], h_bit[kN], top[kN], d[kN], hvy[kN], dep[kN],
	dfn[kN], siz[kN], dfv = 0;
void Dfs(int u) {
	dfn[u] = ++dfv; siz[u] = 1;
	dep[u] = dep[fa[u][0]] + 1;
	for(auto v : E[u]) if(v != fa[u][0]) {
		fa[v][0] = u; Dfs(v);
		if(d[v] > d[hvy[u]]) hvy[u] = v;
		siz[u] += siz[v];
	}
	d[u] = d[hvy[u]] + 1;
}
void GetTop(int u, int t) {
	top[u] = t;
	if(hvy[u]) GetTop(hvy[u], t);
	for(auto v : E[u]) if(v != fa[u][0] && v != hvy[u]) {
		GetTop(v, v);
	}
}

std::vector <int> lower[kN], upper[kN];
void Init() {
	Dfs(1); GetTop(1, 1);
	for(int i = 1; i <= 18; ++i)
		for(int j = 1; j <= n; ++j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	h_bit[0] = -1;
	for(int i = 1; i <= n; ++i)
		h_bit[i] = h_bit[i >> 1] + 1;
	for(int i = 1; i <= n; ++i) if(i == top[i]) {
		for(int x = i, y = i; top[x] == i; x = hvy[x], y = fa[y][0]) {
			lower[i].push_back(x);
			upper[i].push_back(y);
		}
	}
}
int FindAnc(int x, int k) {
	if(!k) return x;
	int t = top[fa[x][h_bit[k]]];
	k -= dep[x] - dep[t];
	int ret;
	if(k > 0) ret = upper[t][k];
	else ret = lower[t][-k];
	return ret;
}

struct Mod {
	int v; ll d;
} M[kN];
int cnt = 0;
ll t[kN], A[kN], dt[kN];
void Push() {
	cnt = 0;
	for(int u = 1; u <= n; ++u) if(t[u]) {
		ll d = t[u];
		for(auto v : E[u]) if(v != fa[u][0]) {
			dt[dfn[v]] = (dt[dfn[v]] + (n - siz[v]) * d) % kMod;
			dt[dfn[v] + siz[v]] = (dt[dfn[v] + siz[v]] - (n - siz[v]) * d) % kMod;
		}
		dt[1] = (dt[1] + siz[u] * d) % kMod;
		dt[dfn[u]] = (dt[dfn[u]] - siz[u] * d + n * d) % kMod;
		dt[dfn[u] + 1] = (dt[dfn[u] + 1] - n * d) % kMod;
		dt[dfn[u] + siz[u]] = (dt[dfn[u] + siz[u]] + siz[u] * d) % kMod;
	}
	for(int i = 1; i <= n; ++i)
		dt[i] = ((dt[i - 1] + dt[i]) % kMod + kMod) % kMod;
	for(int u = 1; u <= n; ++u)
		A[u] = (A[u] + dt[dfn[u]]) % kMod;
	memset(t, 0, sizeof(t));
	memset(dt, 0, sizeof(dt));
}
void Modify(int v, ll d) {
	t[v] = (t[v] + d) % kMod; 
	M[++cnt] = (Mod) { v, d };
}
ll Query(int v) {
	ll ret = A[v];
	for(int i = 1; i <= cnt; ++i) {
		int u = M[i].v; ll d = M[i].d;
		if(u == v) ret = (ret + n * d) % kMod;
		else if(dep[u] >= dep[v]) ret = (ret + siz[u] * d) % kMod;
		else {
			int x = FindAnc(v, dep[v] - dep[u] - 1);
			if(fa[x][0] != u) ret = (ret + siz[u] * d) % kMod;
			else ret = (ret + (n - siz[x]) * d) % kMod;
		}
	}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		ll n_inv; int B;
		rd(n, q); n_inv = QPow(n, kMod - 2);
		B = sqrt(n);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		Init();
		for(int i = 1; i <= q; ++i)  {
			int opt, v; rd(opt, v);
			if(i / B != (i - 1) / B) Push();
			if(opt == 1) {
				ll d; rd(d);
				Modify(v, d * n_inv % kMod);
			} else printf("%lld\n", Query(v));
		}
	} return 0;
}