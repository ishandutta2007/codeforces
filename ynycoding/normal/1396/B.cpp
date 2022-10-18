#include <cstdio>
#include <algorithm>
int T, n, sum, mx;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		sum=mx=0;
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), sum+=x, mx=std::max(mx, x);
		puts((mx*2>sum||(sum&1))?"T":"HL");
	}
	return 0;
}