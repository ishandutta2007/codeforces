#include <cstdio>
#include <algorithm>
const int N=4000005;
int MOD;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline int fix(int x) { return x+(x>>31&MOD); }
int n, f[N], sum[N];
int main()
{
	scanf("%d%d", &n, &MOD);
	sum[n]=f[n]=1;
	for(int i=n-1; i; --i)
	{
		f[i]=sum[i+1];
		for(int x=2; x*i<=n; ++x) inc(f[i], fix(sum[i*x]-sum[std::min(n+1, (i+1)*x)]));
		sum[i]=mval(f[i]+sum[i+1]);
	}
	printf("%d\n", f[1]);
	return 0;
}