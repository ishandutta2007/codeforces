#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 3000;
int n, m, a[maxn + 3], top, st[maxn + 3];
int bel[maxn + 3], dep[maxn + 3];
bool vis[maxn + 3];
vector<int> G[maxn + 3];
db ans;

void dfs(int u, int f = 0) {
	st[++top] = u;
	vis[u] = true;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == f) continue;
		if (!vis[v]) {
			dfs(v, u);
		} else if (!m) {
			int p = 0;
			for (int i = 1; i <= top; i++) {
				if (st[i] == v) {
					p = i;
					break;
				}
			}
			m = top - p + 1;
			copy(st + p, st + top + 1, a + 1);
		}
	}
	st[top--] = 0;
}

void solve(int u, int f = 0) {
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (vis[v] || v == f) continue;
		bel[v] = bel[u];
		dep[v] = dep[u] + 1;
		solve(v, u);
	}
}

void search(int u, int f = 0, int d = 0) {
	ans += 1. / (d + 1);
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (vis[v] || v == f) continue;
		search(v, u, d + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i <= n; i++) {
		scanf("%d %d", &u, &v), u++, v++;
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= m; i++) {
		vis[a[i]] = true;
	}
	for (int i = 1; i <= m; i++) {
		bel[a[i]] = i;
		solve(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		vis[a[bel[i]]] = false;
		search(i);
		vis[a[bel[i]]] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bel[i] != bel[j]) {
				int x = dep[i] + dep[j], y = (bel[j] - bel[i] + m) % m, z = m - y;
				ans += 1. / (x + y + 1) + 1. / (x + z + 1) - 1. / (x + m);
			}
		}
	}
	printf("%.12lf\n", ans);
	return 0;
}