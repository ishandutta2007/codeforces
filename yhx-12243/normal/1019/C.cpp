#include <bits/stdc++.h>

const int N = 1000054;

int V, E, n;
int to[N], first[N], next[N];
int ans[N];
bool A[N], B[N];

inline void addedge(int u, int v, int id) {to[id] = v, next[id] = first[u], first[u] = id;}

int main() {
	int i, u, v;
	scanf("%d%d", &V, &E);
	for (i = 1; i <= E; ++i) scanf("%d%d", &u, &v), addedge(u, v, i);
	for (v = 1; v <= V; ++v)
		if (!A[v]) for (A[v] = B[v] = true, i = first[v]; i; i = next[i]) A[to[i]] = true;
	for (v = V; v; --v)
		if (B[v]) for (i = first[v]; i; i = next[i]) B[to[i]] = false;
	for (i = 1; i <= V; ++i) if (B[i]) ans[n++] = i;
	printf("%d\n", n);
	for (i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? 10 : 32);
	return 0;
}