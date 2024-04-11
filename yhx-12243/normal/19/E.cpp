#include <bits/stdc++.h>
#define N 100005
#define M 200005
#define ad(x) ((x - 1 ^ 1) + 1)

int V, E, Es;

int to[M], first[N], next[M];
int tree_edge[M];
int p[N], dep[N], used[N];
int odd[N], even[N];
int eodd[M], eeven[M];
int odd_count = 0;
int ans_cnt = 0, ans[M];

inline void addedge(int u, int v){
	to[++Es] = v; next[Es] = first[u]; first[u] = Es;
	to[++Es] = u; next[Es] = first[v]; first[v] = Es;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == -1) {
			p[y] = x; dep[y] = dep[x] + 1;
			tree_edge[i] = tree_edge[ad(i)] = 1;
			dfs(y);
		}
}

void dfs2(int x) {
	int i, y; used[x] = 1;
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) {
			dfs2(y);
			odd[x] += odd[y]; even[x] += even[y];
			eodd[i] = eodd[ad(i)] = odd[y];
			eeven[i] = eeven[ad(i)] = even[y];
		}
}

void output() {
	printf("%d\n", ans_cnt);
	for (int i = 1; i <= ans_cnt; ++i) printf("%d%c", ans[i], i == ans_cnt ? 10 : 32);
}

int main() {
	int i, u, v;
	scanf("%d%d", &V, &E);
	for (i = 1; i <= E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	memset(p, -1, sizeof p);
	for (i = 1; i <= V; ++i)
		if (p[i] == -1) p[i] = 0, dfs(i);
	for (i = 1; i <= Es; i += 2)
		if (!tree_edge[i]) {
			u = to[i]; v = to[i + 1];
			if (dep[u] < dep[v]) std::swap(u, v);
			if ((dep[u] ^ dep[v]) & 1) ++even[u], --even[v]; // even cycle
			else ++odd[u], --odd[v], ++odd_count, eodd[i] = eodd[ad(i)] = 1;
		}
	if (!odd_count) {
		for (i = 1; i <= E; ++i) ans[++ans_cnt] = i;
		output(); return 0;
	}
	for (i = 1; i <= V; ++i)
		if (!used[i]) dfs2(i);
	for (i = 1; i <= Es; i += 2)
		if (tree_edge[i]) {
			if (eodd[i] == odd_count && !eeven[i]) ans[++ans_cnt] = i + 1 >> 1;
		} else {
			if (eodd[i] && odd_count == 1) ans[++ans_cnt] = i + 1 >> 1;
		}
	output();
	return 0;
}