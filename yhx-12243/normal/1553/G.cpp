#include <bits/stdc++.h>
#define gcd std::__gcd
#define EB emplace_back
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef std::vector <int> vector;
typedef std::unordered_set <u64> set;
const int N = 150054, W = 1000054, B = 750;

int n, q;
int a[N], tmp[N];
int pn = 0, c[W], p[78540];
vector U[78540];
bool has_even[N];
set S;

namespace G {
	int p[N], size[N];

	inline void init() {std::iota(p, p + (n + 1), 0), std::fill(size, size + (n + 1), 1);}
	int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}
	inline void link(int x, int y) {
		if ((x = ancestor(x)) == (y = ancestor(y))) return;
		if (size[x] > size[y]) std::swap(x, y);
		p[x] = y, size[y] += size[x];
	}
}

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}

void work(int id) {
	int e, x = a[id];
	for (; x != 1; ) {
		e = c[x], U[e].EB(id);
		for (; !(x % p[e]); x /= p[e]);
	}
}

void work2(int id) {
	int e, x = a[id] + 1, i, j, z = 1;
	for (*tmp = G::p[id]; x != 1; ) {
		e = c[x];
		for (; !(x % p[e]); x /= p[e]);
		if (!U[e].empty())
			tmp[z++] = G::p[U[e].front()];
	}
	std::sort(tmp, tmp + z), z = std::unique(tmp, tmp + z) - tmp;
	//fprintf(stderr, "%d:\n", id);
	for (i = 0; i < z; ++i) for (j = i + 1; j < z; ++j) {
	//	fprintf(stderr, "connect %d %d\n", tmp[i], tmp[j]);
		S.emplace(tmp[i] | (u64)tmp[j] << 32);
	}

}

int solve(int u, int v) {
	int belU = G::p[u], belV = G::p[v];
	if (belU == belV) return 0;
	if (has_even[belU] || has_even[belV]) return 1;
	if (belU > belV) std::swap(belU, belV);
	return S.count(belU | (u64)belV << 32) ? 1 : 2;
}

int main() {
	int i, u, v; sieve(W - 1);
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q, G::init();
	for (i = 1; i <= n; ++i) cin >> a[i], work(i);
	for (i = 0; i < pn; ++i) {
		v = U[i].size();
		for (u = 1; u < v; ++u) G::link(U[i][u - 1], U[i][u]);
	}
	for (i = 1; i <= n; ++i) {
		G::ancestor(i);
	//	fprintf(stderr, "%d => %d\n", i, G::p[i]);
		if (!(a[i] & 1)) has_even[G::p[i]] = true;
	}
	for (i = 1; i <= n; ++i) work2(i);
	for (; q; --q) cin >> u >> v, cout << solve(u, v) << '\n';
	return 0;
}