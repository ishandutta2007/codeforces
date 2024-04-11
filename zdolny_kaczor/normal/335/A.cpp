# include <cstdio>
# include <cstring>
const int MN = 1e3 + 44;
const int A = 26;
char a[MN];
int cou[A];
int main()
{
	int n;
	scanf("%s%d", a, &n);
	for (int i = 0; a[i]; ++i)
		cou[a[i] - 'a']++;
	int low = 1, high = MN, ans = -1;
	while (low <= high)
	{
		int med = (low + high) / 2;
		int needed = 0;
		for (int i = 0; i < A; ++i)
			needed += (cou[i] + med - 1) / med;
		if (needed <= n)
		{
			ans = med;
			high = med - 1;
		}
		else
			low = med + 1;
	}
	printf("%d\n", ans);
	if (ans != -1)
	{
		int left = n;
		for (int i = A - 1; i >= 0; --i)
			for (int k = 0; k < (cou[i] + ans - 1) / ans; ++k)
			{
				putchar(i + 'a');
				left--;
			}
		for (int i = 1; i <= left; ++i)
			putchar('a' + 75319 / i % 26);
		printf("\n");
	}
}