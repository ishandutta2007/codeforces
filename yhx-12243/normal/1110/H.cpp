#include <bits/stdc++.h>

const int N = 2054, M = N * 16;

int n;
char L[N], R[N], fr[N][M];
int f[N][M];

namespace AC {
	char tmp[N];
	int cnt = 1, limit;
	int d[M][10], f[M], que[M];
	int v[M][N], sum[M][N];

	void dfs(int x, int dep, bool bl = true, bool br = true) {
		if (!(bl || br) || dep == limit) {++v[x][limit - dep]; return;}
		int i, m = br ? R[dep] : 9;
		for (i = (bl ? L[dep] : 0); i <= m; ++i)
			dfs(d[x][i] ? d[x][i] : (d[x][i] = ++cnt), dep + 1, bl && i == L[dep], br && i == R[dep]);
	}

	void init() {
		int i, j, nL = strlen(L), nR = strlen(R); char *p;
		for (p = L; *p; *p++ &= 15); for (p = R; *p; *p++ &= 15);
		if (nL == nR) return limit = nL, dfs(1, 0);
		memcpy(tmp, R, nR), memset(R, 9, nL), limit = nL, dfs(1, 0);
		memcpy(R, tmp, nR), memset(L, 0, nR), *L = 1, limit = nR, dfs(1, 0);
		for (i = nL + 1; i < nR; ++i)
			for (j = 1; j < 10; ++j) ++v[ d[1][j] ? d[1][j] : (d[1][j] = ++cnt) ][i - 1];
	}

	void build() {
		int h, ta = 1, i, j, t, id;
		*que = 1, f[1] = 0;
		for (h = 0; h < ta; ++h)
			for (i = que[h], id = 0; id < 10; ++id) {
				t = (f[i] ? d[f[i]][id] : 1);
				int &u = d[i][id];
				if (!u) {u = t; continue;}
				f[u] = t, que[ta++] = u;
				for (j = 0; j < n; ++j) v[u][j] += v[t][j];
			}
	}

	inline void partial_sum() {for (int i = 1; i <= AC::cnt; ++i) std::partial_sum(v[i], v[i] + n, sum[i]);}
}

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, d, nj, nv, t = 1;
	scanf("%s%s%d", L, R, &n), AC::init(), AC::build(), AC::partial_sum();
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= AC::cnt; ++j)
			for (d = 0; d < 10; ++d)
				nj = AC::d[j][d], nv = f[i - 1][nj] + AC::sum[nj][i - 1],
				nv > f[i][j] && (f[i][j] = nv, fr[i][j] = d);
	printf("%d\n", f[n][1]);                        
	for (i = n; i; t = AC::d[t][fr[i][t]], --i) putchar(fr[i][t] | 48);
	return 0;
}