#include <cstdio>
#include <vector>
#include <algorithm>
const int N=1000005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int T, n, a[N], cnt[N], f[N], g[N], rcnt[N], id[N], top, d;
int fac[N], inv[N];
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int solve(int x)
{
	int ret=0;
	int cur=1;
	for(int i=1; i<=top; ++i)
	{
		int u=id[i];
		cur=1ll*cur*qpow(inv[u/x], rcnt[u])%MOD;
	}
	cur=1ll*cur*fac[n/x]%MOD;
	for(int i=1; i<=top; ++i)
	{
		int u=id[i], v=0;
		if(n!=u)
		{
			int mul=1ll*cur*fac[u/x]%MOD*fac[(n-u)/x]%MOD*inv[n/x]%MOD;
//			printf("in %d %d %d\n", u, x, u/x);
//			printf("mul %d\n", mul);
			v=1ll*C(n/x-2, u/x-1)*(n/x)%MOD*mul%MOD*x%MOD;
		}
		else v=1;
//		printf("v %d %d %d\n", u, v, 1ll*fac[n/x]*inv[n/x]%MOD);
		inc(ret, 1ll*v*rcnt[u]%MOD);
	}
//	printf("solve %d %d %d\n", n/x, ret, cur);
	g[x]=cur;
	return ret;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		std::fill(cnt+1, cnt+n+1, 0);
		std::fill(rcnt+1, rcnt+n+1, 0);
		top=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), ++cnt[a[i]];
		d=0;
		for(int i=1; i<=n; ++i) if(cnt[i]) d=std::__gcd(d, cnt[i]), ++rcnt[cnt[i]];
//		printf("d %d\n", d);
		for(int i=1; i<=n; ++i) if(rcnt[i]) id[++top]=i;
//		if(id[1]==n) { puts("1"); continue; }
		fac[0]=inv[0]=inv[1]=1;
		for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
		for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i-1]*inv[i]%MOD;
//		printf("C %d\n", C(4, 2));
		for(int i=1; i<=d; ++i) if(d%i==0) f[i]=solve(i);
		else g[i]=f[i]=0;
		for(int i=d; i; --i) for(int j=2; i*j<=d; ++j) dec(f[i], f[i*j]), dec(g[i], g[i*j]);
//		for(int i=1; i<=d; ++i) printf("%d %d %d\n", n/i, f[i], g[i]);
		int ans=0, q=0;
		for(int i=1; i<=d; ++i) inc(ans, 1ll*f[i]*qpow(n/i, MOD-2)%MOD), inc(q, 1ll*g[i]*qpow(n/i, MOD-2)%MOD);
//		printf("ans %d %d\n", ans, q);
		printf("%d\n", 1ll*ans*qpow(q, MOD-2)%MOD);
	}
	return 0;
}