# include <cstdio>
const int MN = 1e6 + 7;
int main()
{
	int n;
	scanf("%d", &n);
	long long res = 0;
	int min = 1e9, cou = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x%2)
		{
			cou ++;
			if (x < min)
				min = x;
		}
		res += x;
	}
	if (cou % 2)
	{
		res -= min;
	}
	printf("%I64d\n", res);
}