#include <cstdio>
#include <vector>
#include <ctime>
#include <numeric>
#include <random>
#include <algorithm>
#define pb push_back
#define ull unsigned long long
using std::vector;
const int N=200005;

int n, m, fa[N];
int x[N], y[N], w[N], ok[N], f[N], in[N], out[N], pa[N][20], cnt, rs;
vector<int> e[N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
int dep[N];
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1;
	pa[u][0]=fa;
	for(int i=1; (1<<i)<=n; ++i) pa[u][i]=pa[pa[u][i-1]][i-1];
	in[u]=++cnt;
	for(int v:e[u]) if(v!=fa) dfs(v, u);
	out[u]=cnt;
}
inline int kth(int x, int k)
{
	for(int i=19; ~i; --i) if(k&(1<<i)) x=pa[x][i];
	return x;
}
int main()
{
	scanf("%d%d", &n, &m);
	std::iota(fa, fa+n+1, 0);
	for(int i=1; i<=m; ++i) scanf("%d%d", x+i, y+i);
	for(int i=1; i<=m; ++i)
	{
		int u=i;
		int x=findfa(::x[u]), y=findfa(::y[u]);
		if(x!=y) fa[x]=y, ok[u]=1, e[::x[u]].pb(::y[u]), e[::y[u]].pb(::x[u]);
	}
	dfs(1, 0);
	for(int i=1; i<=m; ++i) if(!ok[i])
	{
		++rs;
		int a=x[i], b=y[i];
		if(dep[a]<dep[b]) std::swap(a, b);
		if(in[b]<=in[a]&&out[b]>=out[a])
		{
			int l=kth(a, dep[a]-dep[b]-1);
			++f[in[a]], --f[out[a]+1], ++f[1], --f[in[l]], ++f[out[l]+1];
		}
		else
		{
			++f[in[a]], --f[out[a]+1];
			++f[in[b]], --f[out[b]+1];
		}
	}
	for(int i=1; i<=n; ++i) f[i]+=f[i-1];
	for(int i=1; i<=n; ++i) putchar((f[in[i]]==rs)+'0');
	return 0;
}