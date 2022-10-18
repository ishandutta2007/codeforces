#include <cstdio>
#include <algorithm>
#define MAXN 100005
int T, n, a[MAXN];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		std::sort(a+1, a+n+1);
		printf("%d\n", std::min(std::max(n-2, 0), a[n-1]-1));
	}
	return 0;
}