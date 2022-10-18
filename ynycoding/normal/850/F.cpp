#include <cstdio>
#include <algorithm>
#define N 100005
const int MOD=1000000007;
int n, s, cur, a[N], mx, inv[N], f[N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=mval(x+MOD-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), s+=a[i], mx=std::max(a[i], mx);
	for(int i=1; i<=mx; ++i) inv[i]=qpow(s-i, MOD-2), inc(inv[i], inv[i-1]);
	for(int i=1; i<=n; ++i)
	{
		inc(cur, a[i]-1);
		dec(cur, 1ll*(s-a[i])*inv[a[i]-1]%MOD);
	}
	cur=1ll*cur*(s-1)%MOD;
	printf("%d\n", mval(1ll*(s-1)*(s-1)%MOD+MOD-cur));
	return 0;
}