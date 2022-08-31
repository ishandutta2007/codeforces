#include <bits/stdc++.h>
#define N 108

inline int max(const int x, const int y) {return x < y ? y : x;}

int n, E = 0;
int to[N], first[N], next[N];
int size[N];
double fact[N], f[N][N], tmp[N];

inline void addedge(int u, int v) {
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

inline double C(int u, int v) {return fact[u + v] / (fact[u] * fact[v]);}

void dfs(int x, int px = 0) {
	int e, i, j, y; size[x] = 1; f[x][0] = 1.0;
	for (e = first[x]; e; e = next[e])
		if ((y = to[e]) != px) {
			dfs(y, x);
			// lifting
			for (i = 0; i <= size[y]; ++i) {
				f[0][i] = f[y][i] * (size[y] - i);
				for (j = 0; j < i; ++j) f[0][i] += f[y][j] * 0.5;
			}
			// merging
			memset(tmp, 0, (size[x] + size[y]) << 3);
			for (i = 0; i < size[x]; ++i)
				for (j = 0; j <= size[y]; ++j)
					tmp[i + j] += f[x][i] * f[0][j] * C(i, j) * C(size[x] - i - 1, size[y] - j);
			memcpy(f[x], tmp, (size[x] += size[y]) << 3);
		}
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (*fact = i = 1; i <= n; ++i) fact[i] = fact[i - 1] * (double)i;
	for (i = 1; i <= n; ++i) {
		memset(f, 0, sizeof f); dfs(i);
		printf("%.12lg\n", f[i][n - 1] / fact[n - 1]);
	}
	return 0;
}