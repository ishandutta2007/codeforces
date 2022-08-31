#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef unsigned long long u64;
typedef std::pair <int, int> pr;
const int N = 1554, M = 2 * N, W = N * N / 2, mod = 998244353;

int n, V, E;
int G[N][N], fc[M], nc[M];
int p[M], P[M];
int sizeV[M], sizeE[M];
int f[M][N];
bool key[M];
pr e[W];

inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}
int ancestor(int x) {return P[x] == x ? x : (P[x] = ancestor(P[x]));}

inline int connect(int x, int y) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return ++sizeE[x];
	++V, link(x, V), link(y, V), sizeV[V] = sizeV[x] + sizeV[y], sizeE[V] = sizeE[x] + sizeE[y] + 1;
	return P[x] = P[y] = P[V] = V;
}

void mul(int n, int m, int *a, int *b, int *ret) {
	static u64 u[N];
	int i, j;
	memset(u, 0, (n + m + 1) << 3);
	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= m; ++j)
			u[i + j] += (u64)a[i] * b[j];
		if (!(i & 15)) for (j = 0; j <= n + m; ++j) u[j] %= mod;
	}
	for (i = 0; i <= n + m; ++i) ret[i] = u[i] % mod;
}

void dfs(int x) {
	int y = fc[x], s = 0; f[x][0] = !!y;
	for (; y; y = nc[y]) dfs(y), mul(s, sizeV[y], f[x], f[y], f[x]), s += sizeV[y];
	f[x][1] += key[x];
}

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, V = n, E = n * (n - 1) / 2;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) cin >> G[i][j];
		for (j = i + 1; j <= n; ++j) e[ G[i][j] ] = pr(i, j);
	}
	for (i = 1; i <= V; ++i) P[i] = i, sizeV[i] = 1, sizeE[i] = 0;
	std::iota(P, P + (n + 1), 0);
	for (i = 1; i <= E; ++i) connect(e[i].first, e[i].second);
	for (i = 1; i <= V; ++i) key[i] = 2 * sizeE[i] == sizeV[i] * (sizeV[i] - 1);
	dfs(V);
	for (i = 1; i <= n; ++i) cout << f[V][i] << (i == n ? '\n' : ' ');
	return 0;
}