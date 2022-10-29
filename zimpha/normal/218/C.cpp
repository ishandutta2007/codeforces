#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100+10;

int x[MAXN], y[MAXN];
int map[MAXN][MAXN];
int vis[MAXN];
int n;

void dfs(int u) {
	vis[u]=true;
	for (int v=0; v<n; v++)
		if (map[u][v]&&!vis[v]) dfs(v);
}

int main() {
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	for (int i=0; i<n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		for (int j=0; j<i; j++)
			if (x[i]==x[j]||y[i]==y[j]) map[i][j]=map[j][i]=1;
	}
	int ret=0;
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<n; i++)
		if (!vis[i]) {
			dfs(i);
			ret++;
		}
	printf("%d\n", ret-1);
	return 0;
}