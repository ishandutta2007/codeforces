#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN=100+10;

bool map[MAXN][MAXN];
bool vis[MAXN];
int a[MAXN], b[MAXN];
int n, m;

bool check(int a, int b, int c, int d) {
	if (a>c&&a<d) return true;
	if (b>c&&b<d) return true;
	return false;
}

void dfs(int u) {
	vis[u]=true;
	for (int v=1; v<=n; v++)
		if (map[u][v]&&!vis[v]) dfs(v);
}

int main() {
	memset(map, 0, sizeof(map));
	scanf("%d", &m); n=0;
	for (int i=0; i<m; i++) {
		int cmd, x, y; scanf("%d%d%d", &cmd, &x, &y);
		if (cmd==1) {
			n++; a[n]=x; b[n]=y;
			for (int i=1; i<n; i++) {
				if (check(a[i], b[i], a[n], b[n])) map[i][n]=1;
				if (check(a[n], b[n], a[i], b[i])) map[n][i]=1;
			}
		}
		else {
			memset(vis, 0, sizeof(vis));
			dfs(x);
			if (vis[y]) puts("YES");
			else puts("NO");
		}
	}
}