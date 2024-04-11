#include <bits/stdc++.h>

const int N = 1054;
typedef std::bitset <N> bitset;
	
int n;
bitset leaf, G[N], B[N];

int main() {
	int i, j, k, u, v, L; bitset r, best;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (scanf("%d", &k); k; --k) scanf("%d", &j), B[i].set(j);
	for (i = 1; i <= n; ++i) G[i].set(i), leaf.set(i);
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			if ((r = B[i] & B[j]).count() == 2) {
				u = r._Find_first(), v = r._Find_next(u);
				if (!G[u].test(v))
					G[u].set(v), G[v].set(u), leaf.reset(u), leaf.reset(v);
			}
	L = leaf.count();
	if (L == n) {for (i = 2; i <= n; ++i) printf("1 %d\n", i); return 0;}
	if (L == n - 2) {
		for (i = 0; i < n && B[i].count() == n; ++i); r = B[i];
		for (i = leaf._Find_first(); i != N; i = leaf._Find_next(i))
			j = r.test(i) ? u : v, G[i].set(j), G[j].set(i);
	} else
		for (i = leaf._Find_first(); i != N; i = leaf._Find_next(i)) {
			for (k = INT_MAX, j = 0; j < n; ++j)
				if (B[j].test(i))
					if (r = B[j] & ~leaf, (v = r.count()) < k)
						best = r, k = v;
			for (j = best._Find_first(); j != N; j = best._Find_next(j))
				if ((G[j] & ~leaf) == best) {G[i].set(j), G[j].set(i); break;}
		}
	for (i = 1; i <= n; ++i)
		for (j = G[i]._Find_next(i); j != N; j = G[i]._Find_next(j))
			printf("%d %d\n", i, j);
	return 0;
}