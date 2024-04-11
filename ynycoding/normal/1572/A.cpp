#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
const int N=200005;
using std::vector;
int T, n, vis[N], in[N], f[N], ok;
vector<int> e[N];
int dfs(int u)
{
	if(vis[u]) return f[u];
	vis[u]=1;
	in[u]=1;
	f[u]=1;
	for(int v:e[u])
	{
		f[u]=std::max(f[u], dfs(v)+(u<v));
		if(in[v]||ok) { ok=1; return 0; }
	}
	in[u]=0;
	return f[u];
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1, k; i<=n; ++i)
		{
			scanf("%d", &k);
			for(int j=1, x; j<=k; ++j)
			{
				scanf("%d", &x);
				e[i].pb(x);
			}
		}
		ok=0;
		std::fill(vis+1, vis+n+1, 0);
		std::fill(in+1, in+n+1, 0);
		int ans=0;
		for(int i=1; i<=n&&!ok; ++i) ans=std::max(ans, dfs(i));
		printf("%d\n", ok?-1:ans);
	}
	return 0;
}