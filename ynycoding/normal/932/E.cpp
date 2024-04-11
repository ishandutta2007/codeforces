#include <cstdio>
#include <algorithm>
#define N 5005
const int MOD=1000000007;
int n, k, b[N], c[N], inv[N], ans;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=mval(MOD+x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int main()
{
	scanf("%d %d", &n, &k);
	inv[0]=inv[1]=1;
	for(int i=2; i<=k; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=0; i<=k; ++i) b[i]=qpow(i, k);
	for(int i=0; i<=k; ++i)
	{
		c[i]=b[0];
		for(int j=0; j<k-i; ++j) b[j]=mval(b[j+1]+MOD-b[j]);
	}
	for(int i=0, cur=1; i<=std::min(n, k); ++i, cur=1ll*cur*(n-i+1)%MOD*inv[i]%MOD) inc(ans, 1ll*c[i]*qpow(2, n-i)%MOD*cur%MOD);
	printf("%d\n", ans);
	return 0;
}