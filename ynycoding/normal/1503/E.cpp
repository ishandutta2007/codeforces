#include <cstdio>
#include <algorithm>
const int N=12005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }

int n, m, inv[N], fac[N], ans;
inline void init(int n)
{
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i-1]*inv[i]%MOD;
}
inline int C(int n, int m) { return (n<0||n<m||m<0)?0:1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
inline int F(int n, int m) { return C(n+m, m); }
inline int calc(int n, int m)
{
	int ret=0;
	for(int i=1; i<m; ++i)
	{
		inc(ret, 1ll*fix(F(2*i, n)-F(2*i-1, n))*fix(F(2*(m-i), n)-F(2*(m-i)-1, n))%MOD);
		for(int j=0; j<n; ++j)
		{
			dec(ret, 1ll*F(i, j)*F(i, n-j-1)%MOD*F(m-i, j)%MOD*F(m-i, n-j-1)%MOD);
		}
		for(int j=0; j<n-1; ++j)
		{
			inc(ret, 1ll*F(i, j)*F(i, n-j-2)%MOD*F(m-i, j)%MOD*F(m-i, n-j-2)%MOD);
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
	init(2*(n+m));
	ans=mval(calc(n, m)+calc(m, n));
	for(int i=1; i<n; ++i) for(int j=1; j<m; ++j)
	{
		dec(ans, 2ll*F(j-1, i)*F(m-j-1, n-i)%MOD*F(m-j, i-1)%MOD*F(j, n-i-1)%MOD);
	}
	printf("%d\n", ans);
	return 0;
}