#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int n, m, fa[N], L[N], R[N], pw[22][N], dep[N], cur;

vector<pair<int,int> > e;
vector<int> G[N];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

struct FenWick {
	ll s[N];
	void Mdf(int x, ll v) {
		for (; x <= n; x += x & (-x)) s[x] += v;
	}
	ll Qry(int x) {
		ll ret = 0;
		for (; x; x -= x & (-x)) ret += s[x];
		return ret;
	}
}	bit;

void dfs(int x, int y) {
	L[x] = ++cur;
	dep[x] = dep[y] + 1;
	pw[0][x] = y;
	for (int v : G[x]) {
		if (v == y) continue;
		dfs(v, x);
	}
	R[x] = cur;
}

int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = 20; j >= 0; j--)
		if (dep[pw[j][x]] >= dep[y])
			x = pw[j][x];
	if (x == y) return x;
	for (int j = 20; j >= 0; j--)
		if (pw[j][x] != pw[j][y])
			x = pw[j][x],
			y = pw[j][y];
	return pw[0][x];
}

int getson(int x, int y) {
	for (int j = 20; j >= 0; j--)
		if (dep[pw[j][y]] > dep[x])
			y = pw[j][y];
	return y;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		if (find(u) != find(v)) {
			fa[fa[u]] = fa[v];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		else e.pb(mp(u, v));
	}
	dfs(1, 0);
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++)
			pw[j][i] = pw[j - 1][pw[j - 1][i]];
	for (pair<int,int> pr : e) {
		int u = pr.first, v = pr.second;
		if (dep[u] > dep[v]) swap(u, v);
		int l = Lca(u, v);
		if (l == u) {
			int k = getson(u, v);
			bit.Mdf(1, 1);
			bit.Mdf(L[k], -1);
			bit.Mdf(R[k] + 1, 1);
			bit.Mdf(L[v], 1);
			bit.Mdf(R[v] + 1, -1);
		}
		else {
			bit.Mdf(L[u], 1);
			bit.Mdf(R[u] + 1, -1);
			bit.Mdf(L[v], 1);
			bit.Mdf(R[v] + 1, -1);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d", bit.Qry(L[i]) == m - n + 1);
	puts("");
	return 0;
}