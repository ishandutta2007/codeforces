#include <bits/stdc++.h>

const int N = 4100;

int n, l, pos;
int a[N], p[N], q[N], ip[N];

inline void swapP(int u, int v) {std::swap(ip[p[u]], ip[p[v]]), std::swap(p[u], p[v]);}

void adjust(int i) {
	if (!(p[i] ^ q[i] ^ a[i])) return;
	int j = ip[q[i] ^ a[i]];
	if (swapP(i, j), j < pos) std::swap(q[j], q[pos]), adjust(j);
}

int main() {
	int i;
	scanf("%d", &l), n = 1 << l;
	for (i = 0; i < n; ++i) scanf("%d", a + i), p[i] = q[i] = ip[i] = i;
	if (std::accumulate(a, a + n, 0, std::bit_xor <int> ())) return puts("Fou"), 0;
	for (pos = 1; pos < n; ++pos) adjust(pos - 1);
	puts("Shi");
	for (i = 0; i < n; ++i) printf("%d%c", p[i], i == n - 1 ? 10 : 32);
	for (i = 0; i < n; ++i) printf("%d%c", q[i], i == n - 1 ? 10 : 32);
	return 0;
}