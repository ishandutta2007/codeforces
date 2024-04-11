#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=1000005;
int n, m, deg[N], col[N], ok[N], cnt, top;
vector<int> e[N], g[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[y].pb(x), g[x].pb(y);
	for(int u=n; u; --u) if(!ok[u])
	{
		ok[u]=u;
		for(int v:g[u]) if(!ok[v]) ok[v]=u;
	}
	for(int u=1; u<=n; ++u) if(ok[u]==u)
	{
		col[u]=1;
		for(int v:e[u]) if(ok[v]<=u&&col[v])
		{
			col[u]=0;
			break;
		}
		cnt+=col[u];
	}
	printf("%d\n", cnt);
	for(int i=1; i<=n; ++i) if(col[i]) printf("%d ", i);
	return 0;
}