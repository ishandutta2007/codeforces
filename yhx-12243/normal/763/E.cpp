#include <bits/stdc++.h>
#define popc __builtin_popcount

const int N = 100054;

int n, E, bw, q;
int p[N], G[N], L[N], R[N];
int Rs[N], Ls[N];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline bool connect(int x, int y) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return false;
	return p[x] = y, true;
}

int main() {
	int i, u, v, w, v0, e0;
	scanf("%d%d%d", &n, &bw, &E);
	for (i = 0; i < E; ++i) {
		scanf("%d%d", &u, &v);
		if (u > v) std::swap(u, v);
		G[u] |= 1 << (v - u);
	}
	std::iota(p, p + (n + 1), 0);
	for (v = 1, w = 2; v <= bw; ++v, w <<= 1)
		for (i = 1; i <= n; ++i)
			if (G[i] & w && connect(i, i + v))
				R[i] |= w, L[i + v] |= w;
	for (i = 1; i <= n; ++i) Rs[i] = Rs[i - 1] + popc(R[i]), Ls[i] = Ls[i - 1] + popc(L[i]);
	for (scanf("%d", &q); q; --q) {
		scanf("%d%d", &u, &v), v0 = v - --u, e0 = Ls[v] - Rs[u];
		for (i = u, w = -1 << (v0 + 1); i > v - bw; --i, w <<= 1)
			e0 += popc(R[i] & w);
		printf("%d\n", v0 - e0);
	}
	return 0;
}