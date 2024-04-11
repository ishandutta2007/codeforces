#include <bits/stdc++.h>

const int N = 200054, M = N;

int V, E;
int w[N], W[N], deg[N];
int to[M], first[N], next[M];
int topo[N], mark[N], sg[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void addedge(int u, int v, int id) {to[id] = v, next[id] = first[u], first[u] = id, ++deg[v];}

int main() {
	int i, j, u, v, x, y, h, t = 0;
	scanf("%d%d", &V, &E);
	for (i = 1; i <= V; ++i) scanf("%d", w + i);
	for (i = 1; i <= E; ++i) scanf("%d%d", &u, &v), addedge(u, v, i);
	for (i = 1; i <= V; ++i) if (!deg[i]) topo[t++] = i;
	for (h = 0; h < t; ++h)
		for (i = first[ x = topo[h] ]; i; i = next[i]) if (!--deg[ y = to[i] ]) topo[t++] = y;
	assert(t == V), v = 0;
	for (j = V - 1; j >= 0; --j) {
		for (i = first[ x = topo[j] ]; i; i = next[i]) mark[sg[y = to[i]]] = x;
		for (i = 0; mark[i] == x; ++i); up(v, sg[x] = i), W[i] ^= w[x];
	}
	for (i = v; i >= 0 && !W[i]; --i);
	if (!~i) return puts("LOSE"), 0;
	for (x = 1; x <= V; ++x) if (sg[x] == i && (w[x] ^ W[i]) < w[x]) break;
	assert(x <= V), w[x] ^= W[i], puts("WIN");
	for (i = first[x]; i; i = next[i]) y = to[i], j = sg[y], w[y] ^= W[j], W[j] ^= W[j];
	for (i = 1; i <= V; ++i) printf("%d%c", w[i], i == V ? 10 : 32);
	return 0;
}