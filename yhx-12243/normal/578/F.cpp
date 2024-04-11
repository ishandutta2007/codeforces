#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 108, M = 666, N2 = N * N;

int mod;
int n, R, C, V[2], E = 0;
int p[N2], bel[N2];
int G[2][M][M];
bool type[N2];
char buf_[N];
pr fe[N2 * 2];

inline int ID(int r, int c) {return r * (C + 1) + c;}
int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}
inline void Union(int x, int y) {p[ancestor(x)] = ancestor(y);}	

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void link(int (*mat)[M], int u, int v) {++mat[u][u], --mat[u][v], --mat[v][u], ++mat[v][v];}

int gauss(int n, int (*mat)[M]) {
	int i, j, k, det = 1; ll coe;
	static int *m[M];
	for (i = 0; i < n; ++i) m[i] = mat[i];
	for (i = 0; i < n; ++i) {
		for (j = i; j < n && !m[j][i]; ++j);
		if (j == n) return 0;
		if (i != j) det = mod - det, std::swap(m[i], m[j]);
		det = (ll)det * m[i][i] % mod;
		coe = PowerMod(m[i][i], mod - 2);
		for (j = 0; j < n; ++j) m[i][j] = m[i][j] * coe % mod;
		for (k = i + 1; k < n; ++k)
			for (coe = mod - m[k][i], j = i; j < n; ++j) m[k][j] = (m[k][j] + coe * m[i][j]) % mod;
	}
	return det;
}

int main() {
	int i, j, u, v, ans; bool o;
	scanf("%d%d%d", &R, &C, &mod), n = (R + 1) * (C + 1);
	std::iota(p, p + n, 0);
	for (i = 0; i < R; ++i)
		for (scanf("%s", buf_), j = 0; j < C; ++j)
			switch (buf_[j]) {
				case 42: fe[E++] = pr(ID(i, j + 1), ID(i + 1, j)), fe[E++] = pr(ID(i, j), ID(i + 1, j + 1)); break;
				case 47: Union(ID(i, j + 1), ID(i + 1, j)); break;
				case 92: Union(ID(i, j), ID(i + 1, j + 1)); break;
			}
	for (i = 0; i <= R; ++i)
		for (j = 0; j <= C; ++j) type[ID(i, j)] = (i ^ j) & 1;
	for (i = 0; i < n; ++i) if (p[i] == i) bel[i] = V[type[i]]++;
	for (i = 0; i < n; ++i) bel[i] = bel[ancestor(i)];
	for (i = 0; i < E; ++i) std::tie(u, v) = fe[i], o = type[u], link(G[o], bel[u], bel[v]);
	ans = (gauss(V[0] - 1, G[0]) + gauss(V[1] - 1, G[1])) % mod;
	printf("%d\n", ans + (ans >> 31 & mod));
	return 0;
}