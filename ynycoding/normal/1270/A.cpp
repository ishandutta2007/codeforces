#include <cstdio>
#include <algorithm>
int t, n, k1, k2, mx1, mx2;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		mx1=mx2=0;
		scanf("%d%d%d", &n, &k1, &k2);
		for(int i=1, a; i<=k1; ++i) scanf("%d", &a), mx1=std::max(mx1, a);
		for(int i=1, a; i<=k2; ++i) scanf("%d", &a), mx2=std::max(mx2, a);
		puts(mx1>mx2?"YES":"NO");
	}
	return 0;
}