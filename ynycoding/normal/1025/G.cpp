#include <cstdio>
#include <algorithm>
const int N=505, MOD=1000000007;
int n, a[N], sum[N], ans;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", a+i);
		if(a[i]==-1) ++sum[i];
		else ++sum[a[i]];
	}
	for(int i=1; i<=n; ++i) if(sum[i])
		inc(ans, qpow(2, sum[i]-1)-1);
	printf("%d\n", mval(MOD+qpow(2, n-1)-1-ans));
	return 0;
}