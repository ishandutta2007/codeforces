#include <cstdio>
#include <vector>
#include <algorithm>
const int N=30005;
using std::vector;
int n, m, vis[N];
vector<int> e[N];
void dfs(int u)
{
	vis[u]=1;
	for(int v:e[u]) if(!vis[v]) dfs(v);
	printf("%d ", u);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].push_back(y);
	for(int i=1; i<=n; ++i) if(!vis[i]) dfs(i);
	return 0;
}