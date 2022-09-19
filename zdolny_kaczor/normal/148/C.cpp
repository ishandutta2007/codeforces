# include <cstdio>
int main()
{
	int n, oh, wow;
	scanf("%d%d%d", &n, &oh, &wow);
	if (oh == n - 1)
	{
		if (n == 1)
			printf("%d\n", 531);
		else
			printf("-1\n");
	}
	else
	{
		for (int i = 0; i <= wow; ++i)
			printf("%d ", 1 << i);
		if (wow == 0)
			printf("1 ");
		for (int i = 0; i < oh; ++i)
			printf("%d ", (1 << wow) + i + 1);
		for (int i = 0; i < n - oh - 1 - wow - (wow == 0 ? 1 : 0); ++i)
			printf("1 ");
		printf("\n");
	}
}