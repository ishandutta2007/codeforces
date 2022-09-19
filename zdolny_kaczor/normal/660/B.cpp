# include <cstdio>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * 2; ++i)
	{
		if (i + n * 2 <= m)
			printf("%d ", i + n * 2);
		if (i <= m)
			printf("%d ", i);
	}
}