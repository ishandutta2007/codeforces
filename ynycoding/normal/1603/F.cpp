#include <cstdio>
#include <algorithm>
const int N=10000005, MOD=998244353, iv2=MOD/2+1;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int T, n, k, x, dw[N], up[N], pw[N], ipw[N], pw1, lim;
inline int F(int x)
{
	if(x<0) return 0;
//	printf("F %d %d\n", x, 1ll*dw[x]*up[x]%MOD);
	return 1ll*dw[x]*up[x]%MOD;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &k, &x);
		dw[0]=up[0]=1;
		pw[0]=1;
		for(int i=1; i<=k; ++i) pw[i]=2ll*pw[i-1]%MOD;
		pw1=qpow(2, std::max(0, n-k)), lim=std::max(0, n-k);
		for(int i=1; i<=std::min(n, k); ++i)
		{
			dw[i]=1ll*dw[i-1]*(1ll*pw[n-i+1-lim]*pw1%MOD-1)%MOD;
			up[i]=1ll*up[i-1]*(pw[i]-1)%MOD;
		}
		for(int i=std::min(n, k), cur=qpow(up[i], MOD-2); i; --i)
		{
			up[i]=cur;
			ipw[i]=1ll*cur*up[i-1]%MOD;
			cur=1ll*cur*(pw[i]-1)%MOD;
		}
		int cur=1, ans=0, V=qpow(2, k), iV=qpow(V-1, MOD-2);
		if(x)
		{
			for(int i=1; i<=std::min(n, k); ++i)
			{
				cur=1ll*cur*fix(V-pw[i-1])%MOD;
//				printf("cur %d %d\n", cur, qpow(2, i)-1);
				inc(ans, 1ll*cur*F(i)%MOD*iV%MOD*(pw[i]-1)%MOD);
			}
//			printf("ans %d\n", ans);
			printf("%d\n", fix(qpow(V, n)-ans));
		}
		else
		{
			if(n>k) { puts("0"); continue; }
			int ans=1;
			for(int i=1; i<=n; ++i) ans=1ll*ans*fix(V-pw[i-1])%MOD;
			printf("%d\n", ans);
		}
	}
	return 0;
}