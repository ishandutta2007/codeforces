#include <cstdio>
#include <algorithm>
const int N=100005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
int n, m, f[N], ans=1;
int main()
{
	scanf("%d%d", &n, &m);
	f[0]=f[1]=1;
	for(int i=2; i<=std::max(n, m); ++i)
	{
		f[i]=mval(f[i-2]+f[i-1]);
	}
	printf("%d\n", 2ll*(f[n]+f[m]-1)%MOD);
	return 0;
}