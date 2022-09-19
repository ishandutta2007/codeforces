# include <cstdio>
# include <algorithm>
int tab[31];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", tab + i);
	std::sort(tab, tab + n);
	int amo = 1e9 + 4;
	long long res = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (amo == 0)
			break;
		int take = std::min(amo - 1, tab[i]);
		amo = take;
		res += take;
	}
	printf("%I64d\n", res);
}