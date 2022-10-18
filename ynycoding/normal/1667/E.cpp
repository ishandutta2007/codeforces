#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define ull unsigned long long
using std::vector;
typedef vector<int> poly;
const int N=1000005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, f[N], inv[N], fac[N], tp;
inline int C(int n, int m) { return (m<0||n<m)?0:1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d", &n);
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD;
	inv[n]=qpow(fac[n], MOD-2);
	for(int i=n-1; ~i; --i) inv[i]=1ll*(i+1)*inv[i+1]%MOD;
	for(int i=2; i<=(n+1)/2; ++i)
	{
		int l=(n+1)/2-1, r=n-i;
		f[i]=1ll*fix(C(n-l-1, i-1)-C(n-r-2, i-1))*fac[i-1]%MOD*fac[n-i]%MOD;
	}
	f[1]=fac[n-1];
	for(int i=(n+1)/2, sum=0; i; --i)
	{
		dec(f[i], 1ll*sum*inv[i]%MOD*fac[i-1]%MOD);
		inc(sum, f[i]);
	}
	for(int i=1; i<=n; ++i) printf("%d ", f[i]);
	return 0;
}