# include <cstdio>
long long under(long long a)
{
	long long x = (a / 2) % 2;
	if (a % 2)
		return x ^ (a - 1);
	else
		return x;
}
int main()
{
	long long out = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		long long x, m;
		scanf("%I64d%I64d", &x, &m);
		out ^= under(x) ^ under(x + m);
	}
	if (out)
		printf("tolik\n");
	else
		printf("bolik\n");
}