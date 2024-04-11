#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef unsigned long long u64;
typedef std::pair <u64, int> pr;
const int N = 500054;

int V, E;
ll c[N];
u64 w[N], ww[N];
pr g[N];
std::mt19937_64 gen;

void work() {
	int i, j, u, v; ll sum, gcd = 0;
	scanf("%d%d", &V, &E);
	for (i = 1; i <= V; ++i) scanf("%lld", c + i), w[i] = gen(), ww[i] = 0;
	for (i = 1; i <= E; ++i) scanf("%d%d", &u, &v), ww[v] ^= w[u];
	for (i = 1; i <= V; ++i) g[i - 1] = pr(ww[i], i);
	std::sort(g, g + V);
	for (j = i = 0; i < V; i = j) {
		for (sum = 0; j < V && g[i].first == g[j].first; ++j)
			sum += c[g[j].second];
		if (g[i].first) gcd = std::__gcd(gcd, sum);
	}
	printf("%lld\n", gcd);
}

int main() {
	int T;
	char *_ = new char; gen.seed(time(NULL) + (size_t)_), delete _;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}