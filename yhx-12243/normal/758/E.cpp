#include <bits/stdc++.h>

const int N = 200054, M = N * 2;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, E = 0;
int ord[N];
int p[N], fc[N], nc[N];
int w[N], c[N], fl[N];
long long sum[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}
inline void flow(int x, int f) {fl[x] += f, w[x] -= f, c[x] -= f;}

bool dfs(int x) {
	int y; sum[x] = 0;
	for (y = fc[x]; y; y = nc[y]) {
		if (!dfs(y)) return false;
		sum[x] += sum[y] + w[y];
	}
	if (x == 1) return true;
	if (c[x] < sum[x]) return false;
	return flow(x, min(w[x] - 1, c[x] - sum[x])), true;
}

int solve(int x, int lim) {
	int a, y, f = 0;
	a = min(lim, fl[x]), flow(x, -a), f += a;
	down(lim, c[x] - sum[x] + a);
	for (y = fc[x]; y; y = nc[y]) {
		a = solve(y, lim - f);
		if ((f += a) == lim) return f;
	}
	return f;
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), ord[i] = v, scanf("%d%d", w + v, c + v), link(v, u);
	if (!dfs(1)) return puts("-1"), 0;
	for (v = fc[1]; v; v = nc[v]) solve(v, INT_MAX);
	printf("%d\n", n);
	for (i = 1; i < n; ++i) v = ord[i], printf("%d %d %d %d\n", p[v], v, w[v], c[v]);
	return 0;
}