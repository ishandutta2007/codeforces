#include <cstdio>
#include <algorithm>
const int N=50005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, m, e[10], f[N][1<<10];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), e[x]|=1<<y, e[y]|=1<<x;
	f[0][0]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int s=0; s<(1<<10); ++s) for(int x=0; x<10; ++x)
		{
			int t=(s&e[x])|(1<<x);
			if(!(t&((1<<x)-1))) inc(f[i][t], f[i-1][s]);
		}
	}
	int ans=0;
	for(int s=0; s<(1<<10); ++s) inc(ans, f[n][s]);
	printf("%d\n", ans);
	return 0;
}