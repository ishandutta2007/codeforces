#include <cstdio>
#include <algorithm>
#define MAXN 150005
int T, n, a[MAXN], ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		ans=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=n, cur=a[n]; ~i; --i) cur=std::min(cur, a[i]), ans+=(a[i]>cur);
		printf("%d\n", ans);
	}
	return 0;
}