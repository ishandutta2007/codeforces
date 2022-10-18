#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 500005
using std::vector;
const int MOD=998244353;
int n, f[N][2], g[N][2];
vector<int> e[N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=mval(MOD+x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
void dfs(int u, int fa)
{
	f[u][0]=1;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		int t=g[u][1];
		g[u][1]=mval(2ll*g[u][1]*(f[v][0]+f[v][1])%MOD+2ll*f[u][1]*(g[v][0]+g[v][1])%MOD);
		inc(g[u][1], mval(1ll*g[u][0]*f[v][0]%MOD+1ll*f[u][0]*g[v][0]%MOD));
		inc(g[u][1], 1ll*f[u][0]*f[v][0]%MOD);
		
		g[u][0]=mval(1ll*g[u][0]*(f[v][0]+2ll*f[v][1])%MOD+1ll*f[u][0]*(g[v][0]+2ll*g[v][1])%MOD);
		
		f[u][1]=mval(2ll*f[u][1]*(f[v][0]+f[v][1])%MOD+1ll*f[u][0]*f[v][0]%MOD);
		f[u][0]=f[u][0]*(2ll*f[v][1]+f[v][0])%MOD;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	printf("%d\n", 2ll*mval(g[1][0]+g[1][1])%MOD);
	return 0;
}