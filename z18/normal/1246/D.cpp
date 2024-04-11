#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, d[maxn + 3], ch[maxn + 3], p[maxn + 3];
int m, id[maxn + 3], dfn[maxn + 3], rht[maxn + 3], k, a[maxn + 3];
vector<int> G[maxn + 3];

void dfs_1(int u) {
	ch[u] = -1;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		dfs_1(v);
		if (ch[u] == -1 || (d[v] > d[ch[u]])) {
			ch[u] = v, d[u] = d[v] + 1;
		}
	}
}

void dfs_2(int u, bool flag) {
	id[++m] = u, dfn[u] = m, rht[u] = m;
	bool t = true;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (ch[u] != v) {
			dfs_2(v, false);
			rht[u] = rht[v];
			if (t) {
				t = false;
			} else {
				a[++k] = dfn[v];
			}
		}
	}
	if (ch[u] != -1) {
		dfs_2(ch[u], flag);
		rht[u] = rht[ch[u]];
		if (t) {
			t = false;
		} else {
			a[++k] = dfn[ch[u]];
		}
	}
	if (!flag && !t) {
		a[++k] = rht[u] + 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]), G[p[i]].push_back(i);
	}
	dfs_1(0);
	dfs_2(0, true);
	for (int i = 1; i <= n; i++) {
		printf("%d%c", id[i], " \n"[i == n]);
	}
	printf("%d\n", k);
	for (int i = 1; i <= k; i++) {
		printf("%d%c", id[a[i]], " \n"[i == k]);
	}
	return 0;
}