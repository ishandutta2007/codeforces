#include <bits/stdc++.h>

const int N = 1054, M = 100054;

int V1, V2, E, deg;
int G[N][N], ans[M];
int col[2][N][N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void dfs(int a, int b, int u, int v, int cu, int cv) {
	int _u = col[b][v][cu];
	col[a][u][cu] = v, col[b][v][cu] = u;
	if (cu == cv) return;
	_u ? dfs(b, a, v, _u, cv, cu) : (void)(col[b][v][cv] = 0);
}

int main() {
	int i, u, v, cu, cv;
	scanf("%d%d%d", &V1, &V2, &E);
	for (i = 1; i <= E; ++i) {
		scanf("%d%d", &u, &v), G[u][v] = i;
		for (cu = 1; col[0][u][cu]; ++cu); up(deg, cu);
		for (cv = 1; col[1][v][cv]; ++cv); up(deg, cv);
		dfs(0, 1, u, v, cu, cv);
	}
	printf("%d\n", deg);
	for (u = 1; u <= V1; ++u)
		for (i = 1; i <= deg; ++i)
			if ((v = col[0][u][i])) ans[G[u][v]] = i;
	for (i = 1; i <= E; ++i) printf("%d%c", ans[i], i == E ? 10 : 32);
	return 0;
}