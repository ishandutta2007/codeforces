#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 100054;

int n, z = 0;
int p[N], fc[N], nc[N];
int dep[N];
int cnt = 0, ans[N];
bool large[N];

inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}

void dfs(int x) {
	if (dep[x] > dep[z]) z = x;
	for (int y = fc[x]; ~y; y = nc[y])
		dep[y] = dep[x] + 1, dfs(y);
}

void dfs2(int x) {
	int zzz = -1;
	ans[cnt++] = x;
	for (int y = fc[x]; ~y; y = nc[y]) {
		if (large[y]) zzz = y;
		else dfs2(y);
	}
	if (~zzz) dfs2(zzz);
}

int main() {
	int i, g, x;
	memset(fc, -1, sizeof fc);
	scanf("%d", &n), *p = -1;
	for (i = 1; i < n; ++i) scanf("%d", &x), link(i, x);
	dfs(0);
	for (g = z; ~g; g = p[g]) large[g] = true;
	dfs2(0);
	for (i = 0; i < cnt; ++i) printf("%d%c", ans[i], i == cnt - 1 ? 10 : 32);
	printf("%d\n", n - 1 - dep[z]);
	for (i = 1; i < cnt; ++i)
		for (g = dep[ans[i - 1]] - dep[ans[i]] + 1; g; --g)
			printf("%d ", ans[i]);
	putchar(10);
	return 0;
}