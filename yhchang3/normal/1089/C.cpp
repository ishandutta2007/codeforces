#include <bits/stdc++.h>

using namespace std;

int e[20001], nxt[20001], g[20001];
int tot = 1;
int N, stk[20001];
int d[502][502];
int q[20001];
bool mark[20001];
int n;

void add(int u, int v) {
	e[tot] = v; nxt[tot] = g[u]; g[u] = tot ++;
	e[tot] = u; nxt[tot] = g[v]; g[v] = tot ++;
}

void bfs(int x) {
	int h = 0, t = 1; q[t] = x;
	for (int i = 1; i <= n; i ++) d[x][i] = 0x3f3f3f3f;
	d[x][x] = 0;
	while (h < t) {
		int k = q[++ h];
		for (int i = g[k]; i; i = nxt[i])
			if (d[x][e[i]] == 0x3f3f3f3f) {
				d[x][e[i]] = d[x][k] + 1;
				q[++ t] = e[i];
			}
	}
}

char str[101];
int a[200001];
bool ask() {
	int ans = 0x3f3f3f3f, x, idx = -1;
	for (int i = 1; i <= N; i ++) {
		int u = stk[i];
		int mx = 0;
		for (int j = g[u]; j; j = nxt[j]) {
			if (mark[e[j]]) continue;
			int v = e[j];
			int tmp = 0;
			for (int k = 1; k <= N; k ++) {
				int w = stk[k];
				if (d[v][w] < d[u][w]) ++ tmp;
			}
			mx = max(mx, tmp);
		}
		if (mx < ans) {
			ans = mx;
			idx = u;
		}
	}
	printf("%d\n", idx);
	fflush(stdout);
	scanf("%s", str);
	if (str[0] == 'F') return true;
	scanf("%d", &x);
	for (int i = 1; i <= N; i ++) {
		int u = stk[i];
		if (d[idx][u] <= d[x][u]) mark[u] = true;
	}
	N = 0;
	for (int i = 1; i <= n; i ++)
		if (mark[i] == false) stk[++ N] = i;
	return false;
}

void gao() {
	for (int i = 1; i <= n; i ++) mark[i] = false;
	N = 0;
	for (int i = 1; i <= n; i ++) stk[++ N] = i;
	for (int i = 1; i <= 10; i ++) {
		bool tmp = ask();
		if (tmp) return ;
	}
}

int main( ) {
	int dd, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &dd);
		for (int j = 1; j <= dd; j ++) scanf("%d", &a[j]);
		for (int j = 1; j < dd; j ++) {
			add(a[j], a[j + 1]);
		}
	}
	for (int i = 1; i <= n; i ++) bfs(i);
	for (int i = 1; i <= n; i ++) gao();
	return 0;
}