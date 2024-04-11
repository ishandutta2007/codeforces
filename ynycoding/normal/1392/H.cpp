#include <cstdio>
#include <algorithm>
const int N=4000005, MOD=998244353;
int n, m, fac[N], iv[N], inv[N], mul, ans;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
inline void init(int n)
{
	iv[0]=iv[1]=fac[0]=inv[0]=1;
	for(int i=2; i<=n; ++i) iv[i]=MOD-1ll*iv[MOD%i]*(MOD/i)%MOD;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i-1]*iv[i]%MOD;
}
int main()
{
	scanf("%d%d", &n, &m);
	init(std::max(n, m+1));
	for(int x=1; x<=n; ++x)
	{
		int add=1ll*C(n, x)*(m+x)%MOD*iv[x]%MOD*(n+m+1)%MOD*iv[m+1]%MOD;
		if(x&1) inc(ans, add);
		else dec(ans, add);
	}
	printf("%d\n", ans);
	return 0;
}