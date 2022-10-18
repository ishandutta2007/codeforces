#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=2005, K=105, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int n, k, f[K][N], g[K][N], fac[N], inv[N], b[N], l[N], r[N];
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", b+i);
		l[i]=b[i]-k;
		r[i]=b[i]+k;
		l[i]=std::max(l[i], l[i-1]);
	}
	r[n+1]=n+1;
	for(int i=n; i; --i) r[i]=std::min(r[i], r[i+1]);
	for(int i=1; i<=n; ++i) if(l[i]>r[i]) return puts("0"), 0;
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=n; ++i) inv[i]=1ll*inv[i]*inv[i-1]%MOD, fac[i]=1ll*i*fac[i-1]%MOD;
	for(int i=0; i<=r[n]-l[n]; ++i) for(int j=l[n]+i; j<=n; ++j)
		f[i][j]=C(n-(l[n]+i), j-l[n]-i);
	if(r[n]>n) f[r[n]-l[n]][n]=1;
	for(int i=n; i; --i)
	{
		memset(g, 0, sizeof(g));
		for(int j=0; j<=r[i]-l[i]; ++j)
		{
			int rv=j+l[i];
			for(int s=std::max(1, l[i]+j); s<=i; ++s) if(f[j][s])
			{
				int val=f[j][s];
				inc(g[std::min(r[i-1], rv-1)-l[i-1]][s-1], val);
			}
		}
		for(int j=r[i-1]-l[i-1]; ~j; --j) for(int s=l[i-1]+j; s<=i; ++s)
			inc(g[j][s], g[j+1][s]);
		for(int j=0; j<=r[i]-l[i]; ++j)
		{
			int rv=j+l[i];
			for(int s=l[i]+j; s<=i; ++s) if(f[j][s])
			{
				int val=f[j][s], t=rv-l[i-1];
				if(s) inc(g[t][s-1], 1ll*(s-rv)*val%MOD);
				inc(g[t][s], 1ll*s*val%MOD);
			}
		}
		memcpy(f, g, sizeof(f));
	}
	printf("%d\n", f[0][0]);
	return 0;
}