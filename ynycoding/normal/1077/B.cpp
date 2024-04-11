#include <cstdio>
int n, pre, ppr, ans;
int main()
{
	scanf("%d", &n);
	for(int i=1, a; i<=n; ++i)
	{
		scanf("%d", &a);
		if(ppr&&!pre&&a) ++ans, a=0;
		ppr=pre;
		pre=a;
	}
	printf("%d", ans);
	return 0;
}