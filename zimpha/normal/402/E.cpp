#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;

int g[MAXN][MAXN], n, cnt, tid, top;
int stk[MAXN], low[MAXN], dfn[MAXN];
int vis[MAXN];

void dfs(int u) {
	low[u] = dfn[u] = ++ tid;
	stk[top ++] = u; vis[u] = 1;
	for (int v = 0; v < n; ++ v) {
		if (!g[u][v]) continue;
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		while (1) {
			int y = stk[-- top];
			vis[y] = 0;
			if (y == u) break;
		}
		++ cnt;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j)
			scanf("%d", &g[i][j]);
	}
	cnt = tid = top = 0;
	memset(vis, 0, sizeof(vis));
	memset(dfn, 0, sizeof(dfn));
	for (int i = 0; i < n; ++ i)
		if (!dfn[i]) dfs(i);
	if (cnt > 1) puts("NO");
	else puts("YES");
	return 0;
}