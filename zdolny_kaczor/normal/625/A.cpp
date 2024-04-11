# include <cstdio>
# include <set>
int main()
{
	long long n;
	long long a, b, c;
	scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
	long long res = n / a;
	if (n > c)
	{
		long long cou = (n - c) / (b - c);
		res = std::max(res, cou + (n - cou * (b - c)) / a);
	}
	printf("%I64d\n", res);
}