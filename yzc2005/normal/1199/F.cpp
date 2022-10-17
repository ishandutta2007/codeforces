#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, r[N][N], c[N][N], f[N][N][N][N];
bool vis[N][N][N][N];
char a[N][N];

inline void ckmin(int &a, int b) {
	if(a > b) a = b;
}

int dfs(int x, int y, int u, int v) {
	if(x > u || y > v) return 0;
	if(x == u && y == v) return a[x][y] == '#';
	if(vis[x][y][u][v]) return f[x][y][u][v]; 
	vis[x][y][u][v] = 1;
	f[x][y][u][v] = max(u - x, v - y) + 1;
	for(int i = x; i <= u; ++i) 
		if(r[i][v] == r[i][y - 1]) 
			ckmin(f[x][y][u][v], dfs(x, y, i - 1, v) + dfs(i + 1, y, u, v));
	for(int i = y; i <= v; ++i)
		if(c[u][i] == c[x - 1][i])
			ckmin(f[x][y][u][v], dfs(x, y, u, i - 1) + dfs(x, i + 1, u, v));
	return f[x][y][u][v];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= n; ++j)
			if(a[i][j] == '#') r[i][j] = r[i][j - 1] + 1, c[i][j] = c[i - 1][j] + 1;
			else r[i][j] = r[i][j - 1], c[i][j] = c[i - 1][j];
	printf("%d", dfs(1, 1, n, n));
}