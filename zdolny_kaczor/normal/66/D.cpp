# include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 3)
		printf("-1\n");
	else
	{
		printf("%d\n%d\n%d\n", 2 * 3, 3 * 5, 2 * 5);
		for (int i = 3; i < n; ++i)
			printf("%I64d\n", (1ll << i) * 3);
	}
}