#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 2e5, maxm = 4e5;
int n, w[maxn + 3], all, cent, node, sz[maxn + 3], mx[maxn + 3];
int tot, ter[maxm + 3], wei[maxm + 3], nxt[maxm + 3], lnk[maxn + 3];
bool vis[maxn + 3];
db sum[maxn + 3], num, ans;

void add(int u, int v, int w) {
	ter[++tot] = v, wei[tot] = w, nxt[tot] = lnk[u], lnk[u] = tot;
}

void centroid(int u, int f = 0) {
	sz[u] = 1, mx[u] = 0;
	for (int i = lnk[u], v; i; i = nxt[i]) {
		if ((v = ter[i]) == f || vis[v]) continue;
		centroid(v, u), sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
	}
	mx[u] = max(mx[u], all - sz[u]);
	if (!cent || mx[u] < mx[cent]) cent = u;
}

void dfs(int u, int f = 0, int d = 0) {
	sum[u] = w[u] * sqrt(d), num += w[u] * pow(d, 1.5);
	for (int i = lnk[u], v; i; i = nxt[i]) {
		if ((v = ter[i]) == f) continue;
		dfs(v, u, d + wei[i]), sum[u] += sum[v];
	}
}

void solve(int u, int m) {
	all = m, cent = 0, centroid(u);
	u = cent, centroid(u), vis[u] = true;
	num = 0, dfs(u);
	if (num < ans) node = u, ans = num;
	for (int i = lnk[u], v; i; i = nxt[i]) {
		if (vis[v = ter[i]]) continue;
		if (sum[u] - sum[v] * 2 >= 0) continue;
		solve(v, sz[v]); break;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	ans = 1e100;
	solve(1, n);
	printf("%d %.12lf\n", node, ans);
	return 0;
}