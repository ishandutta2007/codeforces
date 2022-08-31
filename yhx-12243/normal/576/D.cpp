#include <bits/stdc++.h>
#define matcopy(x, y) std::copy(x + 1, x + (V + 1), y + 1)

const int N = 162, INF = 0x3f3f3f3f;
typedef std::bitset <N> bitset, mat[N], *pmat;

struct edge {
	int u, v, w;
	edge * read() {return scanf("%d%d%d", &u, &v, &w), this;}
	inline bool operator < (const edge &B) const {return w < B.w;}
} e[N];

int V, E;
int que[N], dis[N];
mat G, C;

inline void __builtin_matmul(pmat a, pmat b, pmat ret) {
	for (int k, i = 1; i <= V; ++i)
		for (ret[i].reset(), k = a[i]._Find_first(); k != N; k = a[i]._Find_next(k))
			ret[i] |= b[k];
}

inline void matmul(pmat a, pmat b, pmat ret) {static mat tmp; __builtin_matmul(a, b, tmp), matcopy(tmp, ret);}

void matPower(pmat a, int n, pmat c) {static mat tmp; for (matcopy(a, tmp); n; n >>= 1, matmul(tmp, tmp, tmp)) if (n & 1) matmul(c, tmp, c);}

int main() {
	int i, j, u, v, t = 0, next, head, tail;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; ++i) e[i].read();
	std::sort(e, e + E), e[E].w = INF, C[1].set(1);
	for (j = i = 0; i < E; i = j, t = next) {
		if (t != e[i].w) break;
		for (; e[j].w == t; ++j) G[e[j].u].set(e[j].v); next = e[j].w;
		tail = 0, memset(dis, 63, (V + 1) << 2);
		for (v = C[1]._Find_first(); v != N; v = C[1]._Find_next(v)) dis[v] = t, que[tail++] = v;
		for (head = 0; head < tail; ++head) {
			if ((u = que[head]) == V) return printf("%d\n", dis[V]), 0;
			if (dis[u] == next) break;
			for (v = G[u]._Find_first(); v != N; v = G[u]._Find_next(v))
				if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, que[tail++] = v;
		}
		matPower(G, next - t, C);
	}
	return puts("Impossible"), 0;
}