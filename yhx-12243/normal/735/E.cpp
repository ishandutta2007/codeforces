#include <bits/stdc++.h>

typedef long long ll;
const int N = 108, M = N * 2, mod = 1000000007;

int n, K, E = 0;
int to[M], first[N], next[M];
int f[N][N], g[N];

inline int min(const int x, const int y) {return x < y ? x : y;} 
inline int max(const int x, const int y) {return x < y ? y : x;}
inline void fma(int &x, const int y, const int z) {x = (x + (ll)y * z) % mod;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x, int px = 0) {
	int i, j, k, y; *f[x] = f[x][K + 1] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != px) {
			dfs(y, x);
			for (j = 0; j <= 2 * K; ++j)
				for (k = 0; k <= 2 * K; ++k)
					fma(g[(j + k <= 2 * K ? min : max)(j, k + 1)], f[x][j], f[y][k]);
			memcpy(f[x], g, 8 * K + 4), memset(g, 0, 8 * K + 4);
		}
}

int main() {
	int i, u, v;
	scanf("%d%d", &n, &K);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1);
	printf("%d\n", int(std::accumulate(f[1], f[1] + (K + 1), 0ll) % mod));
	return 0;
}