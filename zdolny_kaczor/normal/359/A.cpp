# include <cstdio>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
		{
			int x;
			scanf("%d", &x);
			if (x == 1 && (i == 0 || k == 0 || i == n - 1 || k == m - 1))
			{
				printf("2\n");
				return 0;
			}
		}
	printf("4\n");
}