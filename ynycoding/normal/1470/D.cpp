#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=300005;
int T, n, m, vis[N], is[N], cnt;
vector<int> e[N];
void dfs(int u)
{
	vis[u]=1;
	for(int v:e[u]) is[u]|=is[v];
	is[u]^=1;
	for(int v:e[u]) if(!vis[v])
		dfs(v);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) e[i].clear(), vis[i]=is[i]=0;
		for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
		dfs(1);
		for(int i=1; i<=n; ++i) if(!vis[i])
		{
			puts("NO");
			goto out;
		}
		cnt=0;
		for(int i=1; i<=n; ++i) cnt+=is[i];
		puts("YES");
		printf("%d\n", cnt);
		for(int i=1; i<=n; ++i) if(is[i]) printf("%d ", i);
		puts("");
		out:;
	}
	return 0;
}