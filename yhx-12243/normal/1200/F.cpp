#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 1054, NM = 2540254, P = 2520;

int n, q, yr, V;
int fact[N], finv[N];
int w[N], p[NM], active[N];
int CC = 0, bel[NM], cyclen[NM];
vector nxt[N], G[NM];
bool iscyc[NM];

void dfs(int x) {
	bel[x] = CC;
	for (int y : G[x])
		if (y == yr) iscyc[x] = true;
		else dfs(y), iscyc[x] |= iscyc[y];
	if (iscyc[x] && active[x % n] != CC) active[x % n] = CC, ++cyclen[CC];
}

int main() {
	int i, j, ni, nj, m, x;
	scanf("%d", &n), V = n * P;
	for (i = 1; i <= n; ++i) scanf("%d", w + i), w[i] %= P, w[i] += w[i] >> 31 & P;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &m), nxt[i].reserve(m);
		for (j = 0; j < m; ++j) scanf("%d", &x), nxt[i].EB(x);
		for (j = 0; j < P; ++j)
			nj = (j + w[i]) % P, ni = nxt[i][nj % m], p[i + j * n] = ni + nj * n;
	}
	for (i = 1; i <= V; ++i) G[p[i]].EB(i);
	for (i = 1; i <= V; ++i) if (!bel[i]) {
		for (++CC, j = i; !bel[j]; j = p[j]) bel[j] = CC;
		yr = j, dfs(j);
	}
	for (scanf("%d", &q); q; --q)
		scanf("%d%d", &i, &x), x %= P, x += x >> 31 & P,
		printf("%d\n", cyclen[ bel[i + x * n] ]);
	return 0;
}