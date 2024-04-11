#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN=2000+10;

int p[MAXN], level[MAXN];
int n, m;

void dfs(int u) {
	if (level[u]) return;
	if (p[u]==-1) level[u]=1;
	else {
		dfs(p[u]);
		level[u]=level[p[u]]+1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", p+i);
	memset(level, 0, sizeof(level));
	int ret=0;
	for (int i=1; i<=n; i++) {
		if (!level[i]) dfs(i);
		if (level[i]>ret) ret=level[i];
	}
	printf("%d\n", ret);
	return 0;
}