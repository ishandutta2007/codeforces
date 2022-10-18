#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 105
using std::vector;
const int MOD=1000000007;
int n, f[N][N][2], tmp[N][2], sz[N], inv[N], fac[N], g[N];
vector<int> e[N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=mval(MOD+x-a); }
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
void dfs(int u, int fa)
{
	f[u][0][0]=1, f[u][0][1]=n;
	sz[u]=1;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		for(int i=0; i<=sz[u]+sz[v]+1; ++i) tmp[i][0]=tmp[i][1]=0;
		for(int i=0; i<=sz[u]; ++i) for(int j=0; j<=sz[v]; ++j)
		{
			inc(tmp[i+j+1][1], (1ll*f[u][i][1]*f[v][j][0]+1ll*f[u][i][0]*f[v][j][1])%MOD);
			inc(tmp[i+j+1][0], 1ll*f[u][i][0]*f[v][j][0]%MOD);
			inc(tmp[i+j][1], 1ll*f[u][i][1]*f[v][j][1]%MOD);
			inc(tmp[i+j][0], 1ll*f[u][i][0]*f[v][j][1]%MOD);
		}
		sz[u]+=sz[v];
		for(int i=0; i<=sz[u]; ++i) f[u][i][0]=tmp[i][0], f[u][i][1]=tmp[i][1];
	}
}
int main()
{
	scanf("%d", &n);
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	int iv=1ll*inv[n]*inv[n]%MOD;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i]*inv[i-1]%MOD;
	
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	for(int i=0; i<=n; ++i) for(int j=i; j<=n; ++j)
	{
		if((i-j)&1) dec(g[i], 1ll*f[1][j][1]*iv%MOD*C(j, i)%MOD);
		else inc(g[i], 1ll*f[1][j][1]*iv%MOD*C(j, i)%MOD);
	}
	for(int i=0; i<n; ++i) printf("%d ", g[i]);
	 
	return 0;
}