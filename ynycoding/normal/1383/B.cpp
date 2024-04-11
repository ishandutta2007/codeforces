#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=100005, K=21;
int T, n, a[N], sum, c0, c1;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		sum=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), sum^=a[i];
		c0=c1=0;
		if(!sum) { puts("DRAW"); continue; }
		int t=1<<(31-__builtin_clz(sum));
		for(int i=1; i<=n; ++i) if(t&a[i]) ++c1;
		else ++c0;
		if(((c1+1)>>1)&1) puts("WIN");
		else puts((c0&1)?"WIN":"LOSE");
	}
	return 0;
}