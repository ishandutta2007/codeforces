#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=100005;
int T, n, l[N], r[N];
ll f[N][2];
vector<int> e[N];
void dfs(int u, int fa)
{
	f[u][0]=f[u][1]=0;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		f[u][0]+=std::max(std::abs(l[u]-l[v])+f[v][0], std::abs(l[u]-r[v])+f[v][1]);
		f[u][1]+=std::max(std::abs(r[u]-l[v])+f[v][0], std::abs(r[u]-r[v])+f[v][1]);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d%d", l+i, r+i), e[i].clear();
		for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
		dfs(1, 0);
		printf("%lld\n", std::max(f[1][0], f[1][1]));
	}
	return 0;
}