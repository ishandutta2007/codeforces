#include <bits/stdc++.h>

typedef long long ll;
const int N = 200054, M = N * 2;

int n, E = 0, root;
int to[M], first[N], next[M];
int a[N], b[N], Lu, Lv, Lt;
int p[N], dep[N];
int diff = 0, buc[N];
int len = 0, cyc[N], in_cyc[N];
int A[N], B[N];

inline ll DD(ll &x, const ll y) {return x > y ? x = y : 0;}
inline int dmax(const int x, const int y) {return dep[x] < dep[y] ? y : x;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, dfs(y);
}

int LCA(int x, int y) {for (; x != y; dep[x] < dep[y] ? y = p[y] : (x = p[x])); return x;}

inline bool find_endpoint() {
	int i;
	for (i = 1; i < diff && p[buc[i]] == buc[i - 1]; ++i);
	if (i == diff) return Lt = Lu = p[*buc], Lv = buc[diff - 1], true;
	Lu = Lv = Lt = p[*buc];
	for (i = 0; i < diff; ++i) {
		if (p[buc[i]] == Lu) Lu = buc[i];
		else if (p[buc[i]] == Lv) Lv = buc[i];
		else return false;
	}
	return true;
}

int main() {
	int i, j, u, v, w, z, offset; ll D;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) scanf("%d", b + i);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs( root = std::find(b + 1, b + (n + 1), 0) - b );
	u = v = std::find(a + 1, a + (n + 1), 0) - a;
	for (i = 0; u != root; ++i) std::swap(a[u], a[p[u]]), u = p[u];
	if (!memcmp(a + 1, b + 1, n << 2)) return printf("0 %d\n", i), 0;

	for (i = 1; i <= n; ++i) if (a[i] != b[i]) buc[diff++] = i;
	std::sort(buc, buc + diff, [] (const int x, const int y) {return dep[x] < dep[y];});

	if (!find_endpoint()) return puts("-1"), 0;

	if (Lu > Lv) std::swap(Lu, Lv);
	cyc[len++] = Lt;
	for (i = Lu; i != Lt; i = p[i]) cyc[len++] = i;
	std::reverse(cyc + 1, cyc + len);
	for (i = Lv; i != Lt; i = p[i]) cyc[len++] = i;
	for (i = 0; i < len; ++i) in_cyc[ cyc[i] ] = i;
	assert(len > 2);

	w = LCA(v, Lt);
	if (w == Lt) z = dmax(LCA(v, Lu), LCA(v, Lv));

#define process() \
	for (j = 0, i = Lt; i != root; i = p[i]) buc[j++] = i; \
	for (; j--; std::swap(a[buc[j]], a[p[buc[j]]]), std::swap(b[buc[j]], b[p[buc[j]]])); \
	for (i = 0; i < len; ++i) A[i] = a[cyc[i]], B[i] = b[cyc[i]]; \
	assert(!(*A || *B)); \
	offset = std::find(A + 1, A + len, B[1]) - A; \
	if (offset >= len || memcmp(A + 1, B + (len - offset + 1), (offset - 1) << 2) \
					  || memcmp(A + offset, B + 1, (len - offset) << 2)) return puts("-1"), 0;

	if (w == Lt && w != z) {
		if ((in_cyc[z] + 1) % len != in_cyc[p[z]])
			for (std::reverse(cyc + 1, cyc + len), i = 0; i < len; ++i) in_cyc[ cyc[i] ] = i;
		assert( (in_cyc[z] + 1) % len == in_cyc[p[z]] );
		process();
	 	D = dep[v] + std::min(len * (offset - 1ll), (ll)len * (len - offset) - 2 * (dep[z] - dep[w]));
	} else {
		process();
		D = dep[v] + 2 * (dep[Lt] - dep[w]) + (ll)len * std::min(offset - 1, len - offset);
	}
	printf("%d %d %lld\n", Lu, Lv, D);
	return 0;
}