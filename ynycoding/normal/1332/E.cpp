#include <cstdio>
#include <algorithm>
#define ll long long
#define MOD 998244353
int n, m, l, r, iv2=MOD/2+1;
inline int qpow(int x, ll p) { int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; } 
int main()
{
	scanf("%d%d%d%d", &n, &m, &l, &r);
	r-=l-1;
	if(n&m&1) printf("%d\n", qpow(r, 1ll*n*m));
	else if(r&1) printf("%d\n", 1ll*iv2*(qpow(r, 1ll*n*m)+1)%MOD);
	else printf("%d\n", 1ll*iv2*qpow(r, 1ll*n*m)%MOD);
	return 0;
}