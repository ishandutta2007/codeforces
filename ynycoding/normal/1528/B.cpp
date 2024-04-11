#include <cstdio>
#include <algorithm>
const int N=1000005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int n, ans, fac[N];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) for(int j=i; j<=n; j+=i)
		++fac[j];
	ans=fac[n];
	for(int i=1, cur=1; i<=n; ++i, cur=2ll*cur%MOD)
	{
		inc(ans, 1ll*cur*fac[n-i]%MOD);
	}
	printf("%d\n", ans);
	return 0;
}