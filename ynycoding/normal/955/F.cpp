#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=300005;
int n, f[N][30], g[N][30], tmp[N];
ll ans;
vector<int> e[N];
int dfs(int u, int fa)
{
	int sz=0, mx=0;
	for(int v:e[u]) if(v!=fa) mx=std::max(mx, dfs(v, u)), ++sz;
	++mx;
	f[u][1]=n;
	ans+=n-1+mx;
	for(int i=2; i<=25; ++i)
	{
		std::fill(tmp, tmp+sz+1, 0);
		for(int v:e[u]) if(v!=fa) ++tmp[std::min(f[v][i-1], sz)];
		for(int j=sz, cur=0; ~j; --j)
		{
			cur+=tmp[j];
			if(cur>=j) { f[u][i]=j; break; }
		}
		g[u][i]=f[u][i];
		for(int v:e[u]) if(v!=fa) g[u][i]=std::max(g[u][i], g[v][i]);
		ans+=std::max(g[u][i]-1, 0);
	}
	return mx;
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}