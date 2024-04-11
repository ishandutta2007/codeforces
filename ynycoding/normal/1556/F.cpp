#include <cstdio>
#include <algorithm>
const int N=16, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int n, a[N], f[1<<N], rp[N][1<<N], p[N][N];
int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", a+i);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(i!=j)
		p[i][j]=1ll*a[i]*qpow(a[i]+a[j], MOD-2)%MOD;
//	for(int i=0; i<n; ++i) f[1<<i]=1;
	for(int i=0; i<n; ++i) for(int s=0; s<(1<<n); ++s)
	{
		rp[i][s]=1;
		for(int j=0; j<n; ++j) if(s&(1<<j))
			rp[i][s]=1ll*rp[i][s]*p[j][i]%MOD;
//		printf("fa %d %d %d\n", i, s, rp[i][s]);
	}
	for(int s=1; s<(1<<n); ++s)
	{
		f[s]=__builtin_popcount(s);
		for(int t=(s-1)&s; t; t=(t-1)&s)
		{
			int mul=1;
			for(int i=0; i<n; ++i) if(t&(1<<i))
				mul=1ll*mul*rp[i][s^t]%MOD;//, printf("mul %d %d %d\n", i, s^t, rp[i][s^t]);
//			printf("dec %d %d %d\n", s, t, mul);
			dec(f[s], 1ll*mul*f[t]%MOD);
		}
	}
	printf("%d\n", f[(1<<n)-1]);
	return 0;
}