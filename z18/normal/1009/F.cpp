#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n, mx[maxn + 3], ch[maxn + 3], id[maxn + 3], ans[maxn + 3], res[maxn + 3];
vector<int> G[maxn + 3], f[maxn + 3];

void dfs(int u, int pa = 0) {
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == pa) continue;
		dfs(v, u);
		if (mx[v] + 1 > mx[u]) {
			mx[u] = mx[v] + 1, ch[u] = v;
		}
	}
	int x = id[u] = ch[u] ? id[ch[u]] : u;
	ans[u] = ch[u] ? ans[ch[u]] + 1 : 0, res[u] = ch[u] ? res[ch[u]] : 1;
	f[x].push_back(1);
	if (res[u] == 1) {
		ans[u] = 0;
	}
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == pa || v == ch[u]) continue;
		int y = id[v];
		for (int j = 0; j < f[y].size(); j++) {
			int p = f[x].size() - f[y].size() + j - 1;
			f[x][f[x].size() - f[y].size() + j - 1] += f[y][j];
			int id = f[x].size() - p - 1, val = f[x][p];
			if (val > res[u] || (val == res[u] && id < ans[u])) {
				ans[u] = id, res[u] = val;
			}
		}
	}
	/*
	for (int j = f[x].size() - 1; ~j; j--) {
		printf("%d %d\n", f[x].size() - 1 - j, f[x][j]);
	}
	*/
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}