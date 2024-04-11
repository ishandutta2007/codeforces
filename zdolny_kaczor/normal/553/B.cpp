# include <cstdio>
const int MN = 51;
long long f[MN];
int res[MN];
int main()
{
	f[0] = f[1] = 1;
	for (int i = 2; i < MN; ++i)
		f[i] = f[i - 1] + f[i - 2];
	int n;
	long long k;
	scanf("%d%I64d", &n, &k);
	for (int i = 1; i <= n; )
	{
		if (k > f[n - i])
		{
			k -= f[n - i];
			res[i] = i + 1;
			res[i + 1] = i;
			i += 2;
		}
		else
		{
			res[i] = i;
			i++;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	printf("\n");
}