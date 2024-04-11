# include <cstdio>
int main()
{
	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);
	if (d > 2 * h || (d == h && h == 1 && n > 2))
		printf("-1\n");
	else
	{
		for (int i = 1; i <= h; ++i)
			printf("%d %d\n", i, i + 1);
		int last = 1;
		for (int i = h + 2; i <= d + 1; ++i)
		{
			printf("%d %d\n", i, last);
			last = i;
		}
		int beg = (d > h) ? 1 : 2;
		for (int i = d + 2; i <= n; ++i)
			printf("%d %d\n", beg, i);
	}
}