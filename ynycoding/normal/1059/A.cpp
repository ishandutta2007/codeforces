#include <cstdio>
int n, l, a, cnt, pre;
int main()
{
	scanf("%d%d%d", &n, &l, &a);
	for(int i=1; i<=n; ++i)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		cnt+=(s-pre)/a;
		pre=s+t;
	}
	cnt+=(l-pre)/a;
	printf("%d", cnt);
	return 0;
}