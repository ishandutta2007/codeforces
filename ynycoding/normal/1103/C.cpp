#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
const int N=250005;
using std::vector;
int n, m, k, lim, pa[N], is[N], dep[N];
vector<int> e[N];
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1;
	pa[u]=fa;
	is[fa]=1;
	if(dep[u]>=lim)
	{
		puts("PATH");
		printf("%d\n", dep[u]);
		while(u) printf("%d ", u), u=pa[u];
		exit(0);
	}
	for(int v:e[u]) if(!dep[v]) dfs(v, u);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	lim=(n+k-1)/k;
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	puts("CYCLES");
	for(int u=1, tc=k; u<=n&&tc; ++u) if(!is[u])
	{
		--tc;
		int x=e[u][0]==pa[u]?e[u][1]:e[u][0];
		int y=(e[u][1]==x||e[u][1]==pa[u])?e[u][2]:e[u][1];
		if((dep[u]-dep[x]+1)%3)
		{
			printf("%d\n", dep[u]-dep[x]+1);
			for(int t=u; t!=pa[x]; t=pa[t]) printf("%d ", t);
			puts("");
		}
		else if((dep[u]-dep[y]+1)%3)
		{
			printf("%d\n", dep[u]-dep[y]+1);
			for(int t=u; t!=pa[y]; t=pa[t]) printf("%d ", t);
			puts("");
		}
		else
		{
			if(dep[x]<dep[y]) std::swap(x, y);
			printf("%d\n", dep[x]-dep[y]+2);
			for(int t=x; t!=pa[y]; t=pa[t]) printf("%d ", t);
			printf("%d\n", u);
		}
	}
	return 0;
}