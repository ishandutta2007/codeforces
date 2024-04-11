# include <cstdio>
const int MN = 1e7 + 44;
int div[MN];
long long cou[MN];
long long exp(int p, long long n)
{
	long long res = 0;
	while (n > 0)
	{
		res += n / p;
		n /= p;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		cou[a] ++;
	}
	for (int p = 2; p < MN; ++p)
		if (div[p] == 0)
			for (int k = p; k < MN; k += p)
				div[k] = p;
	for (int i = MN - 1; i > 0; --i)
		cou[i - 1] += cou[i];
	for (int i = MN - 1; i >= 2; --i)
		if (div[i] != i)
		{
			cou[i / div[i]] += cou[i];
			cou[div[i]] += cou[i];
			cou[i] = 0;
		}
	long long ans = 0, low = 1, high = 1e13 + 44;
	while (low <= high)
	{
		long long med = (low + high) / 2;
		bool OK = true;
		for (int i = 2; i < MN; ++i)
			if (div[i] == i)
				if (exp(i, med) < cou[i])
					OK = false;
		if (OK)
		{
			ans = med;
			high = med - 1;
		}
		else
		{
			low = med + 1;
		}
	}
	printf("%I64d\n", ans);
}