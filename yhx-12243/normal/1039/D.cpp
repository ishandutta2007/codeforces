#include <bits/stdc++.h>
#define N 100010

const int INF = 0x3f3f3f3f;

int n, E = 0;
int to[N * 2], first[N], next[N * 2], deg[N], fy[N];
int p[N], dep[N], que[N], ans[N];
int cnt = 0, o[N], id[N], end_id[N];
int great[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++E] = v; next[E] = first[u]; first[u] = E; ++deg[u];
	to[++E] = u; next[E] = first[v]; first[v] = E; ++deg[v];
}

void bfs(int root) {
	int h, t = 1, i, x, y;
	que[1] = root; dep[root] = 1;
	for (h = 0; h < t; )
		for (i = first[x = que[++h]]; i; i = next[i])
			if ((y = to[i]) != p[x]) {
				p[y] = x;
				dep[y] = dep[x] + 1;
				que[++t] = y;
			}
}

int work(int len) { // 1 <= len <= n - 1
	int i, j, x, y, ret = 0, R1, R2;
	for (j = n; j; --j) {
		x = que[j]; R1 = R2 = 0;
		for (i = first[x]; i; i = next[i])
			R1 < great[y = to[i]] + 1 ? (void)(R2 = R1, R1 = great[y] + 1) : up(R2, great[y] + 1);
		if (R1 + R2 >= len) ++ret, great[x] = -INF;
		else great[x] = R1;
	}
	return ret;
}

void divide(int L, int R) {
	if (L + 1 >= R) return;
	int M = (L + R) / 2;
	ans[M] = work(M);
	if (ans[L] == ans[M]) std::fill(ans + (L + 1), ans + M, ans[L]);
	else divide(L, M);
	if (ans[M] == ans[R]) std::fill(ans + (M + 1), ans + R, ans[M]);
	else divide(M, R);
}

int Chain() {
	for (int i = 1; i <= n; ++i) printf("%d\n", n / i);
	return 0;
}

int main() {
	int i, u, v; bool chain = true;
	scanf("%d", &n);
	for (i = 1; i < n; ++i)
		scanf("%d%d", &u, &v), addedge(u, v);
	for (i = 1; i <= n; ++i) chain &= deg[i] <= 2; if (chain) return Chain();
	bfs(1);
	for (v = 1; v <= n; ++v) {
		if (to[i = first[v]] == p[v]) first[v] = next[i];
		for (i = first[v]; next[i]; i = next[i])
			if (to[next[i]] == p[v]) next[i] = next[next[i]];
	}
	*ans = n; ans[n - 1] = 0;
	divide(0, n - 1);
	for (i = 0; i < n; ++i) printf("%d\n", ans[i]);
	return 0;
}