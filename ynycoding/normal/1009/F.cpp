#include <cstdio>
#include <vector>
#include <algorithm>
#define N 1000005
#define pb push_back
using std::vector;
int n, son[N], dep[N], mx[N], dp[N], *f[N], top, ans[N];
vector<int> e[N];
void dfs(int u, int fa)
{
	dep[u]+=dep[fa];
	for(int v:e[u]) if(v!=fa) dfs(v, u), (mx[u]<mx[v]+1?mx[u]=mx[v]+1, son[u]=v:0);
}
void solve(int u, int fa)
{
	++top;
	f[u]=dp+top;
	if(son[u]) solve(son[u], u), ans[u]=ans[son[u]]+1;
	++f[u][0];
	(f[u][0]>f[u][ans[u]]||f[u][0]==f[u][ans[u]])?ans[u]=0:0;
	for(int v:e[u]) if(v!=fa&&v!=son[u])
	{
		solve(v, u);
		for(int i=0; i<=mx[v]; ++i) f[u][i+1]+=f[v][i],
		((f[u][i+1]>f[u][ans[u]]||(f[u][i+1]==f[u][ans[u]]&&i+1<ans[u]))?ans[u]=i+1:0);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	solve(1, 0);
	for(int i=1; i<=n; ++i) printf("%d\n", ans[i]);
	return 0;
}