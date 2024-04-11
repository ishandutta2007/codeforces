#include <cstdio>
#include <algorithm>
#define MOD 998244353
#define N 300005
int n, ivn, c[N], ans;
inline int mval(int x) { return x>=MOD?x-MOD:x<0?x+MOD:x; }
inline int qpow(int x, int p) { int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; x=1ll*x*x%MOD, p>>=1; } return ret; }
bool cmp(int x, int y) { return x>y; }
int main()
{
	scanf("%d", &n);
	ivn=qpow(n, MOD-2);
	for(int i=1; i<=n; ++i) scanf("%d", c+i);
	std::sort(c+1, c+n+1, cmp);
	for(int i=1; i<=n; ++i) c[i]=mval(c[i]+c[i-1]);
	for(int k=1; k<=n; ++k)
	{
		ans=0;
		for(int i=1; i*k<n; ++i) ans=mval(ans+1ll*i*mval(c[std::min(n, (i+1)*k)]-c[i*k])%MOD);
		printf("%d ", 1ll*ans*ivn%MOD);
	}
	return 0;
}