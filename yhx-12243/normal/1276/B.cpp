#include <bits/stdc++.h>

const int N = 200054, M = 1000054;

int V, E, si, ti, Es;
int to[M], first[N], next[M];
int cnt = 0, id[N], low[N];
int top = 0, stack[N];
int bcc_cnt, p[M], deg[M], size[M];
int fc[M], nc[M];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es;
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

inline void link(int x, int y) {p[x] = y, ++deg[x], ++deg[y], nc[x] = fc[y], fc[y] = x;}

void dfs(int x, int px) {
	int i, y, z;
	id[x] = low[x] = ++cnt, stack[top++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, i), down(low[x], low[y]);
			if (id[x] <= low[y])
				for (link(++bcc_cnt + V, x), z = 0; z != y; )
					link(z = stack[--top], bcc_cnt + V);
		} else if (px - 1 ^ i - 1 ^ 1)
			down(low[x], id[y]);
}

void dfss(int x) {
	int y; size[x] = (x <= V);
	for (y = fc[x]; y; y = nc[y]) dfss(y), size[x] += size[y];
}

void work() {
	int i, u, v, a, b;
	scanf("%d%d%d%d", &V, &E, &si, &ti), Es = cnt = top = bcc_cnt = 0;
	memset(first, 0, (V + 1) << 2);
	memset(id, 0, (V + 1) << 2);
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(si, 0);
	if (deg[si] < 2 || deg[ti] < 2) puts("0");
	else {
		dfss(si), a = size[ti] - 1;
		assert(size[si] == V);
		for (u = ti; p[u] != si; u = p[u]);
		b = size[si] - size[u] - 1;
		printf("%lld\n", (long long)a * b);
	}
	memset(p, 0, (V + bcc_cnt + 1) << 2);
	memset(deg, 0, (V + bcc_cnt + 1) << 2);
	memset(fc, 0, (V + bcc_cnt + 1) << 2);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}