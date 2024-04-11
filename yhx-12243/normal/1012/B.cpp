#include <bits/stdc++.h>
#define N 200005

int r, c, q, E;
int to[N * 4], first[N * 2], next[N * 4];
int scx[N * 2];

inline void addedge(int u, int v) {
	to[++E] = v; next[E] = first[u]; first[u] = E;
	to[++E] = u; next[E] = first[v]; first[v] = E;
}

void dfs(int x) {
	int i, y;
	scx[x] = 1;
	for (i = first[x]; i; i = next[i])
		if (!scx[y = to[i]]) dfs(y);
}


int main() {
	int i, u, v, ans = 0;
	scanf("%d%d%d", &r, &c, &q);
	for (i = 1; i <= q; ++i) {
		scanf("%d%d", &u, &v); addedge(u, v + r);
	}
	for (i = 1; i <= r + c; ++i)
		if (!scx[i]) dfs(i), ++ans;
	printf("%d\n", --ans);
	return 0;
}