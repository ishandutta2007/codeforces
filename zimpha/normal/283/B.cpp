#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef long long LL;

const int MAXN=200000+10;
const LL inf=(1ll<<60ll);

LL dp[MAXN][2];
bool vis[MAXN][2];
int a[MAXN], n;

LL dfs(int x, int d) {
	if (x>n||x<=0) return 0;
	if (x==1) return inf;
	if (dp[x][d]!=-1) return dp[x][d];
	if (vis[x][d]) return inf;
	vis[x][d]=true;
	LL ret=0;
	if (d==0) ret=dfs(x+a[x], 1);
	else ret=dfs(x-a[x], 0);
	if (ret!=inf) dp[x][d]=ret+a[x];
	else dp[x][d]=inf;
	return dp[x][d];
}

int main() {
	scanf("%d", &n);
	for (int i=2; i<=n; i++) scanf("%d", a+i);
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	for (int i=2; i<=n; i++) {
		if (dp[i][0]==-1) dp[i][0]=dfs(i, 0);
		if (dp[i][1]==-1) dp[i][1]=dfs(i, 1);
	}
	for (int i=1; i<n; i++) {
		if (dp[i+1][1]==inf) puts("-1");
		else printf("%I64d\n", dp[i+1][1]+i);
	}
	return 0;
}