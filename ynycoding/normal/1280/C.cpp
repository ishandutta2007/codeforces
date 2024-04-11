#include <cstdio>
#include <vector>
#define ll long long
#define pb push_back
#define MAXN 200005
using std::vector;
int t, n, sz[MAXN];
vector<int> e[MAXN], w[MAXN];
ll ansa, ansb;
void dfs(int u, int fa)
{
	sz[u]=1;
	for(int i=0; i<e[u].size(); ++i)
	{
		int v=e[u][i], c=w[u][i];
		if(v==fa) continue;
		dfs(v, u);
		sz[u]+=sz[v];
		ansa+=((sz[v]&1)||(n&1))?c:0;
		ansb+=(ll)c*std::min(sz[v], n-sz[v]);
	}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n), n*=2, ansa=ansb=0;
		for(int i=1; i<=n; ++i) e[i].clear(), w[i].clear(), sz[i]=0;
		for(int i=1, a, b, c; i<n; ++i) scanf("%d%d%d", &a, &b, &c), e[a].pb(b), e[b].pb(a), w[a].pb(c), w[b].pb(c);
		dfs(1, 0);
		printf("%lld %lld\n", ansa, ansb);
	}
	return 0;
}