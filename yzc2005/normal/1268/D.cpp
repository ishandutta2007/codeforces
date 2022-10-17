#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, col[N], siz[N], m, que[N], top, d[N], d1[N];
bitset<N> g[N], rg[N], rest;
char str[N];
void dfs1(int u) {
	rest.reset(u);
	auto e = rg[u] & rest;
	for (int v = e._Find_first(); v != N; v = e._Find_next(v))
		if (rest.test(v)) dfs1(v);
	que[++top] = u;
}
void dfs2(int u, int c) {
	col[u] = c, ++siz[c];
	auto e = g[u] & rest;
	for (int v = e._Find_first(); v != N; v = e._Find_next(v))
		if (!col[v]) dfs2(v, c);
}
bool check(int u) {
	memcpy(d1, d, sizeof d);
	for (int v = 1; v <= n; ++v) {
		if (u == v) continue;
		bool flag = g[u].test(v);
		d1[u] += (flag ? -1 : 1), d1[v] += (flag ? 1 : -1); 
	}
	sort(d1 + 1, d1 + n + 1);
	for (int i = 1; i < n; ++i)
		if (d1[i] += d1[i - 1], d1[i] == i * (i - 1) / 2) return false;
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str + 1);
		for (int j = 1; j <= n; ++j)
			if (str[j] == '1') g[i].set(j), rg[j].set(i);
	}
	for (int i = 1; i <= n; ++i) rest.set(i);
	for (int i = 1; i <= n; ++i) if (rest.test(i)) dfs1(i);
	for (int i = 1; i <= n; ++i) rest.set(i);
	for (int o = n; o; --o) if (!col[que[o]]) dfs2(que[o], ++m);
	if (m == 1) {
		puts("0 1");
		return 0;
	}
	for (int i = 1; i <= n; ++i) d[i] = g[i].count();
	int mx = *max_element(siz + 1, siz + m + 1);
	if (m >= 3 || mx > 3) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += check(i);
		printf("1 %d\n", ans);
		return 0;
	}
	if (n == 4) puts("-1");
	else puts("2 18");
	return 0;
}