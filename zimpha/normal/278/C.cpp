#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN=100+10;

bool EL[MAXN][MAXN], LE[MAXN][MAXN];
bool vis[MAXN];
int n, m;

void dfs(int a) {
	vis[a]=true;
	for (int b=1; b<=m; b++)
		if (EL[a][b]) {
			for (int c=1; c<=n; c++)
				if (LE[b][c]&&!vis[c]) 
					dfs(c);
		}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(EL, 0, sizeof(EL));
	memset(LE, 0, sizeof(LE));
	int sum=0;
	for (int k, i=1; i<=n; i++) {
		scanf("%d", &k); sum+=k;
		for (int x, j=0; j<k; j++) {
			scanf("%d", &x);
			EL[i][x]=LE[x][i]=1;
		}
	}
	int ret=0;
	memset(vis, 0, sizeof(vis));
	for (int i=1; i<=n; i++)
		if (!vis[i]) {
			ret++; dfs(i);
		}
	if (!sum) printf("%d\n", ret);
	else printf("%d\n", ret-1);
}