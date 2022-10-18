#include <cstdio>
#include <vector>
#include <ctime>
#include <numeric>
#include <random>
#include <algorithm>
#define pb push_back
#define ull unsigned long long
using std::vector;
const int N=2005;
int MOD;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int n, f[N][N], cur[N], h[N][N], g[N], sz[N];
int fac[N], inv[N], iv[N];
vector<int> e[N];
inline void init(int n)
{
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD;
	for(int i=0; i<=n; ++i)
	{
		inv[i]=qpow(fac[i], MOD-2);
		iv[i]=qpow(i, MOD-2);
	}
}
void dfs(int u, int fa)
{
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
	}
	std::fill(cur+1, cur+n+1, 1);
	for(int v:e[u]) if(v!=fa)
	{
		std::copy(cur+1, cur+n+1, h[v]+1);
		for(int i=1; i<=n; ++i) cur[i]=1ll*cur[i]*f[v][i]%MOD;
	}
	std::copy(cur+1, cur+n+1, f[u]+1);
	std::reverse(e[u].begin(), e[u].end());
	std::fill(cur+1, cur+n+1, 1);
	if(u>1) for(int v:e[u]) if(v!=fa)
	{
		for(int i=1, s=0, rs=0, pr=0; i<=n; ++i)
		{
			inc(f[u][i], (1ll*i*s+MOD-rs)%MOD*fix(f[v][i]-f[v][i-1])%MOD);
			int val=1ll*cur[i]*h[v][i]%MOD;
			dec(val, pr);
			inc(pr, val);
			inc(s, val);
			inc(rs, 1ll*i*val%MOD);
		}
		for(int i=1; i<=n; ++i) cur[i]=1ll*cur[i]*f[v][i]%MOD;
	}
	if(u>1) for(int i=1; i<=n; ++i) inc(f[u][i+1], f[u][i]);
}
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d%d", &n, &MOD);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	init(n);
	dfs(1, 0);
	for(int i=1; i<=n; ++i) g[i]=f[1][i];
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) dec(g[j], 1ll*g[i]*C(j, i)%MOD);
	for(int i=1; i<n; ++i) printf("%d ", g[i]);
	return 0;
}