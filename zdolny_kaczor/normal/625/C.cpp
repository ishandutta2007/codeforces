# include <cstdio>
const int MN = 509;
int tab[MN][MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int nr = 1;
	for (int j = 1; j <= n; ++j)
		for (int i = 1; i < k; ++i)
		{
			tab[j][i] = nr;
			nr ++;
		}
	int res = 0;
	for (int j = 1; j <= n; ++j)
		for (int i = k; i <= n; ++i)
		{
			tab[j][i] = nr;
			if (i == k)
				res += nr;
			nr++;
		}
	printf("%d\n", res);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
}