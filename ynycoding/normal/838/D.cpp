#include <cstdio>
#include <algorithm>
const int MOD=1000000007;
int n, m, ans=1;
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int main()
{
	scanf("%d%d", &n, &m);
	ans=2*(n+1-m);
	ans=1ll*ans*qpow(2*n+2, m-1)%MOD;
	printf("%d\n", ans);
	return 0;
}