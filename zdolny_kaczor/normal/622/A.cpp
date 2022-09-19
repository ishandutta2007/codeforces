# include <cstdio>
int main()
{
	long long n;
// 	int n;
	scanf("%I64d", &n);
	long long sum = 0;
	for (int i = 1; sum < n; ++i)
	{
		if (n - sum <= i)
		{
			printf("%I64d\n", n - sum);
			return 0;
		}
		sum += i;
	}
}